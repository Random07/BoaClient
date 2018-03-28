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
	char StringFromWeb[REQ_RSP_STRING_LEN];
    char StringFromJava[REQ_RSP_STRING_LEN];
    char ApnName[50];
    char Path[50];
    char *req_method;
    char Sendstring[50];
    char Result[2];
        //debug_message_printf("Can't find Language1");

    req_method = getenv("REQUEST_METHOD");
    get_cgi_data(stdin,req_method,StringFromWeb);
        //debug_message_printf("Can't find Language2");

    if(!get_index_str_from_web(StringFromWeb,"ConfigFileSelect=",ApnName))
    {
        debug_message_printf("Can't find Language");
        return 0;
    }

    strcpy(Sendstring,"Request|ApnChange|");
    strcat(Sendstring,ApnName);

    //  send_cmd_to_js(Sendstring,StringFromJava);
    char StringFromJavatest[]="1|ApnChange";
    get_index_str_from_js(StringFromJavatest,1,Result);

    if (!strcmp(Result,"1"))
    {
        web_header();
        puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/settings_netset_apn.cgi\">");
        we_btail();
    }
return 0;
}
