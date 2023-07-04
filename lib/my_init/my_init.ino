#include <lvgl.h>
#include <ui.h>

// ui_luxiang工作的时候闪烁图标，工作结束后图标常亮
void luxiang_icon_loop ()
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


void init_speed_dashboard()
{
    for (int i = 0; i <= 299; i+=1)
    {
        lv_arc_set_value(ui_speed, i);
        lv_label_set_text_fmt(ui_speed2,"%d",i);
        lv_timer_handler();
        Serial.println(i);
    }
    for (int j = 298; j >=0; j--)
    {
        lv_arc_set_value(ui_speed, j);
        lv_label_set_text_fmt(ui_speed2,"%d",j);
        lv_timer_handler();
        Serial.println(j);
    }
}