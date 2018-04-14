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
#include <time.h>


/*=============================================================================

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
	char NameFromWeb[50];
	char PassFromWeb[50];
	char NameInDevice[50];
	char PassInDevice[50];
	char Language[50];
	int i = 0;
	int j = 0;
	int templen=0;
    

    time_out();
	/*-----------------------------------------------------------------*/

	req_method = getenv("REQUEST_METHOD");
	get_cgi_data(stdin,req_method,StringFromWeb);
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"The StringFromWeb is:");
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,StringFromWeb);

	if(!get_index_str_from_web(StringFromWeb,"Username=",NameFromWeb))
	{
		debug_message_printf("Can't find Username");
		return 0;
	}
	if(!get_index_str_from_web(StringFromWeb,"Password=",PassFromWeb))
	{
		debug_message_printf("Can't find Username");
		return 0;
	}
	if(!get_index_str_from_web(StringFromWeb,"Submit=",Language))
	{
		debug_message_printf("Can't find Language");
		return 0;
	}

	send_cmd_to_js("Request|Login",StringFromJava);
//	char StringFromJavatest[]="Confirm|Login|Admin|123456";
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"The StringFromJava is:");
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,StringFromJava);
	get_index_str_from_js(StringFromJava,3,NameInDevice);
	get_index_str_from_js(StringFromJava,4,PassInDevice);
	//strcpy(wifi_pro_password,PassInDevice);
	//strcpy(wifi_pro_username,NameInDevice);
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"The setupin username and password:");
   // xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,wifi_pro_username);
   // xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,wifi_pro_password);


	if(!strncmp("Login",Language,strlen("Login")))
	{
		send_cmd_to_js("Request|SetLanguage|0",StringFromJava);
	}else{
	
		send_cmd_to_js("Request|SetLanguage|1",StringFromJava);
	}
	
	if(!strncmp(NameInDevice,NameFromWeb,strlen(NameInDevice)) && !strncmp(PassInDevice,PassFromWeb,strlen(PassInDevice)))
	{	
		web_header();
		puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/homepage.cgi\">");
		we_btail();
	}else{
		web_header();
		puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/loginerror.cgi\">");
		we_btail();
	}
	
	return 0;
}
