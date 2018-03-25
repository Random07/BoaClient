#include "define.h"

int main()
{
	char *req_method;
	char StringFromWeb[1024];
	char StringFromJava[1024];
	char NameFromWeb[30];
	char PassFromWeb[30];
	char NameInDevice[30];
	char PassInDevice[30];
	int i = 0;
	int j = 0;

	req_method = getenv("REQUEST_METHOD");
	getcgidata(stdin,req_method,StringFromWeb);

	if(!GetindexstrfromWeb(StringFromWeb,"Username=",NameFromWeb))
	{
		logmessageprintf("Can't find Username");
		return 0;
	}
	if(!GetindexstrfromWeb(StringFromWeb,"Password=",PassFromWeb))
	{
		logmessageprintf("Can't find Username");
		return 0;
	}

//	Socketwithjavaserver("Request|Login",StringFromJava);
	char StringFromJavatest[]="Confirm|Login|Admin|123456";

	GetindexstrfromJS(StringFromJavatest,3,NameInDevice);
	GetindexstrfromJS(StringFromJavatest,4,PassInDevice);

		
	if(!strncmp(NameInDevice,NameFromWeb,strlen(NameInDevice)) && !strncmp(PassInDevice,PassFromWeb,strlen(PassInDevice)))
	{	
		webheader();
		puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/basicconfig/basicconfig.cgi\">");
		webtail();
	}else{
		webheader();
		puts("<meta http-equiv=\"Refresh\" content=\"0;URL=/cgi-bin/login/loginerror.cgi\">");
		webtail();
	}

	return 0;
}
