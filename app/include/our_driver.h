#ifndef _OUR_DRIVER_INCLUDE

#define _OUR_DRIVER_INCLUDE

#include <zephyr/drivers/sensor.h>
#include <zephyr/kernel.h>

struct my_sensor_data {
    int custom_value;
};

int my_sensor_set_custom_value(const struct device *dev, int value)
{
    struct my_sensor_data *data = (struct my_sensor_data *)dev->data;
    data->custom_value = value;

    return 0;
}

#endif


