/*
 * ESP8266 connections:
 * Vcc to 3.3v
 * RST to 3.3v
 * CH_PD to 3.3v
 * GND to GND
 * RX to TX
 * TX to RX
 * For programming, connect GPIO 0 to GND 
 */
 
 /* Credit to: 
 *	HTTPS on ESP8266 with follow redirects, chunked encoding support
 *  Version 3.0
 *  Author: Sujay Phadke
 *  Github: @electronicsguy
 *  Copyright (C) 2018 Sujay Phadke <electronicsguy123@gmail.com>
 *  All rights reserved.
 */
 
#include <ESP8266WiFi.h> 
#include "HTTPSRedirect.h"

const char* ssid = "Hello";   //Wi-Fi SSID
const char* password = "helloworld";  //Wi-Fi Password
const char *GScriptId = "AKfycbxZx2s8K2nYBjVNaW3ko_xiH3vFX9siDXZCeu5IAbuIH27E2pgJ";  //Google Script ID
const int dataPostDelay = 3000; 
const char* host = "script.google.com"; 
const char* googleRedirHost = "script.googleusercontent.com";
const int httpsPort =     443; 
HTTPSRedirect client(httpsPort);
String url = String("/macros/s/") + GScriptId + "/exec?";
String data="";

void setup() { 
    Serial.begin(115200); 
    Serial.println("Connecting to wifi: "); 
    Serial.println(ssid); 
    Serial.flush();
    WiFi.begin(ssid, password); 
    while (WiFi.status() != WL_CONNECTED) { 
            delay(500); 
            Serial.print("."); 
    } 
    Serial.println(" IP address: "); 
    Serial.println(WiFi.localIP());
    Serial.print(String("Connecting to ")); 
    Serial.println(host);
    bool flag = false; 
    for (int i=0; i<5; i++){ 
            int retval = client.connect(host, httpsPort); 
            if (retval == 1) { 
                        flag = true; 
                        break; 
            } 
            else 
                    Serial.println("Connection failed. Retrying…"); 
    }
    Serial.println("Connection Status: " + String(client.connected())); 
    Serial.flush(); 
    if (!flag){ 
            Serial.print("Could not connect to server: "); 
            Serial.println(host); 
            Serial.println("Exiting…"); 
            Serial.flush(); 
            return; 
    }
}

void postData(String tag, String value){ 
    if (!client.connected()){ 
            Serial.println("Connecting to client again…"); 
            client.connect(host, httpsPort); 
    } 
    String urlFinal = url + "tag=" + tag + "&value=" + value; 
    client.printRedir(urlFinal, host, googleRedirHost); 
}

void loop() {
	//Initialize String data with blank value.
    data="";
    while(data==""){
      data=Serial.readString();
    }
    postData("SPS", data);
    delay (dataPostDelay);
}
