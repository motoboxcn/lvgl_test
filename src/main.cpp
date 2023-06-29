#include <WiFi.h>
#include <TFT_eSPI.h>
#include <lvgl.h>
#include <ArduinoJson.h>
#include <ArduinoWebsockets.h>

// WiFi 信息
const char *ssid = "your_SSID";
const char *password = "your_password";

// WebSocket 服务器地址
const char *websockets_server_host = "192.168.4.1"; // Enter server adress
const uint16_t websockets_server_port = 80;         // Enter server port

using namespace websockets;
WebsocketsClient client;

// TFT 配置
TFT_eSPI tft = TFT_eSPI();
#define TFT_WIDTH 240
#define TFT_HEIGHT 320

// LVGL 配置
lv_disp_draw_buf_t draw_buf;
lv_color_t buf[TFT_WIDTH * 10];

// JSON 解析缓冲区大小
const size_t JSON_BUFFER_SIZE = JSON_OBJECT_SIZE(11) + 320;

// GPS 数据结构
struct GPSData
{
    uint32_t gps_time;
    char status;
    float heading;
    int hight;
    char high_tube[10];
    char lon_direction[2];
    char lat_direction[2];
    float longitude;
    float latitude;
    bool is_gps_normal;
    float speed;
};

GPSData gpsData;

/* Display flushing */
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    tft.pushColors((uint16_t *)&color_p->full, w * h, true);
    tft.endWrite();

    lv_disp_flush_ready(disp);
}

void webSocketEvent()
{
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
    tft.init();
    tft.setRotation(0);

    // 初始化 LVGL
    lv_init();
    lv_disp_draw_buf_init(&draw_buf, buf, NULL, TFT_WIDTH * 10);

    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = TFT_WIDTH;
    disp_drv.ver_res = TFT_HEIGHT;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

     /*获取LVGL版本信息*/
    String LVGL_Arduino = "Hello LVGL! ";
    LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch(); //版本
    lv_obj_t *label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, LVGL_Arduino.c_str());
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0); //居中显示


    // lvgl 显示 ip 地址 以及连接状态
    String ip = "IP: ";
    ip += WiFi.localIP().toString();
    lv_obj_t *label_ip = lv_label_create(lv_scr_act());
    lv_label_set_text(label_ip, ip.c_str());
    lv_obj_align(label_ip, LV_ALIGN_CENTER, 0, 0);

    // 连接到 WebSocket 服务器
    bool connected = client.connect(websockets_server_host, websockets_server_port, "/ws/gps");
    if (connected)
    {
        // lvgl 显示连接状态
        lv_obj_t *label_status = lv_label_create(lv_scr_act());
        lv_label_set_text(label_status, "Connected");
        lv_obj_align(label_status, LV_ALIGN_CENTER, 0, 0);
    }
    else
    {
        // lvgl 显示连接状态
        lv_obj_t *label_status = lv_label_create(lv_scr_act());
        lv_label_set_text(label_status, "Disconnected");
        lv_obj_align(label_status, LV_ALIGN_CENTER, 0, 0);
    }
    client.onMessage([&](WebsocketsMessage message) {
        // lvgl 循环打印数据
        lv_obj_t *label = lv_label_create(lv_scr_act());
        lv_label_set_text(label, message.data().c_str());
        lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
    });
}

void loop()
{
    if (client.available())
    {
        client.poll();
    }
    lv_timer_handler();
    delay(5);
}
