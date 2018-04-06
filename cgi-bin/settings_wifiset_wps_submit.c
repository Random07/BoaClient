/******************************************************************************
  @file    settings_wifiset_wps.c

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
#define SETTINGS_WIFISET_WPS


/*=============================================================================

                           INCLUDE FILES

==============================================================================*/
#include "define.h"


/*=============================================================================

			MAIN FUNCTION IMPLEMENTATION

 ******************************************************************************
 * CGI FUNCTION
 *  settings_wifiset_wps.cgi
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
	char *req_method;
  char StringFromJava[REQ_RSP_STRING_LEN];
	char StringFromWeb[REQ_RSP_STRING_LEN];
	char TempWpsbutton[2];
	char TempTextPin[30];
	char SendString[50];
	char SetResult[3];
	int i;

/*=============================================================================*/
		 req_method = getenv("REQUEST_METHOD");
    get_cgi_data(stdin,req_method,StringFromWeb);
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"The StringFromWeb is:");
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,StringFromWeb);

     if(!get_index_str_from_web(StringFromWeb,"wpsbutton=",TempWpsbutton))
    {
        debug_message_printf("Can't find TempWpsbutton");
        return 0;
    }
      if(!get_index_str_from_web(StringFromWeb,"pintext=",TempTextPin))
    {
        debug_message_printf("Can't find TempWpsbutton");
        return 0;
    }

    strcpy(SendString,"Request|SetWPSConnectMode|");
    if (strcmp("1",TempWpsbutton))
    {
    	strcat(SendString,TempWpsbutton);
    	strcat(SendString,"|");
    	strcat(SendString,TempTextPin);
    }
    else{
    	strcat(SendString,TempWpsbutton);
    }
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"the SendString is ");
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,SendString);

    send_cmd_to_js(SendString,StringFromJava);
  //  char StringFromJavatest[]="1|SetWPSConnectMode";
    get_index_str_from_js(StringFromJava,1,SetResult);

/*==============================================================================*/
	
	   if(!strcmp("1",SetResult))
    {   
        web_header();
        puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/settings_wifiset_wps.cgi\">");
        we_btail();
    }else{
        web_header();
        puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/loginerror.cgi\">");
        we_btail();
    }
return 0;
}
