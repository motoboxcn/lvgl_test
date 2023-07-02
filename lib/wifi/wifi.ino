#include <WiFi.h>
#include <ArduinoJson.h>
#include <ArduinoWebsockets.h>
#include <lvgl.h>
#include <ui.h>

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
        Serial.print(".");
        delay(1000);
    }

    Serial.println();
    Serial.print("Connected! IP address: ");
    Serial.println(WiFi.localIP());
}

WebsocketsClient client_gps;
void gps_ws()
{
    // 连接到 WebSockets 服务器
    bool gps_ws = client_gps.connect(websockets_server_host, websockets_server_port, "/ws/gps");
    if (gps_ws)
    {
        Serial.println("Connected to GPS WebSockets server");
        // run callback when messages are received
        client_gps.onMessage([&](WebsocketsMessage message)
                         {
    // 解析JSON消息
    DynamicJsonDocument jsonBuffer(JSON_BUFFER_SIZE);
    DeserializationError error = deserializeJson(jsonBuffer, message.data());
  
    // 检查解析是否成功
    if (error) {
        Serial.print(F("deserializeJson() failed with code "));
        return;
    }

    // 获取速度给 lv label 赋值
    String speed = jsonBuffer["speed"];
    // 保留整数
    speed = speed.substring(0, speed.indexOf("."));
    // 高度
    String altitude = jsonBuffer["hight"];
    lv_arc_set_value(ui_speed, static_cast<int>(speed.toInt()));
    lv_label_set_text_fmt(ui_speed2,"%s",static_cast<String>(speed)); 
    Serial.printf("speed:%s\n",static_cast<String>(speed));
    Serial.printf("altitude:%s\n",static_cast<String>(altitude));
    });
    }
    else
    {
        Serial.println("GPS WebSockets server connection failed!");
    }
}
WebsocketsClient client_gyro;
void gyro_ws()
{
    // 连接到 WebSockets 服务器
    bool gyro_ws = client_gyro.connect(websockets_server_host, websockets_server_port, "/ws/gyro");
    if (gyro_ws)
    {
        Serial.println("Connected to Gyro WebSockets server");
        // run callback when messages are received
        client_gyro.onMessage([&](WebsocketsMessage message)
                         {
       // 解析JSON消息
    DynamicJsonDocument jsonBuffer(JSON_BUFFER_SIZE);
    DeserializationError error = deserializeJson(jsonBuffer, message.data());
    // 检查解析是否成功
    if (error) {
        Serial.print(F("deserializeJson() failed with code "));
        return;
    }
    String roll = jsonBuffer["Roll"];
    // 保留整数
    roll = roll.substring(0, roll.indexOf("."));
    // 更新 LVGL 控件
    lv_label_set_text_fmt(ui_roll, "%d", static_cast<int>(roll.toInt()));
    lv_img_set_angle(ui_moto, static_cast<int>(roll.toInt()*2));
    Serial.printf("roll:%s\n",static_cast<String>(roll));
     });
    }
    else
    {
        Serial.println("Gyro WebSockets server connection failed!");
    }

}

void wifi_init()
{
    // 连接到 WiFi
    connectToWiFi();
    gps_ws();
    gyro_ws();
}

void wifi_loop()
{
    if (client_gyro.available())
    {
        client_gyro.poll();
    }
    if (client_gps.available())
    {
        client_gps.poll();
    }
}