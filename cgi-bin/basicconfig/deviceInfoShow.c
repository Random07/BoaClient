#include "define.h"

int main()
{
	char StringFromJava[1024];
	char SimCard[30]={0};
char IMEI[30]={0};
char IMSI[30]={0};
char SSID[30]={0};
char ConCount[30]={0};
char IP[30]={0};
char Mac[30]={0};
char Wan_Ip[30]={0};
char SoftVersion[30]={0};
char HardVersion[30]={0};
char FirmWare[30]={0};
int i;

	Readcomminforfromjava();
	//logmessageprintf("cant find correct info");
//	Socketwithjavaserver("Request|DeviceInfo",StringFromJava);
    char StringFromJavatest[]="Confirm|DeviceInfo|3434|3341|1343|454|5|4343|98|424|8967|342|23432";
   
		GetindexstrfromJS(StringFromJavatest,(3),SimCard);
		GetindexstrfromJS(StringFromJavatest,(4),IMEI);
		GetindexstrfromJS(StringFromJavatest,(5),IMSI);
		GetindexstrfromJS(StringFromJavatest,(6),SSID);
		GetindexstrfromJS(StringFromJavatest,(7),ConCount);
		GetindexstrfromJS(StringFromJavatest,(8),IP);
		GetindexstrfromJS(StringFromJavatest,(9),Mac);
		GetindexstrfromJS(StringFromJavatest,(10),Wan_Ip);
		GetindexstrfromJS(StringFromJavatest,(11),SoftVersion);
		GetindexstrfromJS(StringFromJavatest,(12),FirmWare);
		GetindexstrfromJS(StringFromJavatest,(13),HardVersion); 
	for(i=0;i<strlen(SimCard);i++){
		DeviceInfo[0].value[i]=SimCard[i];

	}
	DeviceInfo[0].value[i]='\0';
	for(i=0;i<strlen(IMEI);i++){
		DeviceInfo[1].value[i]=IMEI[i];

	}
	DeviceInfo[1].value[i]='\0';
	for(i=0;i<strlen(IMSI);i++){
		DeviceInfo[2].value[i]=IMSI[i];

	}
	DeviceInfo[2].value[i]='\0';
	for(i=0;i<strlen(SSID);i++){
		DeviceInfo[3].value[i]=SSID[i];

	}
	DeviceInfo[3].value[i]='\0';
	for(i=0;i<strlen(ConCount);i++){
		DeviceInfo[4].value[i]=ConCount[i];

	}
	DeviceInfo[4].value[i]='\0';
	for(i=0;i<strlen(IP);i++){
		DeviceInfo[5].value[i]=IP[i];

	}
	DeviceInfo[5].value[i]='\0';
	for(i=0;i<strlen(Mac);i++){
		DeviceInfo[6].value[i]=Mac[i];

	}
	DeviceInfo[6].value[i]='\0';
	for(i=0;i<strlen(Wan_Ip);i++){
		DeviceInfo[7].value[i]=Wan_Ip[i];

	}
	DeviceInfo[7].value[i]='\0';
	for(i=0;i<strlen(SoftVersion);i++){
		DeviceInfo[8].value[i]=SoftVersion[i];

	}
	DeviceInfo[8].value[i]='\0';
	for(i=0;i<strlen(FirmWare);i++){
		DeviceInfo[9].value[i]=FirmWare[i];

	}
	DeviceInfo[9].value[i]='\0';
	for(i=0;i<strlen(HardVersion);i++){
		DeviceInfo[10].value[i]=HardVersion[i];

	}
	DeviceInfo[10].value[i]='\0';	

Readhtml("deviceinfo.html");

}
