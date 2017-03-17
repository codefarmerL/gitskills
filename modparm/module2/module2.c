#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

static char *user_name="book_user";
static int num_operator=0;

extern int factorial_op(int);
static int __init module2_init(void)
{
        int result=0;
        printk(KERN_INFO"_ _ _Module2 init!_ _ _\n");
        printk(KERN_INFO"%s,Welcome to use this factorial_op!\n",user_name);
        result=factorial_op(num_operator);
        printk(KERN_INFO"%d!=%d\n",num_operator,result);
        return 0;
}

static void __exit module2_exit(void)
{
        printk(KERN_ALERT"_ _ _Module2 delete!_ _ _%s\n",user_name);
}

module_param(user_name,charp,S_IRUGO);
module_param(num_operator,int,S_IRUGO);

module_init(module2_init);
module_exit(module2_exit);
MODULE_LICENSE("GPL");

