/******************************************************************************
  @file    define.h

  DESCRIPTION
-------------------------------------------------------------------------------
  Copyright (c) StephenSoftware, Inc.
  All Rights Reserved.
  Confidential and Proprietary - StephenSoftware, Inc.
-------------------------------------------------------------------------------

******************************************************************************/




/*===========================================================================

                           INCLUDE FILES

===========================================================================*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

/*===========================================================================

                          DEFINITIONS AND TYPES

===========================================================================*/
#define TEMP_STRING_LEN 512
#define REQ_RSP_STRING_LEN 1024
#define SOCKET_INET_ADDR "127.0.0.1"

typedef struct
{
char *key;
char value[50];
}CommonPara;


CommonPara CommonParaInfor[6]={
{"BatteryVolume",},
{"NetworkType",},
{"OperatorName",},
{"SignalStrength",},
{"DataStatus",},
{"Lanaguage",},
};

#ifdef HOME_PAGE
typedef struct
{
CommonPara index;
CommonPara DeviceName;
CommonPara MAC;
CommonPara IP;
}ConnCustomer;

ConnCustomer ConnCustInfor[10]={
{{"ConnCustIndex0",},{"ConnCustDeviceName0",},{"ConnCustMAC0",},{"ConnCustIP0",},},
{{"ConnCustIndex1",},{"ConnCustDeviceName1",},{"ConnCustMAC1",},{"ConnCustIP1",},},
{{"ConnCustIndex2",},{"ConnCustDeviceName2",},{"ConnCustMAC2",},{"ConnCustIP2",},},
{{"ConnCustIndex3",},{"ConnCustDeviceName3",},{"ConnCustMAC3",},{"ConnCustIP3",},},
{{"ConnCustIndex4",},{"ConnCustDeviceName4",},{"ConnCustMAC4",},{"ConnCustIP4",},},
{{"ConnCustIndex5",},{"ConnCustDeviceName5",},{"ConnCustMAC5",},{"ConnCustIP5",},},
{{"ConnCustIndex6",},{"ConnCustDeviceName6",},{"ConnCustMAC6",},{"ConnCustIP6",},},
{{"ConnCustIndex7",},{"ConnCustDeviceName7",},{"ConnCustMAC7",},{"ConnCustIP7",},},
{{"ConnCustIndex8",},{"ConnCustDeviceName8",},{"ConnCustMAC8",},{"ConnCustIP8",},},
{{"ConnCustIndex9",},{"ConnCustDeviceName9",},{"ConnCustMAC9",},{"ConnCustIP9",},},
};
#endif

#ifdef BASICINFOR_DEVICEINFOR
CommonPara DeviceInfo[11]={
{"SimCardNumber",},
{"IMEI",},
{"IMSI",},
{"SSID",},
{"MaxConnCounts",},
{"IpAddr",},
{"MacAddr",},
{"WAN_IPAddr",},
{"SoftwareVersion",},
{"FiremwareVersion",},
{"HardwareVersion",},
};
#endif

#ifdef BASICINFOR_DATAUSAGE
CommonPara DataUsage[2]={
{"UsedData",},
{"LimitData",},
};
#endif

#ifdef BASICINFOR_DATALIMIT
#endif

#ifdef SDCARD_SDCARD
#endif

#ifdef SDCARD_HTTPSHARE
#endif

#ifdef DRIVER_DOWNLOAD
#endif

#ifdef SMS_DEVICEPART
#endif

#ifdef SMS_SIMPART
#endif

#ifdef SMS_SMSSETTINGS
#endif

#ifdef SETTINGS_NETSET_DAILUP
#endif

#ifdef SETTINGS_NETSET_NETSEARCH
#endif

#ifdef SETTINGS_NETSET_APN
typedef struct
{
CommonPara SETAPNNAME;
CommonPara SETAPN;
CommonPara SETMNC;
CommonPara SETMCC;
CommonPara SETAUTH;
CommonPara SETUSERNAME;
CommonPara SETPASSWORD;
}SetApnPara;

