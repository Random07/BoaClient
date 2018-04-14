/******************************************************************************
  @file    settings_netset_dailup.c

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
#define SETTINGS_NETSET_DAILUP


/*=============================================================================

                           INCLUDE FILES

==============================================================================*/
#include "define.h"


/*=============================================================================

			MAIN FUNCTION IMPLEMENTATION

 ******************************************************************************
 * CGI FUNCTION
 *  settings_netset_dailup.cgi
 * ATCTIONS
 *  1,read comm infor data from js and set to globa strcut
 *  2,read wan mode infor from js
 *  3,handle wan mode infor, method shoud be thinked ???
 *  4,read corresponding html file due to different language
 *    1,convert key to value in html file
 *    2,printf new dynamic string which is gained at step4.1 to boa server 
 ******************************************************************************
==============================================================================*/
int main()
{
	char StringFromJava[REQ_RSP_STRING_LEN];
	int i;
    time_out();
	read_comm_infor_from_js();

/*=============================================================================
		please implement
==============================================================================*/
	
	if(!strncmp("English",CommonParaInfor[5].value,strlen("English")))
	{
		read_html_file_into_cgi("settings_netset_dailup_eng.html");
	}else{

		read_html_file_into_cgi("settings_netset_dailup.html");
	}
return 0;
}
