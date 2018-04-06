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
    char *req_method;
    char StringFromWeb[REQ_RSP_STRING_LEN];
    char StringFromJava[REQ_RSP_STRING_LEN];
    char TempReceiver[12];
    char TempContent[200];
    char SendString[30];
    char SetResult[2];
    int i = 0;
    int j = 0;

read_comm_infor_from_js();

/*==============================================================================*/
	
    if(!strncmp("English",CommonParaInfor[5].value,strlen("English")))
    {//printf("this will goto read html file\n");
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"this will goto html file");

        read_html_file_into_cgi("sms_devicepart_send_eng.html");
    }else{

        read_html_file_into_cgi("sms_devicepart.html");
    }
return 0;
}
