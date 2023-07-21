# 1 "/var/folders/28/z1jd9trj1xv9ffjy7b6x0wf80000gp/T/tmphe1x55yw"
#include <Arduino.h>
# 1 "/Users/zhoushoujian/lvgl_test/src/main.ino"
#include <ArduinoWebsockets.h>
#include <lvgl.h>
#include <TFT_eSPI.h>
#include <wifi.ino>



#define TFT_MOSI 23
#define TFT_SCLK 18
#define TFT_CS 5
#define TFT_DC 22
#define TFT_RST 17


static const uint16_t screenWidth = TFT_HEIGHT;
static const uint16_t screenHeight = TFT_WIDTH;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[screenWidth * screenHeight / 10];

TFT_eSPI tft = TFT_eSPI();

#if LV_USE_LOG != 0
void my_print(const char *buf);
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p);
void initSerial();
void setup();
void loop();
#line 25 "/Users/zhoushoujian/lvgl_test/src/main.ino"
void my_print(const char *buf)
{
    Serial.printf(buf);
    Serial.flush();
}
#endif



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

void initSerial()
{
    Serial.begin(9600);
    String LVGL_Arduino = "Hello Arduino! ";
    LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();
    Serial.println(LVGL_Arduino);
    Serial.println("I am LVGL_Arduino");
}

void setup()
{
    initSerial();

    lv_init();

#if LV_USE_LOG != 0
    lv_log_register_print_cb(my_print);
#endif

    tft.begin();
    tft.setRotation(1);


    lv_disp_draw_buf_init(&draw_buf, buf, NULL, screenWidth * screenHeight / 10);

    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);

    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);


    ui_init();
    init_speed_dashboard();
    wifi_init();
    Serial.println("Setup done");
}

void loop()
{
    wifi_loop();
    lv_timer_handler();
    delay(5);
}