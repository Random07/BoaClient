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
	char SetResult[3];
	int i;


	//read_comm_infor_from_js();

/*=============================================================================*/
  	send_cmd_to_js("Request|setDataEnabled|1",StringFromJava);
	//char StringFromJavatest[]="Confirm|DataStatic|343400000|2000000";
	get_index_str_from_js(StringFromJava,1,SetResult);
	
    if(!strcmp("1",SetResult))
    {   
        web_header();
        puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/homepage.cgi\">");
        we_btail();
    }else{
        web_header();
        puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/homepage.cgi\">");
        we_btail();
    }

return 0;
}
