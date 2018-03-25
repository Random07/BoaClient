/******************************************************************************
  @file    loginerror.c

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
#include "define.h"


/*=============================================================================

			MAIN FUNCTION IMPLEMENTATION

 ******************************************************************************
 * CGI FUNCTION
 *  basicconfig.cgi
 * ATCTIONS
 *  1,read language from devices
 *  2,read different html file due to different language
 *    1,convert key to value in loginerror.html or loginerror_eng.html
 *    2,printf new dynamic string which is gained at step2.1 to boa server 
 ******************************************************************************
==============================================================================*/
int main()
{
	read_comm_infor_from_js();
	
	if(!strncmp("English",CommonParaInfor[5].value,strlen("English")))
	{
		read_html_file_into_cgi("loginerror_eng.html");
	}else{
		read_html_file_into_cgi("loginerror.html");
	}
	return 0;
}
