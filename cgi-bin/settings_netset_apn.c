/******************************************************************************
  @file    settings_netset_apn.c

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
#define SETTINGS_NETSET_APN


/*=============================================================================

                           INCLUDE FILES

==============================================================================*/
#include "define.h"


/*=============================================================================

			MAIN FUNCTION IMPLEMENTATION

 ******************************************************************************
 * CGI FUNCTION
 *  settings_netset_apn.cgi
 * ATCTIONS
 *  1,read comm infor data from js and set to globa strcut
 *  2,read apn infor from js
 *  3,handle apn infor, method shoud be thinked ???
 *  4,read corresponding html file due to different language
 *    1,convert key to value in html file
 *    2,printf new dynamic string which is gained at step4.1 to boa server 
 ******************************************************************************
==============================================================================*/
int main()
{
	//char StringFromJava[REQ_RSP_STRING_LEN];
	//char StringFromJavatest[150];
	char TempTotalApn[2];
    char TempApnId[10];
	char TempApnName[30];
	char TempApn[10];
	char TempMcc[5];
	char TempMnc[5];
	char TempAuth[10];
	char TempUsername[10];
	char TempPassword[10];
	int TotalApn;
	int i;
	int j;
    extern char wifi_pro_from_java_string[1024];
    time_out();
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"this is in apn module,will goto readcomminfo");
	read_comm_infor_from_js();

/*=============================================================================*/
	for (i = 0; i < 10; i++)
	{
		Setings_Apn_List[i].SETAPNNAME.value[0]='\0';
	}

	send_cmd_to_js("Request|ApnShow",wifi_pro_from_java_string);
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"The wifi_pro_from_java_string is:");
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,wifi_pro_from_java_string);
    //Result|ApnShow|total|apn_id|apnname|apn|mcc|mnc|Security type|admin|password
    //char StringFromJavatest[]="1|ApnShow|2|cmcc|cmcm|460|01|0|xiaojun|xiaojun1234|cmcc2|cmcm2|460|01|1|xiaojun|xiaojun1234";
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"this will goto get_index_str_from_js");
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,TempTotalApn);

    get_index_str_from_js(wifi_pro_from_java_string,3,TempTotalApn);
    TotalApn=(int)(TempTotalApn[0]-'0');

    for (i = 0; i < TotalApn; i++)
    {   
        xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"this will goto get_index_str_from_js");
        get_index_str_from_js(wifi_pro_from_java_string,(4+i*8),TempApnId);
        for (j = 0; j < strlen(TempApnId); j++)
        {
            Setings_Apn_List[i].SETAPNID.value[j]=TempApnId[j];
        }
        Setings_Apn_List[i].SETAPNID.value[j]='\0';
        xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,Setings_Apn_List[i].SETAPNID.value);


        get_index_str_from_js(wifi_pro_from_java_string,(5+i*8),TempApnName);
    	for (j = 0; j < strlen(TempApnName); j++)
    	{
    		Setings_Apn_List[i].SETAPNNAME.value[j]=TempApnName[j];
    	}
    	Setings_Apn_List[i].SETAPNNAME.value[j]='\0';
        xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,Setings_Apn_List[i].SETAPNNAME.value);

        get_index_str_from_js(wifi_pro_from_java_string,(6+i*8),TempApn);
    	for (j = 0; j < strlen(TempApn); j++)
    	{

    		Setings_Apn_List[i].SETAPN.value[j]=TempApn[j];
    	}
    	Setings_Apn_List[i].SETAPN.value[j]='\0';

        get_index_str_from_js(wifi_pro_from_java_string,(7+i*8),TempMcc);
    	for (j = 0; j < strlen(TempMcc); j++)
    	{
    		Setings_Apn_List[i].SETMCC.value[j]=TempMcc[j];
    	}
    	Setings_Apn_List[i].SETMCC.value[j]='\0';

        get_index_str_from_js(wifi_pro_from_java_string,(8+i*8),TempMnc);
    	for (j = 0; j < strlen(TempMnc); j++)
    	{
    		Setings_Apn_List[i].SETMNC.value[j]=TempMnc[j];
    	}
    	Setings_Apn_List[i].SETMNC.value[j]='\0';

        get_index_str_from_js(wifi_pro_from_java_string,(10+i*8),TempUsername);
    	for (j = 0; j < strlen(TempUsername); j++)
    	{
    		Setings_Apn_List[i].SETUSERNAME.value[j]=TempUsername[j];
    	}
    	Setings_Apn_List[i].SETUSERNAME.value[j]='\0';

        get_index_str_from_js(wifi_pro_from_java_string,(11+i*8),TempPassword);
    	for (j = 0; j < strlen(TempPassword); j++)
    	{
    		Setings_Apn_List[i].SETPASSWORD.value[j]=TempPassword[j];
    	}
    	Setings_Apn_List[i].SETPASSWORD.value[j]='\0';

        get_index_str_from_js(wifi_pro_from_java_string,(9+i*8),TempAuth);
    	if (!strcmp(TempAuth,"0"))
    	{
    		strcpy(TempAuth,"None");
    	} else if (!strcmp(TempAuth,"1"))
    	{
    		strcpy(TempAuth,"PAP");
    	} else if (!strcmp(TempAuth,"2"))
    	{
    		strcpy(TempAuth,"CHAP");
    	} else if (!strcmp(TempAuth,"3"))
    	{
    		strcpy(TempAuth,"PAP or CHAP");
    	}
    	for (j = 0; j < strlen(TempAuth); j++)
    	{
    		Setings_Apn_List[i].SETAUTH.value[j]=TempAuth[j];
    	}
    	Setings_Apn_List[i].SETAUTH.value[j]='\0';
    }
/*==============================================================================*/
	
	if(!strncmp("English",CommonParaInfor[5].value,strlen("English")))
	{
		xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"this will goto read html");
        read_html_file_into_cgi("settings_netset_apn_eng.html");
	}else{

		read_html_file_into_cgi("settings_netset_apn.html");
	}
return 0;
}
