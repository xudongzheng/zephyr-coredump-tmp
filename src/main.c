#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(app);

static void my_timer_handler(struct k_timer *dummy) {
	k_panic();
}

K_TIMER_DEFINE(my_timer, my_timer_handler, NULL);

void main(void) {
	LOG_ERR("boot");
	k_timer_start(&my_timer, K_SECONDS(7), K_FOREVER);
}
