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
char value[150];
}CommonPara;


CommonPara CommonParaInfor[7]={
{"BatteryVolume",},
{"NetworkType",},
{"OperatorName",},
{"SignalStrength",},
{"Maxconn",},
{"Lanaguage",},
{"UnreadSms",},
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

/*#ifdef SMS_DEVICEPART*/
typedef struct
{
CommonPara totalall;
CommonPara id;
CommonPara addr;
CommonPara body;
CommonPara time;
CommonPara flag;
}SmsInfo;
SmsInfo SmsInfoList[10]={
{{"totalall",},{"id",},{"addr",},{"body",},{"time",},{"flag",},},
{{"totalall",},{"id",},{"addr",},{"body",},{"time",},{"flag",},},
{{"totalall",},{"id",},{"addr",},{"body",},{"time",},{"flag",},},
{{"totalall",},{"id",},{"addr",},{"body",},{"time",},{"flag",},},
{{"totalall",},{"id",},{"addr",},{"body",},{"time",},{"flag",},},
{{"totalall",},{"id",},{"addr",},{"body",},{"time",},{"flag",},},
{{"totalall",},{"id",},{"addr",},{"body",},{"time",},{"flag",},},
{{"totalall",},{"id",},{"addr",},{"body",},{"time",},{"flag",},},
{{"totalall",},{"id",},{"addr",},{"body",},{"time",},{"flag",},},
{{"totalall",},{"id",},{"addr",},{"body",},{"time",},{"flag",},},
};


/*#endif*/

#ifdef SMS_SIMPART
#endif

#ifdef SMS_SMSSETTINGS
#endif

#ifdef SETTINGS_NETSET_DAILUP
#endif

/*#ifdef SETTINGS_NETSET_NETSEARCH*/
CommonPara SetSearchMode[1]={
{"SetNetworkModeValue",},
};

CommonPara SetNetworkMode[23]={
	{"0","NETWORK_MODE_WCDMA_PREF"},
	{"1","NETWORK_MODE_GSM_ONLY"},
	{"2","NETWORK_MODE_WCDMA_ONLY"},
	{"3","NETWORK_MODE_GSM_UMTS"},
	{"4","NETWORK_MODE_CDMA"},
	{"5","NETWORK_MODE_CDMA_NO_EVDO"},
	{"6","NETWORK_MODE_EVDO_NO_CDMA"},
	{"7","NETWORK_MODE_GLOBAL"},
	{"8","NETWORK_MODE_LTE_CDMA_EVDO"},
	{"9","NETWORK_MODE_LTE_GSM_WCDMA"},
	{"10","NETWORK_MODE_LTE_CDMA_EVDO_GSM_WCDMA"},
	{"11","NETWORK_MODE_LTE_ONLY"},
	{"12","NETWORK_MODE_LTE_WCDMA"},
	{"13","NETWORK_MODE_TDSCDMA_ONLY"},
	{"14","NETWORK_MODE_TDSCDMA_WCDMA"},
	{"15","NETWORK_MODE_LTE_TDSCDMA"},
	{"16","NETWORK_MODE_TDSCDMA_GSM"},
	{"17","NETWORK_MODE_LTE_TDSCDMA_GSM"},
	{"18","NETWORK_MODE_TDSCDMA_GSM_WCDMA"},
	{"19","NETWORK_MODE_LTE_TDSCDMA_WCDMA"},
	{"20","NETWORK_MODE_LTE_TDSCDMA_GSM_WCDMA"},
	{"21","NETWORK_MODE_TDSCDMA_CDMA_EVDO_GSM_WCDMA"},
	{"22","NETWORK_MODE_LTE_TDSCDMA_CDMA_EVDO_GSM_WCDMA"},
};
/*#endif*/

/*#ifdef SETTINGS_NETSET_APN*/
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
};

