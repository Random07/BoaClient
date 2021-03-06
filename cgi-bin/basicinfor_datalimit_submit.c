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
#define BASICINFOR_DATALIMIT

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
	//char StringFromJava[REQ_RSP_STRING_LEN];
	char DataLimit[10];
	char Sendstring[50];
	char Result[10];
	extern char wifi_pro_from_java_string[1024];


	req_method = getenv("REQUEST_METHOD");
	get_cgi_data(stdin,req_method,StringFromWeb);
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"The StringFromWeb is:");
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,StringFromWeb);

	if(!get_index_str_from_web(StringFromWeb,"DataLimit=",DataLimit))
	{
		debug_message_printf("Can't find DataLimit");
		return 0;
	}

	sprintf(DataLimit,"%d",atoi(DataLimit)*1000000);
    strcpy(Sendstring,"Request|DataLimit|");
	strcat(Sendstring,DataLimit);
	send_cmd_to_js(Sendstring,wifi_pro_from_java_string);
	
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"The StringFromJava is:");
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,wifi_pro_from_java_string);

	//char StringFromJavatest[]="1|DataLimit|";
    get_index_str_from_js(wifi_pro_from_java_string,1,Result);


    if (!strcmp(Result,"1"))
    {
    	web_header();
		puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/basicinfor_datalimit.cgi\">");
		we_btail();
    }
    else{
    	wifi_pro_alert_info="Set fail,please retry!";
    	read_html_file_into_cgi("alert.html");
    	web_header();
		puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/basicinfor_datalimit.cgi\">");
		we_btail();
    }
		
	
	return 0;
    
}

