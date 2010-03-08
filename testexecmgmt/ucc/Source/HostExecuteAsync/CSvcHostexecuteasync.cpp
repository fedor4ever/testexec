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
* System Includes
*
*/




#include <stdio.h>


/****************************************************************************************
 * 
 * Local Includes
 * 
 ***************************************************************************************/
#include "CSvcHostexecuteasync.h"
#include "hostexecuteasync.h"


/****************************************************************************************
 * 
 * Macro Functions
 * 
 ***************************************************************************************/
#define SET_ERROR_CODE(type_name,member_name,ptr_to_result)    { \
                                                                 ptr_to_result = (type_name*)aArgs;                    \
                                                                 memset( ptr_to_result, 0, sizeof(type_name) );        \
                                                                 ptr_to_result->member_name = aError;                  \
                                                               }

#define SET_LIST_ERROR_CODE(type_name,ptr_to_result)           { \
                                                                 assert( aError != ERR_NONE );                         \
                                                                 ptr_to_result = (type_name*)aArgs;                    \
                                                                 if( ptr_to_result->type_name##_len != 0 ) {           \
                                                                   free( ptr_to_result->type_name##_val );             \
                                                                   ptr_to_result->type_name##_val = NULL;              \
                                                                   ptr_to_result->type_name##_len = 0;                 \
                                                                 }                                                     \
							       }			



/****************************************************************************************
 * 
 * File-scope variables
 * 
 ***************************************************************************************/
static CComponentManager<CSHostexecuteasync> *iComponentManager;


/****************************************************************************************
 * 
 * Implementation
 * 
 ***************************************************************************************/


/****************************************************************************************
 * 
 * PUBLIC: GetInstanceKeyFromArgs
 * 
 ***************************************************************************************/
int CSvcHostexecuteasync::GetInstanceKeyFromArgs( int aMethod, void *aArgs )
{
	int rv;
	int *ik_integer;

	switch( aMethod ) {

		// Integer params 
	case DSTR_REMOVEPROCESS:
	case KILLPROCESS:
	case STOPPROCESS:
	case GETPROCESSINFO:
	case GETSTANDARDOUTPUT:
	case GETSTANDARDERROR:
		ik_integer = (int*)aArgs;
		rv = *ik_integer;
		break;

		// Error
	default:
		rv = ERR_INVALID_METHOD;
		break;
	}
	return rv;
}


/****************************************************************************************
 * 
 * PUBLIC: SetError
 * 
 ***************************************************************************************/
int CSvcHostexecuteasync::SetError( int aMethod, void *aArgs, int aError )
{
	int rv;
	TResult *rv_result;
	THostExecuteAsyncProcessInfo *rv_proc_info;
	TVarData *rv_vardata;
	TComponentList *rv_cl;

	switch( aMethod ) {

		// TComponentList
	case LIST_DEVICES:
		SET_LIST_ERROR_CODE( TComponentList, rv_cl );
		break;

		// TResult
	case CSTR_STARTPROCESS:
	case DSTR_REMOVEPROCESS:
	case KILLPROCESS:
	case STOPPROCESS:
	    SET_ERROR_CODE( TResult, iStandardResult, rv_result );
		break;

		// THostExecuteAsyncProcessInfo
	case GETPROCESSINFO:
	    SET_ERROR_CODE( THostExecuteAsyncProcessInfo, iErrorCode, rv_proc_info );
		break;

		// VarData
	case GETSTANDARDOUTPUT:
	case GETSTANDARDERROR:
	    SET_LIST_ERROR_CODE( TVarData, rv_vardata );
		break;

		// Invalid
	default:
		rv = ERR_INVALID_METHOD;
		break;
	}
	return rv;
}


/****************************************************************************************
 * 
 * PUBLIC: GetError
 * 
 ***************************************************************************************/
int CSvcHostexecuteasync::GetError( int aMethod, void *aArgs )
{
  TResult *result;
  
  // check assumption
  assert( (aMethod == CSTR_STARTPROCESS) || (aMethod == DSTR_REMOVEPROCESS) );
  
  // return error code
  result = (TResult*)aArgs;
  return result->iStandardResult;
}


/****************************************************************************************
 * 
 * PUBLIC: StartRPCService
 * 
 ***************************************************************************************/
int CSvcHostexecuteasync::StartRPCService( CComponentManager<CSHostexecuteasync> *aComponentManager, TStartupInfo *aArg )
{
	assert( iComponentManager == NULL );
	iComponentManager = aComponentManager;
	return ERR_NONE;
}


/****************************************************************************************
 * 
 * PUBLIC: StopRPCService
 * 
 ***************************************************************************************/
int CSvcHostexecuteasync::StopRPCService()
{
	iComponentManager = NULL;
	return ERR_NONE;
}
