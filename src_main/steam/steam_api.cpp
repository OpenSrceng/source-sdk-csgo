//===== Copyright © 1996-2005, Valve Corporation, All rights reserved. ======//
//
// Purpose: 
//
//===========================================================================//

#include <steam/steam_api.h>

S_API bool SteamAPI_InitSafe()
{
	return true;
}

S_API void SteamAPI_Shutdown()
{
}

S_API void SteamAPI_SetMiniDumpComment( const char *pchMsg )
{
}

S_API void SteamAPI_RunCallbacks()
{
}

S_API void SteamAPI_RegisterCallback( class CCallbackBase *pCallback, int iCallback )
{
}

S_API void SteamAPI_UnregisterCallback( class CCallbackBase *pCallback )
{
}

S_API void SteamAPI_RegisterCallResult( class CCallbackBase *pCallback, SteamAPICall_t hAPICall )
{
}

S_API void SteamAPI_UnregisterCallResult( class CCallbackBase *pCallback, SteamAPICall_t hAPICall )
{
}

S_API HSteamPipe SteamAPI_GetHSteamPipe()
{
	return 0;
}

