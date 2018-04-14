/******************************************************************************
  @file    settings_netset_apn.c

  DESCRIPTION
-------------------------------------------------------------------------------
  Copyright (c) StephenSoftware, Inc.
  All Rights Reserved.
  Confidential and Proprietary - StephenSoftware, Inc.
-------------------------------------------------------------------------------

******************************************************************************/

/*===========================================================================

				MACRO DEFINE

===========================================================================*/
#define SETTINGS_NETSET_APN


/*=============================================================================

                           INCLUDE FILES

==============================================================================*/
#include "define.h"


/*=============================================================================

			MAIN FUNCTION IMPLEMENTATION

 ******************************************************************************
 * CGI FUNCTION
 *  settings_netset_apn.cgi
 * ATCTIONS
 *  1,read comm infor data from js and set to globa strcut
 *  2,read apn infor from js
 *  3,handle apn infor, method shoud be thinked ???
 *  4,read corresponding html file due to different language
 *    1,convert key to value in html file
 *    2,printf new dynamic string which is gained at step4.1 to boa server 
 ******************************************************************************
==============================================================================*/
int main()
{
	char StringFromJava[REQ_RSP_STRING_LEN];
	//char StringFromJavatest[150];
	char TempTotalApn[2];
	char TempApnName[10];
	char TempApn[10];
	char TempMcc[5];
	char TempMnc[5];
	char TempAuth[10];
	char TempUsername[10];
	char TempPassword[10];
	int TotalApn;
	int i;
	int j;
    time_out();
	read_comm_infor_from_js();

/*=============================================================================*/

/*==============================================================================*/
	
	if(!strncmp("English",CommonParaInfor[5].value,strlen("English")))
	{
		read_html_file_into_cgi("settings_netset_apn_new_eng.html");
	}else{

		read_html_file_into_cgi("settings_netset_apn_new.html");
	}
return 0;
}
