#include <lvgl.h>
#include <TFT_eSPI.h>
#include <ui.h>
#include <wifi.ino>
#include <my_init.ino>
#include <ArduinoJson.h>
#include <ArduinoWebsockets.h>

/*Don't forget to set Sketchbook location in File/Preferencesto the path of your UI project (the parent foder of this INO file)*/
// #define TFT_MOSI 23
// #define TFT_SCLK 18
// #define TFT_CS   5   // Chip select control pin
// #define TFT_DC   22  // Data Command control pin
// #define TFT_RST  17  // Reset pin (could connect to RST pin)

/*Change to your screen resolution*/
static const uint16_t screenWidth = TFT_HEIGHT;
static const uint16_t screenHeight = TFT_WIDTH;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[screenWidth * screenHeight / 10];

TFT_eSPI tft = TFT_eSPI(); /* TFT instance */

#if LV_USE_LOG != 0
/* Serial debugging */
void my_print(const char *buf)
{
    Serial.printf(buf);
    Serial.flush();
}
#endif


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

void setup()
{
    Serial.begin(9600); /* prepare for possible serial debug */
    String LVGL_Arduino = "Hello Arduino! ";
    LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();
    Serial.println(LVGL_Arduino);
    Serial.println("I am LVGL_Arduino");
    
    lv_init();

#if LV_USE_LOG != 0
    lv_log_register_print_cb(my_print); /* register print function for debugging */
#endif

    tft.begin();        /* TFT init */
    tft.setRotation(1); /* Landscape orientation, flipped */
    lv_disp_draw_buf_init(&draw_buf, buf, NULL, screenWidth * screenHeight / 10);

    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    /*Change the following line to your display resolution*/
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);
    ui_init();
    Serial.println("Setup done");
    for (int i = 0; i <= 299; i+=1)
    {
        lv_arc_set_value(ui_speed, i);
        lv_label_set_text_fmt(ui_speed2,"%d",i);
        lv_timer_handler();
    }
    for (int i = 299; i >=0; i--)
    {
        lv_arc_set_value(ui_speed, i);
        lv_label_set_text_fmt(ui_speed2,"%d",i);
        lv_timer_handler();
    }
    wifi_init();
    Serial.println("Setup done");
}

void loop()
{
    wifi_loop();
    lv_timer_handler(); /* let the GUI do its work */
    delay(5);
}
