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
* Tue Nov 16 15:19:57 2004
*
*/



#ifndef __CSVCGENERICSTUB_H__
#define __CSVCGENERICSTUB_H__


/****************************************************************************************
 * 
 * Local Includes
 * 
 ***************************************************************************************/
#include "GenericStub.h"
#include "CSGenericstub.h"
#include "CComponentManager.h"


/****************************************************************************************
 * 
 * Definition: CSvcGenericstub
 * 
 ***************************************************************************************/
class CSvcGenericstub
{
public:
	/* standard methods */
	static int GetInstanceKeyFromArgs( int aMethod, void *aArgs );
	static int SetError( int aMethod, void *aArgs, int aError );
	static int GetError( int aMethod, void *aArgs );
	static int StartRPCService( CComponentManager<CSGenericstub> *aComponentManager, TStartupInfo *aArg );
	static int StopRPCService();
};

#endif
