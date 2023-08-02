#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Omer");
MODULE_DESCRIPTION("A simple example Linux module.");
MODULE_VERSION("0.01");

static char* str = "World"; // default 

module_param(str, charp, S_IRUGO); // allow user to comunicate with kernel in read-only permission

static int __init lkm_example_init(void) {
	printk(KERN_INFO "Hello, %s\n", str);
	return 0;
}

static void __exit lkm_example_exit(void) {
	printk(KERN_INFO "Goodbye %s\n", str);
}

module_init(lkm_example_init);
module_exit(lkm_example_exit);

