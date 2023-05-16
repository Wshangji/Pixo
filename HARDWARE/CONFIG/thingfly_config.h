#ifndef __CONFIG_THINGFLY_H
#define __CONFIG_THINGFLY_H	 

// WiFi设置信息
#define ESP8266_WIFI_INFO		"AT+CWJAP=\"Nanfbunan\",\"wytsw123321\"\r\n"

// EMQX平台地址
#define ESP8266_EMQX_INFO		"AT+CIPSTART=\"TCP\",\"8.130.65.20\",1883\r\n"


// 设备信息配置
#define deviceNum				"D1I5I6945N3R"
#define userId 					"1"
#define productId 				"44"
#define firmwareVersion 		1.0
// 经度和纬度可选，如果产品使用设备定位，则必须传
#define latitude				0
#define longitude				0


// mqtt账号配置
#define mqttUserName			"thingfly"
#define mqttPwd					"P261I5G3RY3MCIGG"
//连接 设备mqtt客户端Id格式为：认证类型(E=加密、S=简单) & 设备编号 & 产品ID & 用户ID
#define clientId				"S&" deviceNum "&" productId"&" userId
// 启用授权码则authCode不能为空
#define authCode				""
#define prefix					"/" productId "/" deviceNum
// 订阅的主题	
#define sInfoTopic				prefix "/info/get"
#define sOtaTopic  				prefix "/ota/get"
#define sNtpTopic  				prefix "/ntp/get"
#define sPropertyTopic 			prefix "/property/get"
#define sFunctionTopic  		prefix "/function/get"
#define sPropertyOnline  		prefix "/property-online/get"
#define sFunctionOnline  		prefix "/function-online/get"
#define sMonitorTopic  			prefix "/monitor/get"

// 发布的主题
#define pInfoTopic 				prefix "/info/post"
#define pNtpTopic		 		prefix "/ntp/post"
#define pPropertyTopic 			prefix "/property/post"
#define pFunctionTopic 			prefix "/function/post"
#define pMonitorTopic 			prefix "/monitor/post"
#define pEventTopic 			prefix "/event/post"

#endif
