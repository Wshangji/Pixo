#ifndef __CONFIG_THINGFLY_H
#define __CONFIG_THINGFLY_H	 

// WiFi设置信息
#define ESP8266_WIFI_INFO		"AT+CWJAP=\"Nanfbunan\",\"wytsw123321\"\r\n"

// EMQX平台地址
#define ESP8266_EMQX_INFO		"AT+CIPSTART=\"TCP\",\"8.130.65.20\",1883\r\n"

//#define mqttUserName			"wumei-smart"
//#define mqttPwd					"P261I5G3RY3MCIGG"
//#define mqttSecret				b"K2IB784BM0O01GG6"
//// 启用授权码则authCode不能为空
//#define authCode				""
		 				    
#endif
