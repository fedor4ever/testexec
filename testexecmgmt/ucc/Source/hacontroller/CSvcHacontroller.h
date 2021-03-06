/*
* Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:   
* This file was autogenerated by rpcgen, but should be modified by the developer.
* Make sure you don't use the -component_mod flag in future or this file will be overwritten.
* Mon Oct 13 13:43:15 2003
*
*/




#ifndef __CSVCHACONTROLLER_H__
#define __CSVCHACONTROLLER_H__


/****************************************************************************************
 * 
 * Local Includes
 * 
 ***************************************************************************************/
#include "hacontroller.h"
#include "CSHacontroller.h"
#include "CComponentManager.h"
#include "../AliasLibrary/CInterfaceAlias.h"
#include "CNetworkPartitionManager.h"


/****************************************************************************************
 * 
 * Definition: CSvcHacontroller
 * 
 ***************************************************************************************/
class CSvcHacontroller
{
public:
	static int GetInstanceKeyFromArgs( int aMethod, void *aArgs );
	static int SetError( int aMethod, void *aArgs, int aError );
	static int GetError( int aMethod, void *aArgs );
	static int StartRPCService( CComponentManager<CSHacontroller> *aComponentManager, TStartupInfo *aArg );
	static int StopRPCService();

	// Custom
	static TStartupInfo GetStartupInfo();
	static CIntegerAllocator *GetAliasHostAddressAllocator();
	static CNetworkPartitionManager *GetNetworkPartitionManager();
};

#endif
