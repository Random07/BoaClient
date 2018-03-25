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
	char StringFromJava[REQ_RSP_STRING_LEN];
	int i;
	int j;
	char tempvalue[]="&nbsp;";
	char temptotalnum[2];
	int totalnum;
	char tempindex[2];
	char tempDeviceName[64];
	char tempMAC[64];
	char tempIP[64];

	read_comm_infor_from_js();

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

//	send_cmd_to_js("Request|Connect_Customer",StringFromJava);
	char StringFromJavatest[]="Confirm|Connect_Customer|TotalNum|3|1|DeviceNameA|MACA|IPA|2|DeviceNameB|MACB|IPB|3|DeviceNameC|MACC|IPC";
//	Debug_Single_Var_Message(%s,StringFromJava);

	get_index_str_from_js(StringFromJavatest,4,temptotalnum);
	totalnum =(int)(temptotalnum[0]-'0');

	for(i=0;i<totalnum;i++)
	{	
		get_index_str_from_js(StringFromJavatest,(5+i*4),tempindex);
		get_index_str_from_js(StringFromJavatest,(6+i*4),tempDeviceName);
		get_index_str_from_js(StringFromJavatest,(7+i*4),tempMAC);
		get_index_str_from_js(StringFromJavatest,(8+i*4),tempIP);

		for(j=0;j<strlen(tempindex);j++)
		{
			ConnCustInfor[i].index.value[j]= tempindex[j];
		}
		ConnCustInfor[i].index.value[j]='\0';

		for(j=0;j<strlen(tempDeviceName);j++)
		{
			ConnCustInfor[i].DeviceName.value[j]= tempDeviceName[j];
		}
		ConnCustInfor[i].DeviceName.value[j]='\0';

		for(j=0;j<strlen(tempMAC);j++)
		{
			ConnCustInfor[i].MAC.value[j]= tempMAC[j];
		}
		ConnCustInfor[i].MAC.value[j]='\0';

		for(j=0;j<strlen(tempIP);j++)
		{
			ConnCustInfor[i].IP.value[j]= tempIP[j];
		}
		ConnCustInfor[i].IP.value[j]='\0';
	}
	
	if(!strncmp("English",CommonParaInfor[5].value,strlen("English")))
	{
		read_html_file_into_cgi("homepage_eng.html");
	}else{

		read_html_file_into_cgi("homepage.html");
	}
return 0;
}
