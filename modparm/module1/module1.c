#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

static char *user_name="book_user";
static int num_operator=0;

extern int sum_op(int);
static int __init module1_init(void)
{
	int result=0;
	printk(KERN_INFO"_ _ _Module1 init!_ _ _\n");
	printk(KERN_INFO"%s,Welcome to use this sum_op!\n",user_name);
	result=sum_op(num_operator);
	printk(KERN_INFO"1+..+%d=%d\n",num_operator,result);
	return 0;
}

static void __exit module1_exit(void)
{
        printk(KERN_ALERT"_ _ _Module1 delete!_ _ _%s\n",user_name);
}

module_param(user_name,charp,S_IRUGO);
module_param(num_operator,int,S_IRUGO);

module_init(module1_init);
module_exit(module1_exit);
MODULE_LICENSE("GPL");
