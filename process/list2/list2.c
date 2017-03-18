#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/list.h>
MODULE_LICENSE("GPL");

static int pid = 1;

module_param(pid,int,S_IRUGO);

static int ps_begin(void){
	struct task_struct *p,*p_parent,*pp;
	struct list_head *lh;
	p=pid_task(find_get_pid(pid),PIDTYPE_PID);
	if(p){
		printk("\n Thread Info!\n");
		printk("\ncomm=%s,pid=%d,state=%ld\n",p->comm,p->pid,p->state);
		p_parent=p->parent;
		printk("\nHis father is : comm=%s,pid=%d,state=%ld\n",p->comm,p->pid,p->state);
		list_for_each(lh,&p->children){
			pp=list_entry(lh,struct task_struct,sibling);
			printk("\nchildren %d %s\n",pp->pid,pp->comm);
		}
		list_for_each(lh,&p->real_parent->children){
                        pp=list_entry(lh,struct task_struct,sibling);
                        printk("\nsibling %d %s\n",pp->pid,pp->comm);
                }
	}
	else{
		printk("\n process %d does not exist!\n",pid);
	}
	return 0;
}

static void ps_end(void){
	printk("\nExit!\n");
}

module_init(ps_begin);
module_exit(ps_end);
