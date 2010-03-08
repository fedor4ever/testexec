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
* THIS FILE IS AUTOGENERATED. Do not modify the contents of this file directly
* as changes will be lost
* Mon Nov 24 15:19:47 2003
* System Includes
*
*/




#include <assert.h>


/****************************************************************************************
 * 
 * Local Includes
 * 
 ***************************************************************************************/
#include "CSvcUuinterface.h"
#include "CSUuinterface.h"
#include "CComponentManager.h"


/****************************************************************************************
 * 
 * Static Variables
 * 
 ***************************************************************************************/
static CComponentManager<CSUuinterface> *iComponentManager;


/****************************************************************************************
 * 
 * PUBLIC FUNCTION: ss_startuprpcservice
 * 
 ***************************************************************************************/
int *ss_startuprpcservice_2( TStartupInfo *aArgs, CLIENT *aDutout )
{
	static int rv;

	// if the service is already started then return an error
	if( iComponentManager != NULL ) {
		rv = ERR_SERVICE_ALREADY_STARTED;
		return &rv;
	}

	// create the component manager
	iComponentManager = new CComponentManager<CSUuinterface>( INFO_MAXIMUM_OBJECTS );
	if( iComponentManager == NULL ) {
		rv = ERR_FAILED_TO_CREATE_COMPONENT_MANAGER;
		return &rv;
	}

	// call the custom service manager
	rv = CSvcUuinterface::StartRPCService( iComponentManager, aArgs );
	if( rv != ERR_NONE ) {
		delete iComponentManager;
		iComponentManager = NULL;
		return &rv;
	}

	// success
	rv = ERR_NONE;
	return &rv;
}


/****************************************************************************************
 * 
 * PUBLIC FUNCTION: sc_shutdownrpcservice
 * 
 ***************************************************************************************/
int *sc_shutdownrpcservice_2( int *aArgs, CLIENT *aDutout )
{
	static int rv;
	int instance_count;
	int err;

	// check that the service is started
	if( iComponentManager == NULL ) {
		rv = ERR_SERVICE_NOT_RUNNING;
		return &rv;
	}

	// if there are active sessions and the force flag isn't set then return an error
	instance_count = iComponentManager->GetInstanceCount();
	if( (instance_count > 0) && (*aArgs == 0) ) {
		rv = ERR_ACTIVE_USER_SESSIONS;
		return &rv;
	};

	// if the force flag IS set then reset all active connections
	instance_count = iComponentManager->GetInstanceCount();
	if( instance_count > 0 ) {
		err = iComponentManager->DeleteAllInstances();
		if( err != 0 ) {
			rv = ERR_FAILED_TO_REMOVE_ACTIVE_SESSIONS;
			return &rv;
		}
	}

	// call the custom service manager
	rv = CSvcUuinterface::StopRPCService();
	if( rv != ERR_NONE ) {
		return &rv;
	}

	// delete the component manager
	delete iComponentManager;
	iComponentManager = NULL;

	// success
	rv = ERR_NONE;
	return &rv;
}


/****************************************************************************************
 * 
 * PUBLIC FUNCTION: list_devices
 * 
 ***************************************************************************************/
TComponentList *list_devices_2( void *aArgs, CLIENT *aDutout )
{
	static TComponentList rv;
	int i, valid_count, component_instance_count;

	//free any allocated memory
	if( rv.TComponentList_val != NULL ) {
		free( rv.TComponentList_val );
		rv.TComponentList_val = NULL;
		rv.TComponentList_len = 0;
	}

	// check that the service is started
	if( iComponentManager == NULL ) {
		CSvcUuinterface::SetError( LIST_DEVICES, (void*)&rv, ERR_SERVICE_NOT_RUNNING );
		return &rv;
	}

	// set the return value to generic error
	CSvcUuinterface::SetError( LIST_DEVICES, (void*)&rv, ERR_FAILED_TO_RETRIEVE_KEY );

	// get the number of active component instances
	component_instance_count = iComponentManager->GetInstanceCount();

	// if there are one or more instances then allocate the memory
	if( component_instance_count > 0 ) {
		rv.TComponentList_val = (int*)malloc( sizeof(int) * component_instance_count );
		assert( rv.TComponentList_val != NULL );
		rv.TComponentList_len = component_instance_count;
	}

	// store all the currently active IDs in the list
	for( i = 0, valid_count = 0; i < INFO_MAXIMUM_OBJECTS; i++ ) {
		if( iComponentManager->IsValidKey(i) != 0 ) {
			assert( valid_count < component_instance_count );
			(rv.TComponentList_val)[valid_count++] = i;
		}
	}

	// ok return everything
	return &rv;
}


/****************************************************************************************
 * 
 * PUBLIC FUNCTION: st_setdelay
 * 
 ***************************************************************************************/
