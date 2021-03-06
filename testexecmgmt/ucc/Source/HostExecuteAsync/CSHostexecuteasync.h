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
* Thu Oct 16 14:41:55 2003
*
*/




#ifndef __CSHOSTEXECUTEASYNC_H__
#define __CSHOSTEXECUTEASYNC_H__


/****************************************************************************************
 * 
 * Local Includes
 * 
 ***************************************************************************************/
#include "hostexecuteasync.h"
#include "../ProcessLibrary/proclib.h"


/****************************************************************************************
 * 
 * Definition: CSHostexecuteasync
 * 
 ***************************************************************************************/
class CSHostexecuteasync
{
public:
	// Standard Methods
	CSHostexecuteasync();
	~CSHostexecuteasync();
	int GetKey();
	void SetKey( int aKey );

	// RPC Service Methods
	TResult cstr_startprocess( char *aArgs );
	TResult dstr_removeprocess( int aArgs, int *aDeleteInstance );
	TResult killprocess( int aArgs );
	TResult stopprocess( int aArgs );
	THostExecuteAsyncProcessInfo getprocessinfo( int aArgs );
	TVarData getstandardoutput( int aArgs );
	TVarData getstandarderror( int aArgs );

private:
	int iKey;
	CAProcess *iProcess;
	TResult StopProcessWithSignal( int aSignal );
};

#endif
