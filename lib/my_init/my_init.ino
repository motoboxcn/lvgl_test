#include <lvgl.h>
#include <ui.h>

// wifi连接时候闪烁图标，连接成功后图标常亮
void wifi_icon_loop ()
{
    if (WiFi.status() == WL_CONNECTED)
    {
        lv_obj_set_style_blend_mode(ui_wifi, LV_BLEND_MODE_MULTIPLY, 0);
    }
    else
    {
        // 闪烁
        delay(500);
        lv_obj_set_style_blend_mode(ui_wifi, LV_BLEND_MODE_MULTIPLY, 0);
        delay(500);
        lv_obj_set_style_blend_mode(ui_wifi, LV_BLEND_MODE_NORMAL, 0);
    }
}

// websocket连接时候闪烁图标，连接成功后图标常亮
void ws_icon_loop ()
{
    // 闪烁
    delay(500);
    lv_obj_set_style_blend_mode(ui_websocket, LV_BLEND_MODE_MULTIPLY, 0);
    delay(500);
    lv_obj_set_style_blend_mode(ui_websocket, LV_BLEND_MODE_NORMAL, 0);
}

// ui_luxiang工作的时候闪烁图标，工作结束后图标常亮
void luxiang_icon_loop ()
{
    // 闪烁
    delay(500);
    lv_obj_set_style_blend_mode(ui_luxiang, LV_BLEND_MODE_MULTIPLY, 0);
    delay(500);
    lv_obj_set_style_blend_mode(ui_luxiang, LV_BLEND_MODE_NORMAL, 0);
}


