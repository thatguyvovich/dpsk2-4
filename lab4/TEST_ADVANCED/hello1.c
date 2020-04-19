#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include "hello1.h"

MODULE_AUTHOR("Serhii Popovych <serhii.popovych@globallogic.com>");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");
EXPORT_SYMBOL(print_hello);

static int __init hello_init(void)
{
	return 0;
}

static void __exit hello_exit(void)
{
	/* Do nothing here right now */
}

int print_hello(uint n){
	int i = 0;
	if(n == 0 || (n  >= 5 && n <= 10))
		pr_warn("WARNING! Invalid argument. Continuing job...");
	else if(n > 10) {
		pr_err("ERROR! Invalid arguemnt. Exiting job...");
		return -EINVAL;
	}
	else
		for(i = 0; i < n; i++)
			pr_info("Hello, world!\n");
	return 0;
}

module_init(hello_init);
module_exit(hello_exit);
