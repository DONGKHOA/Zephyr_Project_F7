#include <stdio.h>
#include <stdint.h>
#include <zephyr/drivers/display.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <lvgl.h>
#include "../gui/ui.h"

LOG_MODULE_REGISTER(app);

int main(void)
{
	const struct device *display_dev;

	display_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));
	if (!device_is_ready(display_dev)) {
		return 0;
	}
	ui_init();
	ui_Screen1_screen_init();
	lv_task_handler();
	display_blanking_off(display_dev);

    while (1)
    {
		k_msleep(lv_task_handler());
    }
    
    return 0;
}