SetApnPara Setings_Apn_List[10]={
	{{"SETAPNNAME",},{"SETAPN",},{"SETMNC",},{"SETMCC",},{"SETAUTH",},{"SETUSERNAME",},{"SETPASSWORD",},},
	{{"SETAPNNAME",},{"SETAPN",},{"SETMNC",},{"SETMCC",},{"SETAUTH",},{"SETUSERNAME",},{"SETPASSWORD",},},
	{{"SETAPNNAME",},{"SETAPN",},{"SETMNC",},{"SETMCC",},{"SETAUTH",},{"SETUSERNAME",},{"SETPASSWORD",},},
	{{"SETAPNNAME",},{"SETAPN",},{"SETMNC",},{"SETMCC",},{"SETAUTH",},{"SETUSERNAME",},{"SETPASSWORD",},},
	{{"SETAPNNAME",},{"SETAPN",},{"SETMNC",},{"SETMCC",},{"SETAUTH",},{"SETUSERNAME",},{"SETPASSWORD",},},
	{{"SETAPNNAME",},{"SETAPN",},{"SETMNC",},{"SETMCC",},{"SETAUTH",},{"SETUSERNAME",},{"SETPASSWORD",},},
	{{"SETAPNNAME",},{"SETAPN",},{"SETMNC",},{"SETMCC",},{"SETAUTH",},{"SETUSERNAME",},{"SETPASSWORD",},},
	{{"SETAPNNAME",},{"SETAPN",},{"SETMNC",},{"SETMCC",},{"SETAUTH",},{"SETUSERNAME",},{"SETPASSWORD",},},
	{{"SETAPNNAME",},{"SETAPN",},{"SETMNC",},{"SETMCC",},{"SETAUTH",},{"SETUSERNAME",},{"SETPASSWORD",},},
	{{"SETAPNNAME",},{"SETAPN",},{"SETMNC",},{"SETMCC",},{"SETAUTH",},{"SETUSERNAME",},{"SETPASSWORD",},},
};
/*#endif*/

/*#ifdef SETTINGS_WIFISET_BASIC*/
CommonPara Settings_SSID[6]={
	{"SSIDVALUE",},
	{"SSIDSHOW1",},
	{"SSIDSHOW2",},
	{"SSIDSEC",},
	{"SSIDPASSWORD",},
	{"SSIDCONNNUM",},
};
/*#endif*/

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

int write_networkmode_select_option();
int write_ssidsecurity_select_option();
int write_ssidconnnum_select_option();
int write_apn_select_option();
int convert_key_to_value(char *Tag,int Taglen);
int read_html_file_into_cgi(char *patch);

int web_header();
int we_btail();
int xdebug_message_printf(const char * file,const char * function,int line,char * errormsg);
int xdebug_message_printf_int(const char *file,const char *function,int line,int errormsg);

int debug_message_printf(char *errormsg);
int debug_web_header_printf();
int debug_web_tail_printf();



