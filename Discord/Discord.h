#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>
#include "SECRET.h"


WiFiClientSecure client;
const char *ssid = SSID;
const char *password = PASSWORD;
const String api_key = API_KEY;

void connect_WIFI() {
    WiFi.begin(ssid, password);
    WiFi.mode(WIFI_STA);
    client.setInsecure();
    Serial.print("Connecting to ");
    Serial.println(ssid);
    while(WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(100);
    }
    Serial.println();
    Serial.print("WIFI Connected");
}

void Send_MSG(String data) {
    HTTPClient https;
    Serial.println("[HTTP] Connecting to Discord...");
    Serial.println("[HTTP] Message: " + data);
    

    if (https.begin(client, api_key)) {  // HTTPS
    // start connection and send HTTP header
    https.addHeader("Content-Type", "application/json");
    int httpCode = https.POST("{\"content\":\"" + data + "\",\"tts\":false}");

    // httpCode will be negative on error
    if (httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
      Serial.print("[HTTP] Status code: ");
      Serial.println(httpCode);

      // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
            String payload = https.getString();
            Serial.print("[HTTP] Response: ");
            Serial.println(payload);
        }
      
        } else {
            Serial.print("[HTTP] Post... failed, error: ");
            Serial.println(https.errorToString(httpCode).c_str());
        }

        https.end();
    } else {
        Serial.printf("[HTTP] Unable to connect\n");
    }
}
