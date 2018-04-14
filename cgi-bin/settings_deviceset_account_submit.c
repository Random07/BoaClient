/******************************************************************************
  @file    login.c

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
#define SETTINGS_DEVICESET_ACCOUNT


#include "define.h"


/*=============================================================================

            MAIN FUNCTION IMPLEMENTATION

 ******************************************************************************
 * CGI FUNCTION
 *  login.cgi
 * ATCTIONS
 *  1,read data from boa server which is submitted from web page by user
 *  2,resolve Username and Password and Language para
 *  3,get corresponding data from js
 *  4,compare Username and Password to check correct or not
 *  5,set language
 *  6,goto differenct page
 ******************************************************************************
==============================================================================*/
int main()
{
    char *req_method;
    char StringFromWeb[REQ_RSP_STRING_LEN];
    char StringFromJava[30];
    char TempUserName1[30];
    char TempUserName2[30];
    char SendString[150];
    char SetResult[2];
    char NameInDevice[50];
    char PassInDevice[50];
    extern char wifi_pro_from_java_string[1024];

    send_cmd_to_js("Request|Login",wifi_pro_from_java_string);
    get_index_str_from_js(wifi_pro_from_java_string,3,NameInDevice);
    get_index_str_from_js(wifi_pro_from_java_string,4,PassInDevice);

    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"This will read the request from user");
    req_method = getenv("REQUEST_METHOD");
    get_cgi_data(stdin,req_method,StringFromWeb);
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"The StringFromWeb is:");
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,StringFromWeb);
//get_index_str_from_web_new(char *org,int index,char *Tag,char *outcome)
    

    strcpy(SendString,"Request|SetAccountInfo|");
    if(!get_index_str_from_web(StringFromWeb,"textfield2=",TempUserName1))
    {
        debug_message_printf("Can't find TempUserName1");
        return 0;
    }
    
    if(!get_index_str_from_web(StringFromWeb,"textfield3=",TempUserName2))
    {
        debug_message_printf("Can't find TempUserName2");
        return 0;
    }

    if (!strcmp(TempUserName1,TempUserName2) && strlen(TempUserName2) > 3)
    {
        strcat(SendString,TempUserName1);
        strcat(SendString,"|");
        strcat(SendString,PassInDevice);
        send_cmd_to_js(SendString,StringFromJava);
        xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"The SendString is:");
        xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,SendString);
    }else{
        web_header();
        puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/settings_deviceset_account.cgi\">");
        we_btail();
        return 0;
    }
        
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"The SendString is:");
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,SendString);

    //send_cmd_to_js(SendString,StringFromJava);
  //  char StringFromJavatest[]="1|ApnAdd";
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"The StringFromJava is:");
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,StringFromJava);
    get_index_str_from_js(StringFromJava,1,SetResult);

    
    if(!strcmp("1",SetResult))
    {   
        web_header();
        puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/\">");
        we_btail();
    }else{
        wifi_pro_alert_info="Change Username fail,please retry!";
        read_html_file_into_cgi("alert.html");
        web_header();
        puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/settings_deviceset_account.cgi\">");
        we_btail();
    }
    
    return 0;
}
