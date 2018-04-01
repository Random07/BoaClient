
# Change these if necessary
# compile for linux,set CC = gcc
# compile for Android, set CC = arm-linux-androideabi-gcc -static

CC = arm-linux-androideabi-gcc -static

all:	login.cgi \
	loginerror.cgi \
	languagechange.cgi \
	homepage.cgi \
	basicinfor_deviceinfor.cgi \
	basicinfor_datausage.cgi \
	basicinfor_datalimit.cgi \
	sdcard_sdcard.cgi \
	sdcard_httpshare.cgi \
	driverdownload.cgi \
	sms_devicepart.cgi \
	sms_simpart.cgi \
	sms_settings.cgi \
	settings_netset_dailup.cgi \
	settings_netset_netsearch.cgi \
	settings_netset_apn.cgi \
	settings_wifiset_basic.cgi \
	settings_wifiset_wps.cgi \
	settings_deviceset_account.cgi \
	settings_deviceset_restore.cgi \
	settings_deviceset_reboot.cgi \
    settings_deviceset_reboot_submit.cgi \
    settings_deviceset_restore_submit.cgi \
    settings_netset_apn_change.cgi \
    settings_netset_apn_new.cgi \
    settings_netset_apn_new_submit.cgi \
    settings_wifiset_basic_submit.cgi \
    basicinfor_datalimit_submit.cgi

login.cgi:login.c
	$(CC) -o $@ $^

loginerror.cgi:loginerror.c
	$(CC) -o $@ $^

languagechange.cgi:languagechange.c
	$(CC) -o $@ $^

homepage.cgi:homepage.c
	$(CC) -o $@ $^

basicinfor_deviceinfor.cgi:basicinfor_deviceinfor.c
	$(CC) -o $@ $^

basicinfor_datausage.cgi:basicinfor_datausage.c
	$(CC) -o $@ $^

basicinfor_datalimit.cgi:basicinfor_datalimit.c
	$(CC) -o $@ $^

sdcard_sdcard.cgi:sdcard_sdcard.c
	$(CC) -o $@ $^

sdcard_httpshare.cgi:sdcard_httpshare.c
	$(CC) -o $@ $^

driverdownload.cgi:driverdownload.c
	$(CC) -o $@ $^

sms_devicepart.cgi:sms_devicepart.c
	$(CC) -o $@ $^

sms_simpart.cgi:sms_simpart.c
	$(CC) -o $@ $^

sms_settings.cgi:sms_settings.c
	$(CC) -o $@ $^

settings_netset_dailup.cgi:settings_netset_dailup.c
	$(CC) -o $@ $^

settings_netset_netsearch.cgi:settings_netset_netsearch.c
	$(CC) -o $@ $^

settings_netset_apn.cgi:settings_netset_apn.c
	$(CC) -o $@ $^

settings_wifiset_basic.cgi:settings_wifiset_basic.c
	$(CC) -o $@ $^

settings_wifiset_wps.cgi:settings_wifiset_wps.c
	$(CC) -o $@ $^

settings_deviceset_account.cgi:settings_deviceset_account.c
	$(CC) -o $@ $^

settings_deviceset_restore.cgi:settings_deviceset_restore.c
	$(CC) -o $@ $^

settings_deviceset_reboot.cgi:settings_deviceset_reboot.c
	$(CC) -o $@ $^

settings_deviceset_reboot_submit.cgi:settings_deviceset_reboot_submit.c
	$(CC) -o $@ $^

settings_deviceset_restore_submit.cgi:settings_deviceset_restore_submit.c
	$(CC) -o $@ $^

settings_netset_apn_change.cgi:settings_netset_apn_change.c
	$(CC) -o $@ $^

settings_netset_apn_new.cgi:settings_netset_apn_new.c
	$(CC) -o $@ $^

settings_netset_apn_new_submit.cgi:settings_netset_apn_new_submit.c
	$(CC) -o $@ $^

settings_wifiset_basic_submit.cgi:settings_wifiset_basic_submit.c
	$(CC) -o $@ $^

basicinfor_datalimit_submit.cgi:basicinfor_datalimit_submit.c
	$(CC) -o $@ $^

clean:
	rm -rf *.cgi

move:
	cp *.cgi cgi_bin_to_push
	cp *.html cgi_bin_to_push

pushcgi:
	adb push cgi_bin_to_push/. data/boa/cgi-bin/

pushwww:
	adb push ../www/. data/boa/www/

pushall:
	adb push ../boa vendor/bin/
	adb push ../boa_indexer vendor/bin/
	adb push ../boa.conf data/boa/
	adb push ../mime.types data/boa/
	adb push cgi_bin_to_push/. data/boa/cgi-bin/
	adb push ../www/. data/boa/www/

newpushall:
	adb shell mkdir /data/boa
	adb shell mkdir /data/boa/www/image
	adb shell mkdir /sdcard/boa
	adb push ../boa vendor/bin/
	adb push ../boa_indexer vendor/bin/
	adb push ../boa.conf data/boa/
	adb push ../mime.types data/boa/
	adb push cgi_bin_to_push/. data/boa/cgi-bin/
	adb push ../www/. data/boa/www/
	

