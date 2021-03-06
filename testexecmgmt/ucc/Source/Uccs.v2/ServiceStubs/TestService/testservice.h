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
*
*/




#ifndef __TESTSERVICE_H__
#define __TESTSERVICE_H__
#include <rpc/types.h>
#include <rpc/rpc.h>

#define ERR_NONE 0
#define ERR_INVALID_ERROR_CODE -16
#define ERR_SERVICE_ALREADY_STARTED -1
#define ERR_SERVICE_NOT_RUNNING -2
#define ERR_ACTIVE_USER_SESSIONS -3
#define ERR_FAILED_TO_REMOVE_ACTIVE_SESSIONS -4
#define ERR_FAILED_TO_CREATE_COMPONENT_MANAGER -5
#define ERR_FAILED_TO_RETRIEVE_KEY -6
#define ERR_INSTANCE_DOES_NOT_EXIST -7
#define ERR_CANNOT_CREATE_NEW_INSTANCE -9
#define ERR_MISSING_PARAMETER -17
#define ERR_INVALID_METHOD -8
#define ERR_STUB_ALREADY_CONNECTED -10
#define ERR_FAILED_TO_CONNECT -11
#define ERR_STUB_NOT_CONNECTED -12
#define ERR_INVALID_RV_POINTER -13
#define ERR_RPC_ERROR -14
#define ERR_INVALID_SERVICE -15
#define ERR_INVALIDARG -50
#define ERR_INVALIDSTATE -51
#define ERR_GENERAL -52
#define INFO_MAXIMUM_OBJECTS 256

typedef struct {
	u_int TComponentList_len;
	int *TComponentList_val;
} TComponentList;
#ifdef __cplusplus
extern "C" {
bool_t xdr_testservice_TComponentList(...);
}
#else
bool_t xdr_testservice_TComponentList();
#endif


struct TResult {
	int iStandardResult;
	int iExtendedCode;
	int iSystemError;
};
typedef struct TResult TResult;
#ifdef __cplusplus
extern "C" {
bool_t xdr_testservice_TResult(...);
}
#else
bool_t xdr_testservice_TResult();
#endif


struct TStartupInfo {
	int iEmpty;
};
typedef struct TStartupInfo TStartupInfo;
#ifdef __cplusplus
extern "C" {
bool_t xdr_testservice_TStartupInfo(...);
}
#else
bool_t xdr_testservice_TStartupInfo();
#endif


#define TESTSERVICE ((u_long)0x34630211)
#define TESTSERVICE_VERSION ((u_long)11)
#define SS_STARTUPRPCSERVICE ((u_long)1)
#ifdef __cplusplus
extern "C" {
extern int *ss_startuprpcservice_11( TStartupInfo * arg, CLIENT *cl );
}
#else
extern int *ss_startuprpcservice_11();
#endif /* __cplusplus */
#define SC_SHUTDOWNRPCSERVICE ((u_long)2)
#ifdef __cplusplus
extern "C" {
extern int *sc_shutdownrpcservice_11( int * arg, CLIENT *cl );
}
#else
extern int *sc_shutdownrpcservice_11();
#endif /* __cplusplus */
#define LIST_DEVICES ((u_long)3)
#ifdef __cplusplus
extern "C" {
extern TComponentList *list_devices_11( void * arg, CLIENT *cl );
}
#else
extern TComponentList *list_devices_11();
#endif /* __cplusplus */
#define ST_DISCARD ((u_long)10)
#ifdef __cplusplus
extern "C" {
extern TResult *st_discard_11( int * arg, CLIENT *cl );
}
#else
extern TResult *st_discard_11();
#endif /* __cplusplus */
#define ST_BLOCK ((u_long)11)
#ifdef __cplusplus
extern "C" {
extern TResult *st_block_11( int * arg, CLIENT *cl );
}
#else
extern TResult *st_block_11();
#endif /* __cplusplus */
#define ST_WAIT ((u_long)12)
#ifdef __cplusplus
extern "C" {
extern TResult *st_wait_11( int * arg, CLIENT *cl );
}
#else
extern TResult *st_wait_11();
#endif /* __cplusplus */

#endif /* __TESTSERVICE_H__ */
