#include <WiFi.h>
#include <ArduinoJson.h>
#include <ArduinoWebsockets.h>
#include <lvgl.h>
#include <ui.h>
#include <my_init.ino>

using namespace websockets;
// WiFi 信息
const char *ssid = "motobox.cn";
const char *password = "12345678";
const char *websockets_server_host = "192.168.4.1"; // Enter server adress
const uint16_t websockets_server_port = 80;         // Enter server port
const size_t JSON_BUFFER_SIZE = JSON_OBJECT_SIZE(11) + 320;

String formatUnixTime(unsigned long timestamp)
{
    // 将 UNIX 时间戳转换为 struct tm 结构
    struct tm *tm;
    time_t t = (time_t)timestamp;
    tm = localtime(&t);

    // 格式化日期和时间
    char buffer[20];
    // UTC to 北京时间
    tm->tm_hour += 8;
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm);

    return String(buffer);
}

// 连接到 WiFi
void connectToWiFi()
{
    Serial.print("Connecting to ");
    Serial.print(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        lv_obj_set_style_blend_mode(ui_wifi, LV_BLEND_MODE_MULTIPLY, 0);
        Serial.print(".");
        delay(5);
    }
    lv_obj_set_style_blend_mode(ui_wifi, LV_BLEND_MODE_NORMAL, 0);

    Serial.println();
    Serial.print("Connected! IP address: ");
    Serial.println(WiFi.localIP());
}

WebsocketsClient client;
void all_ws()
{
    // 判断wifi连接还在不在
    if (WiFi.status() != WL_CONNECTED)
    {
        lv_obj_set_style_blend_mode(ui_weixing, LV_BLEND_MODE_MULTIPLY, 0);
    }
    else
    {
        lv_obj_set_style_blend_mode(ui_weixing, LV_BLEND_MODE_NORMAL, 0);
        // 连接到 WebSockets 服务器
        bool gps_ws = client.connect(websockets_server_host, websockets_server_port, "/ws/all");
        if (gps_ws)
        {
            lv_obj_set_style_blend_mode(ui_websocket, LV_BLEND_MODE_NORMAL, 0);
            Serial.println("Connected to GPS WebSockets server");
            // run callback when messages are received
            client.onMessage([&](WebsocketsMessage message)
                             {
            // 解析JSON消息
            DynamicJsonDocument jsonBuffer(JSON_BUFFER_SIZE);
            DeserializationError error = deserializeJson(jsonBuffer, message.data());

            // 检查解析是否成功
            if (error)
            {
                Serial.print(F("deserializeJson() failed with code "));
                return;
            }

            int speed = jsonBuffer["speed"];
            int time = jsonBuffer["gps_time"];
            int altitude = jsonBuffer["attitude"];
            int heading = jsonBuffer["heading"];
            int roll =  jsonBuffer["roll"];
            int pitch =  jsonBuffer["pitch"];
            bool isTripOn = jsonBuffer["is_trip_on"];
            String location = jsonBuffer["location"];

            // 保留整数
            if (time == 0)
            {
                lv_obj_set_style_blend_mode(ui_weixing, LV_BLEND_MODE_MULTIPLY, 0);
            }
            else
            {
                lv_obj_set_style_blend_mode(ui_weixing, LV_BLEND_MODE_NORMAL, 0);
                // speed
                lv_arc_set_value(ui_speed, speed);
                lv_label_set_text_fmt(ui_speed2, "%d", speed);
                // time
                lv_label_set_text_fmt(ui_gpsTime, "%s", formatUnixTime(time).c_str());
                // attitude
                lv_label_set_text_fmt(ui_haibaText, "%dm", altitude);
                // heading
                lv_label_set_text_fmt(ui_handingText, "%d°", heading);
                lv_img_set_angle(ui_handing, heading * 10);
                
                // location
                lv_label_set_text_fmt(ui_suzhou,"%s",location);
                if (isTripOn)
                {
                    lv_obj_set_style_blend_mode(ui_luxiang, LV_BLEND_MODE_NORMAL, 0);
                }
                else{
                    lv_obj_set_style_blend_mode(ui_luxiang, LV_BLEND_MODE_MULTIPLY, 0);
                }; 
            } 
            // set roll
                lv_img_set_angle(ui_motoRoll,roll*10);
                lv_label_set_text_fmt(ui_rollText, "%d°", roll); });
        }
        else
        {
            lv_obj_set_style_blend_mode(ui_websocket, LV_BLEND_MODE_MULTIPLY, 0);
            Serial.println("GPS WebSockets server connection failed!");
        }
    }
}

void wifi_init()
{
    // 连接到 WiFi
    connectToWiFi();
    all_ws();
}

void wifi_loop()
{
    if (client.available())
    {
        client.poll();
    }
    else
    {
        all_ws();
    }
}