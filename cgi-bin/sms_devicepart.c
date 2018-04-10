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
#define SMS_DEVICEPART


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
	char TempSmsTotalAll[4];
	char TempTotal[2];
	//char Tempvalue[6]="";
	char TempId[10];
	char TempAddr[20];
	char TempBody[1024];
	char TempTime[20];
	char TempFlag[2];
	int i;
	int j;
	int TotalAll;
	int Total;
	extern char wifi_pro_from_java_string[1024];

	read_comm_infor_from_js();

/*=============================================================================*/
    //send_cmd_to_js("Request|GetSmsContent|1",StringFromJava);
    //Result|GetSmsContent|totalall|total this page|id|addr|body|time|flag

 /*for (i = 0; i < 10; i++)
{printf("this will goto read html file6:%d\n",strlen(Tempvalue));
	for (j = 0; j < strlen(Tempvalue); i++)
	{printf("this will goto read html file7\n");
		SmsInfoList[i].totalall.value[j]=Tempvalue[j];
	}
	SmsInfoList[i].totalall.value[j]='\0';
		for (j = 0; j < strlen(Tempvalue); i++)
	{printf("this will goto read html 8\n");
		SmsInfoList[i].id.value[j]=Tempvalue[j];
	}
	SmsInfoList[i].id.value[j]='\0';
		for (j = 0; j < strlen(Tempvalue); i++)
	{printf("this will goto read html 9\n");
		SmsInfoList[i].addr.value[j]=Tempvalue[j];
	}
	SmsInfoList[i].addr.value[j]='\0';
		for (j = 0; j < strlen(Tempvalue); i++)
	{printf("this will goto read html 10\n");
		SmsInfoList[i].body.value[j]=Tempvalue[j];
	}
	SmsInfoList[i].body.value[j]='\0';
		for (j = 0; j < strlen(Tempvalue); i++)
	{printf("this will goto read html 11\n");
		SmsInfoList[i].time.value[j]=Tempvalue[j];
	}
	SmsInfoList[i].time.value[j]='\0';
		for (j = 0; j < strlen(Tempvalue); i++)
	{printf("this will goto read html 12\n");
		SmsInfoList[i].flag.value[j]=Tempvalue[j];
	}
	SmsInfoList[i].flag.value[j]='\0';
	printf("this will goto read html file5\n");

}*/
	send_cmd_to_js("Request|GetSmsContent|1",wifi_pro_from_java_string);
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,wifi_pro_from_java_string);

//xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"this is in the sms_devicepart");
//wifi_pro_index_from_java_test="1|GetSmsContent|22|2|1111|99999|kjkjfejkfekfjekfjefkejkfjekfjkejfkejfke|1991-03-03|1|222|343|fef|890|0";
    get_index_str_from_js(wifi_pro_from_java_string,4,TempTotal);
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,TempSmsTotalAll);
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,TempTotal);
    //TotalAll =(int)(TempTotalAll[0]-'0');
    Total =(int)(TempTotal[0]-'0');
    //TotalAll=ceil((TotalAll*1.0)/10);
for (i = 0; i < Total; i++)
{
	get_index_str_from_js(wifi_pro_from_java_string,(5+i*5),TempId);
		for (j = 0; j < strlen(TempId); j++)
	{
		SmsInfoList[i].id.value[j]=TempId[j];
	}
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"SmsInfoList[i].id.value");
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,SmsInfoList[i].id.value);
	SmsInfoList[i].id.value[j]='\0';

		get_index_str_from_js(wifi_pro_from_java_string,(6+i*5),TempAddr);
		for (j = 0; j < strlen(TempAddr); j++)
	{

		SmsInfoList[i].addr.value[j]=TempAddr[j];
	}
	SmsInfoList[i].addr.value[j]='\0';

		get_index_str_from_js(wifi_pro_from_java_string,(7+i*5),TempBody);
		for (j = 0; j < strlen(TempBody); j++)
	{

		SmsInfoList[i].body.value[j]=TempBody[j];
	}
	SmsInfoList[i].body.value[j]='\0';
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"SmsInfoList[i].body.value");
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,SmsInfoList[i].body.value);
			get_index_str_from_js(wifi_pro_from_java_string,(8+i*5),TempTime);
		for (j = 0; j < strlen(TempTime); j++)
	{

		SmsInfoList[i].time.value[j]=TempTime[j];
	}
	SmsInfoList[i].time.value[j]='\0';
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"SmsInfoList[i].time.value");
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,SmsInfoList[i].time.value);
			get_index_str_from_js(wifi_pro_from_java_string,(9+i*5),TempFlag);
		for (j = 0; j < strlen(TempFlag); j++)
	{
		SmsInfoList[i].flag.value[j]=TempFlag[j];
	}
	SmsInfoList[i].flag.value[j]='\0';
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"SmsInfoList[i].flag.valuee");
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,SmsInfoList[i].flag.value);

}
    get_index_str_from_js(wifi_pro_from_java_string,3,TempSmsTotalAll);
strcpy(SmsInfoList[0].totalall.value,TempSmsTotalAll);
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"SmsInfoList[0].totalall.value");
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,SmsInfoList[0].totalall.value);

/*==============================================================================*/
	
	if(!strncmp("English",CommonParaInfor[5].value,strlen("English")))
	{
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"this will goto html file");

		read_html_file_into_cgi("sms_devicepart_eng.html");
	}else{

		read_html_file_into_cgi("sms_devicepart.html");
	}
return 0;
}
