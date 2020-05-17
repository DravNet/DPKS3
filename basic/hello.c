#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/errno.h>

MODULE_LICENSE("Dual BSD/GPL");

static uint count = 1;
module_param(count , uint, S_IRUGO);
MODULE_PARM_DESC(count , "Here is parameter description");

static int __init hello_init(void)
{
    if (count > 10)
    {
        printk(KERN_ERR "Error - parametr > 10\n");
        return -EINVAL;
    }

    if (!count || (count >= 5 && count <= 10))
        printk(KERN_WARNING "Warning - parameter = %u\n", count );

    uint i;
    for (i = 0; i < count ; ++i)
        printk(KERN_NOTICE "Hello, world\n");

    return 0;
}
module_init(hello_init);

static void __exit hello_exit(void)
{
    printk(KERN_NOTICE "Goodbye, cruel world\n");
}
module_exit(hello_exit);
