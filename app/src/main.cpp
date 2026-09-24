#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <our_driver.h>



#define SLEEP_TIME_MS 1000

/* The devicetree node identifier for the "led0" alias. */
#define LED_NODE DT_ALIAS(led0)

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED_NODE, gpios);

static const struct device* driver = DEVICE_DT_GET(DT_NODELABEL(our_driver0));

LOG_MODULE_REGISTER(main, LOG_LEVEL_INF);


int main(void)
{

    struct sensor_value val;

    if (!gpio_is_ready_dt(&led)) return 0;

    if (gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE) < 0) return 0;

    while (1) {

        if(!sensor_sample_fetch(driver)) 
            return 1;

        my_sensor_set_custom_value(driver, 42);

        if(!sensor_sample_fetch(driver)) 
            return 1;

        k_msleep(SLEEP_TIME_MS);

        if(!sensor_channel_get(driver, SENSOR_CHAN_AMBIENT_TEMP, &val)) 
            return 1;
 

        k_msleep(SLEEP_TIME_MS);

    }

    return 0;

}
