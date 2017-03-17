#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

int sum_op(int numdata);
int factorial_op(int N);

static int __init modtest_init(void)
{
	printk(KERN_INFO"_ _ _Moduletest init!_ _ _\n");
	return 0;
}

static void __exit modtest_exit(void)
{
        printk(KERN_INFO"_ _ _Moduletest delete!_ _ _\n");
}

int sum_op(int numdata)
{
	int i=0;
	int ret=0;
	printk(KERN_INFO"sum operation\n");
	while(i<=numdata)
		ret+=i++;
	return ret;
}

int factorial_op(int N)
{
        int i=1;
        int Nx=1;
        printk(KERN_INFO"factorial operation\n");
        if(N==0)
                return Nx;
	for(;i<=N;i++)
		Nx=Nx*i;
        return Nx;
}

EXPORT_SYMBOL(sum_op);
EXPORT_SYMBOL(factorial_op);
module_init(modtest_init);
module_exit(modtest_exit);
MODULE_LICENSE("GPL");