CommonPara Settings_Apn[7]={
	{"SETAPNNAME",},
	{"SETAPN",},
	{"SETMNC",},
	{"SETMCC",},
	{"SETAUTH",},
	{"SETUSERNAME",},
	{"SETPASSWORD",},
}

SetApnPara Setings_Apn_List[]={
	{{"SETAPNNAME",},{"SETAPN",},{"SETMNC",},{"SETMCC",},{"SETAUTH",},{"SETUSERNAME",},{"SETPASSWORD",},},

}
#endif

#ifdef SETTINGS_WIFISET_BASIC
#endif

#ifdef SETTINGS_WIFISET_WPS
#endif

#ifdef SETTINGS_DEVICESET_ACCOUNT
#endif

#ifdef SETTINGS_DEVICESET_RESTORE
#endif

#ifdef SETTINGS_DEVICESET_REBOOT
#endif
/*===========================================================================

				FUNCTION DECLARE

===========================================================================*/
int get_cgi_data(FILE* fp, char *requestmethod,char *out);

int split_value_from_string(char Tag,char *in,char *out,char *remain);
int get_index_str_from_js(char *org,int index,char *outcome);
int get_index_str_from_web(char *org,char *Tag,char *out);

int read_comm_infor_from_js();
int send_cmd_to_js(char *SendMessage,char *OutString);

int convert_key_to_value(char *Tag,int Taglen);
int read_html_file_into_cgi(char *patch);

int web_header();
int we_btail();
int xdebug_message_printf(const char * file,const char * function,int line,char * errormsg);

int debug_message_printf(char *errormsg);
int debug_web_header_printf();
int debug_web_tail_printf();

