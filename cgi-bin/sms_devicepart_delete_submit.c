/******************************************************************************
  @file    settings_netset_netsearch.c

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
 *  settings_netset_netsearch.cgi
 * ATCTIONS
 *  1,read comm infor data from js and set to globa strcut
 *  2,read net search mode infor from js
 *  3,handle net search mode infor, method shoud be thinked ???
 *  4,read corresponding html file due to different language
 *    1,convert key to value in html file
 *    2,printf new dynamic string which is gained at step4.1 to boa server 
 ******************************************************************************
==============================================================================*/
int main()
{
    char *req_method;
    char StringFromWeb[REQ_RSP_STRING_LEN];
    char StringFromJava[REQ_RSP_STRING_LEN];
    char TempDeleteItems[12];
    char SendString[30];
    char SetResult[2];
    int i = 0;
    int j = 0;



    req_method = getenv("REQUEST_METHOD");
    get_cgi_data(stdin,req_method,StringFromWeb);


    if (!get_index_str_from_web(StringFromWeb,"SmsDeviceDelete=",TempDeleteItems))
    {
        debug_message_printf("Can't find TempDeleteItems");
        return 0;
    }
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,StringFromWeb);
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,TempDeleteItems);

    strcpy(SendString,"Request|DeleteSms|");
    for (i = 0; i<strlen(TempDeleteItems) ; i++)
    {   
        xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"TempDeleteItems");
        xdebug_message_printf_int(__FILE__,__FUNCTION__,__LINE__,TempDeleteItems[i]);
        if (TempDeleteItems[i] != ',')
        {
            j=(int)(TempDeleteItems[i]-'0');
            SendString[strlen(SendString)]=TempDeleteItems[i];
            xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,SendString);       
        }else{
            strcat(SendString,"|");
        }
        
    }
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"the SendString is:");
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,SendString);
    

    send_cmd_to_js(SendString,StringFromJava);
    //char StringFromJavatest[]="1|DeleteSms";
    get_index_str_from_js(StringFromJava,1,SetResult);
/*==============================================================================*/
	
    if(!strcmp("1",SetResult))
    {   
        web_header();
        puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/sms_devicepart.cgi\">");
        we_btail();
    }else{
        web_header();
        puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/loginerror.cgi\">");
        we_btail();
    }
return 0;
}
