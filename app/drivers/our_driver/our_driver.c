#include <zephyr/drivers/sensor.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/drivers/gpio.h>

#define DT_DRV_COMPAT our_driver

/* The devicetree node identifier for the "led0" alias. */
#define LED_NODE DT_ALIAS(led0)

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED_NODE, gpios);

LOG_MODULE_REGISTER(our_driver, LOG_LEVEL_INF);


static int sample_fetch_my_impl(const struct device *dev,
                                enum sensor_channel chan) {

    LOG_INF("Hello From Sample Fetch, device %p", dev);

    if (!gpio_pin_set_dt(&led, 1))
        return 1;
    else
        return 0;

}


static int sensor_channel_get_my_impl(const struct device *dev,
                               enum sensor_channel chan,
                               struct sensor_value *val) {

    LOG_INF("Hello From Channel Get,  channel %d", chan);

    if (!gpio_pin_set_dt(&led, 0))
        return 1;
    else
        return 0;

    return 0;
}


static DEVICE_API(sensor, api_iomico_lecture) = {
    .sample_fetch = sample_fetch_my_impl,
    .channel_get = sensor_channel_get_my_impl,


};

// Init fn
static int init(const struct device * dev) {
    LOG_INF("Device Initialized!");

    return 0;
}

DEVICE_DT_INST_DEFINE(0, init, NULL, NULL, NULL, POST_KERNEL, 80, &api_iomico_lecture);

//#define DEV_INST(inst) DEVICE_DT_INST_DEFINE(inst, init, NULL, NULL, NULL, POST_KERNEL, 80, &api_iomico_lecture);

//DT_INST_FOREACH_STATUS_OKAY(DEV_INST);
