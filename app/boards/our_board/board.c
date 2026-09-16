#include<zephyr/init.h>
#include<zephyr/kernel.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(board_out_board_init, LOG_LEVEL_INF);

static int board_our_board_init(void) {

	/* Some function to run before boot */

        LOG_INF("Board Initialized");

	return 0;
}