char wifi_pro_index_org[1024];
char wifi_pro_index_remain[1024];
char *wifi_pro_index_from_java_test;
char *wifi_pro_alert_info;
char *wifi_pro_from_java_string;
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
{	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"this is in get cgi data");

	char *tempstring;
	int len;
	int i;
	if(!strcmp(requestmethod, "GET"))
	{xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"this is in get cgi data in get");
		tempstring = getenv("QUERY_STRING");
		i=0;
		while(tempstring[i]!='\0')
		{
			out[i]=tempstring[i];
			i++;
		}
		out[i]='\0';
	}else if(!strcmp(requestmethod, "POST"))
		{xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"this is in get cgi data in post");
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
	//char in[REQ_RSP_STRING_LEN];
	//char remain[REQ_RSP_STRING_LEN];
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,org);


	for(i=0;i<strlen(org);i++)
	{
		wifi_pro_index_org[i]=org[i];
	}
	wifi_pro_index_org[i]='\0';
	for(i=0;i<index;i++)
	{
		split_value_from_string('|',wifi_pro_index_org,outcome,wifi_pro_index_remain);
		for(j=0;j<strlen(wifi_pro_index_remain);j++)
		{
			wifi_pro_index_org[j]=wifi_pro_index_remain[j];
		}
		wifi_pro_index_org[j]='\0';
	}
	    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,outcome);

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
	char *StringFromJaveForLangua;
	char TempBattary[5];
	char TempNetworkType[10];
	char TempOperatorName[15];
	char TempSignal[3];
	char TempMaxconn[3];
	char TempLaguage[10];
	char TempUnreadSms[3];
	char *TempFromJavaLan;
	int i;
	int j;

	send_cmd_to_js("Request|Common",StringFromJava);
    send_cmd_to_js("Request|GetLanguage",StringFromJaveForLangua);
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"Read commStringFromJava");
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,StringFromJava);
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"Read StringFromJaveForLangua");
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,StringFromJaveForLangua);
	//wifi_pro_index_from_java_test="1|Common|5|3|90%|LTE|ATT&T|4";
	//TempFromJavaLan="0";


	get_index_str_from_js(StringFromJava,5,TempBattary);
	get_index_str_from_js(StringFromJava,6,TempNetworkType);
	get_index_str_from_js(StringFromJava,7,TempOperatorName);
	get_index_str_from_js(StringFromJava,8,TempSignal);
	get_index_str_from_js(StringFromJava,3,TempMaxconn);
	get_index_str_from_js(StringFromJava,4,TempUnreadSms);

	if(!strcmp(StringFromJaveForLangua,"0")){
		strcpy(TempLaguage,"English");
	}else{
		strcpy(TempLaguage,"Chinese");
	}


	for(i=0;i<strlen(TempBattary);i++)
	{
		CommonParaInfor[0].value[i]=TempBattary[i];
	}
	CommonParaInfor[0].value[i]='\0';

	//TempString = "LTE";
	for(i=0;i<strlen(TempNetworkType);i++)
	{
		CommonParaInfor[1].value[i]=TempNetworkType[i];
	}
	CommonParaInfor[1].value[i]='\0';

	//TempString = "CU";
	for(i=0;i<strlen(TempOperatorName);i++)
	{
		CommonParaInfor[2].value[i]=TempOperatorName[i];
	}
	CommonParaInfor[2].value[i]='\0';

	//TempString = "3";
	for(i=0;i<strlen(TempSignal);i++)
	{
		CommonParaInfor[3].value[i]=TempSignal[i];
	}
	CommonParaInfor[3].value[i]='\0';

	//TempString = "DOWNLOAD";
	for(i=0;i<strlen(TempMaxconn);i++)
	{
		CommonParaInfor[4].value[i]=TempMaxconn[i];
	}
	CommonParaInfor[4].value[i]='\0';

	//TempString = "English";
	for(i=0;i<strlen(TempLaguage);i++)
	{
		CommonParaInfor[5].value[i]=TempLaguage[i];
	}
	CommonParaInfor[5].value[i]='\0';

	for(i=0;i<strlen(TempUnreadSms);i++)
	{
		CommonParaInfor[6].value[i]=TempUnreadSms[i];
	}
	CommonParaInfor[6].value[i]='\0';

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
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"This is in send_cmd_to_js the SendMessage is:");
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,SendMessage);



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
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"thi is in define,have complete excute connect");

	write(server_sock, tempsendmessge, strlen(tempsendmessge));
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"thi is in define,have complete excute write data");

	int goon=1;

	while(goon)
	{
		str_len = read(server_sock, OutString, REQ_RSP_STRING_LEN);
		if(str_len > 0)goon = 0;
	}
	OutString[str_len-4]='\0';
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"The feedback string is:");
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,OutString);

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
for(i=0;i<1;i++)
{
	if(!strcmp(Tag,Setings_Apn_List[0].SETAPNNAME.key))
	{
		//xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,DataUsage[i].value);
		printf("%s",Setings_Apn_List[0].SETAPNNAME.value);
		break;
	}

}