/*===========================================================================

				MACRO DEFINE

===========================================================================*/
#define Debug_Single_Var_Message(VarType,Var)						\
	debug_web_header_printf();							\
	printf(" "#Var" is:"#VarType" ",Var);						\
	debug_web_tail_printf();							\
	return 0;									\

#define Debug_Double_Var_Message(VarType1,Var1,VarType2,Var2)				\
	debug_web_header_printf();							\
	printf(" "#Var1" is:"#VarType1"  "#Var2" is:"#VarType2" ",Var1,Var2);		\
	debug_web_tail_printf();							\
	return 0;									\

#define Debug_Triple_Var_Message(VarType1,Var1,VarType2,Var2,VarType3,Var3)						\
	debug_web_header_printf();											\
	printf(" "#Var1" is:"#VarType1"  "#Var2" is:"#VarType2"  "#Var3" is:"#VarType3" ",Var1,Var2,Var3);		\
	debug_web_tail_printf();											\
	return 0;													\
/*===========================================================================

			FUNCTION IMPLEMENTATION

===========================================================================*/

/*****************************************************************************
 * FUNCTION
 *  get_cgi_data
 * DESCRIPTION
 *  When User submit data to server via web page, the data will transfer by two
 *  method:1,GET 2,POST
 * PARAMETERS
 *  fp  [FILE]
 *  requestmethod [char*]
 *  out [char*]
 * RETURNS
 *  void
 * EXAMPLE
 *   NULL
 *****************************************************************************/
int get_cgi_data(FILE* fp, char *requestmethod,char *out)
{
	char *tempstring;
	int len;
	int i;
	if(!strcmp(requestmethod, "GET"))
	{
		tempstring = getenv("QUERY_STRING");
		i=0;
		while(tempstring[i]!='\0')
		{
			out[i]=tempstring[i];
			i++;
		}
		out[i]='\0';
	}else if(!strcmp(requestmethod, "POST"))
		{
			i=0;
	 		len = atoi(getenv("CONTENT_LENGTH"));
			if (len == 0)
			{
	    			out[0] = '\0';
	   		}
	  		while(1)
	  		{
	    			out[i] = (char)fgetc(fp);
	    			if (i == sizeof(out))
	    			{
					out[i+1] = '\0';
				}
				if (feof(fp) || (!(len)))
				{
					i++;
					out[i] = '\0';
				}
				i++;
			}
		}
	return 1;
}

/********************************************************************************************
 * FUNCTION
 *  split_value_from_string
 * DESCRIPTION
 *  split the string by designated char Tag like '|'(string from js)
 *  or '&'(string from web) one by one.
 * PARAMETERS
 *  Tag  [char] like '|'(string from js) or '&'(string from web)
 *  in [char*] original string, and will not modify it.
 *  out [char*] the string before designated char Tag like '|' or '&'
 * RETURNS
 *  0  there is no designated char Tag in the original string
 *  1 designated char Tag exit in the original string
 * EXAMPLE
 *  1,split_value_from_string('|',"Confirm|Login|Admin|123456",char *out,char *remain)
 *    out="Confirm" remain="Login|Admin|123456"
 *  2,split_value_from_string('&',"Username=Admin&Password=123456",char *out,char *remain)
 *    out="Username=Admin" remain="Password=123456"
 ********************************************************************************************/
int split_value_from_string(char Tag,char *in,char *out,char *remain)
{
	int i;
	int j;

	for(i=0;i<strlen(in)&&in[i]!=Tag;i++)
	{
		out[i]=in[i];
	}
	out[i]='\0';
	
	if(in[i]=='\0')
	{
		remain[0]='\0';
		return 0;	
	}
	
	for(i=strlen(out)+1,j=0;i<strlen(in);i++,j++)
	{
		remain[j]=in[i];
	}
	remain[j]='\0';
	return 1;
}

/*****************************************************************************
 * FUNCTION
 *  get_index_str_from_js
 * DESCRIPTION
 *  get the string of index number in the orginal string
 * PARAMETERS
 *  org [char*] original string, and will not modify it.
 *  index [int] index number which you want
 *  outcome [char*] the string of index number in the orginal string
 * RETURNS
 *  void
 * EXAMPLE
 *  1,get_index_str_from_js("Confirm|Login|Admin|123456",3,char *outcome)
 *    outcome="Admin"
 *****************************************************************************/
int get_index_str_from_js(char *org,int index,char *outcome)
{
	int i;
	int j;
	char in[REQ_RSP_STRING_LEN];
	char remain[REQ_RSP_STRING_LEN];

	for(i=0;i<strlen(org);i++)
	{
		in[i]=org[i];
	}
	in[i]='\0';
	for(i=0;i<index;i++)
	{
		split_value_from_string('|',in,outcome,remain);
		for(j=0;j<strlen(remain);j++)
		{
			in[j]=remain[j];
		}
		in[j]='\0';
	}
	return 1;
}

/*****************************************************************************************
 * FUNCTION
 *  get_index_str_from_web
 * DESCRIPTION
 *  get the string which is following the foramt Tag in the orginal string
 * PARAMETERS
 *  org [char*] original string, and will not modify it.
 *  Tag [char*] the string Tag which you want
 *  outcome [char*] the string which is following the foramt Tag in the orginal string
 * RETURNS
 *  0 no such string the in original is following the format Tag
 *  1 find the string the in original is following the format Tag
 * EXAMPLE
 *  1,get_index_str_from_web("Username=Admin&Password=123456","Password",char *outcome)
 *    outcome="123456"
 *****************************************************************************************/
int get_index_str_from_web(char *org,char *Tag,char *outcome)
{
	int i;
	int j;
	char in[REQ_RSP_STRING_LEN];
	char tempout[TEMP_STRING_LEN];
	char remain[REQ_RSP_STRING_LEN];
	for(i=0;i<strlen(org);i++)
	{
		in[i]=org[i];
	}
	
	while(1){
		if(split_value_from_string('&',in,tempout,remain))
		{
			if(!strncmp(Tag,tempout,strlen(Tag)))
			{
				for(i=strlen(Tag),j=0;i<strlen(tempout);i++,j++)
				{
					outcome[j]=tempout[i];
				}
				outcome[j]='\0';

				return 1;
			}
			for(i=0;i<strlen(remain);i++)
			{
				in[i]=remain[i];
			}
			in[i]='\0';

		}else{
			if(!strncmp(Tag,tempout,strlen(Tag)))
			{
				for(i=strlen(Tag),j=0;i<strlen(tempout);i++,j++)
				{
					outcome[j]=tempout[i];
				}
				outcome[j]='\0';
				return 1;
			}
			return 0;	
		}
	}
}

/*****************************************************************************************
 * FUNCTION
 *  read_comm_infor_from_js
 * DESCRIPTION
 *  read common information which are need by the web UI.
 *  like BatteryVolume,NetworkType...in globa struct CommonParaInfor
 *  this function will update those value in globa struct CommonParaInfor for using
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * EXAMPLE
 *  NULL
 *****************************************************************************************/
int read_comm_infor_from_js()
{
	char *StringFromJava;
	char *TempString;
	int i;
	int j;

//	send_cmd_to_js("Request|Common",StringFromJava);
//	Debug_Single_Var_Message(%s,StringFromJava);

	TempString = "70%";
	for(i=0;i<strlen(TempString);i++)
	{
		CommonParaInfor[0].value[i]=TempString[i];
	}
	CommonParaInfor[0].value[i]='\0';

	TempString = "LTE";
	for(i=0;i<strlen(TempString);i++)
	{
		CommonParaInfor[1].value[i]=TempString[i];
	}
	CommonParaInfor[1].value[i]='\0';

	TempString = "CU";
	for(i=0;i<strlen(TempString);i++)
	{
		CommonParaInfor[2].value[i]=TempString[i];
	}
	CommonParaInfor[2].value[i]='\0';

	TempString = "3";
	for(i=0;i<strlen(TempString);i++)
	{
		CommonParaInfor[3].value[i]=TempString[i];
	}
	CommonParaInfor[3].value[i]='\0';

	TempString = "DOWNLOAD";
	for(i=0;i<strlen(TempString);i++)
	{
		CommonParaInfor[4].value[i]=TempString[i];
	}
	CommonParaInfor[4].value[i]='\0';

	TempString = "English";
	for(i=0;i<strlen(TempString);i++)
	{
		CommonParaInfor[5].value[i]=TempString[i];
	}
	CommonParaInfor[5].value[i]='\0';

	return 1;
}

/*****************************************************************************************
 * FUNCTION
 *  send_cmd_to_js
 * DESCRIPTION
 *  send command to java sockect server.
 *  java server will handle the command
 *  java server will get back string response after successfully handle.
 * PARAMETERS
 *  SendMessage [char*] the command you want to send, no need to add '\n'
 *  OutString [char*] the response string which is sent by java server
 * RETURNS
 *  void
 * EXAMPLE
 *  send_cmd_to_js("Request|Login",OutString);
 *  OutString="Confirm|Login|Admin|123456"
 *****************************************************************************************/
int send_cmd_to_js(char *SendMessage,char *OutString)
{
   	int i;
	int server_sock;
	char tempsendmessge[TEMP_STRING_LEN];
	int str_len = 0;
	struct sockaddr_in server_addr;

	for(i=0;i<strlen(SendMessage);i++)
	{
		tempsendmessge[i]=SendMessage[i];
	}
	tempsendmessge[i]='\n';
	tempsendmessge[i+1]='\0';

	server_sock = socket(PF_INET, SOCK_STREAM, 0);
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr(SOCKET_INET_ADDR);
	server_addr.sin_port = htons(30000);
	
	connect(server_sock, (struct sockaddr*)&server_addr,sizeof(server_addr));

	write(server_sock, tempsendmessge, strlen(tempsendmessge));

	int goon=1;

	while(goon)
	{
		str_len = read(server_sock, OutString, REQ_RSP_STRING_LEN);
		if(str_len > 0)goon = 0;
	}
	OutString[str_len-4]='\0';
	close(server_sock);

	return 1;
}

/*****************************************************************************************
 * FUNCTION
 *  convert_key_to_value
 * DESCRIPTION
 *  this function will lookup the Key Tag in the globa structs
 *  when it find the Key Tag in globa structs
 *  it will printf the value Corresponding to the Key Tag to instead the Key Tag
 *  if no thing found, it will keep on and go out.
 * PARAMETERS
 *  Tag [char*]
 *  Taglen [int]
 * RETURNS
 *  void
 * EXAMPLE
 *  convert_key_to_value("BatteryVolume",strlen("BatteryVolume"))
 *  100% will be printf out
 *****************************************************************************************/
int convert_key_to_value(char *Tag,int Taglen)
{
	int i;

	for(i=0;i<6;i++)
	{
		if(!strncmp(Tag,CommonParaInfor[i].key,Taglen))
		{
			printf("%s",CommonParaInfor[i].value);
			break;
		}		
	}

#ifdef HOME_PAGE
	for(i=0;i<10;i++)
	{
		if(!strncmp(Tag,ConnCustInfor[i].index.key,Taglen))
		{
			printf("%s",ConnCustInfor[i].index.value);
			break;
		}
		if(!strncmp(Tag,ConnCustInfor[i].DeviceName.key,Taglen))
		{
			printf("%s",ConnCustInfor[i].DeviceName.value);
			break;
		}
		if(!strncmp(Tag,ConnCustInfor[i].MAC.key,Taglen))
		{
			printf("%s",ConnCustInfor[i].MAC.value);
			break;
		}
		if(!strncmp(Tag,ConnCustInfor[i].IP.key,Taglen))
		{
			printf("%s",ConnCustInfor[i].IP.value);
			break;
		}		
	}
#endif

#ifdef BASICINFOR_DEVICEINFOR

	for(i=0;i<11;i++)
	{
	
		if(!strncmp(Tag,DeviceInfo[i].key,Taglen))
		{
		xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,DeviceInfo[i].value);
			printf("%s",DeviceInfo[i].value);
			break;
		}
	}

#endif

#ifdef BASICINFOR_DATAUSAGE
for(i=0;i<2;i++)
{
	if(!strncmp(Tag,DataUsage[i].key,Taglen))
			{
			xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,DataUsage[i].value);
				printf("%s",DataUsage[i].value);
				break;
			}

}
#endif

#ifdef BASICINFOR_DATALIMIT
#endif

#ifdef SDCARD_SDCARD
#endif

#ifdef SDCARD_HTTPSHARE
#endif

#ifdef DRIVER_DOWNLOAD
#endif

#ifdef SMS_DEVICEPART
#endif

#ifdef SMS_SIMPART
#endif

#ifdef SMS_SMSSETTINGS
#endif

#ifdef SETTINGS_NETSET_DAILUP
#endif

#ifdef SETTINGS_NETSET_NETSEARCH
#endif

#ifdef SETTINGS_NETSET_APN
#endif

#ifdef SETTINGS_WIFISET_BASIC
#endif

#ifdef SETTINGS_WIFISET_WPS
#endif

#ifdef SETTINGS_DEVICESET_ACCOUNT
#endif

#ifdef SETTINGS_DEVICESET_RESTORE
#endif

#ifdef SETTINGS_DEVICESET_REBOOT
#endif
	return 1;
}

/*****************************************************************************************
write by Xavier
 *****************************************************************************************/
int write_select_option()
{
	int Setapnlist;

	Setapnlist=sizeof(Setings_Apn_List)/sizeof(Setings_Apn_List[0]);
	if (Setapnlist >1)
	{
		printf("<option selected="selected" value="%s">%s</option>\n",Setings_Apn_List[0].SETAPNNAME.value);
	}
	for (int i = 1; i < Setapnlist; ++i)
	{
		printf("<option value="%s">%s</option>\n",Setings_Apn_List[i].SETAPNNAME.value);
	}

}

/*****************************************************************************************
 * FUNCTION
 *  read_html_file_into_cgi
 * DESCRIPTION
 *  this function is used to:
 *  1, read the html file to string buffer
 *  2, look up the Key tag in the string buffer, like |%BatteryVolume|
 *  3, call function convert_key_to_value to search the key tag and then printf to instead
 * PARAMETERS
 *  patch [char*]
 * RETURNS
 *  0 successful excute
 * EXAMPLE
 *  read_html_file_into_cgi("basicconfig.html")
 *  such as |%BatteryVolume| in the basicconfig.html will be instead by 100%
 *  such as |%NetworkType| in the basicconfig.html will be instead by WCDMA
 *****************************************************************************************/
int read_html_file_into_cgi(char *patch)
{
	char Tempstrline[20*REQ_RSP_STRING_LEN]; 
	int Tempstrlen;
	int i;
	char Tempconfpara[50];
	int Tempconfparalen;
	int j;
	int k;

	puts("<Content-type:text/html>\n");

	FILE *fp;

	fp = fopen(patch,"r"); 

	if(fp == NULL)
	{
		debug_message_printf("File can't be openned!!!");
	}else{
		fseek(fp,0,SEEK_END);
        	Tempstrlen = ftell(fp);
        	rewind(fp);

        	fread(Tempstrline,Tempstrlen,1,fp);

        for(i=0;i<Tempstrlen-1;i++)
	   {
	   	/**************************************/
	   	if (('<' ==Tempstrline[i]) && ('!' == Tempstrline[i+1]))
	   	{
	   		for (k = 0; Tempstrline[i+k] != '>'; k++)
	   		{
	   			//Tempconfpara[k] = Tempstrline[i+k];
	   		}
	   		//Tempconfpara[k]='\0';
	   		i = i+k;
	   		//Tempconfparalen = k;
	   		write_select_option();
	   		continue;
	   	}

	   	/***************************************/
		if(('|' == Tempstrline[i]) && ('%' == Tempstrline[i+1]))
	    	{
			for(j=0;Tempstrline[i+2+j] != '|';j++)
			{
				Tempconfpara[j] = Tempstrline[i+2+j];
			}
				Tempconfpara[j] = '\0';

	        	i = i+2+j;
			Tempconfparalen = j;
			xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,Tempconfpara);

			convert_key_to_value(Tempconfpara,Tempconfparalen);

			continue;	    
		}
	  	printf("%c",Tempstrline[i]);
	   }
    	} 
  fclose(fp);
  return 1;
}

