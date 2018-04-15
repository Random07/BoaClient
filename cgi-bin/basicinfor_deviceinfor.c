/******************************************************************************
  @file    basicinfor_deviceinfor.c

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
#define BASICINFOR_DEVICEINFOR


/*=============================================================================

                           INCLUDE FILES

==============================================================================*/
#include "define.h"


/*=============================================================================

			MAIN FUNCTION IMPLEMENTATION

 ******************************************************************************
 * CGI FUNCTION
 *  basicinfor_deviceinfor.cgi
 * ATCTIONS
 *  1,read comm infor data from js and set to globa strcut
 *  2,initialize DeviceInfo strcut ConnCustInfor value to "&nbsp;"
 *  3,read DeviceInfo data from js and set to globa strcut
 *  4,read different html file due to different language
 *    1,convert key to value in html file
 *    2,printf new dynamic string which is gained at step4.1 to boa server 
 ******************************************************************************
==============================================================================*/
int main()
{
	//char StringFromJava[1024];
	char SimCard[30]={0};
	char IMEI[30]={0};
	char IMSI[30]={0};
	char SSID[30]={0};
	char ConCount[30]={0};
	char IP[30]={0};
	char Mac[30]={0};
	char Wan_Ip[30]={0};
	char SoftVersion[30]={0};
	char HardVersion[30]={0};
	char FirmWare[30]={0};
	int i;

	extern char wifi_pro_from_java_string[1024];

    time_out();
	read_comm_infor_from_js();


	send_cmd_to_js("Request|DeviceInfo",wifi_pro_from_java_string);
    //char StringFromJavatest[]="Confirm|DeviceInfo|3434|3341|1343|454|5|4343|98|424|8967|342|23432";
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"The StringFromJava is:");
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,wifi_pro_from_java_string);
   
	get_index_str_from_js(wifi_pro_from_java_string,(3),SimCard);
	get_index_str_from_js(wifi_pro_from_java_string,(4),IMEI);
	get_index_str_from_js(wifi_pro_from_java_string,(5),IMSI);
	get_index_str_from_js(wifi_pro_from_java_string,(6),SSID);
	get_index_str_from_js(wifi_pro_from_java_string,(7),ConCount);
	get_index_str_from_js(wifi_pro_from_java_string,(8),IP);
	get_index_str_from_js(wifi_pro_from_java_string,(9),Mac);
	//get_index_str_from_js(StringFromJavatest,(10),Wan_Ip);
	//get_index_str_from_js(StringFromJavatest,(11),SoftVersion);
	get_index_str_from_js(wifi_pro_from_java_string,(10),FirmWare);
	get_index_str_from_js(wifi_pro_from_java_string,(11),HardVersion);
	strcpy(Wan_Ip,"192.168.43.1");
	strcpy(SoftVersion,"web 1.1");
 
	for(i=0;i<strlen(SimCard);i++){
		DeviceInfo[0].value[i]=SimCard[i];

	}
	DeviceInfo[0].value[i]='\0';

	for(i=0;i<strlen(IMEI);i++){
		DeviceInfo[1].value[i]=IMEI[i];

	}
	DeviceInfo[1].value[i]='\0';

	for(i=0;i<strlen(IMSI);i++){
		DeviceInfo[2].value[i]=IMSI[i];

	}
	DeviceInfo[2].value[i]='\0';
	for(i=0;i<strlen(SSID);i++){
		DeviceInfo[3].value[i]=SSID[i];

	}
	DeviceInfo[3].value[i]='\0';

	for(i=0;i<strlen(ConCount);i++){
		DeviceInfo[4].value[i]=ConCount[i];

	}
	DeviceInfo[4].value[i]='\0';
	for(i=0;i<strlen(IP);i++){
		DeviceInfo[5].value[i]=IP[i];

	}
	DeviceInfo[5].value[i]='\0';

	for(i=0;i<strlen(Mac);i++){
		DeviceInfo[6].value[i]=Mac[i];

	}
	DeviceInfo[6].value[i]='\0';
	for(i=0;i<strlen(Wan_Ip);i++){
		DeviceInfo[7].value[i]=Wan_Ip[i];

	}
	DeviceInfo[7].value[i]='\0';

	for(i=0;i<strlen(SoftVersion);i++){
		DeviceInfo[8].value[i]=SoftVersion[i];

	}
	DeviceInfo[8].value[i]='\0';
	for(i=0;i<strlen(FirmWare);i++){
		DeviceInfo[9].value[i]=FirmWare[i];

	}
	DeviceInfo[9].value[i]='\0';

	for(i=0;i<strlen(HardVersion);i++){
		DeviceInfo[10].value[i]=HardVersion[i];

	}
	DeviceInfo[10].value[i]='\0';
	
	if(!strncmp("English",CommonParaInfor[5].value,strlen("English")))
	{
		read_html_file_into_cgi("basicinfor_deviceinfor_eng.html");
	}else{

		read_html_file_into_cgi("basicinfor_deviceinfor.html");
	}
return 0;
}