for(i=0;i<1;i++)
{
	if(!strncmp(Tag,Setings_Apn_List[0].SETAPN.key,Taglen))
	{
		//xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,DataUsage[i].value);
		printf("%s",Setings_Apn_List[0].SETAPN.value);
		break;
	}

}

for(i=0;i<1;i++)
{
	if(!strncmp(Tag,Setings_Apn_List[0].SETMCC.key,Taglen))
	{
		//xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,DataUsage[i].value);
		printf("%s",Setings_Apn_List[0].SETMCC.value);
		break;
	}

}

for(i=0;i<1;i++)
{
	if(!strncmp(Tag,Setings_Apn_List[0].SETMNC.key,Taglen))
	{
		//xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,DataUsage[i].value);
		printf("%s",Setings_Apn_List[0].SETMNC.value);
		break;
	}

}

for(i=0;i<1;i++)
{
	if(!strncmp(Tag,Setings_Apn_List[0].SETUSERNAME.key,Taglen))
	{
		//xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,DataUsage[i].value);
		printf("%s",Setings_Apn_List[0].SETUSERNAME.value);
		break;
	}

}

for(i=0;i<1;i++)
{
	if(!strncmp(Tag,Setings_Apn_List[0].SETPASSWORD.key,Taglen))
	{
		//xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,Setings_Apn_List[0].SETPASSWORD.value);
		printf("%s",Setings_Apn_List[0].SETPASSWORD.value);
		break;
	}

}

for(i=0;i<1;i++)
{
	if(!strncmp(Tag,Setings_Apn_List[0].SETAUTH.key,Taglen))
	{
		//xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,DataUsage[i].value);
		printf("%s",Setings_Apn_List[0].SETAUTH.value);
		break;
	}

}
#endif

#ifdef SETTINGS_WIFISET_BASIC
if (!strncmp(Tag,Settings_SSID[0].key,Taglen))
{
	printf("%s",Settings_SSID[0].value);
	//break;
}
if (!strncmp(Tag,Settings_SSID[1].key,Taglen))
{
	printf("%s",Settings_SSID[1].value);
	//break;
}
if (!strncmp(Tag,Settings_SSID[2].key,Taglen))
{
	printf("%s",Settings_SSID[2].value);
	//break;
}

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
int write_apn_select_option()
{
	int Setapnlist;
	int i;

	//Setapnlist=sizeof(Setings_Apn_List)/sizeof(Setings_Apn_List[0]);
	Setapnlist=0;
	for (i = 0; i < 10; i++)
	{
		if (Setings_Apn_List[i].SETAPNNAME.value[0] != '\0')
		{
			Setapnlist=Setapnlist+1;
		} else{break;}
	
	}

	if (Setapnlist >0)
	{
		printf("<option selected=\"selected\" value=\"%s\">%s</option>\n",Setings_Apn_List[0].SETAPNNAME.value,Setings_Apn_List[0].SETAPNNAME.value);
	}
	for (i = 1; i < Setapnlist; i++)
	{
		printf("<option value=\"%s\">%s</option>\n",Setings_Apn_List[i].SETAPNNAME.value,Setings_Apn_List[i].SETAPNNAME.value);
	}
	return 1;
}


int write_ssidsecurity_select_option(){
	char TempSSIDSec[5];
	strcpy(TempSSIDSec,Settings_SSID[3].value);
	if (!strcmp(TempSSIDSec,"0"))
	{
		printf("<option selected=\"selected\" value=\"0\">open</option>");
		printf("<option  value=\"1\">WPA_PSK</option>");
		printf("<option  value=\"2\">WPA_PSK2</option>");
	}
	if (!strcmp(TempSSIDSec,"1"))
	{
		printf("<option  value=\"0\">open</option>");
		printf("<option  selected=\"selected\" value=\"1\">WPA_PSK</option>");
		printf("<option  value=\"2\">WPA_PSK2</option>");
	}
	if (!strcmp(TempSSIDSec,"2"))
	{
		printf("<option  value=\"0\">open</option>");
		printf("<option  value=\"1\">WPA_PSK</option>");
		printf("<option  selected=\"selected\" value=\"2\">WPA_PSK2</option>");
	}

}

