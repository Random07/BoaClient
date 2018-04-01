#include "define.h"

int main()
{
	char StringFromJava[1024];
	int i;
	int j;
	char tempvalue[]="&nbsp;";
	char temptotalnum[2];
	int totalnum;
	char tempindex[2];
	char tempDeviceName[64];
	char tempMAC[64];
	char tempIP[64];

	Readcomminforfromjava();


	Socketwithjavaserver("Request|Connect_Customer",StringFromJava);
	//char StringFromJavatest[]="Confirm|Connect_Customer|TotalNum|3|1|DeviceNameA|MACA|IPA|2|DeviceNameB|MACB|IPB|3|DeviceNameC|MACC|IPC";

	for(i=0;i<10;i++)
	{
		for(j=0;j<strlen(tempvalue);j++)
		{
			ConnCustInfor[i].index.value[j]=tempvalue[j];
		}
		ConnCustInfor[i].index.value[j]='\0';

		for(j=0;j<strlen(tempvalue);j++)
		{
			ConnCustInfor[i].DeviceName.value[j]=tempvalue[j];
		}
		ConnCustInfor[i].DeviceName.value[j]='\0';

		for(j=0;j<strlen(tempvalue);j++)
		{
			ConnCustInfor[i].MAC.value[j]=tempvalue[j];
		}
		ConnCustInfor[i].MAC.value[j]='\0';

		for(j=0;j<strlen(tempvalue);j++)
		{
			ConnCustInfor[i].IP.value[j]=tempvalue[j];
		}
		ConnCustInfor[i].IP.value[j]='\0';
	}

	GetindexstrfromJS(StringFromJava,4,temptotalnum);
	totalnum =(int)(temptotalnum[0]-'0');

	for(i=0;i<totalnum;i++)
	{	
		GetindexstrfromJS(StringFromJavatest,(5+i*4),tempindex);
		GetindexstrfromJS(StringFromJavatest,(6+i*4),tempDeviceName);
		GetindexstrfromJS(StringFromJavatest,(7+i*4),tempMAC);
		GetindexstrfromJS(StringFromJavatest,(8+i*4),tempIP);

		for(j=0;j<strlen(tempindex);j++)
		{
			ConnCustInfor[i].index.value[j]= tempindex[j];
		}
		ConnCustInfor[i].index.value[j]='\0';

		for(j=0;j<strlen(tempDeviceName);j++)
		{
			ConnCustInfor[i].DeviceName.value[j]= tempDeviceName[j];
		}
		ConnCustInfor[i].DeviceName.value[j]='\0';

		for(j=0;j<strlen(tempMAC);j++)
		{
			ConnCustInfor[i].MAC.value[j]= tempMAC[j];
		}
		ConnCustInfor[i].MAC.value[j]='\0';

		for(j=0;j<strlen(tempIP);j++)
		{
			ConnCustInfor[i].IP.value[j]= tempIP[j];
		}
		ConnCustInfor[i].IP.value[j]='\0';
	}
	
	Readhtml("basicconfig.html");

return 0;
}
