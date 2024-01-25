#include <stdio.h>
#include <stdint.h>
#include <zephyr/drivers/display.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <lvgl.h>
#include "../gui/ui.h"
#include "../drivers/gpio_driver/gpio_driver.h"

LOG_MODULE_REGISTER(app);
#define NODE_LED DT_ALIAS(led0)

static struct gpio_dt_spec led = GPIO_DT_SPEC_GET(NODE_LED, gpios);

gpio_driver_t *led_driver;

int main(void)
{

	led_driver = GPIO_DRIVER_Create(&led);
	led_driver->config_output(led_driver);

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