#include "hello1.h"

#include <linux/errno.h>

static int __init hello1_init(void)
{
    pr_info("hello1 module loaded\n");
    return 0;
}
module_init(hello1_init);

int print_hello(uint n)
{
    if (n > 10)
    {
        pr_err("Error - parameter > 10\n");
        return -EINVAL;
    }

    if (!n || (n >= 5 && n <= 10))
        pr_warn("Warning - parameter = %u\n", n);

    uint i;
    for (i = 0; i < n; ++i)
        pr_info("Hello, world\n");

    return 0;
}
EXPORT_SYMBOL(print_hello);

static void __exit hello1_exit(void)
{
    pr_info("hello1 module unloaded\n");
}
module_exit(hello1_exit);
