/*********************
 *      INCLUDES
 *********************/

#include "gpio_driver.h"
#include <stdlib.h>

static uint8_t ret = 0;

/**
 * The function `GPIO_DRIVER_Init` initializes member function pointers of a `gpio_driver_t` struct
 * with the provided input, output, set, and reset functions.
 * 
 * @param dev A pointer to a structure of type gpio_driver_t, which represents a GPIO driver.
 * @param input_func A function pointer that points to a function responsible for configuring the GPIO
 * pin as an input.
 * @param output_func A function pointer that points to a function that configures the GPIO pin as an
 * output.
 * @param set_func The `set_func` parameter is a function pointer that points to a function that sets
 * the GPIO pin to a high state. This function will be called when the `set` member function of the
 * `gpio_driver_t` structure is invoked.
 * @param reset_func The `reset_func` parameter is a function pointer that points to a function that
 * will be called to reset the GPIO pin. This function should take a `gpio_driver_t` pointer as a
 * parameter and return void.
 */
void GPIO_DRIVER_Init(gpio_driver_t * const dev,
        void (* input_func)(gpio_driver_t * const dev),
        void (* output_func)(gpio_driver_t * const dev),
        void (* set_func)(gpio_driver_t * const dev),
        void (* reset_func)(gpio_driver_t * const dev)){
    
    // Initialize member function pointers
    dev->config_input = input_func;
    dev->config_output = output_func;
    dev->set = set_func;
    dev->reset = reset_func;
}

/**
 * The function configures a GPIO pin as an input with a pull-up resistor.
 * 
 * @param dev The "dev" parameter is a pointer to a structure of type "gpio_driver_t". This structure
 * contains information about the GPIO driver, such as the port and pin number.
 * 
 * @return In this code snippet, the function `GPIO_CONFIG_Input` returns nothing (void).
 */
void GPIO_CONFIG_Input(gpio_driver_t * const dev){
    if (!device_is_ready(dev->driver->port))
    {
        return;
    }
    
    ret = gpio_pin_configure(dev->driver->port, dev->driver->pin, 
                    GPIO_PULL_UP | GPIO_INPUT);
    
    if (ret < 0)
    {
        return;
    }
}

/**
 * The function configures a GPIO pin as an output with active low logic level.
 * 
 * @param dev The "dev" parameter is a pointer to a structure of type "gpio_driver_t". This structure
 * likely contains information about the GPIO driver, such as the port and pin number to configure.
 * 
 * @return In this code snippet, the function `GPIO_CONFIG_Output` returns nothing (void).
 */
void GPIO_CONFIG_Output(gpio_driver_t * const dev){
    if (!device_is_ready(dev->driver->port))
    {
        return;
    }
    
    ret = gpio_pin_configure(dev->driver->port, dev->driver->pin, 
                    GPIO_ACTIVE_LOW | GPIO_OUTPUT);
    
    if (ret < 0)
    {
        return;
    }
    
}

/**
 * The function GPIO_SET sets a GPIO pin to a high state.
 * 
 * @param dev The "dev" parameter is a pointer to a structure of type "gpio_driver_t". This structure
 * likely contains information about the GPIO driver, such as the port and pin number to be set.
 * 
 * @return nothing (void).
 */
void GPIO_SET(gpio_driver_t * const dev){
    ret = gpio_pin_set(dev->driver->port, dev->driver->pin, 1);
    if (ret < 0)
    {
        return;
    }
    
}

/**
 * The function GPIO_RESET sets a GPIO pin to a low state.
 * 
 * @param dev The "dev" parameter is a pointer to a structure of type "gpio_driver_t". This structure
 * likely contains information about the GPIO driver, such as the port and pin number to be reset.
 * 
 * @return nothing (void).
 */
void GPIO_RESET(gpio_driver_t * const dev){
    gpio_pin_set(dev->driver->port, dev->driver->pin, 0);
    if (ret < 0)
    {
        return;
    }
}

/**
 * The function creates a GPIO driver object and initializes it with the specified device driver.
 * 
 * @param dev_driver The dev_driver parameter is a pointer to a structure of type gpio_dt_spec. This
 * structure contains the necessary information for initializing the GPIO driver, such as pin
 * configurations and other settings.
 * 
 * @return a pointer to a gpio_driver_t structure.
 */
gpio_driver_t *GPIO_DRIVER_Create(const struct gpio_dt_spec *dev_driver){
    gpio_driver_t *dev = malloc(sizeof(gpio_driver_t));
    dev->driver = dev_driver;
    if (dev != NULL)
    {
        GPIO_DRIVER_Init(dev, GPIO_CONFIG_Input, GPIO_CONFIG_Output,
                    GPIO_SET, GPIO_RESET);
    }
    return dev;
}

/**
 * The function `GPIO_DRIVER_Destroy` frees the memory allocated for a GPIO driver object.
 * 
 * @param dev The parameter "dev" is a pointer to a structure of type "gpio_driver_t".
 */
void GPIO_DRIVER_Destroy(gpio_driver_t * const dev){
    free(dev);
}