/*****************************************************************************************
 * FUNCTION
 *  web_header
 * DESCRIPTION
 *  printf the web formart before <body>
 * PARAMETERS
 *  void
 * RETURNS
 *  0 successful excute
 * EXAMPLE
 *  NULL
 *****************************************************************************************/
int web_header()
{

  puts("<Content-type:text/html>\n");
  puts("<html>");
  puts("<head>");
  puts("<title>MIFI</title>");
  puts("</head>");
  puts("<body>");

  return 1;
}

/*****************************************************************************************
 * FUNCTION
 *  we_btail
 * DESCRIPTION
 *  printf the web formart after <body> so that you can add your own string which you
 *  want to web UI by following the using of function web_header()
 * PARAMETERS
 *  void
 * RETURNS
 *  0 successful excute
 * EXAMPLE
 *  NULL
 *****************************************************************************************/
int we_btail()
{

//  puts("Refresh---please waiting");
  puts("</body>");
  puts("</html>");

  return 1;

}

/******************************************************************************************
* FUNCTION
*  debug_message_printf to file
* DESCRIPTION
*  printf the error message you want to the file for debug purpose
*  will print the file name,function and the line
* PARAMETERS
*  
* RETURNS
*  0 successful excute
* EXAMPLE
*  NULL
******************************************************************************************/
int xdebug_message_printf(const char *file,const char *function,int line,char *errormsg)
{
         FILE *fp = fopen("log_info.txt","a+");
         if (fp==0){
        printf("can't open file\n");
        return 0;
         }
         fseek(fp,0,SEEK_END);
         fprintf(fp, "[%s|@%s,%d] :%s\n\n" , function, file, line,errormsg);

         fclose(fp);
        return 1;

}