int write_ssidconnnum_select_option(){
	if (!strcmp(Settings_SSID[5].value,"1"))
	{
		printf("<option  selected=\"selected\" value=\"1\">1</option>");
		printf("<option   value=\"2\">2</option>");
		printf("<option   value=\"3\">3</option>");
		printf("<option   value=\"4\">4</option>");
		printf("<option   value=\"5\">5</option>");
		printf("<option   value=\"6\">6</option>");
		printf("<option   value=\"7\">7</option>");
		printf("<option   value=\"8\">8</option>");
		printf("<option   value=\"9\">9</option>");
		printf("<option   value=\"10\">10</option>");
	}
	if (!strcmp(Settings_SSID[5].value,"2"))
	{
		printf("<option   value=\"1\">1</option>");
		printf("<option  selected=\"selected\" value=\"2\">2</option>");
		printf("<option   value=\"3\">3</option>");
		printf("<option   value=\"4\">4</option>");
		printf("<option   value=\"5\">5</option>");
		printf("<option   value=\"6\">6</option>");
		printf("<option   value=\"7\">7</option>");
		printf("<option   value=\"8\">8</option>");
		printf("<option   value=\"9\">9</option>");
		printf("<option   value=\"10\">10</option>");
	}
	if (!strcmp(Settings_SSID[5].value,"3"))
	{
		printf("<option   value=\"1\">1</option>");
		printf("<option   value=\"2\">2</option>");
		printf("<option  selected=\"selected\" value=\"3\">3</option>");
		printf("<option   value=\"4\">4</option>");
		printf("<option   value=\"5\">5</option>");
		printf("<option   value=\"6\">6</option>");
		printf("<option   value=\"7\">7</option>");
		printf("<option   value=\"8\">8</option>");
		printf("<option   value=\"9\">9</option>");
		printf("<option   value=\"10\">10</option>");
	}
	if (!strcmp(Settings_SSID[5].value,"4"))
	{
		printf("<option   value=\"1\">1</option>");
		printf("<option   value=\"2\">2</option>");
		printf("<option   value=\"3\">3</option>");
		printf("<option  selected=\"selected\" value=\"4\">4</option>");
		printf("<option   value=\"5\">5</option>");
		printf("<option   value=\"6\">6</option>");
		printf("<option   value=\"7\">7</option>");
		printf("<option   value=\"8\">8</option>");
		printf("<option   value=\"9\">9</option>");
		printf("<option   value=\"10\">10</option>");
	}
	if (!strcmp(Settings_SSID[5].value,"5"))
	{
		printf("<option   value=\"1\">1</option>");
		printf("<option   value=\"2\">2</option>");
		printf("<option   value=\"3\">3</option>");
		printf("<option   value=\"4\">4</option>");
		printf("<option  selected=\"selected\" value=\"5\">5</option>");
		printf("<option   value=\"6\">6</option>");
		printf("<option   value=\"7\">7</option>");
		printf("<option   value=\"8\">8</option>");
		printf("<option   value=\"9\">9</option>");
		printf("<option   value=\"10\">10</option>");
	}
	if (!strcmp(Settings_SSID[5].value,"6"))
	{
		printf("<option   value=\"1\">1</option>");
		printf("<option   value=\"2\">2</option>");
		printf("<option   value=\"3\">3</option>");
		printf("<option   value=\"4\">4</option>");
		printf("<option   value=\"5\">5</option>");
		printf("<option  selected=\"selected\" value=\"6\">6</option>");
		printf("<option   value=\"7\">7</option>");
		printf("<option   value=\"8\">8</option>");
		printf("<option   value=\"9\">9</option>");
		printf("<option   value=\"10\">10</option>");
	}
	if (!strcmp(Settings_SSID[5].value,"7"))
	{
		printf("<option  value=\"1\">1</option>");
		printf("<option   value=\"2\">2</option>");
		printf("<option   value=\"3\">3</option>");
		printf("<option   value=\"4\">4</option>");
		printf("<option   value=\"5\">5</option>");
		printf("<option   value=\"6\">6</option>");
		printf("<option   selected=\"selected\" value=\"7\">7</option>");
		printf("<option   value=\"8\">8</option>");
		printf("<option   value=\"9\">9</option>");
		printf("<option   value=\"10\">10</option>");
	}
	if (!strcmp(Settings_SSID[5].value,"8"))
	{
		printf("<option   value=\"1\">1</option>");
		printf("<option   value=\"2\">2</option>");
		printf("<option   value=\"3\">3</option>");
		printf("<option   value=\"4\">4</option>");
		printf("<option   value=\"5\">5</option>");
		printf("<option   value=\"6\">6</option>");
		printf("<option   value=\"7\">7</option>");
		printf("<option  selected=\"selected\" value=\"8\">8</option>");
		printf("<option   value=\"9\">9</option>");
		printf("<option   value=\"10\">10</option>");
	}
	if (!strcmp(Settings_SSID[5].value,"9"))
	{
		printf("<option   value=\"1\">1</option>");
		printf("<option   value=\"2\">2</option>");
		printf("<option   value=\"3\">3</option>");
		printf("<option   value=\"4\">4</option>");
		printf("<option   value=\"5\">5</option>");
		printf("<option   value=\"6\">6</option>");
		printf("<option   value=\"7\">7</option>");
		printf("<option   value=\"8\">8</option>");
		printf("<option  selected=\"selected\"  value=\"9\">9</option>");
		printf("<option  value=\"10\">10</option>");
	}
	if (!strcmp(Settings_SSID[5].value,"10"))
	{
		printf("<option   value=\"1\">1</option>");
		printf("<option   value=\"2\">2</option>");
		printf("<option   value=\"3\">3</option>");
		printf("<option   value=\"4\">4</option>");
		printf("<option   value=\"5\">5</option>");
		printf("<option   value=\"6\">6</option>");
		printf("<option   value=\"7\">7</option>");
		printf("<option   value=\"8\">8</option>");
		printf("<option   value=\"9\">9</option>");
		printf("<option  selected=\"selected\" value=\"10\">10</option>");
	}

	return 1;
}

