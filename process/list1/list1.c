#include <linux/init.h>
#include <linux/sched.h>
#include <linux/module.h>
MODULE_LICENSE("GPL");

static int ps_begin(void)
{
	int count = 0;
	struct task_struct *p;
	p=&init_task;
	for_each_process(p)
	{
		if(p->mm==NULL)
		{
			printk("\nThread Info!\n");
			printk("\ncomm=%s,pid=%d,state=%ld",p->comm,p->pid,p->state);
			count++;
		}
		printk("\nthe number of process is : %d\n",count);
	}
	return 0;
}

static void ps_end(void)
{
	printk("\nExit\n");
}

module_init(ps_begin);
module_exit(ps_end);

