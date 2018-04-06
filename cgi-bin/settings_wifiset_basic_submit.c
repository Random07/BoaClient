/******************************************************************************
  @file    login.c

  DESCRIPTION
-------------------------------------------------------------------------------
  Copyright (c) StephenSoftware, Inc.
  All Rights Reserved.
  Confidential and Proprietary - StephenSoftware, Inc.
-------------------------------------------------------------------------------

******************************************************************************/



/*=============================================================================

                           INCLUDE FILES

==============================================================================*/
#include "define.h"
#include <string.h>
/*============================================================

			MAIN FUNCTION IMPLEMENTATION

 ******************************************************************************
 * CGI FUNCTION
 *  login.cgi
 * ATCTIONS
 *  1,read data from boa server which is submitted from web page by user
 *  2,resolve Username and Password and Language para
 *  3,get corresponding data from js
 *  4,compare Username and Password to check correct or not
 *  5,set language
 *  6,goto differenct page
 ******************************************************************************
==============================================================================*/
int main()
{
	char *req_method;
	char StringFromWeb[REQ_RSP_STRING_LEN];
	char StringFromJava[REQ_RSP_STRING_LEN];
	char SSID[20];
	char BCSSID[3];
	char SECURITY[20];
	char Password[30];
	char MaxConnection[3];
	char Sendstring[50];
	char Result[10];

	req_method = getenv("REQUEST_METHOD");
	get_cgi_data(stdin,req_method,StringFromWeb);
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"The StringFromWeb is:");
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,StringFromWeb);

	strcpy(Sendstring,"Request|WIFISetting|");
	if(!get_index_str_from_web(StringFromWeb,"SSID=",SSID))
	{
		debug_message_printf("Can't find SSID");
		return 0;
	}
	else{
		strcat(Sendstring,SSID);
		strcat(Sendstring,"|");

	}
	if(!get_index_str_from_web(StringFromWeb,"BCSSID=",BCSSID))
	{
		debug_message_printf("Can't find BCSSID");
		return 0;
	}
	else{
		strcat(Sendstring,BCSSID);
		strcat(Sendstring,"|");
	}
	if(!get_index_str_from_web(StringFromWeb,"SECURITY=",SECURITY))
	{
		debug_message_printf("Can't find SECURITY");
		return 0;
	}else{
		strcat(Sendstring,SECURITY);
		strcat(Sendstring,"|");
	}
	if(!get_index_str_from_web(StringFromWeb,"Password=",Password))
	{
		debug_message_printf("Can't find Password");
		return 0;
	}else{
		strcat(Sendstring,Password);
		strcat(Sendstring,"|");
	}
	if(!get_index_str_from_web(StringFromWeb,"MaxConnection=",MaxConnection))
	{
		debug_message_printf("Can't find MaxConnection");
		return 0;
	}else{
		strcat(Sendstring,MaxConnection);
		//strcat(Sendstring,"|");
	}


	send_cmd_to_js(Sendstring,StringFromJava);
	//char StringFromJavatest[]="1|DataLimit|";
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"The StringFromJava is:");
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,StringFromJava);
    get_index_str_from_js(StringFromJava,1,Result);


    if (!strcmp(Result,"1"))
    {
    	web_header();
		puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/settings_wifiset_basic.cgi\">");
		we_btail();
    }
		
	
	return 0;
}