int write_networkmode_select_option(){
	int i;

	for (i = 0; i < 23;i++)
	{
		//printf("<option   value=\"%s\">%s</option>",SetSearchMode[0].key,SetSearchMode[0].value);
		if (!strcmp(SetSearchMode[0].value,SetNetworkMode[i].key))
		{
		printf("<option   value=\"%s\"  selected=\"selected\">%s</option>\n",SetNetworkMode[i].key,SetNetworkMode[i].value);	
		}
		else{
			printf("<option   value=\"%s\">%s</option>\n",SetNetworkMode[i].key,SetNetworkMode[i].value);
		}
	}
	return 1;
}

int write_smsdevicepart_select_option(char smsdevicepartnum){
	int i;
	//char *sms=smsdevicepartnum;
	i=(int)(smsdevicepartnum-'0');
xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"write_smsdevicepart_select_option");

xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,SmsInfoList[i].addr.value);
xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,SmsInfoList[i].body.value);
xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,SmsInfoList[i].time.value);
//xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,sms);
	//i=atoi(sms);
	//printf("<option   value=\"%d\"  selected=\"selected\"></option>\n",i);
	printf("<input type=\"checkbox\" name=\"smsdevicecheckbox\" class=\"STYLE1\" value=\"%s\" /></td>\n",SmsInfoList[i].id.value);
    printf("<td align=\"center\" class=\"STYLE2\">%s</td>\n",SmsInfoList[i].addr.value);
    printf("<td align=\"center\"class=\"STYLE2\">%s</td>\n",SmsInfoList[i].body.value);
	printf(" <td height=\"50\" align=\"right\" class=\"STYLE2\">%s</td>\n",SmsInfoList[i].time.value);
}

