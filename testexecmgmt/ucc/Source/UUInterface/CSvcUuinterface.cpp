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
* Wed Nov 05 16:06:20 2003
* System Includes
*
*/




#include <stdio.h>


/****************************************************************************************
 * 
 * Local Includes
 * 
 ***************************************************************************************/
#include "CSvcUuinterface.h"
#include "uuinterface.h"
#include "../ProcessLibrary/proclib.h"
#include "../include/standard_unix.h"
#include "../include/standard_service_manager.h"

/****************************************************************************************
 * 
 * File-scope variables
 * 
 ***************************************************************************************/
static CComponentManager<CSUuinterface> *iComponentManager;


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
int CSvcUuinterface::GetInstanceKeyFromArgs( int aMethod, void *aArgs )
{
	// Not implemented as we will never have more that one instance
	assert( !"NOT IMPLEMENTED" );
	return ERR_NONE;
}


/****************************************************************************************
 * 
 * PUBLIC: SetError
 * 
 ***************************************************************************************/
int CSvcUuinterface::SetError( int aMethod, void *aArgs, int aError )
{
	TResult* result;
	TComponentList *rv_component_list;
	int rv = ERR_NONE;
	
	// Check params
	assert ( aArgs != NULL );

	switch( aMethod ) {
	case LIST_DEVICES:
		SET_LIST_ERROR_CODE( TComponentList, rv_component_list );

	case ST_SETDELAY:
	case ST_SETDROPPERCENTAGE:
	case ST_SETDUPLICATEPERCENTAGE:
	case ST_SETBANDWIDTH:
	case ST_SETDRD:
	case ST_CLEARSETTINGS:
	case ST_STOPSERVICE:
	case ST_RESET:
		SET_ERROR_CODE( TResult, iStandardResult, result );
		break;

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
int CSvcUuinterface::GetError( int aMethod, void *aArgs )
{
	// Not implemented as we will never have more that one instance
	assert( !"NOT IMPLEMENTED" );
	return ERR_NONE;
}


/****************************************************************************************
 * 
 * PUBLIC: StartRPCService
 * 
 ***************************************************************************************/
int CSvcUuinterface::StartRPCService( CComponentManager<CSUuinterface> *aComponentManager, TStartupInfo *aArg )
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
int CSvcUuinterface::StopRPCService()
{
	iComponentManager = NULL;
	return ERR_NONE;
}


/****************************************************************************************
 * 
 * PUBLIC: st_setdelay
 * 
 ***************************************************************************************/
TResult CSvcUuinterface::st_setdelay( TConfigValue aArgs )
{
	TResult rv;
	int ret;

	char commandLine[MAX_COMMANDLINE];
	char finalSrc[TOTAL_MAX_ADDRESS_LEN]; 
	char finalDst[TOTAL_MAX_ADDRESS_LEN];

	// check the values in the config values structure
	ret = CheckConfigValue( aArgs, finalSrc, finalDst );
	if ( ret == ERR_INVALIDARG )
	{
		memset( &rv, 0, sizeof(rv) );
		rv.iStandardResult = ERR_INVALIDARG;	
		return rv;
	}	

	// construct the command line
	snprintf( commandLine, MAX_COMMANDLINE, "./config_nistnet_add.pl -u -a %s %s --delay %d.%d %d.%d/%d.%d",
		finalSrc, 
		finalDst, 
		aArgs.iValueIntegerPart, 
		aArgs.iValueFractionPart, 
		aArgs.iSigmaIntegerPart,
		aArgs.iSigmaFractionPart,
		aArgs.iCorrelationIntegerPart,
		aArgs.iCorrelationFractionPart );

	// execute the command and return the result
	ret = execute(commandLine, &rv);
	assert ( (ret == ERR_FAILEDTOEXECUTECOMMAND) || (ret == ERR_NONE) );

	return rv;
}


/****************************************************************************************
 * 
 * PUBLIC: st_setdroppercentage
 * 
 ***************************************************************************************/
TResult CSvcUuinterface::st_setdroppercentage( TConfigValue aArgs )
{
	TResult rv;
	int ret;

	char commandLine [MAX_COMMANDLINE];
	char finalSrc[TOTAL_MAX_ADDRESS_LEN]; 
	char finalDst[TOTAL_MAX_ADDRESS_LEN];

	// check the values in the config values structure
	ret = CheckConfigValue( aArgs, finalSrc, finalDst );
	if ( ret == ERR_INVALIDARG )
	{
		memset( &rv, 0, sizeof(rv) );
		rv.iStandardResult = ERR_INVALIDARG;	
		return rv;
	}	

	ret = CheckPercentage( aArgs.iValueIntegerPart );
	if ( ret == ERR_INVALIDARG )
	{
		memset( &rv, 0, sizeof(rv) );
		rv.iStandardResult = ERR_INVALIDARG;	
		return rv;
	}	

	// construct the command line
	snprintf( commandLine, MAX_COMMANDLINE, "./config_nistnet_add.pl -u -a  %s %s --drop %d.%d/%d.%d",
		finalSrc, 
		finalDst, 
		aArgs.iValueIntegerPart, 
		aArgs.iValueFractionPart, 
		aArgs.iCorrelationIntegerPart,
		aArgs.iCorrelationFractionPart );

	// execute the command and return the result
	ret = execute(commandLine, &rv);	
	assert ( (ret == ERR_FAILEDTOEXECUTECOMMAND) || (ret == ERR_NONE) );

	return rv;
}


/****************************************************************************************
 * 
 * PUBLIC: st_setduplicatepercentage
 * 
 ***************************************************************************************/
TResult CSvcUuinterface::st_setduplicatepercentage( TConfigValue aArgs )
{
	TResult rv;
	int ret;

	char commandLine [MAX_COMMANDLINE];
	char finalSrc[TOTAL_MAX_ADDRESS_LEN]; 
	char finalDst[TOTAL_MAX_ADDRESS_LEN];

	// check the values in the config values structure
	ret = CheckConfigValue( aArgs, finalSrc, finalDst );
	if ( ret == ERR_INVALIDARG )
	{
		memset( &rv, 0, sizeof(rv) );
		rv.iStandardResult = ERR_INVALIDARG;	
		return rv;
	}
	
	ret = CheckPercentage( aArgs.iValueIntegerPart );
	if ( ret == ERR_INVALIDARG )
	{
		memset( &rv, 0, sizeof(rv) );
		rv.iStandardResult = ERR_INVALIDARG;	
		return rv;
	}	

	// construct the command line
	snprintf( commandLine, MAX_COMMANDLINE, "./config_nistnet_add.pl -u -a %s %s --dup %d.%d/%d.%d",
		finalSrc,
		finalDst, 
		aArgs.iValueIntegerPart, 
		aArgs.iValueFractionPart, 
		aArgs.iCorrelationIntegerPart,
		aArgs.iCorrelationFractionPart );

	// execute the command and return the result
	ret = execute(commandLine, &rv);	
	assert ( (ret == ERR_FAILEDTOEXECUTECOMMAND) || (ret == ERR_NONE) );
	
	return rv;
}


/****************************************************************************************
 * 
 * PUBLIC: st_setbandwidth
 * 
 ***************************************************************************************/
TResult CSvcUuinterface::st_setbandwidth( TConfigValue aArgs )
{
	TResult rv;
	int ret;
	
	char commandLine [MAX_COMMANDLINE];
	char finalSrc[TOTAL_MAX_ADDRESS_LEN]; 
	char finalDst[TOTAL_MAX_ADDRESS_LEN];

	// check the values in the config values structure
	ret = CheckConfigValue( aArgs, finalSrc, finalDst );
	if ( ret == ERR_INVALIDARG )
	{
		memset( &rv, 0, sizeof(rv) );
		rv.iStandardResult = ERR_INVALIDARG;	
		return rv;
	}	

	// construct the command line
	snprintf( commandLine, MAX_COMMANDLINE, "./config_nistnet_add.pl -u -a %s %s --bandwidth %d.%d",
		finalSrc, 
		finalDst, 
		aArgs.iValueIntegerPart, 
		aArgs.iValueFractionPart );

	// execute the command and return the result
	ret = execute(commandLine, &rv);	
	assert ( (ret == ERR_FAILEDTOEXECUTECOMMAND) || (ret == ERR_NONE) );

	return rv;
}


/**************************************************************************************** * 
 * PUBLIC: st_setdrd
 * 
 ***************************************************************************************/
TResult CSvcUuinterface::st_setdrd( TConfigValue aArgs )
{
	TResult rv;
	int ret;
	
	char commandLine [MAX_COMMANDLINE];
	char finalSrc[TOTAL_MAX_ADDRESS_LEN]; 
	char finalDst[TOTAL_MAX_ADDRESS_LEN];

	// check the values in the config values structure
	ret = CheckConfigValue( aArgs, finalSrc, finalDst );
	if ( ret == ERR_INVALIDARG )
	{
		memset( &rv, 0, sizeof(rv) );
		rv.iStandardResult = ERR_INVALIDARG;	
		return rv;
	}	

    ret = CheckDRDs( aArgs.iValueIntegerPart, aArgs.iValueFractionPart,
					aArgs.iMaximumValueIntegerPart, aArgs.iMaximumValueFractionPart, 
					aArgs.iCongestionIntegerPart, aArgs.iCongestionFractionPart );

	if ( ret == ERR_INVALIDARG )
	{
		memset( &rv, 0, sizeof(rv) );
		rv.iStandardResult = ERR_INVALIDARG;	
		return rv;
	}	

	// construct the command line
	snprintf( commandLine, MAX_COMMANDLINE, "./config_nistnet_add.pl -u -a %s %s --drd %d.%d %d.%d %d.%d",
		finalSrc, 
		finalDst, 
		aArgs.iValueIntegerPart, 
		aArgs.iValueFractionPart,
		aArgs.iMaximumValueIntegerPart, 
		aArgs.iMaximumValueFractionPart,
		aArgs.iCongestionIntegerPart, 
		aArgs.iCongestionFractionPart );

	// execute the command and return the result
	ret = execute(commandLine, &rv);
	assert ( (ret == ERR_FAILEDTOEXECUTECOMMAND) || (ret == ERR_NONE) );
	
	return rv;
}

/****************************************************************************************
 * 
 * PUBLIC: st_clearsettings
 * 
 ***************************************************************************************/
TResult CSvcUuinterface::st_clearsettings( TConfigValue aArgs )
{
	TResult rv;
	int ret;
	
	char commandLine [MAX_COMMANDLINE];
	char finalSrc[TOTAL_MAX_ADDRESS_LEN]; 
	char finalDst[TOTAL_MAX_ADDRESS_LEN];

	// check the values in the config values structure
	ret = CheckConfigValue( aArgs, finalSrc, finalDst );
	if ( ret == ERR_INVALIDARG )
	{
		memset( &rv, 0, sizeof(rv) );
		rv.iStandardResult = ERR_INVALIDARG;	
		return rv;
	}	

	// construct the command line
	snprintf( commandLine, MAX_COMMANDLINE, "./config_nistnet_add.pl -r %s %s",
		finalSrc, 
		finalDst );

	// execute the command and return the result
	ret = execute(commandLine, &rv);	
	assert ( (ret == ERR_FAILEDTOEXECUTECOMMAND) || (ret == ERR_NONE) );

	return rv;
}


/****************************************************************************************
 * 
 * PUBLIC: st_stopservice
 * 
 ***************************************************************************************/
TResult CSvcUuinterface::st_stopservice( void )
{
	TResult rv;
	int ret;
	char commandLine [MAX_COMMANDLINE];
	
	// construct the command line
	snprintf( commandLine, MAX_COMMANDLINE, "./config_nistnet_add.pl -d" );

	// execute the command and return the result
	ret = execute(commandLine, &rv);
	assert ( (ret == ERR_FAILEDTOEXECUTECOMMAND) || (ret == ERR_NONE) );
	
	return rv;
}


/****************************************************************************************
 * 
 * PUBLIC: st_reset
 * 
 ***************************************************************************************/
TResult CSvcUuinterface::st_reset( void )
{
	TResult rv;
	int ret;
	char commandLine [MAX_COMMANDLINE];
	
	// construct the command line
	snprintf( commandLine, MAX_COMMANDLINE, "./config_nistnet_reset.pl" );

	// execute the command and return the result
	ret = execute(commandLine, &rv);	
	assert ( (ret == ERR_FAILEDTOEXECUTECOMMAND) || (ret == ERR_NONE) );
	
	return rv;
}


/****************************************************************************************
 * 
 * PRIVATE: Executes the given command line
 * 
 ***************************************************************************************/
int CSvcUuinterface::execute(const char* aCommandLine, TResult* rv)
{
	int errcode;
	CAProcess process;
	TCAProcessError perr;
	TProcessExitReason preason;

	// Check params
	assert ( aCommandLine != NULL );
	assert ( rv != NULL );

	// init the rv
	memset( rv, 0, sizeof(*rv) );
	rv->iStandardResult = ERR_NONE;	

	// execute the process - return any errors
	perr = process.Execute( aCommandLine, &errcode );  
	if( perr != CAE_NONE ) {
		rv->iStandardResult = ERR_PROCESSEXECUTEFAILED;
		rv->iExtendedCode = (int)perr;
		rv->iSystemError = errcode;
	}

	// if there was an error then return now
	if( rv->iStandardResult != ERR_NONE ) {
		return ERR_FAILEDTOEXECUTECOMMAND ;
	}

	// save the status, exitreason, etc
	perr = process.GetExitReason( &preason );
	assert( perr == CAE_NONE );
	rv->iExtendedCode = (int)preason;
	
	perr = process.GetExitCode( &errcode );
	assert( perr == CAE_NONE );
	rv->iSystemError = errcode;
	
	return ERR_NONE;
}

/*******************************************************************************
 *
 * INTERNAL FUNCTION: CheckConfigVals
 *
 ******************************************************************************/
int CSvcUuinterface::CheckConfigValue( TConfigValue aConfigValue, char* afinalSrc, char* afinalDst)
{
	int err;

	assert ( afinalSrc != NULL );
	assert ( afinalDst != NULL );

	// construct valid NISTNET source/destination strings from the passed information
	err = GetSrcDstStrings( aConfigValue.iSourceAddress, aConfigValue.iDestinationAddress, 
							aConfigValue.iProtocol,
							aConfigValue.iSrcPort, aConfigValue.iDstPort,
							afinalSrc, afinalDst );
	if( err != ERR_NONE) {
		return ERR_INVALIDARG;
	}

	// do semantic checking of the values
	err = CheckCorrelation( aConfigValue.iCorrelationIntegerPart, aConfigValue.iCorrelationFractionPart );
	if( err != ERR_NONE ) {
		return ERR_INVALIDARG;
	}

	err = CheckPositive( aConfigValue.iSigmaIntegerPart, aConfigValue.iSigmaFractionPart );
	if( err != ERR_NONE ) {
		return ERR_INVALIDARG;
	}

	err = CheckPositive( aConfigValue.iValueIntegerPart, aConfigValue.iValueFractionPart );
	if( err != ERR_NONE ) {
		return ERR_INVALIDARG;
	}

	err = CheckPositive( aConfigValue.iMaximumValueIntegerPart, aConfigValue.iMaximumValueFractionPart );
	if( err != ERR_NONE ) {
		return ERR_INVALIDARG;
	}

	err = CheckPositive( aConfigValue.iCongestionIntegerPart, aConfigValue.iCongestionFractionPart );
	if( err != ERR_NONE ) {
		return ERR_INVALIDARG;
	}

	return ERR_NONE;
}		

/*******************************************************************************
 *
 * INTERNAL FUNCTION: CheckPorts
 *
 ******************************************************************************/
int CSvcUuinterface::CheckPorts( int aSrcPort, int aDestPort )
{
	
	if( !(( aSrcPort >= MIN_PORT_VAL ) && ( aSrcPort <= MAX_PORT_VAL )) ) {
		return ERR_INVALIDARG;
	}
	
	if( !(( aDestPort >= MIN_PORT_VAL ) && ( aDestPort <= MAX_PORT_VAL )) ) {
		return ERR_INVALIDARG;
	}

	return ERR_NONE;
}

/*******************************************************************************
 *
 * INTERNAL FUNCTION: CheckProts
 *
 ******************************************************************************/
int CSvcUuinterface::CheckProt( int aProtocol )
{
	if ( aProtocol == X_UDP ) 
		return ERR_NONE;
	
	if ( aProtocol == X_TCP ) 
		return ERR_NONE;

	return ERR_INVALIDARG;
}


/*******************************************************************************
 *
 * INTERNAL FUNCTION: CheckPositive
 *
 ******************************************************************************/
int CSvcUuinterface::CheckPositive( int aIntegerPart, int aFractionPart )
{
	if( aIntegerPart < 0 ) {
		return ERR_INVALIDARG;
	}
	if( aFractionPart < 0 ) {
		return ERR_INVALIDARG;
	}
	return ERR_NONE;
}

/*******************************************************************************
 *
 * INTERNAL FUNCTION: CheckCorrelation
 *
 ******************************************************************************/
int CSvcUuinterface::CheckCorrelation( int aIntegerPart, int aFractionPart )
{
	if( (aIntegerPart > -1) && (aIntegerPart < 1) ) {
		return ERR_NONE;
	}
	if( (aIntegerPart == -1) && (aFractionPart == 0) ) {
		return ERR_NONE;
	}
	if( (aIntegerPart == 1) && (aFractionPart == 0) ) {
		return ERR_NONE;
	}
	return ERR_INVALIDARG;
}

/*******************************************************************************
 *
 * INTERNAL FUNCTION: CheckDRDs
 *
 ******************************************************************************/
int CSvcUuinterface::CheckDRDs( const int aDRDMinInt, const int aDRDMinFrac, 
							    const int aDRDMaxInt, const int aDRDMaxFrac, 
							    const int aDRDCongestInt, const int aDRDCongestFrac )
{
   	//Condition for drd vals is 0<=drdmin (<= drdcongest) <=drdmax
   	if (!(aDRDMinInt>=0 && aDRDMinFrac>=0 && aDRDMaxInt >=0 && aDRDMaxFrac>=0 )) {
		return ERR_INVALIDARG;
   	}   
   	if ( aDRDMinInt > aDRDMaxInt ) {
		return ERR_INVALIDARG;
   	}   
   	if (aDRDCongestInt >= 0 && aDRDCongestFrac >=0) {
   		if ( !( (aDRDMinInt < aDRDCongestInt) && (aDRDMaxInt > aDRDCongestInt) ) ) {
			return ERR_INVALIDARG;
   		}
   	} else {
		return ERR_INVALIDARG;	
	}
   	return ERR_NONE;
}

/*******************************************************************************
 *
 * INTERNAL FUNCTION: CheckPercentage
 *
 ******************************************************************************/
int CSvcUuinterface::CheckPercentage( const int aPercentage )
{
	if (aPercentage >= 0 && aPercentage < 100)
		return ERR_NONE;
	return ERR_INVALIDARG;
}

/*******************************************************************************
 *
 * GetSrcDstStrings
 *
 ******************************************************************************/
int CSvcUuinterface::GetSrcDstStrings(	char* aSrc, char* aDst, 
						int aProtocol,
						int aSrcPort, int aDstPort,
						char* finalSrc, char* finalDst )
{
	int err, len;

	// validate params
	assert(aSrc!=NULL);
	assert(aDst!=NULL);
	assert(finalSrc!=NULL);
	assert(finalDst!=NULL);

	// Validate the ports
	err = CheckPorts( aSrcPort,aDstPort );
	if( err != ERR_NONE ) {
		return ERR_INVALIDARG;
	}

	// Validate the prots
	err = CheckProt( aProtocol );
	if( err != ERR_NONE ) {
		return ERR_INVALIDARG;
	}

	// Formulate a complete source string <ip-address> + ':' + <port> + '.' + <protocol>
	len = strlen(aSrc) + 1 + 1 + 1 + 1 + 1;
	assert( len < TOTAL_MAX_ADDRESS_LEN );
	snprintf( finalSrc, TOTAL_MAX_ADDRESS_LEN, "%s:%d.%d", aSrc, aSrcPort, aProtocol );

	// Formulate a complete dest string <ip-address> + ':' + <port> + '.' + <protocol>
	len = strlen(aDst) + 1 + 1 + 1 + 1 + 1;
	assert( len < TOTAL_MAX_ADDRESS_LEN );
	snprintf( finalDst, TOTAL_MAX_ADDRESS_LEN, "%s:%d.%d", aDst, aDstPort, aProtocol );

	// done
	return ERR_NONE;
}










