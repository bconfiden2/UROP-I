#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int __init hello_init(void)
{
  printk("hello_init() hello world!\n");
  return 0;
}

static void __exit hello_exit(void)
{
  printk("hello_exit() bye wolrd..\n");
}

module_init(hello_init);
module_exit(hello_exit);
