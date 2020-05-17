#include "hello1.h"

#include <linux/moduleparam.h>

static uint count = 1;
module_param(count , uint, S_IRUGO);
MODULE_PARM_DESC(count , "Here is parameter description");

extern int print_hello(uint count);

static int __init hello2_init(void)
{
    return print_hello(count);
}
module_init(hello2_init);

static void __exit hello2_exit(void)
{
    pr_info("Good bye, cruel world.\n");
}
module_exit(hello2_exit);
