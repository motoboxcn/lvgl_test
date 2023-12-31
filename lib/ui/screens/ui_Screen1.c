// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"

void ui_Screen1_screen_init(void)
{
ui_Screen1 = lv_obj_create(NULL);
lv_obj_clear_flag( ui_Screen1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Screen1, 30, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Screen1, lv_color_hex(0x05915D), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Screen1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_grad_color(ui_Screen1, lv_color_hex(0x055088), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_main_stop(ui_Screen1, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_grad_stop(ui_Screen1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_grad_dir(ui_Screen1, LV_GRAD_DIR_VER, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_speed = lv_arc_create(ui_Screen1);
lv_obj_set_width( ui_speed, 150);
lv_obj_set_height( ui_speed, 150);
lv_obj_set_x( ui_speed, 8 );
lv_obj_set_y( ui_speed, -40 );
lv_obj_set_align( ui_speed, LV_ALIGN_BOTTOM_LEFT );
lv_arc_set_range(ui_speed, 0,299);
lv_arc_set_value(ui_speed, 199);

lv_obj_set_style_bg_color(ui_speed, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_speed, 255, LV_PART_INDICATOR| LV_STATE_DEFAULT);
lv_obj_set_style_bg_grad_color(ui_speed, lv_color_hex(0x0A9F62), LV_PART_INDICATOR | LV_STATE_DEFAULT );

lv_obj_set_style_opa(ui_speed, 0, LV_PART_KNOB| LV_STATE_DEFAULT);

ui_speed2 = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_speed2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_speed2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_speed2, -56 );
lv_obj_set_y( ui_speed2, 8 );
lv_obj_set_align( ui_speed2, LV_ALIGN_CENTER );
lv_label_set_text(ui_speed2,"199");
lv_obj_set_style_text_color(ui_speed2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_speed2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_speed2, &lv_font_montserrat_42, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label1 = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_Label1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label1, -57 );
lv_obj_set_y( ui_Label1, 60 );
lv_obj_set_align( ui_Label1, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label1,"km/h");
lv_obj_set_style_text_color(ui_Label1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label1, &lv_font_montserrat_20, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_haiba = lv_img_create(ui_Screen1);
lv_img_set_src(ui_haiba, &ui_img_haiba_png);
lv_obj_set_width( ui_haiba, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_haiba, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_haiba, 32 );
lv_obj_set_y( ui_haiba, -47 );
lv_obj_set_align( ui_haiba, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_haiba, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_haiba, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_suzhou = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_suzhou, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_suzhou, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_suzhou, 3 );
lv_obj_set_y( ui_suzhou, 97 );
lv_obj_set_align( ui_suzhou, LV_ALIGN_CENTER );
lv_label_set_text(ui_suzhou,"SuZhou");
lv_obj_set_style_text_color(ui_suzhou, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_suzhou, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_suzhou, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_motoRoll = lv_img_create(ui_Screen1);
lv_img_set_src(ui_motoRoll, &ui_img_1869354606);
lv_obj_set_width( ui_motoRoll, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_motoRoll, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_motoRoll, 45 );
lv_obj_set_y( ui_motoRoll, 5 );
lv_obj_set_align( ui_motoRoll, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_motoRoll, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_motoRoll, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_rollText = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_rollText, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_rollText, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_rollText, 102 );
lv_obj_set_y( ui_rollText, 4 );
lv_obj_set_align( ui_rollText, LV_ALIGN_CENTER );
lv_label_set_text(ui_rollText,"3.14°");
lv_obj_set_style_text_color(ui_rollText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_rollText, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_rollText, &lv_font_montserrat_22, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_luxiang = lv_img_create(ui_Screen1);
lv_img_set_src(ui_luxiang, &ui_img_918429721);
lv_obj_set_width( ui_luxiang, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_luxiang, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_luxiang, -118 );
lv_obj_set_y( ui_luxiang, 95 );
lv_obj_set_align( ui_luxiang, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_luxiang, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_luxiang, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_wifi = lv_img_create(ui_Screen1);
lv_img_set_src(ui_wifi, &ui_img_953604683);
lv_obj_set_width( ui_wifi, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_wifi, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_wifi, 121 );
lv_obj_set_y( ui_wifi, -94 );
lv_obj_set_align( ui_wifi, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_wifi, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_wifi, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_websocket = lv_img_create(ui_Screen1);
lv_img_set_src(ui_websocket, &ui_img_lianjie_png);
lv_obj_set_width( ui_websocket, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_websocket, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_websocket, 123 );
lv_obj_set_y( ui_websocket, 97 );
lv_obj_set_align( ui_websocket, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_websocket, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_websocket, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_weixing = lv_img_create(ui_Screen1);
lv_img_set_src(ui_weixing, &ui_img_weixing_png);
lv_obj_set_width( ui_weixing, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_weixing, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_weixing, -119 );
lv_obj_set_y( ui_weixing, -94 );
lv_obj_set_align( ui_weixing, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_weixing, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_weixing, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_haibaText = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_haibaText, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_haibaText, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_haibaText, 92 );
lv_obj_set_y( ui_haibaText, -47 );
lv_obj_set_align( ui_haibaText, LV_ALIGN_CENTER );
lv_label_set_text(ui_haibaText,"31m");
lv_obj_set_style_text_color(ui_haibaText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_haibaText, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_haibaText, &lv_font_montserrat_22, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_gpsTime = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_gpsTime, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_gpsTime, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_gpsTime, -12 );
lv_obj_set_y( ui_gpsTime, -95 );
lv_obj_set_align( ui_gpsTime, LV_ALIGN_CENTER );
lv_label_set_text(ui_gpsTime,"2023-07-03 21:21:30");
lv_obj_set_style_text_color(ui_gpsTime, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_gpsTime, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_gpsTime, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_handing = lv_img_create(ui_Screen1);
lv_img_set_src(ui_handing, &ui_img_direction_png);
lv_obj_set_width( ui_handing, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_handing, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_handing, 27 );
lv_obj_set_y( ui_handing, 56 );
lv_obj_set_align( ui_handing, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_handing, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_handing, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_handingText = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_handingText, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_handingText, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_handingText, 83 );
lv_obj_set_y( ui_handingText, 59 );
lv_obj_set_align( ui_handingText, LV_ALIGN_CENTER );
lv_label_set_text(ui_handingText,"245°");
lv_obj_set_style_text_color(ui_handingText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_handingText, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_handingText, &lv_font_montserrat_22, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_bettery = lv_img_create(ui_Screen1);
lv_img_set_src(ui_bettery, &ui_img_dianliang_png);
lv_obj_set_width( ui_bettery, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_bettery, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_bettery, 94 );
lv_obj_set_y( ui_bettery, -94 );
lv_obj_set_align( ui_bettery, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_bettery, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_bettery, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

lv_obj_add_event_cb(ui_speed, ui_event_speed, LV_EVENT_ALL, NULL);

}
