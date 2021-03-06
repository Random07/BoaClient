/******************************************************************************
  @file    settings_deviceset_account.c

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
#define SETTINGS_DEVICESET_ACCOUNT


/*=============================================================================

                           INCLUDE FILES

==============================================================================*/
#include "define.h"


/*=============================================================================

			MAIN FUNCTION IMPLEMENTATION

 ******************************************************************************
 * CGI FUNCTION
 *  settings_deviceset_account.cgi
 * ATCTIONS
 *  1,read comm infor data from js and set to globa strcut
 *  2,read wifi wps infor from js
 *  3,handle wifi wps infor, method shoud be thinked ???
 *  4,read corresponding html file due to different language
 *    1,convert key to value in html file
 *    2,printf new dynamic string which is gained at step4.1 to boa server 
 ******************************************************************************
==============================================================================*/
int main()
{
	char StringFromJava[REQ_RSP_STRING_LEN];
	int i;
	extern char wifi_pro_password[50];
	extern char wifi_pro_username[50];
    time_out();

	read_comm_infor_from_js();

/*=============================================================================*/


send_cmd_to_js("Request|Login",StringFromJava);
get_index_str_from_js(StringFromJava,3,wifi_pro_username);
wifi_pro_username[strlen(wifi_pro_username)] = '\0';

/*==============================================================================*/
	
	if(!strncmp("English",CommonParaInfor[5].value,strlen("English")))
	{
		read_html_file_into_cgi("settings_deviceset_account_eng.html");
	}else{

		read_html_file_into_cgi("settings_deviceset_account.html");
	}
return 0;
}