TResult *st_setdelay_2( TConfigValue *aArgs, CLIENT *aDutout )
{
	static TResult rv;

	// check that the service is started
	if( iComponentManager == NULL ) {
		CSvcUuinterface::SetError( ST_SETDELAY, (void*)&rv, ERR_SERVICE_NOT_RUNNING );
		return &rv;
	}

	// call the corresponding method on the instance
	rv = CSvcUuinterface::st_setdelay( *aArgs );
	return &rv;
}


/****************************************************************************************
 * 
 * PUBLIC FUNCTION: st_setdroppercentage
 * 
 ***************************************************************************************/
TResult *st_setdroppercentage_2( TConfigValue *aArgs, CLIENT *aDutout )
{
	static TResult rv;

	// check that the service is started
	if( iComponentManager == NULL ) {
		CSvcUuinterface::SetError( ST_SETDROPPERCENTAGE, (void*)&rv, ERR_SERVICE_NOT_RUNNING );
		return &rv;
	}

	// call the corresponding method on the instance
	rv = CSvcUuinterface::st_setdroppercentage( *aArgs );
	return &rv;
}


/****************************************************************************************
 * 
 * PUBLIC FUNCTION: st_setduplicatepercentage
 * 
 ***************************************************************************************/
TResult *st_setduplicatepercentage_2( TConfigValue *aArgs, CLIENT *aDutout )
{
	static TResult rv;

	// check that the service is started
	if( iComponentManager == NULL ) {
		CSvcUuinterface::SetError( ST_SETDUPLICATEPERCENTAGE, (void*)&rv, ERR_SERVICE_NOT_RUNNING );
		return &rv;
	}

	// call the corresponding method on the instance
	rv = CSvcUuinterface::st_setduplicatepercentage( *aArgs );
	return &rv;
}


/****************************************************************************************
 * 
 * PUBLIC FUNCTION: st_setbandwidth
 * 
 ***************************************************************************************/
TResult *st_setbandwidth_2( TConfigValue *aArgs, CLIENT *aDutout )
{
	static TResult rv;

	// check that the service is started
	if( iComponentManager == NULL ) {
		CSvcUuinterface::SetError( ST_SETBANDWIDTH, (void*)&rv, ERR_SERVICE_NOT_RUNNING );
		return &rv;
	}

	// call the corresponding method on the instance
	rv = CSvcUuinterface::st_setbandwidth( *aArgs );
	return &rv;
}


/****************************************************************************************
 * 
 * PUBLIC FUNCTION: st_setdrd
 * 
 ***************************************************************************************/
TResult *st_setdrd_2( TConfigValue *aArgs, CLIENT *aDutout )
{
	static TResult rv;

	// check that the service is started
	if( iComponentManager == NULL ) {
		CSvcUuinterface::SetError( ST_SETDRD, (void*)&rv, ERR_SERVICE_NOT_RUNNING );
		return &rv;
	}

	// call the corresponding method on the instance
	rv = CSvcUuinterface::st_setdrd( *aArgs );
	return &rv;
}


/****************************************************************************************
 * 
 * PUBLIC FUNCTION: st_clearsettings
 * 
 ***************************************************************************************/
TResult *st_clearsettings_2( TConfigValue *aArgs, CLIENT *aDutout )
{
	static TResult rv;

	// check that the service is started
	if( iComponentManager == NULL ) {
		CSvcUuinterface::SetError( ST_CLEARSETTINGS, (void*)&rv, ERR_SERVICE_NOT_RUNNING );
		return &rv;
	}

	// call the corresponding method on the instance
	rv = CSvcUuinterface::st_clearsettings( *aArgs );
	return &rv;
}


/****************************************************************************************
 * 
 * PUBLIC FUNCTION: st_stopservice
 * 
 ***************************************************************************************/
TResult *st_stopservice_2( void *aArgs, CLIENT *aDutout )
{
	static TResult rv;

	// check that the service is started
	if( iComponentManager == NULL ) {
		CSvcUuinterface::SetError( ST_STOPSERVICE, (void*)&rv, ERR_SERVICE_NOT_RUNNING );
		return &rv;
	}

	// call the corresponding method on the instance
	rv = CSvcUuinterface::st_stopservice();
	return &rv;
}


/****************************************************************************************
 * 
 * PUBLIC FUNCTION: st_reset
 * 
 ***************************************************************************************/
TResult *st_reset_2( void *aArgs, CLIENT *aDutout )
{
	static TResult rv;

	// check that the service is started
	if( iComponentManager == NULL ) {
		CSvcUuinterface::SetError( ST_RESET, (void*)&rv, ERR_SERVICE_NOT_RUNNING );
		return &rv;
	}

	// call the corresponding method on the instance
	rv = CSvcUuinterface::st_reset();
	return &rv;
}