/******************************************************************************
  @file    sms_devicepart.c

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
#define SMS_SIGNAL


/*=============================================================================

                           INCLUDE FILES

==============================================================================*/
#include "define.h"


/*=============================================================================

			MAIN FUNCTION IMPLEMENTATION

 ******************************************************************************
 * CGI FUNCTION
 *  sms_devicepart.cgi
 * ATCTIONS
 *  1,read comm infor data from js and set to globa strcut
 *  2,read sms devicepart infor from js
 *  3,handle sms devicepart infor, method shoud be thinked ???
 *  4,read corresponding html file due to different language
 *    1,convert key to value in html file
 *    2,printf new dynamic string which is gained at step4.1 to boa server 
 ******************************************************************************
==============================================================================*/
int main()
{
	//char StringFromJava[REQ_RSP_STRING_LEN];
	//char TempTotalAll[4];
	char *req_method;
	char StringFromWeb[50];

	//char Tempvalue[6]="";
	char TempAddr[13];
	//char TempTime[20];
	char TempId[10];
	char SendString[30];
	char Result[3];
	int i;
	int j;
	int TotalAll;
	int Total;
	extern char wifi_pro_from_java_string[1024];
	extern char TempBody[1024];
	extern char TempTime[20];

	read_comm_infor_from_js();

/*=============================================================================*/

	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"The goto req is:");

    req_method = getenv("REQUEST_METHOD");
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"The goto req is2:");

	i = get_cgi_data(stdin,req_method,StringFromWeb);
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"The StringFromWeb is:");
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,StringFromWeb);
    strcpy(SendString,"Request|GetOneSIMSms|");
    if (i)
    {
    	if(get_index_str_from_web(StringFromWeb,"smsSignal=",TempId))
	    {
		    strcat(SendString,TempId);
		    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,SendString);

	    }
	    else{
	    	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"SendString1");

	    	 debug_message_printf("Can't find Password");

	    }
    }else{
    	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"SendString2");

    	    debug_message_printf("Can't find Password");

    }


	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,SendString);

    //strcat("Request|GetSmsContent|1",TempPage);
	send_cmd_to_js(SendString,wifi_pro_from_java_string);
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,wifi_pro_from_java_string);

    get_index_str_from_js(wifi_pro_from_java_string,4,TempAddr);
     for (j = 0; j < strlen(TempAddr); j++)
	{
		SmsSignal[0].value[j]=TempAddr[j];
	}
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"SmsSignal[i].addr.value");
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,SmsSignal[0].value);
	SmsSignal[0].value[j]='\0';

        get_index_str_from_js(wifi_pro_from_java_string,5,TempBody);
	 for (j = 0; j < strlen(TempBody); j++)
	{
		//SmsSignal[1].value[j]=TempBody[j];
	}
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"SmsSignal[i].TempBody.TempBodyvalue");
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,TempBody);
	//SmsSignal[1].value[j]='\0';

        get_index_str_from_js(wifi_pro_from_java_string,6,TempTime);
        xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"TempTime");
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,TempTime);
	 for (j = 0; j < strlen(TempTime); j++)
	{
		SmsSignal[2].value[j]=TempTime[j];
	}
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"SmsSignal[i].time.value");
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,SmsSignal[2].value);
	SmsSignal[2].value[j]='\0';
xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,SmsSignal[2].value);
	//xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,TempTotal);

    get_index_str_from_js(wifi_pro_from_java_string,1,Result);


/*==============================================================================*/
	
	if(!strncmp("English",CommonParaInfor[5].value,strlen("English")))
	{
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"this will goto html file");

		read_html_file_into_cgi("sms_signal_eng.html");
	}else{

		read_html_file_into_cgi("sms_signal.html");
	}
return 0;
}
