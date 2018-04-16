/******************************************************************************
  @file    languagechange.c

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
 *  basicconfig.cgi
 * ATCTIONS
 *  1,read data from boa server which is submitted from web page by user
 *  2,resolve Language para and Path para
 *  3,language change is from indext,read different html file
 *    1,convert key to value in loginerror.html or loginerror_eng.html, return
 *    2,printf new dynamic string which is gained at step3.1 to boa server, return
 *  4,set languange and waiting for result to goto step 5.
 *  5,refresh to different cgi due to Path para
 ******************************************************************************
==============================================================================*/
int main()
{
	char StringFromWeb[REQ_RSP_STRING_LEN];
	char Language[50];
	char Path[50];
	char *req_method;
	char SetResult[3];
	extern char wifi_pro_from_java_string[1024];


	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"this beforeget StringFromWeb");

	req_method = getenv("REQUEST_METHOD");
	get_cgi_data(stdin,req_method,StringFromWeb);

	if(!get_index_str_from_web(StringFromWeb,"LanguageSelect=",Language))
	{
		debug_message_printf("Can't find Language");
		return 0;
	}	
	if(!get_index_str_from_web(StringFromWeb,"Path=",Path))
	{
		debug_message_printf("Can't find Path");
		return 0;
	}

//	Debug_Signal_Var_Message(%s,Path);

	if(!strcmp("/",Path) || !strcmp("/index.html",Path) || !strcmp("/index_eng.html",Path))
	{
		if(!strncmp("English",Language,strlen("English")))
		{
			web_header();
			puts("<meta http-equiv=\"Refresh\" content=\"0;URL=../index_eng.html\">");
			we_btail();
			return 0;
		}else{
			web_header();
			puts("<meta http-equiv=\"Refresh\" content=\"0;URL=../index.html\">");
			we_btail();
			return 0;
		}
	}

	if(!strncmp("English",Language,strlen("English")))
	{
		xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"the user choose English");
		send_cmd_to_js("Request|SetLanguage|0",wifi_pro_from_java_string);
	}else{
		xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"the user choose Chinese");
	
		send_cmd_to_js("Request|SetLanguage|1",wifi_pro_from_java_string);
	}
    get_index_str_from_js(wifi_pro_from_java_string,1,SetResult);
	if(strcmp("1",SetResult)) return 0;
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"Setlanguage success");

	if(!strcmp("/cgi-bin/homepage.cgi",Path))
	{
		xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"this will goto homepage");

		web_header();
		puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/homepage.cgi\">");
		we_btail();
	}

	if(!strcmp("/cgi-bin/basicinfor_deviceinfor.cgi",Path))
	{
		web_header();
		puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/basicinfor_deviceinfor.cgi\">");
		we_btail();
	}

	if(!strcmp("/cgi-bin/basicinfor_datausage.cgi",Path))
	{
		web_header();
		puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/basicinfor_datausage.cgi\">");
		we_btail();
	}

	if(!strcmp("/cgi-bin/basicinfor_datalimit.cgi",Path))
	{
		web_header();
		puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/basicinfor_datalimit.cgi\">");
		we_btail();
	}

	if(!strcmp("/cgi-bin/sdcard_sdcard.cgi",Path))
	{
		web_header();
		puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/sdcard_sdcard.cgi\">");
		we_btail();
	}

	if(!strcmp("/cgi-bin/sdcard_httpshare.cgi",Path))
	{
		web_header();
		puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/sdcard_httpshare.cgi\">");
		we_btail();
	}

	if(!strcmp("/cgi-bin/driverdownload.cgi",Path))
	{
		web_header();
		puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/driverdownload.cgi\">");
		we_btail();
	}

	if(!strcmp("/cgi-bin/sms_devicepart.cgi",Path))
	{
		web_header();
		puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/sms_devicepart.cgi\">");
		we_btail();
	}

	if(!strcmp("/cgi-bin/sms_simpart.cgi",Path))
	{
		web_header();
		puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/sms_simpart.cgi\">");
		we_btail();
	}

	if(!strcmp("/cgi-bin/sms_settings.cgi",Path))
	{
		web_header();
		puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/sms_settings.cgi\">");
		we_btail();
	}

	if(!strcmp("/cgi-bin/settings_netset_dailup.cgi",Path))
	{
		web_header();
		puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/settings_netset_dailup.cgi\">");
		we_btail();
	}

	if(!strcmp("/cgi-bin/settings_netset_netsearch.cgi",Path))
	{
		web_header();
		puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/settings_netset_netsearch.cgi\">");
		we_btail();
	}

	if(!strcmp("/cgi-bin/settings_netset_apn.cgi",Path))
	{
		web_header();
		puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/settings_netset_apn.cgi\">");
		we_btail();
	}

	if(!strcmp("/cgi-bin/settings_wifiset_basic.cgi",Path))
	{
		web_header();
		puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/settings_wifiset_basic.cgi\">");
		we_btail();
	}

	if(!strcmp("/cgi-bin/settings_wifiset_wps.cgi",Path))
	{
		web_header();
		puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/settings_wifiset_wps.cgi\">");
		we_btail();
	}

	if(!strcmp("/cgi-bin/settings_deviceset_account.cgi",Path))
	{
		web_header();
		puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/settings_deviceset_account.cgi\">");
		we_btail();
	}

	if(!strcmp("/cgi-bin/settings_deviceset_restore.cgi",Path))
	{
		web_header();
		puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/settings_deviceset_restore.cgi\">");
		we_btail();
	}

	if(!strcmp("/cgi-bin/settings_deviceset_reboot.cgi",Path))
	{
		web_header();
		puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/settings_deviceset_reboot.cgi\">");
		we_btail();
	}

	if(!strcmp("/cgi-bin/settings_netset_apn_new.cgi",Path))
	{
		web_header();
		puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/settings_netset_apn_new.cgi\">");
		we_btail();
	}

	if(!strcmp("/cgi-bin/sms_signal.cgi",Path))
	{
		web_header();
		puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/sms_signal.cgi\">");
		we_btail();
	}

	return 0;
}
