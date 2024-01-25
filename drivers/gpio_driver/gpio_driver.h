#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

/*********************
 *      INCLUDES
 *********************/

#include <stdint.h>
#include <zephyr/drivers/gpio.h>

/**********************
 *      TYPEDEFS
 **********************/

typedef struct gpio_driver gpio_driver_t;

struct gpio_driver
{
    const struct gpio_dt_spec *driver;

    void (* config_input)(gpio_driver_t * const dev);
    void (* config_output)(gpio_driver_t * const dev);
    void (* set)(gpio_driver_t * const dev);
    void (* reset)(gpio_driver_t * const dev);
};

// Constructor and Deconstructor
void GPIO_DRIVER_Init(gpio_driver_t * const dev,
        void (* input_func)(gpio_driver_t * const dev),
        void (* output_func)(gpio_driver_t * const dev),
        void (* set_func)(gpio_driver_t * const dev),
        void (* reset_func)(gpio_driver_t * const dev));

// Operation

gpio_driver_t *GPIO_DRIVER_Create(const struct gpio_dt_spec *dev_driver);
void GPIO_DRIVER_Destroy(gpio_driver_t * const dev);

#endif