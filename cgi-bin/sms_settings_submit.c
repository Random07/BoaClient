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
  char StringFromWeb[512];
  //char StringFromJava[REQ_RSP_STRING_LEN];
	char TempSmsSettings_submit_Time[3];
	char TempSmsSettings_submit_CenterNume[25];
	char TempSmsSettinds_submit_Reporter[3];
  char SendString[30];
  char Result[2];
  char TempNum[25];
	int i;
  int j;
  extern char wifi_pro_from_java_string[1024];

	//read_comm_infor_from_js();

/*=============================================================================*/
	req_method = getenv("REQUEST_METHOD");
  get_cgi_data(stdin,req_method,StringFromWeb);
  xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"The StringFromWeb is:");
  xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,StringFromWeb);


  strcpy(SendString,"Request|SetSmsSettings|");
  if(!get_index_str_from_web(StringFromWeb,"smssettingsoption=",TempSmsSettings_submit_Time))
  {
      debug_message_printf("Can't find TempSmsSettings_submit_Time");
      return 0;
  }else{
      xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"The StringFromWeb is:");

    strcat(SendString,TempSmsSettings_submit_Time);
    strcat(SendString,"|");
  }
  if(!get_index_str_from_web(StringFromWeb,"SMSCenterNumber=",TempSmsSettings_submit_CenterNume))
  {
      debug_message_printf("Can't find TempSmsSettings_submit_CenterNume");
      return 0;
  }else{
      xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"The TempSmsSettings_submit_CenterNume is:");
            xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,TempSmsSettings_submit_CenterNume);
            xdebug_message_printf_int(__FILE__,__FUNCTION__,__LINE__,strlen(TempSmsSettings_submit_CenterNume));

    if (strlen(TempSmsSettings_submit_CenterNume) ==11)
    {
      strcpy(TempNum,"+86");
            xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,TempNum);

      strcat(TempNum,TempSmsSettings_submit_CenterNume);
      xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,TempNum);
      strcat(SendString,TempNum);
    strcat(SendString,"|");

    }else if (strlen(TempSmsSettings_submit_CenterNume) == 16)
    {
      for (i = 3 ,j=0; i < strlen(TempSmsSettings_submit_CenterNume); i++,j++)
      {

        TempNum[j]=TempSmsSettings_submit_CenterNume[i];


        /*if (TempSmsSettings_submit_CenterNume[i]='8' && TempSmsSettings_submit_CenterNume[i+1]='6')
        {
          TempNum[]
        }*/
      }
      TempNum[j]='\0';
      strcat(SendString,TempNum);
    strcat(SendString,"|");
    }
    else{
      strcat(SendString,TempSmsSettings_submit_CenterNume);
    strcat(SendString,"|");
    }

    
  }
  if(!get_index_str_from_web(StringFromWeb,"smssettingsoption=",TempSmsSettinds_submit_Reporter))
  {
      debug_message_printf("Can't find TempSmsSettinds_submit_Reporter");
      return 0;
  }else{
    strcat(SendString,"12");
    //strcat(SendString,TempSmsSettinds_submit_Reporter);
  }
   xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"The SendString is:");
  xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,SendString);
  //strcat(SendString,TempSmsSettings_submit_Time);
  xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"The SendString is:");
  xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,SendString);
  send_cmd_to_js(SendString,wifi_pro_from_java_string);
  xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"The StringFromJava is:");
  xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,wifi_pro_from_java_string);

get_index_str_from_js(wifi_pro_from_java_string,1,Result);
/*==============================================================================*/
	
    if (!strcmp(Result,"1"))
    {
      web_header();
    puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/sms_settings.cgi\">");
    we_btail();
    }
    else{
      wifi_pro_alert_info="Set fail,please retry!";
      read_html_file_into_cgi("alert.html");
      web_header();
    puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/sms_settings.cgi\">");
    we_btail();
    }
return 0;
}
