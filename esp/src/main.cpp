#include <Arduino.h>
#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <Hash.h>
#include <SocketIOclient.h>
#include <WebSocketsClient.h>
#include "game-api.h"
#include "server-client.h"
void error_handler(const size_t &error_nr) {
}

std::shared_ptr<ServerClient> client;
std::shared_ptr<GameApi> game;


void setup() {
    pinMode(0, INPUT);
    // USE_SERIAL.begin(921600);
    USE_SERIAL.begin(9600);

    // Serial.setDebugOutput(true);
    USE_SERIAL.setDebugOutput(true);

    USE_SERIAL.println();
    USE_SERIAL.println();
    USE_SERIAL.println();

    for (uint8_t t = 4; t > 0; t--) {
        USE_SERIAL.printf("[SETUP] BOOT WAIT %d...\n", t);
        USE_SERIAL.flush();
        delay(1000);
    }
    client = std::make_shared<ServerClient>("multimedia_plastek", "123454321", "192.168.0.21", 8000);
}
bool first = true;
void loop() {
    // if (first) {
    //     first = false;
        
    //     // USE_SERIAL.print("[HTTP] Requesting setting...");
    //     // auto raw_settings = client->RequestSettings(this_board_id);
    //     // while (raw_settings == String()) {
    //     //     USE_SERIAL.print(".");
    //     //     raw_settings = client->RequestSettings(this_board_id);
    //     //     delay(500);
    //     // }
    //     // StaticJsonDocument<SIZE_SETTINGS_JSON> doc;
    //     // deserializeJson(doc, raw_settings);
    //     // Settings set(doc);

    //     USE_SERIAL.println("==============================================");

    //     // game = std::make_shared<GameApi>(set);
    //     // client->game_id = game->id;
    //     // USE_SERIAL.println();
    //     // USE_SERIAL.println("[GAME] Game Initialized");
    // }

    
    client->loop();

   // if (!digitalRead(0)){
    //    Serial.println("huj dup cycki");
    //    client->send_message();
    //}

    
    // while (game->status != GameStatus_Finished) {
    //     if (not client->JoinedGame()) return;
    //     client->loop();
    //     game->loop();
      
    // }
    // first = true;
}








// #include <Arduino.h>
// #include <ArduinoJson.h>
// #include <ESP8266HTTPClient.h>
// #include <ESP8266WiFi.h>
// #include <ESP8266WiFiMulti.h>
// #include <Hash.h>
// #include <SocketIOclient.h>
// #include <WebSocketsClient.h>
// #include "game-api.h"
// #include "server-client.h"
// // void error_handler(const size_t &error_nr) {
// // }

// WebSocketsClient webSocket;
// ESP8266WiFiMulti WiFiMulti;
// SocketIOclient socketIO;

// void event_callback(socketIOmessageType_t type, uint8_t *payload, size_t length) {
//     socketIOmessageType_t status = type;
//     switch (type) {
//         case sIOtype_DISCONNECT:
//             USE_SERIAL.printf("[IOc] Disconnected!\n");
//             bool connection_initialied = false;
//             break;
//         case sIOtype_CONNECT:
//             USE_SERIAL.printf("[IOc] Connected to url: %s\n", payload);

//             // join default namespace (no auto join in Socket.IO V3)
//             socketIO.send(sIOtype_CONNECT, "/esp");
//             // USE_SERIAL.printf("[WEBSOCKETIO] First connection message: %s.\n", out.c_str());
//             break;
//         case sIOtype_EVENT:
//             USE_SERIAL.printf("[IOc] get event: %s\n", payload);
//             //todo: if gevent is "game_loop"
//             break;
//         case sIOtype_ACK:
//             USE_SERIAL.printf("[IOc] get ack: %u\n", length);
//             hexdump(payload, length);
//             break;
//         case sIOtype_ERROR:
//             USE_SERIAL.printf("[IOc] get error: %u\n", length);
//             hexdump(payload, length);
//             break;
//         case sIOtype_BINARY_EVENT:
//             USE_SERIAL.printf("[IOc] get binary: %u\n", length);
//             hexdump(payload, length);
//             break;
//         case sIOtype_BINARY_ACK:
//             USE_SERIAL.printf("[IOc] get binary ack: %u\n", length);
//             hexdump(payload, length);
//             break;
//     }
// }

// void setup() {
//     Serial.begin(9600);

//     String stassid = "multimedia_plastek";
//     String stapsk = "123454321";
//     String server_ip = "192.168.0.21";
//     uint16 server_port = 8000;


//     if (WiFi.getMode() & WIFI_AP) {
//         WiFi.softAPdisconnect(true);
//     }

//     WiFiMulti.addAP(stassid.c_str(), stapsk.c_str());

//     // WiFi.disconnect();
//     while (WiFiMulti.run() != WL_CONNECTED) {
//         delay(100);
//     }

//     String ip = WiFi.localIP().toString();
//     USE_SERIAL.printf("[SETUP] WiFi Connected %s\n", ip.c_str());;
//     USE_SERIAL.printf("[WEBSOCKETIO] Host ip: %s", server_ip.c_str());

//     socketIO.begin(server_ip, server_port, "/socket.io/?EIO=4");

//     socketIO.onEvent(socketIOEvent);



//     // USE_SERIAL.begin(921600);
//     // USE_SERIAL.begin(9600);

//     // // Serial.setDebugOutput(true);
//     // USE_SERIAL.setDebugOutput(true);

//     // USE_SERIAL.println();
//     // USE_SERIAL.println();
//     // USE_SERIAL.println();

//     // for (uint8_t t = 4; t > 0; t--) {
//     //     USE_SERIAL.printf("[SETUP] BOOT WAIT %d...\n", t);
//     //     USE_SERIAL.flush();
//     //     delay(1000);
//     // }
// }
// bool first = true;
// void loop() {
//     // if (first) {
//     //     first = false;
//     //     client = std::make_shared<ServerClient>("multimedia_plastek", "123454321", "192.168.0.21", 8000);
//     //     USE_SERIAL.print("[HTTP] Requesting setting...");
//     //     auto raw_settings = client->RequestSettings(this_board_id);
//     //     while (raw_settings == String()) {
//     //         USE_SERIAL.print(".");
//     //         raw_settings = client->RequestSettings(this_board_id);
//     //         delay(500);
//     //     }
//     //     StaticJsonDocument<SIZE_SETTINGS_JSON> doc;
//     //     deserializeJson(doc, raw_settings);
//     //     Settings set(doc);

//     //     USE_SERIAL.println("==============================================");

//     //     game = std::make_shared<GameApi>(set);
//     //     client->game_id = game->id;
//     //     USE_SERIAL.println();
//     //     USE_SERIAL.println("[GAME] Game Initialized");
//     // }
    
//     // while (game->status != GameStatus_Finished) {
//     //     if (not client->JoinedGame()) return;
//     //     client->loop();
//     //     game->loop(); 
      
//     // }
//     // first = true;
// }
