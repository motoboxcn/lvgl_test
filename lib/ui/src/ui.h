// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#ifndef _SQUARELINE_PROJECT_UI_H
#define _SQUARELINE_PROJECT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
  #if __has_include("lvgl.h")
    #include "lvgl.h"
  #elif __has_include("lvgl/lvgl.h")
    #include "lvgl/lvgl.h"
  #else
    #include "lvgl.h"
  #endif
#else
  #include "lvgl.h"
#endif

#include "ui_helpers.h"
#include "ui_events.h"
// SCREEN: ui_Screen1
void ui_Screen1_screen_init(void);
extern lv_obj_t *ui_Screen1;
void ui_event_speed( lv_event_t * e);
extern lv_obj_t *ui_speed;
extern lv_obj_t *ui_speed2;
extern lv_obj_t *ui_Label1;
extern lv_obj_t *ui_haiba;
extern lv_obj_t *ui_suzhou;
extern lv_obj_t *ui_motoRoll;
extern lv_obj_t *ui_rollText;
extern lv_obj_t *ui_luxiang;
extern lv_obj_t *ui_wifi;
extern lv_obj_t *ui_websocket;
extern lv_obj_t *ui_weixing;
extern lv_obj_t *ui_haibaText;
extern lv_obj_t *ui_gpsTime;
extern lv_obj_t *ui_handing;
extern lv_obj_t *ui_handingText;
extern lv_obj_t *ui____initial_actions0;

LV_IMG_DECLARE( ui_img_haiba_png);   // assets/haiba.png
LV_IMG_DECLARE( ui_img_965679087);   // assets/map-b-2.png
LV_IMG_DECLARE( ui_img_1869354606);   // assets/motuoche-diandongche.png
LV_IMG_DECLARE( ui_img_918429721);   // assets/bx-video-recording.png
LV_IMG_DECLARE( ui_img_wifi_png);   // assets/wifi.png
LV_IMG_DECLARE( ui_img_ai70_png);   // assets/ai70.png
LV_IMG_DECLARE( ui_img_weixing_png);   // assets/weixing.png
LV_IMG_DECLARE( ui_img_direction_png);   // assets/direction.png
LV_IMG_DECLARE( ui_img_1753992569);   // assets/motuoche-diandongche-2.png
LV_IMG_DECLARE( ui_img_1743932013);   // assets/wuwifi-2.png

void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
