#include<zephyr/init.h>
#include<zephyr/kernel.h>

static int board_our_board_init(void) {

	/* Some function to run before boot */

        printk("Board Initialized");

	return 0;
}

SYS_INIT(board_our_board_init, APPLICATION, 0);
