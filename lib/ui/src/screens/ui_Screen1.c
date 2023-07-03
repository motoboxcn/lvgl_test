// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"

void ui_Screen1_screen_init(void)
{
ui_Screen1 = lv_obj_create(NULL);
lv_obj_clear_flag( ui_Screen1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Screen1, 20, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Screen1, lv_color_hex(0x5B5B5B), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Screen1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_speed = lv_arc_create(ui_Screen1);
lv_obj_set_width( ui_speed, 150);
lv_obj_set_height( ui_speed, 150);
lv_obj_set_x( ui_speed, 10 );
lv_obj_set_y( ui_speed, -10 );
lv_obj_set_align( ui_speed, LV_ALIGN_BOTTOM_LEFT );
lv_arc_set_range(ui_speed, 0,299);
lv_arc_set_value(ui_speed, 199);

lv_obj_set_style_arc_color(ui_speed, lv_color_hex(0x40FFDF), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_arc_opa(ui_speed, 255, LV_PART_INDICATOR| LV_STATE_DEFAULT);

lv_obj_set_style_opa(ui_speed, 0, LV_PART_KNOB| LV_STATE_DEFAULT);

ui_speed2 = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_speed2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_speed2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_speed2, -74 );
lv_obj_set_y( ui_speed2, 0 );
lv_obj_set_align( ui_speed2, LV_ALIGN_CENTER );
lv_label_set_text(ui_speed2,"199");
lv_obj_set_style_text_color(ui_speed2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_speed2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_speed2, &lv_font_montserrat_42, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label1 = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_Label1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label1, -75 );
lv_obj_set_y( ui_Label1, 50 );
lv_obj_set_align( ui_Label1, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label1,"km/h");
lv_obj_set_style_text_color(ui_Label1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label1, &lv_font_montserrat_20, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_haiba = lv_img_create(ui_Screen1);
lv_img_set_src(ui_haiba, &ui_img_haiba_png);
lv_obj_set_width( ui_haiba, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_haiba, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_haiba, 35 );
lv_obj_set_y( ui_haiba, -40 );
lv_obj_set_align( ui_haiba, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_haiba, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_haiba, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_location = lv_img_create(ui_Screen1);
lv_img_set_src(ui_location, &ui_img_965679087);
lv_obj_set_width( ui_location, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_location, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_location, -37 );
lv_obj_set_y( ui_location, 72 );
lv_obj_set_align( ui_location, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_location, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_location, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_suzhou = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_suzhou, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_suzhou, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_suzhou, 11 );
lv_obj_set_y( ui_suzhou, 72 );
lv_obj_set_align( ui_suzhou, LV_ALIGN_CENTER );
lv_label_set_text(ui_suzhou,"SuZhou");
lv_obj_set_style_text_color(ui_suzhou, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_suzhou, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_suzhou, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_motoRoll = lv_img_create(ui_Screen1);
lv_img_set_src(ui_motoRoll, &ui_img_1869354606);
lv_obj_set_width( ui_motoRoll, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_motoRoll, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_motoRoll, 33 );
lv_obj_set_y( ui_motoRoll, 4 );
lv_obj_set_align( ui_motoRoll, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_motoRoll, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_motoRoll, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_rollText = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_rollText, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_rollText, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_rollText, 106 );
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
lv_obj_set_x( ui_luxiang, -141 );
lv_obj_set_y( ui_luxiang, 70 );
lv_obj_set_align( ui_luxiang, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_luxiang, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_luxiang, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_wifi = lv_img_create(ui_Screen1);
lv_img_set_src(ui_wifi, &ui_img_wifi_png);
lv_obj_set_width( ui_wifi, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_wifi, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_wifi, 143 );
lv_obj_set_y( ui_wifi, -73 );
lv_obj_set_align( ui_wifi, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_wifi, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_wifi, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_websocket = lv_img_create(ui_Screen1);
lv_img_set_src(ui_websocket, &ui_img_ai70_png);
lv_obj_set_width( ui_websocket, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_websocket, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_websocket, 142 );
lv_obj_set_y( ui_websocket, 73 );
lv_obj_set_align( ui_websocket, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_websocket, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_websocket, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_weixing = lv_img_create(ui_Screen1);
lv_img_set_src(ui_weixing, &ui_img_weixing_png);
lv_obj_set_width( ui_weixing, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_weixing, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_weixing, -142 );
lv_obj_set_y( ui_weixing, -70 );
lv_obj_set_align( ui_weixing, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_weixing, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_weixing, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_haibaText = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_haibaText, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_haibaText, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_haibaText, 105 );
lv_obj_set_y( ui_haibaText, -39 );
lv_obj_set_align( ui_haibaText, LV_ALIGN_CENTER );
lv_label_set_text(ui_haibaText,"31m");
lv_obj_set_style_text_color(ui_haibaText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_haibaText, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_haibaText, &lv_font_montserrat_22, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_gpsTime = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_gpsTime, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_gpsTime, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_gpsTime, 50 );
lv_obj_set_y( ui_gpsTime, -70 );
lv_obj_set_align( ui_gpsTime, LV_ALIGN_CENTER );
lv_label_set_text(ui_gpsTime,"2023-07-03 21:21");
lv_obj_set_style_text_color(ui_gpsTime, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_gpsTime, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_gpsTime, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_handing = lv_img_create(ui_Screen1);
lv_img_set_src(ui_handing, &ui_img_direction_png);
lv_obj_set_width( ui_handing, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_handing, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_handing, 31 );
lv_obj_set_y( ui_handing, 47 );
lv_obj_set_align( ui_handing, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_handing, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_handing, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_handingText = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_handingText, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_handingText, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_handingText, 105 );
lv_obj_set_y( ui_handingText, 43 );
lv_obj_set_align( ui_handingText, LV_ALIGN_CENTER );
lv_label_set_text(ui_handingText,"245°");
lv_obj_set_style_text_color(ui_handingText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_handingText, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_handingText, &lv_font_montserrat_22, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_add_event_cb(ui_speed, ui_event_speed, LV_EVENT_ALL, NULL);

}
