/******************************************************************************
  @file    driverdownload.c

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
#define DRIVER_DOWNLOAD


/*=============================================================================

                           INCLUDE FILES

==============================================================================*/
#include "define.h"


/*=============================================================================

			MAIN FUNCTION IMPLEMENTATION

 ******************************************************************************
 * CGI FUNCTION
 *  driverdownload.cgi
 * ATCTIONS
 *  1,read comm infor data from js and set to globa strcut
 *  2,read driver infor from js
 *  3,read corresponding html file due to different language
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
		read_html_file_into_cgi("driverdownload_eng.html");
	}else{

		read_html_file_into_cgi("driverdownload.html");
	}
return 0;
}
