ifneq ($(KERNELRELEASE),)
        obj-m:=module2.o
else
        KDIR:=/lib//modules/$(shell uname -r)/build
        PWD:=$(shell pwd)
default:
	$(MAKE) -C $(KDIR) M=$(PWD)
clean: 
	rm -rf *.o *.mod.c *.ko *.symvers *.order *.markers
endif
KBUILD_EXTRA_STMBOLS+=/home/lzy/learngit/gitskills/modparm/Module.symvers
export $(KBUILD_EXTRA_STMBOLS)

