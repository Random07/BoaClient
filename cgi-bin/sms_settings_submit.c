/******************************************************************************
  @file    sms_settings.c

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
#define SMS_SMSSETTINGS


/*=============================================================================

                           INCLUDE FILES

==============================================================================*/
#include "define.h"


/*=============================================================================

			MAIN FUNCTION IMPLEMENTATION

 ******************************************************************************
 * CGI FUNCTION
 *  sms_settings.cgi
 * ATCTIONS
 *  1,read comm infor data from js and set to globa strcut
 *  2,read sms settings infor from js
 *  3,handle sms settings infor
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
	char TempSmsSettings_submit_Time[3];
	char TempSmsSettings_submit_CenterNume[15];
	char TempSmsSettinds_submit_Reporter[3];
  char SendString[30];
	int i;

	//read_comm_infor_from_js();

/*=============================================================================*/
	req_method = getenv("REQUEST_METHOD");
  get_cgi_data(stdin,req_method,StringFromWeb);
  xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"The StringFromWeb is:");
  xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,StringFromWeb);


  strcpy("Request|SetSmsSettings|")
  if(!get_index_str_from_web(StringFromWeb,"smssettingsoption=",TempSmsSettings_submit_Time))
  {
      debug_message_printf("Can't find TempSmsSettings_submit_Time");
      return 0;
  }else{
    strcat(SendString,TempSmsSettings_submit_Time);
    strcat(SendString,"|");
  }
  if(!get_index_str_from_web(StringFromWeb,"smssettingsoption=",TempSmsSettings_submit_CenterNume))
  {
      debug_message_printf("Can't find TempSmsSettings_submit_CenterNume");
      return 0;
  }else{
    strcat(SendString,TempSmsSettings_submit_CenterNume);
    strcat(SendString,"|");
  }
  if(!get_index_str_from_web(StringFromWeb,"smssettingsoption=",TempSmsSettinds_submit_Reporter))
  {
      debug_message_printf("Can't find TempSmsSettinds_submit_Reporter");
      return 0;
  }else{
    strcat(SendString,TempSmsSettinds_submit_Reporter);
    //strcat(SendString,TempSmsSettinds_submit_Reporter);
  }

  send_cmd_to_js(SendString,StringFromJava);
  xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"The StringFromJava is:");
  xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,StringFromJava);

/*==============================================================================*/
	
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
