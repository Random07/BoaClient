/******************************************************************************
  @file    settings_deviceset_reboot_submit.c

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
#define SETTINGS_DEVICESET_REBOOT


/*=============================================================================

                           INCLUDE FILES

==============================================================================*/
#include "define.h"


/*=============================================================================

			MAIN FUNCTION IMPLEMENTATION

 ******************************************************************************
 * CGI FUNCTION
 *  settings_deviceset_reboot.cgi
 * ATCTIONS
 *  1,read comm infor data from js and set to globa strcut
 *  2,read corresponding html file due to different language
 *    1,convert key to value in html file
 *    2,printf new dynamic string which is gained at step2.1 to boa server 
 ******************************************************************************
==============================================================================*/
int main()
{
	char *req_method;
	char StringFromJava[REQ_RSP_STRING_LEN];
	char Sendstring[20];
	char Result[2];

	int i;

	read_comm_infor_from_js();
    	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"SendString2");

/*=============================================================================*/
	wifi_pro_alert_info="Add APN fail,please retry!";
        read_html_file_into_cgi("alert.html");
web_header();
		puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/settings_deviceset_reboot.cgi\">");
		we_btail();
    	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"SendString3");

strcpy(Sendstring,"Request|ReBoot");
send_cmd_to_js(Sendstring,StringFromJava);

//char Sendstring[]="1|ReBoot|";
//get_index_str_from_js(StringFromJava,1,Result);

/*==============================================================================*/
    	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"SendString4");

	wifi_pro_alert_info="Add APN fail,please retry!";
        read_html_file_into_cgi("alert.html");
	web_header();
		puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/settings_deviceset_reboot.cgi\">");
		we_btail();

return 0;
}
