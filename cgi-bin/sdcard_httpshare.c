/******************************************************************************
  @file    sdcard_httpshare.c

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
#define SDCARD_HTTPSHARE


/*=============================================================================

                           INCLUDE FILES

==============================================================================*/
#include "define.h"


/*=============================================================================

			MAIN FUNCTION IMPLEMENTATION

 ******************************************************************************
 * CGI FUNCTION
 *  sdcard_httpshare.cgi
 * ATCTIONS
 *  1,read comm infor data from js and set to globa strcut
 *  2,what will be shown should be confirmed with custmoer ???
 *  3,read corresponding due to different language
 *    1,convert key to value in html file
 *    2,printf new dynamic string which is gained at step3.1 to boa server 
 ******************************************************************************
==============================================================================*/
int main()
{
	char StringFromJava[REQ_RSP_STRING_LEN];
	int i;

	read_comm_infor_from_js();

/*=============================================================================
		please implement
==============================================================================*/
	
	if(!strncmp("English",CommonParaInfor[5].value,strlen("English")))
	{
		read_html_file_into_cgi("sdcard_httpshare_eng.html");
	}else{

		read_html_file_into_cgi("sdcard_httpshare.html");
	}
return 0;
}
