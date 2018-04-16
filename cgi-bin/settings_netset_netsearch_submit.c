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
    char TempNetworkSearchMode[3];
    char SendString[30];
    char SetResult[2];
    int i = 0;
    int j = 0;
    int templen=0;



    req_method = getenv("REQUEST_METHOD");   
    get_cgi_data(stdin,req_method,StringFromWeb);
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"The StringFromWeb is:");
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,StringFromWeb);

    if(!get_index_str_from_web(StringFromWeb,"NetSearchMode=",TempNetworkSearchMode))
    {
        debug_message_printf("Can't find TempNetworkSearchMode");
        return 0;
    }
    strcpy(SendString,"Request|SetNetworkType|");
    strcpy(SendString,TempNetworkSearchMode);

    send_cmd_to_js(SendString,StringFromJava);
    //char StringFromJavatest[]="1|ApnAdd";
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"The StringFromJava is:");
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,StringFromJava);


    get_index_str_from_js(StringFromJava,1,SetResult);
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"the SendString is ");
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,SendString);

/*==============================================================================*/
	
    if(!strcmp("1",SetResult))
    {   
        web_header();
        puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/settings_netset_netsearch.cgi\">");
        we_btail();
    }else{
        web_header();
        puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/settings_netset_netsearch.cgi\">");
        we_btail();
    }
return 0;
}
