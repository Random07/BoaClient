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
	char StringFromJava[REQ_RSP_STRING_LEN];
	char TempSmsSettings_Time[3];
	char TempSmsSettings_CenterNume[15];
	char TempSmsSettinds_Reporter[3];
	int i;

    time_out();	
  read_comm_infor_from_js();

/*=============================================================================*/
	send_cmd_to_js("Request|GetSmsSettings",StringFromJava);
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"The StringFromJava is:");
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,StringFromJava);

    get_index_str_from_js(StringFromJava,3,TempSmsSettings_Time);
    get_index_str_from_js(StringFromJava,4,TempSmsSettings_CenterNume);
    get_index_str_from_js(StringFromJava,5,TempSmsSettinds_Reporter);

    for (i = 0; i < strlen(TempSmsSettings_Time); i++)
    {
    	SmsSettings[0].value[i] = TempSmsSettings_Time[i];
    }
    SmsSettings[0].value[i]='\0';
    for (i = 0; i < strlen(TempSmsSettings_CenterNume); i++)
    {
    	SmsSettings[1].value[i] = TempSmsSettings_CenterNume[i];
    }
    SmsSettings[1].value[i]='\0';
    for (i = 0; i < strlen(TempSmsSettinds_Reporter); i++)
    {
    	SmsSettings[2].value[i] = TempSmsSettinds_Reporter[i];
    }
    SmsSettings[2].value[i]='\0';



/*==============================================================================*/
	
	if(!strncmp("English",CommonParaInfor[5].value,strlen("English")))
	{
		read_html_file_into_cgi("sms_settings_eng.html");
	}else{

		read_html_file_into_cgi("sms_settings.html");
	}
return 0;
}