int write_alert_info(){
	xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"the wifi_pro_alert_info is:");
    xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,wifi_pro_alert_info);

    printf("%s",write_alert_info );
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
	char Tempoption[20];
	char Tempoptionnum[2];
	char Tempoptionstr[18];
	int j;
	int k;
	int m;
	int n;

	puts("<Content-type:text/html>\n");
	   		xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"this is in read html");

	FILE *fp;

	fp = fopen(patch,"r"); 

	if(fp == NULL)
	{
		debug_message_printf("File can't be openned!!!");
		puts("File can't be opened");
	}else{
		fseek(fp,0,SEEK_END);
        	Tempstrlen = ftell(fp);
        	rewind(fp);

        	fread(Tempstrline,Tempstrlen,1,fp);

        for(i=0;i<Tempstrlen-1;i++)
	   {
	   	/**************************************/
	   		   		//xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"i=0;i<Tempstrlen-1;i++");

	   	if (('<' ==Tempstrline[i]) && ('!' == Tempstrline[i+1]) && ('%'==Tempstrline[i+4]))
	   	{
	   		xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"this is in <!-- -->");
	   		for (k = 0; Tempstrline[i+k+5] != '%'; k++)
	   		{
	   			Tempoption[k] = Tempstrline[i+k+5];
	   		}
	   		Tempoption[k]='\0';
	   		i = i+k+5+3;
	   		/*for (m = 0; m < (strlen(Tempoption)-1); m++)
	   		{
	   			Tempoptionstr[m]=Tempoption[m];
	   		}*/
	   		//strcpy(Tempoptionnum[0],Tempoption[k-1]);
	   		//printf("this will print Tempoption%s\n",Tempoption );
	   		xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,Tempoption);
	   		//xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,Tempoption[k-1]);
	   		if (!strncmp(Tempoption,"apnconfig",strlen("apnconfig")))
	   		{
	   			//puts("this will goto write_select_option");
	   			write_apn_select_option();
	   		}
	   		if (!strncmp(Tempoption,"ssidsecurity",strlen("ssidsecurity")))
	   		{
	   			write_ssidsecurity_select_option();
	   		}
	   		if (!strncmp(Tempoption,"ssidconnnum",strlen("ssidconnnum")))
	   		{
	   			write_ssidconnnum_select_option();
	   		}
	   		if (!strncmp(Tempoption,"SetNetworkMode",strlen("SetNetworkMode")))
	   		{
	   			write_networkmode_select_option();
	   		}
	   		if(!strncmp(Tempoption,"smsdevicepart",strlen("smsdevicepart"))){

                write_smsdevicepart_select_option(Tempoption[k-1]);
	   		}
	   		if(!strncmp(Tempoption,"alertinfo",strlen("alertinfo"))){
	   			write_alert_info();
	   		}
	   		
	   		continue;
	   	}

	   	/***************************************/
		if(('|' == Tempstrline[i]) && ('%' == Tempstrline[i+1]))
	    	{
	    			   		xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"this is in |% |");

			for(j=0;Tempstrline[i+2+j] != '|';j++)
			{
				Tempconfpara[j] = Tempstrline[i+2+j];
			}
				Tempconfpara[j] = '\0';

	        	i = i+2+j;
			Tempconfparalen = j;
			
			convert_key_to_value(Tempconfpara,Tempconfparalen);

			continue;	    
		}
			   		//xdebug_message_printf(__FILE__,__FUNCTION__,__LINE__,"this willl print html");

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

int xdebug_message_printf_int(const char *file,const char *function,int line,int errormsg)
{
         FILE *fp = fopen("log_info.txt","a+");
         if (fp==0){
        printf("can't open file\n");
        return 0;
         }
         fseek(fp,0,SEEK_END);
         fprintf(fp, "[%s|@%s,%d] :%d\n\n" , function, file, line,errormsg);

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
