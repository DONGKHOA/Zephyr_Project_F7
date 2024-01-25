#include "../ui.h"

void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag( ui_Screen1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

    ui_Button1 = lv_btn_create(ui_Screen1);
    lv_obj_set_width( ui_Button1, 100);
    lv_obj_set_height( ui_Button1, 50);
    lv_obj_set_x( ui_Button1, -136 );
    lv_obj_set_y( ui_Button1, -3 );
    lv_obj_set_align( ui_Button1, LV_ALIGN_CENTER );
    lv_obj_add_flag( ui_Button1, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
    lv_obj_clear_flag( ui_Button1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
    lv_obj_set_style_bg_color(ui_Button1, lv_color_hex(0x00FF19), LV_PART_MAIN | LV_STATE_DEFAULT );
    lv_obj_set_style_bg_opa(ui_Button1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

    ui_Label2 = lv_label_create(ui_Screen1);
    lv_obj_set_width( ui_Label2, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height( ui_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_x( ui_Label2, -138 );
    lv_obj_set_y( ui_Label2, -3 );
    lv_obj_set_align( ui_Label2, LV_ALIGN_CENTER );
    lv_label_set_text(ui_Label2,"ON");

    ui_Button2 = lv_btn_create(ui_Screen1);
    lv_obj_set_width( ui_Button2, 100);
    lv_obj_set_height( ui_Button2, 50);
    lv_obj_set_x( ui_Button2, -136 );
    lv_obj_set_y( ui_Button2, 56 );
    lv_obj_set_align( ui_Button2, LV_ALIGN_CENTER );
    lv_obj_add_flag( ui_Button2, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
    lv_obj_clear_flag( ui_Button2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
    lv_obj_set_style_bg_color(ui_Button2, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT );
    lv_obj_set_style_bg_opa(ui_Button2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

    ui_Label1 = lv_label_create(ui_Screen1);
    lv_obj_set_width( ui_Label1, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height( ui_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_x( ui_Label1, -136 );
    lv_obj_set_y( ui_Label1, 57 );
    lv_obj_set_align( ui_Label1, LV_ALIGN_CENTER );
    lv_label_set_text(ui_Label1,"OFF");

    lv_obj_add_event_cb(ui_Button1, ui_event_Button1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button2, ui_event_Button2, LV_EVENT_ALL, NULL);

}
