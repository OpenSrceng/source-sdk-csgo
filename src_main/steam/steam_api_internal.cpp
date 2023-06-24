//===== Copyright © 1996-2005, Valve Corporation, All rights reserved. ======//
//
// Purpose: 
//
//===========================================================================//

#include <steam/steam_api.h>

S_API HSteamUser SteamAPI_GetHSteamUser()
{
	return 0;
}

S_API void *SteamInternal_CreateInterface( const char *ver )
{
	return 0;
}

S_API void SteamAPI_UseBreakpadCrashHandler( char const *pchVersion, char const *pchDate, char const *pchTime, bool bFullMemoryDumps, void *pvContext, PFNPreMinidumpCallback m_pfnPreMinidumpCallback )
{
}

S_API void SteamAPI_SetBreakpadAppID( uint32 unAppID )
{
}