/*****************************************************************************************
 * FUNCTION
 *  debug_message_printf
 * DESCRIPTION
 *  printf the error message you want to the web page for debug purpose
 *  environment variable will also be printf out on the web page for debug purpose
 * PARAMETERS
 *  void
 * RETURNS
 *  0 successful excute
 * EXAMPLE
 *  NULL
 *****************************************************************************************/
int debug_message_printf(char *errormsg)
{

  puts("<Content-type:text/html>\n");
  puts("<html>");
  puts("<head>");
  puts("<title>login Successfully</title>");
  puts("</head>");
  puts("<body>");
  printf("Error Message =%s<br> \n", errormsg);

  puts("<br>");
  puts("<br>");
  puts("<br>");
	printf("REQUEST_METHOD=%s<br> \n", getenv("REQUEST_METHOD"));
	printf("SERVER_ADDR=%s<br> \n", getenv("SERVER_ADDR"));
	printf("SERVER_PROTOCOL=%s<br> \n", getenv("SERVER_PROTOCOL"));
	printf("REQUEST_URI=%s<br> \n", getenv("REQUEST_URI"));
	printf("PATH_INFO=%s<br> \n", getenv("PATH_INFO"));
	printf("PATH_TRANSLATED=%s<br> \n", getenv("PATH_TRANSLATED"));
	printf("SCRIPT_NAME=%s<br> \n", getenv("SCRIPT_NAME"));
	printf("QUERY_STRING=%s<br> \n", getenv("QUERY_STRING"));
	printf("REMOTE_ADDR=%s<br> \n", getenv("REMOTE_ADDR"));
	printf("REMOTE_PORT=%s<br> \n", getenv("REMOTE_PORT"));
	printf("CONTENT_TYPE=%s<br> \n", getenv("CONTENT_TYPE"));
	printf("CONTENT_LENGTH=%s<br> \n", getenv("CONTENT_LENGTH"));
	printf("HTTP_ACCEPT=%s<br> \n", getenv("HTTP_ACCEPT"));
  puts("<br>");
  puts("<br>");
  puts("<br>");
  puts("StephenSoftWare\n");
  puts("</body>");
  puts("</html>");

  return 1;

}

