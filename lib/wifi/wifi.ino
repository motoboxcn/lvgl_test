#include <WiFi.h>
#include <ArduinoJson.h>
#include <ArduinoWebsockets.h>
#include <lvgl.h>
#include <TFT_eSPI.h>
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
    // 设置系统时区为东八区（北京时间）
    setenv("TZ", "CST-8", 1);
    tzset();

    // 将 UNIX 时间戳转换为 struct tm 结构
    struct tm *tm;
    time_t t = (time_t)timestamp;
    tm = localtime(&t);

    // 格式化日期和时间
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm);

    return String(buffer);
}

// 连接到 WiFi
void connectToWiFi()
{
    WiFi.begin(ssid, password);
    Serial.println();
    Serial.print("Connecting to ");
    Serial.print(ssid);
    for (int i = 0; i < 10; i++)
    {
        if (WiFi.status() == WL_CONNECTED)
        {
            lv_obj_set_style_blend_mode(ui_wifi, LV_BLEND_MODE_NORMAL, 0);
            Serial.println();
            Serial.print("Connected! IP address: ");
            Serial.println(WiFi.localIP());
            break;
        }
        lv_obj_set_style_blend_mode(ui_wifi, LV_BLEND_MODE_MULTIPLY, 0);
        delay(200);
        Serial.print(".");
        lv_timer_handler();
    }
}

WebsocketsClient client;
void all_ws()
{
    // 判断wifi连接还在不在
    if (WiFi.status() != WL_CONNECTED)
    {
        ui_wifi_connect_off();
    }
    else
    {
        ui_wifi_connect_on();
        // 连接到 WebSockets 服务器
        bool gps_ws = client.connect(websockets_server_host, websockets_server_port, "/ws/all");
        if (gps_ws)
        {
            ui_websocket_on();
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
            String lon = jsonBuffer["lon"];
            String lat = jsonBuffer["lat"];

            // 保留整数
            if (time == 0)
            {
                ui_gps_off();
            }
            else
            {
                ui_gps_on();
                // speed
                speed_dashboard(speed);
                // time
                lv_label_set_text_fmt(ui_gpsTime, "%s", formatUnixTime(time).c_str());
                // attitude
                lv_label_set_text_fmt(ui_haibaText, "%dm", altitude);
                // heading
                lv_label_set_text_fmt(ui_handingText, "%d°", heading);
                lv_img_set_angle(ui_handing, heading * 10);
                
                // location
                lv_label_set_text_fmt(ui_suzhou,"%s,%s",lon,lat);

                if (isTripOn)
                {
                    ui_trip_on();
                }
                else{
                    ui_trip_off();
                }; 
            } 
            // set roll
                lv_img_set_angle(ui_motoRoll,roll*10);
                lv_label_set_text_fmt(ui_rollText, "%d°", roll); });
        }
        else
        {
            lv_obj_set_style_blend_mode(ui_websocket, LV_BLEND_MODE_MULTIPLY, 0);
            lv_obj_set_style_blend_mode(ui_weixing, LV_BLEND_MODE_MULTIPLY, 0);
            lv_obj_set_style_blend_mode(ui_luxiang, LV_BLEND_MODE_MULTIPLY, 0);
            Serial.println("GPS WebSockets server connection failed!delay 5s");
            delay(5000);
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
    // 检查 wifi 连接
    if (WiFi.status() != WL_CONNECTED)
    {
        connectToWiFi();
    }
    if (client.available())
    {
        client.poll();
    }
    else
    {
        all_ws();
    }
}