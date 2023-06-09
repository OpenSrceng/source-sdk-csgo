//===== Copyright  1996-2005, Valve Corporation, All rights reserved. ======//
//
// Purpose: 
//
//===========================================================================//

#include "shaderlib/ShaderDLL.h"
#include "materialsystem/IShader.h"
#include "tier1/utlvector.h"
#include "tier1/utllinkedlist.h"
#include "tier0/dbg.h"
#include "materialsystem/imaterialsystemhardwareconfig.h"
#include "materialsystem/materialsystem_config.h"
#include "materialsystem/ishadersystem.h"
#include "materialsystem/ishaderapi.h"
#include "shaderlib_cvar.h"
#include "mathlib/mathlib.h"
#include "tier2/tier2.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

//-----------------------------------------------------------------------------
// The standard implementation of CShaderDLL
//-----------------------------------------------------------------------------
class CShaderDLL : public IShaderDLLInternal, public IShaderDLL
{
public:
	CShaderDLL();

	// methods of IShaderDLL
	virtual bool Connect( CreateInterfaceFn factory );
	virtual void Disconnect();

	// methods of IShaderDLLInternal
	virtual int ShaderCount() const;
	virtual IShader *GetShader( int nShader );
	int ShaderComboSemanticsCount() const;
	const ShaderComboSemantics_t *GetComboSemantics( int n );
	virtual bool Connect( CreateInterfaceFn factory, bool bIsMaterialSystem );
	virtual void Disconnect( bool bIsMaterialSystem );
	virtual void InsertShader( IShader *pShader );

	virtual void AddShaderComboInformation( const ShaderComboSemantics_t *pSemantics );

private:
	CUtlVector< IShader * >	m_ShaderList;
	CUtlLinkedList< const ShaderComboSemantics_t * > m_ShaderComboSemantics;
};


//-----------------------------------------------------------------------------
// Global interfaces/structures
//-----------------------------------------------------------------------------
extern MaterialSystem_Config_t g_config;
const MaterialSystem_Config_t *g_pConfig = &g_config;


//-----------------------------------------------------------------------------
// Interfaces/structures local to shaderlib
//-----------------------------------------------------------------------------
#ifndef _PS3
IShaderSystem* g_pSLShaderSystem;
#endif


// Pattern necessary because shaders register themselves in global constructors
static CShaderDLL *s_pShaderDLL;


//-----------------------------------------------------------------------------
// Global accessor
//-----------------------------------------------------------------------------
IShaderDLL *GetShaderDLL()
{
	// Pattern necessary because shaders register themselves in global constructors
	if ( !s_pShaderDLL )
	{
		s_pShaderDLL = new CShaderDLL;
	}

	return s_pShaderDLL;
}

IShaderDLLInternal *GetShaderDLLInternal()
{
	// Pattern necessary because shaders register themselves in global constructors
	if ( !s_pShaderDLL )
	{
		s_pShaderDLL = new CShaderDLL;
	}

	return static_cast<IShaderDLLInternal*>( s_pShaderDLL );
}

//-----------------------------------------------------------------------------
// Singleton interface
//-----------------------------------------------------------------------------
EXPOSE_INTERFACE_FN( (InstantiateInterfaceFn)GetShaderDLLInternal, IShaderDLLInternal, SHADER_DLL_INTERFACE_VERSION );

//-----------------------------------------------------------------------------
// Connect, disconnect...
//-----------------------------------------------------------------------------
CShaderDLL::CShaderDLL()
{
	MathLib_Init( 2.2f, 2.2f, 0.0f, 2.0f );
}


//-----------------------------------------------------------------------------
// Connect, disconnect...
//-----------------------------------------------------------------------------
bool CShaderDLL::Connect( CreateInterfaceFn factory, bool bIsMaterialSystem )
{
#if defined( _PS3 )
	return true;
#else
	g_pSLShaderSystem =  (IShaderSystem*)factory( SHADERSYSTEM_INTERFACE_VERSION, NULL );
	return ( g_pSLShaderSystem != NULL );
#endif
}

void CShaderDLL::Disconnect( bool bIsMaterialSystem )
{
#if !defined( _PS3 )
	g_pSLShaderSystem = NULL;
#endif
}

bool CShaderDLL::Connect( CreateInterfaceFn factory )
{
	return Connect( factory, false );
}

void CShaderDLL::Disconnect()
{
	Disconnect( false );
}


//-----------------------------------------------------------------------------
// Iterates over all shaders
//-----------------------------------------------------------------------------
int CShaderDLL::ShaderCount() const
{
	return m_ShaderList.Count();
}

IShader *CShaderDLL::GetShader( int nShader ) 
{
	if ( ( nShader < 0 ) || ( nShader >= m_ShaderList.Count() ) )
		return NULL;

	return m_ShaderList[nShader];
}


//-----------------------------------------------------------------------------
// Adds to the shader lists
//-----------------------------------------------------------------------------
void CShaderDLL::InsertShader( IShader *pShader )
{
	Assert( pShader );
	m_ShaderList.AddToTail( pShader );
}

//-----------------------------------------------------------------------------
// Iterates over all shader semantics
//-----------------------------------------------------------------------------
int CShaderDLL::ShaderComboSemanticsCount() const
{
	return m_ShaderComboSemantics.Count();
}

const ShaderComboSemantics_t *CShaderDLL::GetComboSemantics( int n ) 
{
	if ( ( n < 0 ) || ( n >= m_ShaderComboSemantics.Count() ) )
		return NULL;

	return m_ShaderComboSemantics[n];
}

//-----------------------------------------------------------------------------
// Adds to the shader combo semantics list
//-----------------------------------------------------------------------------
void CShaderDLL::AddShaderComboInformation( const ShaderComboSemantics_t *pSemantics )
{
	m_ShaderComboSemantics.AddToTail( pSemantics );
}
