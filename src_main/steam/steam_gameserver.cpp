//===== Copyright © 1996-2005, Valve Corporation, All rights reserved. ======//
//
// Purpose: 
//
//===========================================================================//

#include <steam/steam_api.h>
#include <steam/steam_gameserver.h>

S_API void SteamGameServer_Shutdown()
{
}

S_API void SteamGameServer_RunCallbacks()
{
}

S_API HSteamPipe S_CALLTYPE SteamGameServer_GetHSteamPipe()
{
	return 0;
}

S_API HSteamUser S_CALLTYPE SteamGameServer_GetHSteamUser()
{
	return 0;
}

S_API bool SteamInternal_GameServer_Init( uint32 unIP, uint16 usPort, uint16 usGamePort, uint16 usQueryPort, EServerMode eServerMode, const char *pchVersionString )
{
	return false;
}