/*****************************************************************************************
 * FUNCTION
 *  debug_web_header_printf
 * DESCRIPTION
 *  printf the web formart before <body>
 * PARAMETERS
 *  void
 * RETURNS
 *  0 successful excute
 * EXAMPLE
 *  NULL
 *****************************************************************************************/
int debug_web_header_printf()
{

  puts("<Content-type:text/html>\n");
  puts("<html>");
  puts("<head>");
  puts("<title>login Successfully</title>");
  puts("</head>");
  puts("<body>");
  puts("<br>");
  puts("<br>");
  puts("<br>");

  return 1;

}

/*****************************************************************************************
 * FUNCTION
 *  debug_web_tail_printf
 * DESCRIPTION
 *  printf the web formart after <body> so that you can add your own string which you
 *  want to web UI by following the using of function debug_web_header_printf()
 *  environment variable will also be printf out on the web page for debug purpose
 * PARAMETERS
 *  void
 * RETURNS
 *  0 successful excute
 * EXAMPLE
 *  NULL
 *****************************************************************************************/
int debug_web_tail_printf()
{
  puts("<br>");
  puts("<br>");
  puts("<br>");
	printf("REQUEST_METHOD=%s<br> \n", getenv("REQUEST_METHOD"));
	printf("SERVER_ADDR=%s<br> \n", getenv("SERVER_ADDR"));
	printf("SERVER_PROTOCOL=%s<br> \n", getenv("SERVER_PROTOCOL"));
	printf("REQUEST_URI=%s<br> \n", getenv("REQUEST_URI"));
	printf("PATH_INFO=%s<br> \n", getenv("PATH_INFO"));
	printf("PATH_TRANSLATED=%s<br> \n", getenv("PATH_TRANSLATED"));
	printf("SCRIPT_NAME=%s<br> \n", getenv("SCRIPT_NAME"));
	printf("QUERY_STRING=%s<br> \n", getenv("QUERY_STRING"));
	printf("REMOTE_ADDR=%s<br> \n", getenv("REMOTE_ADDR"));
	printf("REMOTE_PORT=%s<br> \n", getenv("REMOTE_PORT"));
	printf("CONTENT_TYPE=%s<br> \n", getenv("CONTENT_TYPE"));
	printf("CONTENT_LENGTH=%s<br> \n", getenv("CONTENT_LENGTH"));
	printf("HTTP_ACCEPT=%s<br> \n", getenv("HTTP_ACCEPT"));
  puts("<br>");
  puts("<br>");
  puts("<br>");
  puts("StephenSoftWare\n");
  puts("</body>");
  puts("</html>");

  return 1;

}
