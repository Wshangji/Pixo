#ifndef __CONFIG_THINGFLY_H
#define __CONFIG_THINGFLY_H	 

// WiFi������Ϣ
#define ESP8266_WIFI_INFO		"AT+CWJAP=\"Nanfbunan\",\"wytsw123321\"\r\n"

// EMQXƽ̨��ַ
#define ESP8266_EMQX_INFO		"AT+CIPSTART=\"TCP\",\"8.130.65.20\",1883\r\n"


// �豸��Ϣ����
#define deviceNum				"D1I5I6945N3R"
#define userId 					"1"
#define productId 				"44"
#define firmwareVersion 		1.0
// ���Ⱥ�γ�ȿ�ѡ�������Ʒʹ���豸��λ������봫
#define latitude				0
#define longitude				0


// mqtt�˺�����
#define mqttUserName			"thingfly"
#define mqttPwd					"P261I5G3RY3MCIGG"
//���� �豸mqtt�ͻ���Id��ʽΪ����֤����(E=���ܡ�S=��) & �豸��� & ��ƷID & �û�ID
#define clientId				"S&" deviceNum "&" productId"&" userId
// ������Ȩ����authCode����Ϊ��
#define authCode				""
#define prefix					"/" productId "/" deviceNum
// ���ĵ�����	
#define sInfoTopic				prefix "/info/get"
#define sOtaTopic  				prefix "/ota/get"
#define sNtpTopic  				prefix "/ntp/get"
#define sPropertyTopic 			prefix "/property/get"
#define sFunctionTopic  		prefix "/function/get"
#define sPropertyOnline  		prefix "/property-online/get"
#define sFunctionOnline  		prefix "/function-online/get"
#define sMonitorTopic  			prefix "/monitor/get"

// ����������
#define pInfoTopic 				prefix "/info/post"
#define pNtpTopic		 		prefix "/ntp/post"
#define pPropertyTopic 			prefix "/property/post"
#define pFunctionTopic 			prefix "/function/post"
#define pMonitorTopic 			prefix "/monitor/post"
#define pEventTopic 			prefix "/event/post"

#endif
