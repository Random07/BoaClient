/******************************************************************************
  @file    settings_wifiset_basic.c

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
#define SETTINGS_WIFISET_BASIC


/*=============================================================================

                           INCLUDE FILES

==============================================================================*/
#include "define.h"


/*=============================================================================

			MAIN FUNCTION IMPLEMENTATION

 ******************************************************************************
 * CGI FUNCTION
 *  settings_wifiset_basic.cgi
 * ATCTIONS
 *  1,read comm infor data from js and set to globa strcut
 *  2,read wifi ap infor from js
 *  3,handle wifi ap infor, method shoud be thinked ???
 *  4,read corresponding html file due to different language
 *    1,convert key to value in html file
 *    2,printf new dynamic string which is gained at step4.1 to boa server 
 ******************************************************************************
==============================================================================*/
int main()
{
	//char StringFromJava[REQ_RSP_STRING_LEN];
	char TempSSID[20];
	char TempSSIDShow1[7];
	char TempSSIDShow2[7];
	char TempSSIDSecurity[20];
	char TempPassword[20];
	char TempSSIDConnNum[3];
	int i;
    int j;
    extern char wifi_pro_from_java_string[1024];
    time_out();

    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"This will goto read comminfo:");
	read_comm_infor_from_js();

/*=============================================================================*/
	send_cmd_to_js("Request|WIFIShow",wifi_pro_from_java_string);
    //char StringFromJavatest[]="1|WIFIShow|fdsfdfd|false|0|21212|5";
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"The wifi_pro_from_java_string is:");
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,wifi_pro_from_java_string);


    get_index_str_from_js(wifi_pro_from_java_string,4,TempSSIDShow1);
    if (!strncmp(TempSSIDShow1,"true",strlen("true")))
    {
    	strcpy(TempSSIDShow1,"checked");
    	strcpy(TempSSIDShow2,"");
    }
    else{
    	strcpy(TempSSIDShow2,"checked");
    	strcpy(TempSSIDShow1,"");
    }

    get_index_str_from_js(wifi_pro_from_java_string,3,TempSSID);
    for (j = 0; j < strlen(TempSSID); j++)
    {
    	Settings_SSID[0].value[j]=TempSSID[j];
    }
    Settings_SSID[0].value[j]='\0';

    for (j = 0; j < strlen(TempSSIDShow1); j++)
    {

    	Settings_SSID[1].value[j]=TempSSIDShow1[j];
    }
    Settings_SSID[1].value[j]='\0';

    for (j = 0; j < strlen(TempSSIDShow2); j++)
    {
    	Settings_SSID[2].value[j]=TempSSIDShow2[j];
    }
    Settings_SSID[2].value[j]='\0';

    get_index_str_from_js(wifi_pro_from_java_string,5,TempSSIDSecurity);
    for (j = 0; j < strlen(TempSSIDSecurity); j++)
    {
    	Settings_SSID[3].value[j]=TempSSIDSecurity[j];
    }
    Settings_SSID[3].value[j]='\0';

    get_index_str_from_js(wifi_pro_from_java_string,6,TempPassword);
    for (j = 0; j < strlen(TempPassword); j++)
    {
    	Settings_SSID[4].value[j]=TempPassword[j];
    }
    Settings_SSID[4].value[j]='\0';

    get_index_str_from_js(wifi_pro_from_java_string,7,TempSSIDConnNum);
    for (j = 0; j < strlen(TempSSIDConnNum); j++)
    {
        Settings_SSID[5].value[j]=TempSSIDConnNum[j];
    }
    Settings_SSID[5].value[j]='\0';

    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"Follow will read html");

/*==============================================================================*/
	
	if(!strncmp("English",CommonParaInfor[5].value,strlen("English")))
	{
		read_html_file_into_cgi("settings_wifiset_basic_eng.html");
	}else{

		read_html_file_into_cgi("settings_wifiset_basic.html");
	}
return 0;
}
