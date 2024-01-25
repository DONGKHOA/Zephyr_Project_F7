#include "ui.h"
#include "../drivers/gpio_driver/gpio_driver.h"

extern gpio_driver_t *led_driver;


void enable_led(lv_event_t * e)
{
	led_driver->set(led_driver);
}

void disable_led(lv_event_t * e)
{
	led_driver->reset(led_driver);
}
