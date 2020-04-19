#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include "hello1.h"

extern int print_hello(uint n);

MODULE_AUTHOR("Serhii Popovych <serhii.popovych@globallogic.com>");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");

static uint hello_param = 1;
module_param(hello_param, uint, S_IRUGO); // visibility: world, immutable
MODULE_PARM_DESC(hello_param, "An unsigned int, describes how many times \"Hello world\" will be said.");

static int __init hello_init(void)
{
	return print_hello(hello_param);
}

static void __exit hello_exit(void)
{
	/* Do nothing here right now */
}

module_init(hello_init);
module_exit(hello_exit);
