/******************************************************************************
  @file    settings_deviceset_restore_submit.c

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
#define SETTINGS_DEVICESET_RESTORE


/*=============================================================================

                           INCLUDE FILES

==============================================================================*/
#include "define.h"


/*=============================================================================

			MAIN FUNCTION IMPLEMENTATION

 ******************************************************************************
 * CGI FUNCTION
 *  settings_deviceset_restore.cgi
 * ATCTIONS
 *  1,read comm infor data from js and set to globa strcut
 *  2,read corresponding html file due to different language
 *    1,convert key to value in html file
 *    2,printf new dynamic string which is gained at step2.1 to boa server 
 ******************************************************************************
==============================================================================*/
int main()
{
	char StringFromJava[REQ_RSP_STRING_LEN];
	char Sendstring[20];
	char Result[2];

/*=============================================================================*/
Sendstring[20]="Request|ReFactory";
//send_cmd_to_js(Sendstring,StringFromJava);

char StringFromJavatest[]="1|ReFactory|";
get_index_str_from_js(StringFromJavatest,1,Result);

/*==============================================================================*/
	
	if(!strcmp(Result,"1"))
	{
		web_header();
		puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/settings_deviceset_restore.cgi\">");
		we_btail();
	}
return 0;
}
