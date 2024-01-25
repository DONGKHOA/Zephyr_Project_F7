#ifndef _SQUARELINE_PROJECT_UI_H
#define _SQUARELINE_PROJECT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

    #include "lvgl.h"

#include "ui_helpers.h"
#include "ui_events.h"
// SCREEN: ui_Screen1
void ui_Screen1_screen_init(void);
extern lv_obj_t *ui_Screen1;
void ui_event_Button1( lv_event_t * e);
extern lv_obj_t *ui_Button1;
extern lv_obj_t *ui_Label2;
void ui_event_Button2( lv_event_t * e);
extern lv_obj_t *ui_Button2;
extern lv_obj_t *ui_Label1;



void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
