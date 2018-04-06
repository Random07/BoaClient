/******************************************************************************
  @file    basicinfor_datausage.c

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
#define BASICINFOR_DATAUSAGE


/*=============================================================================

                           INCLUDE FILES

==============================================================================*/
#include "define.h"
#include "stdio.h"


/*=============================================================================

			MAIN FUNCTION IMPLEMENTATION

 ******************************************************************************
 * CGI FUNCTION
 *  basicinfor_datausage.cgi
 * ATCTIONS
 *  1,read comm infor data from js and set to globa strcut
 *  2,read datausage infor from js
 *  3,handle datausage infor infor, method shoud be thinked ???
 *  4,read corresponding html file due to different language
 *    1,convert key to value in html file
 *    2,printf new dynamic string which is gained at step3.1 to boa server 
 ******************************************************************************
==============================================================================*/
int main()
{
	char StringFromJava[REQ_RSP_STRING_LEN];
	char UsedData[20]={0};
	char LimitData[20]={0};
	int i;


	read_comm_infor_from_js();

/*=============================================================================*/
  	send_cmd_to_js("Request|DataStatic",StringFromJava);
	//char StringFromJavatest[]="Confirm|DataStatic|343400000|2000000";
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"The StringFromJava is:");
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,StringFromJava);

    get_index_str_from_js(StringFromJava,3,UsedData);
	get_index_str_from_js(StringFromJava,4,LimitData);


	sprintf(UsedData,"%d",atoi(UsedData)/1000000);
	for(i=0;i<strlen(UsedData);i++){
		DataUsage[0].value[i]=UsedData[i];
	}
	DataUsage[0].value[i]='\0';


	//if LimitData=-1,the value is null
	if (!strcmp(LimitData,"-1"))
	{
		DataUsage[1].value[0]='\0';
	}else{
		sprintf(LimitData,"%d",atoi(LimitData)/1000000);
		for(i=0;i<strlen(LimitData);i++){
		    DataUsage[1].value[i]=LimitData[i];
	    }
	    DataUsage[1].value[i]='\0';
	}
		   
/*==============================================================================*/
	
	if(!strncmp("English",CommonParaInfor[5].value,strlen("English")))
	{
		read_html_file_into_cgi("basicinfor_datausage_eng.html");
	}else{

		read_html_file_into_cgi("basicinfor_datausage.html");
	}
return 0;
}
