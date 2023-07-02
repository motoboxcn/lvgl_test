#include <WiFi.h>
#include <TFT_eSPI.h>
#include <ArduinoJson.h>
#include <ArduinoWebsockets.h>


using namespace websockets;


// WiFi 信息
const char *ssid = "motobox.cn";
const char *password = "12345678";
const char *websockets_server_host = "192.168.4.1"; // Enter server adress
const uint16_t websockets_server_port = 80;         // Enter server port
const size_t JSON_BUFFER_SIZE = JSON_OBJECT_SIZE(11) + 320;


WebsocketsClient client;
TFT_eSPI tft = TFT_eSPI();

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


void setup()
{
    // 连接到 WiFi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    // 初始化 TFT 显示器
    tft.init();         // initialize a ST7735S chip, black tab
    tft.setRotation(3); // set rotation to 0
    tft.fillScreen(TFT_BLACK);              // fill the screen with black
    tft.setTextColor(TFT_WHITE, TFT_BLACK); // set text color to white and black background
    tft.setCursor(0, 0);                    // set cursor to top-left corner
    // 连接到 WebSocket 服务器
    bool connected = client.connect(websockets_server_host, websockets_server_port, "/ws/gps");
    if (!connected)
    {
        tft.println("Failed to connect to WebSocket server!");
        return;
    }
    tft.println("Connected to WebSocket server!");
    // run callback when messages are received
    client.onMessage([&](WebsocketsMessage message) {
    // 解析JSON消息
    DynamicJsonDocument jsonBuffer(JSON_BUFFER_SIZE);
    DeserializationError error = deserializeJson(jsonBuffer, message.data());
  
    // 检查解析是否成功
    if (error) {
        tft.println("Failed to parse JSON!");
        return;
    }

    // 获取速度、时间和经纬度、航向、高度
    float speed = jsonBuffer["speed"];
    unsigned long timestamp = jsonBuffer["gps_time"];
    // unix timestamp to human readable time format 2020-01-01 00:00:00
    String time = formatUnixTime(timestamp);
    float latitude = jsonBuffer["latitude"];
    float longitude = jsonBuffer["longitude"];
    float heading = jsonBuffer["heading"];
    float altitude = jsonBuffer["altitude"];

    // 设置字体颜色
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    // 设置字体大小
    tft.setTextSize(2);
    // 坐标
    tft.setCursor(0, 0);

    // 打印时间
    tft.print("Time:");
    tft.println(time);
  
    // 打印速度
    tft.print("Speed: ");
    tft.setTextSize(4);
    tft.println(speed);

    tft.setTextSize(2);
    // 打印经纬度
    tft.print("Latitude: ");
    tft.println(latitude);
    tft.print("Longitude: ");
    tft.println(longitude);
    // 航向
    tft.print("Heading: ");
    tft.println(heading);
    // 高度
    tft.print("Altitude: ");
    tft.println(altitude);

});

}

void loop()
{
    // let the websockets client check for incoming messages
    if (client.available())
    {
        client.poll();
    }
    delay(200);
}
