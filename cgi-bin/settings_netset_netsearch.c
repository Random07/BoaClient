/******************************************************************************
  @file    settings_netset_netsearch.c

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
#define SETTINGS_NETSET_NETSEARCH


/*=============================================================================

                           INCLUDE FILES

==============================================================================*/
#include "define.h"


/*=============================================================================

			MAIN FUNCTION IMPLEMENTATION

 ******************************************************************************
 * CGI FUNCTION
 *  settings_netset_netsearch.cgi
 * ATCTIONS
 *  1,read comm infor data from js and set to globa strcut
 *  2,read net search mode infor from js
 *  3,handle net search mode infor, method shoud be thinked ???
 *  4,read corresponding html file due to different language
 *    1,convert key to value in html file
 *    2,printf new dynamic string which is gained at step4.1 to boa server 
 ******************************************************************************
==============================================================================*/
int main()
{
	char StringFromJava[REQ_RSP_STRING_LEN];
	char TempNetworkType[3];
	char TempNetworkTypeShow[20];
	int i;
    time_out();

	read_comm_infor_from_js();

/*=============================================================================*/
	  send_cmd_to_js("Request|GetNetworkType",StringFromJava);
    //char StringFromJavatest[]="1|GetNetworkType|22";
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"The StringFromJava is:");
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,StringFromJava);

    get_index_str_from_js(StringFromJava,3,TempNetworkType);

    for (i = 0; i < strlen(TempNetworkType); i++)
    {
    	SetSearchMode[0].value[i]=TempNetworkType[i];
    }
    SetSearchMode[0].value[i]='\0';


/*==============================================================================*/
	
	if(!strncmp("English",CommonParaInfor[5].value,strlen("English")))
	{
		read_html_file_into_cgi("settings_netset_netsearch_eng.html");
	}else{

		read_html_file_into_cgi("settings_netset_netsearch.html");
	}
return 0;
}
