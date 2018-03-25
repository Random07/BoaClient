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

	req_method = getenv("REQUEST_METHOD");
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,req_method);
	get_cgi_data(stdin,req_method,StringFromWeb);

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

//	send_cmd_to_js("Request|Login",StringFromJava);
	char StringFromJavatest[]="Confirm|Login|Admin|123456";

	get_index_str_from_js(StringFromJavatest,3,NameInDevice);
	get_index_str_from_js(StringFromJavatest,4,PassInDevice);

//	Debug_Triple_Var_Message(%s,StringFromJava,%d,strlen(StringFromJava),%d,strlen(PassInDevice));	

	if(!strncmp("Login",Language,strlen("Login")))
	{
//		send_cmd_to_js("Request|Setlanguage|English",StringFromJava);
	}else{
	
//		send_cmd_to_js("Request|Setlanguage|Chines",StringFromJava);
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
