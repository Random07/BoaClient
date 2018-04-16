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
#define SETTINGS_NETSET_APN


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
    char StringFromJava[REQ_RSP_STRING_LEN];
    char ApnNameFromWeb[50];
    char APNFromWeb[50];
    char MNCFromWeb[50];
    char MCCFromWeb[50];
    char AuthSelectFromWeb[50];
    char UsernameFromWeb[50];
    char PasswordFromWeb[50];
    char SendString[150];
    char SetResult[2];
    int i = 0;
    int j = 0;
    int templen=0;


    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"This will read the request from user");
    req_method = getenv("REQUEST_METHOD");
    get_cgi_data(stdin,req_method,StringFromWeb);
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"The StringFromWeb is:");
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,StringFromWeb);
//get_index_str_from_web_new(char *org,int index,char *Tag,char *outcome)

    strcpy(SendString,"Request|ApnAdd|");
    if(!get_index_str_from_web(StringFromWeb,"ApnName=",ApnNameFromWeb))
    {
        debug_message_printf("Can't find ApnName");
        return 0;
    }
    else{
        strcat(SendString,ApnNameFromWeb);
        strcat(SendString,"|");
            xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,SendString);

    }
    if(!get_index_str_from_web(StringFromWeb,"APN=",APNFromWeb))
    {
        debug_message_printf("Can't find APN");
        return 0;
    }
    else{
        strcat(SendString,APNFromWeb);
        strcat(SendString,"|");
                    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,SendString);


    }
    if(!get_index_str_from_web(StringFromWeb,"MNC=",MNCFromWeb))
    {
        debug_message_printf("Can't find MNC");
        return 0;
    }
    else{
        strcat(SendString,MNCFromWeb);
        strcat(SendString,"|");
                    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,SendString);

    }
    if(!get_index_str_from_web(StringFromWeb,"MCC=",MCCFromWeb))
    {
        debug_message_printf("Can't find MCC");
        return 0;
    }
    else{
        strcat(SendString,MCCFromWeb);
        strcat(SendString,"|");
                    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,SendString);


    }
    if(!get_index_str_from_web(StringFromWeb,"AuthSelect=",AuthSelectFromWeb))
    {
        debug_message_printf("Can't find AuthSelect");
        return 0;
    }
    else{
        strcat(SendString,AuthSelectFromWeb);
        strcat(SendString,"|");
                    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,SendString);


    }
    if(!get_index_str_from_web(StringFromWeb,"Username=",UsernameFromWeb))
    {
        debug_message_printf("Can't find Username");
        return 0;
    }
    else{
        strcat(SendString,UsernameFromWeb);
        strcat(SendString,"|");
                    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,SendString);


    }
    if(!get_index_str_from_web(StringFromWeb,"Password=",PasswordFromWeb))
    {
        debug_message_printf("Can't find Password");
        return 0;
    }
    else{
        strcat(SendString,PasswordFromWeb);
    }
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"The SendString is:");
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,SendString);

    send_cmd_to_js(SendString,StringFromJava);
  //  char StringFromJavatest[]="1|ApnAdd";
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"The StringFromJava is:");
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,StringFromJava);
    get_index_str_from_js(StringFromJava,1,SetResult);

    
    if(!strcmp("1",SetResult))
    {   
        web_header();
        puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/settings_netset_apn.cgi\">");
        we_btail();
    }else{
        //wifi_pro_alert_info="Add APN fail,please retry!";
        //read_html_file_into_cgi("alert.html");
        web_header();
        puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/settings_netset_apn.cgi\">");
        we_btail();
    }
    
    return 0;
}
