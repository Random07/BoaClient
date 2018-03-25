#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

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

void getcgidata(FILE* fp, char *requestmethod,char *out);

int Splitvaluefromstring(char Tag,char *in,char *out,char *remain);
void GetindexstrfromJS(char *org,int index,char *outcome);
int GetindexstrfromWeb(char *org,char *Tag,char *out);

void Readcomminforfromjava();
void Socketwithjavaserver(char *SendMessage,char *OutString);

void Convertkeytovalue(char *Tag,int Taglen);
int Readhtml(char *patch);

int webheader();
int webtail();
int logmessageprintf(char *errormsg);
int logwebheaderprintf();
int logwebtailprintf();

//logwebheaderprintf();		
//printf("NameFromWeb=%s,PassFromWeb=%s",NameFromWeb,PassFromWeb);
//printf("<br>");
//printf("NameInDevice=%s,PassInDevice=%s",NameInDevice,PassInDevice);
//logwebtailprintf();

void getcgidata(FILE* fp, char *requestmethod,char *out)
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
}

int Splitvaluefromstring(char Tag,char *in,char *out,char *remain)
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

void GetindexstrfromJS(char *org,int index,char *outcome)
{
	int i;
	int j;
	char in[1024];
	char remain[1024];

	for(i=0;i<strlen(org);i++)
	{
		in[i]=org[i];
	}
	in[i]='\0';
	for(i=0;i<index;i++)
	{
		Splitvaluefromstring('|',in,outcome,remain);
		for(j=0;j<strlen(remain);j++)
		{
			in[j]=remain[j];
		}
		in[j]='\0';
	}
}

int GetindexstrfromWeb(char *org,char *Tag,char *outcome)
{
	int i;
	int j;
	char in[1024];
	char tempout[512];
	char remain[1024];
	for(i=0;i<strlen(org);i++)
	{
		in[i]=org[i];
	}
	
	while(1){
		if(Splitvaluefromstring('&',in,tempout,remain))
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

void Readcomminforfromjava()
{
	char *StringFromJava;
	char *TempString;
	int i;
	int j;

	TempString = "90%";
	for(i=0;i<strlen(TempString);i++)
	{
		CommonParaInfor[0].value[i]=TempString[i];
	}
	CommonParaInfor[0].value[i]='\0';

	TempString = "WCDMA";
	for(i=0;i<strlen(TempString);i++)
	{
		CommonParaInfor[1].value[i]=TempString[i];
	}
	CommonParaInfor[1].value[i]='\0';

	TempString = "CMCC";
	for(i=0;i<strlen(TempString);i++)
	{
		CommonParaInfor[2].value[i]=TempString[i];
	}
	CommonParaInfor[2].value[i]='\0';

	TempString = "5";
	for(i=0;i<strlen(TempString);i++)
	{
		CommonParaInfor[3].value[i]=TempString[i];
	}
	CommonParaInfor[3].value[i]='\0';

	TempString = "UPLOAD";
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

}

void Socketwithjavaserver(char *SendMessage,char *OutString)
{
   	int i;
	int server_sock;
	char tempsendmessge[100];
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
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_addr.sin_port = htons(30000);
	connect(server_sock, (struct sockaddr*)&server_addr,sizeof(server_addr));
	
	write(server_sock, tempsendmessge, strlen(tempsendmessge));

	int goon=1;

	while(goon)
	{
		str_len = read(server_sock, OutString, 1024);
		OutString[str_len]='\0';
		if(str_len > 0)goon = 0;
	}

	close(server_sock);
}

void Convertkeytovalue(char *Tag,int Taglen)
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
	for(i=0;i<11;i++){
	    if(!strncmp(Tag,DeviceInfo[i].key,Taglen)){
			printf("%s",DeviceInfo[i].value);
			break;
		}
	}
}
int Readhtml(char *patch)
{
	char Tempstrline[10240]; 
	int Tempstrlen;
	int i;
	char Tempconfpara[30];
	int Tempconfparalen;
	int j;

	puts("<Content-type:text/html>\n");

	FILE *fp;

	fp = fopen(patch,"r"); 

	if(fp == NULL)
	{
		logmessageprintf("File can't be openned!!!");
	}else{
		fseek(fp,0,SEEK_END);
        	Tempstrlen = ftell(fp);
        	rewind(fp);

        	fread(Tempstrline,Tempstrlen,1,fp);

        for(i=0;i<Tempstrlen-1;i++)
	   {
		if(('|' == Tempstrline[i]) && ('%' == Tempstrline[i+1]))
	    	{
			for(j=0;Tempstrline[i+2+j] != '|';j++)
			{
				Tempconfpara[j] = Tempstrline[i+2+j];
			}
				Tempconfpara[j] = '\0';

	        	i = i+2+j;
			Tempconfparalen = j;
			
			Convertkeytovalue(Tempconfpara,Tempconfparalen);

			continue;	    
		}
	  	printf("%c",Tempstrline[i]);
	   }
    	} 
  fclose(fp);
  return 0;
}

int webheader()
{

  puts("<Content-type:text/html>\n");
  puts("<html>");
  puts("<head>");
  puts("<title>MIFI</title>");
  puts("</head>");
  puts("<body>");
  puts("<br>");
  puts("<br>");
  puts("<br>");

  return 0;
}

int webtail()
{

  puts("<br>");
  puts("<br>");
  puts("<br>");
  puts("Refresh---please waiting");
  puts("</body>");
  puts("</html>");

  return 0;

}

int logmessageprintf(char *errormsg)
{

  puts("<Content-type:text/html>\n");
  puts("<html>");
  puts("<head>");
  puts("<title>login Successfully</title>");
  puts("</head>");
  puts("<body>");
  printf("What We Want Is =%s<br> \n", errormsg);

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

  return 0;

}

int logwebheaderprintf()
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

  return 0;

}

int logwebtailprintf()
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

  return 0;

}
