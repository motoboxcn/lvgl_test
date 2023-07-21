#include <lvgl.h>
#include <ui.h>

// ui_luxiang工作的时候闪烁图标，工作结束后图标常亮
void luxiang_icon_loop()
{
    // 闪烁
    delay(500);
    lv_obj_set_style_blend_mode(ui_luxiang, LV_BLEND_MODE_MULTIPLY, 0);
    delay(500);
    lv_obj_set_style_blend_mode(ui_luxiang, LV_BLEND_MODE_NORMAL, 0);
}

void trip_on()
{
    lv_obj_set_style_blend_mode(ui_luxiang, LV_BLEND_MODE_MULTIPLY, 0);
}

// 改变 ui 样式
void ui_wifi_connect_off()
{
    lv_obj_set_style_blend_mode(ui_weixing, LV_BLEND_MODE_MULTIPLY, 0);
    lv_obj_set_style_blend_mode(ui_websocket, LV_BLEND_MODE_MULTIPLY, 0);
    lv_obj_set_style_blend_mode(ui_wifi, LV_BLEND_MODE_MULTIPLY, 0);
    lv_obj_set_style_blend_mode(ui_luxiang, LV_BLEND_MODE_MULTIPLY, 0);
}

void ui_wifi_connect_on()
{
    // lv_obj_set_style_blend_mode(ui_weixing, LV_BLEND_MODE_NORMAL, 0);
    // lv_obj_set_style_blend_mode(ui_websocket, LV_BLEND_MODE_NORMAL, 0);
    lv_obj_set_style_blend_mode(ui_wifi, LV_BLEND_MODE_NORMAL, 0);
    // lv_obj_set_style_blend_mode(ui_luxiang, LV_BLEND_MODE_NORMAL, 0);
}

void ui_websocket_on()
{
    lv_obj_set_style_blend_mode(ui_websocket, LV_BLEND_MODE_NORMAL, 0);
    Serial.println("Connected to GPS WebSockets server");
}

void ui_gps_on()
{
    lv_obj_set_style_blend_mode(ui_weixing, LV_BLEND_MODE_NORMAL, 0);
}

void ui_gps_off()
{
    lv_obj_set_style_blend_mode(ui_weixing, LV_BLEND_MODE_MULTIPLY, 0);
}

void ui_trip_on()
{
    lv_obj_set_style_blend_mode(ui_luxiang, LV_BLEND_MODE_NORMAL, 0);
}

void ui_trip_off()
{
    lv_obj_set_style_blend_mode(ui_luxiang, LV_BLEND_MODE_MULTIPLY, 0);
}

void init_speed_dashboard()
{
    for (int i = 0; i <= 299; i += 2)
    {
        // speed dashboard
        lv_arc_set_value(ui_speed, i);
        lv_label_set_text_fmt(ui_speed2, "%d", i);
        lv_timer_handler();
        delay(5);
        Serial.println(i);
    }
    for (int j = 299; j >= 0; j -= 2)
    {
        // speed dashboard
        lv_arc_set_value(ui_speed, j);
        lv_label_set_text_fmt(ui_speed2, "%d", j);
        lv_timer_handler();
        delay(5);
        Serial.println(j);
    }
    lv_arc_set_value(ui_speed, 0);
    lv_label_set_text_fmt(ui_speed2, "%d", 0);
    lv_timer_handler();
}