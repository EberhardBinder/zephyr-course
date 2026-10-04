#include <zephyr/drivers/sensor.h>
#include <zephyr/kernel.h>
#include <zephyr/shell/shell.h>
#include <our_driver.h>
#include <stdlib.h>

static const struct device* driver = DEVICE_DT_GET(DT_NODELABEL(our_driver0));

static int cmd_sensor_sample_fetch_handler(const struct shell *sh, size_t argc, char** argv)
{

    ARG_UNUSED(argc);

    ARG_UNUSED(argv);

    shell_print(sh, "sensor sample fetch");

    if(!sensor_sample_fetch(driver))
         return 1;

    return 0;

}


static int cmd_sensor_channel_get_handler(const struct shell *sh, size_t argc, char** argv)
{

    struct sensor_value val;

    ARG_UNUSED(argc);

    ARG_UNUSED(argv);

    shell_print(sh, "sensor channel get");

    if(!sensor_channel_get(driver, SENSOR_CHAN_AMBIENT_TEMP, &val))
        return 1;

    //shell_fprintf(sh, SHELL_INFO, "sensor value %d\n", val.val1);

    shell_print(sh, "sensor value %d", val.val1);

    return 0;

}

static int cmd_sensor_info_handler(const struct shell *sh, size_t argc, char** argv)
{

    ARG_UNUSED(argc);

    ARG_UNUSED(argv);

    shell_print(sh, "sensor info");

    shell_print(sh, "sensor driver name %s", driver->name);

    shell_print(sh, "sensor driver state %d", driver->state->initialized);

    return 0;

}

static int cmd_sensor_set_handler(const struct shell *sh, size_t argc, char** argv)
{

    shell_print(sh, "sensor set");

    if( argc != 2) {

        shell_error(sh, "Wrong number of parameters");

        return 1;
    }

    int value = atoi(argv[1]);

    //shell_print(sh, "argc %d", argc);

    //shell_print(sh, "value %d", value);

    my_sensor_set_custom_value(driver, value);

    return 0;

}



SHELL_STATIC_SUBCMD_SET_CREATE(sensor_subcmd,
    SHELL_CMD(fetch, NULL, "Sensor sample fetch.", cmd_sensor_sample_fetch_handler),
    SHELL_CMD(read, NULL, "Sensor channel get.", cmd_sensor_channel_get_handler),
    SHELL_CMD(info, NULL, "Sensor info.", cmd_sensor_info_handler),
    SHELL_CMD_ARG(set, NULL, "Sensor set.", cmd_sensor_set_handler, 2, 0),
    SHELL_SUBCMD_SET_END
);


SHELL_CMD_REGISTER(sensor, &sensor_subcmd,  "Sensor sample driver commands.", NULL);
