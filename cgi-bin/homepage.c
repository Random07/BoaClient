/******************************************************************************
  @file    homepage.c

  DESCRIPTION
-------------------------------------------------------------------------------
  Copyright (c) StephenSoftware, Inc.
  All Rights Reserved.
  Confidential and Proprietary - StephenSoftware, Inc.
-------------------------------------------------------------------------------

******************************************************************************/

/*===========================================================================

				MACRO DEFINE

=============================================================================*/
#define HOME_PAGE


/*=============================================================================

                           INCLUDE FILES

==============================================================================*/
#include "define.h"


/*=============================================================================

			MAIN FUNCTION IMPLEMENTATION

 ******************************************************************************
 * CGI FUNCTION
 *  homepage.cgi
 * ATCTIONS
 *  1,read comm infor data from js and set to globa strcut
 *  2,initialize globa strcut ConnCustInfor value to "&nbsp;"
 *  3,read connect_customer infor data from js and set to globa strcut
 *  4,read homepage.html or homepage_eng.html due to different language
 *    1,convert key to value in homepage.html or homepage_eng.html file
 *    2,printf new dynamic string which is gained at step4.1 to boa server 
 ******************************************************************************
==============================================================================*/
int main()
{
	//char StringFromJava[REQ_RSP_STRING_LEN];
	int i;
	int j;
	char tempvalue[]="&nbsp;";
	char temptotalnum[2];
	int totalnum;
	char tempindex[2];
	char tempDeviceName[64];
	char tempMAC[64];
	char tempIP[64];

	extern char wifi_pro_from_java_string[1024];
    time_out();

	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"this will goto read_comm_infor_from_js1");

	read_comm_infor_from_js();
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"this will goto read_comm_infor_from_js");


	for(i=0;i<10;i++)
	{
		for(j=0;j<strlen(tempvalue);j++)
		{
			ConnCustInfor[i].index.value[j]=tempvalue[j];
		}
		ConnCustInfor[i].index.value[j]='\0';

		for(j=0;j<strlen(tempvalue);j++)
		{
			ConnCustInfor[i].DeviceName.value[j]=tempvalue[j];
		}
		ConnCustInfor[i].DeviceName.value[j]='\0';

		for(j=0;j<strlen(tempvalue);j++)
		{
			ConnCustInfor[i].MAC.value[j]=tempvalue[j];
		}
		ConnCustInfor[i].MAC.value[j]='\0';

		for(j=0;j<strlen(tempvalue);j++)
		{
			ConnCustInfor[i].IP.value[j]=tempvalue[j];
		}
		ConnCustInfor[i].IP.value[j]='\0';
	}

	send_cmd_to_js("Request|Connect_Customer",wifi_pro_from_java_string);
	//wifi_pro_from_java_string=StringFromJava;
//	char StringFromJavatest[]="1|Connect_Customer|2|Devicename|mac|ip|Devicename|mac|ip";
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"Have use the extern wifi_pro_from_java_string is:");
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,wifi_pro_from_java_string);
    
	get_index_str_from_js_new(wifi_pro_from_java_string,3,temptotalnum);
	    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,temptotalnum);

	//get_index_str_from_js(wifi_pro_from_java_string,3,temptotalnum);
	totalnum =(int)(temptotalnum[0]-'0');

	for(i=0;i<totalnum;i++)
	{	
		//get_index_str_from_js(StringFromJava,(5+i*4),tempindex);
		sprintf(tempindex,"%d",i+1);
		//tempindex[0]=i+1;
		/*get_index_str_from_js(StringFromJava,(4+i*3),tempDeviceName);
		get_index_str_from_js(StringFromJava,(5+i*3),tempMAC);
		get_index_str_from_js(StringFromJava,(6+i*3),tempIP);*/
		xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,wifi_pro_from_java_string);

        xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,tempindex);

		for(j=0;j<strlen(tempindex);j++)
		{
			ConnCustInfor[i].index.value[j]= tempindex[j];
		}
		ConnCustInfor[i].index.value[j]='\0';
		xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,ConnCustInfor[i].index.value);

        get_index_str_from_js_new(wifi_pro_from_java_string,(6+i*3),tempDeviceName);
		xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,wifi_pro_from_java_string);
		for(j=0;j<strlen(tempDeviceName);j++)
		{
			ConnCustInfor[i].DeviceName.value[j]= tempDeviceName[j];
		}
		ConnCustInfor[i].DeviceName.value[j]='\0';

        get_index_str_from_js_new(wifi_pro_from_java_string,(5+i*3),tempMAC);
		xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,wifi_pro_from_java_string);
		for(j=0;j<strlen(tempMAC);j++)
		{
			ConnCustInfor[i].MAC.value[j]= tempMAC[j];
		}
		ConnCustInfor[i].MAC.value[j]='\0';

		get_index_str_from_js_new(wifi_pro_from_java_string,(4+i*3),tempIP);
		for(j=0;j<strlen(tempIP);j++)
		{
			ConnCustInfor[i].IP.value[j]= tempIP[j];
		}
		ConnCustInfor[i].IP.value[j]='\0';
	}
	
	if(!strncmp("English",CommonParaInfor[5].value,strlen("English")))
	{
		xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"this will goto homepage_eng");

		read_html_file_into_cgi("homepage_eng.html");
	}else{
		xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"this will goto homepage.html");

		read_html_file_into_cgi("homepage.html");
	}
return 0;
}
