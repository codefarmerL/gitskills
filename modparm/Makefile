ifneq ($(KERNELRELEASE),)
	obj-m:=modtest.o
else
	KDIR:=/lib//modules/$(shell uname -r)/build
	PWD:=$(shell pwd)
default:
	$(MAKE) -C $(KDIR) M=$(PWD)
clean:
	rm -rf *.o *.mod.c *.ko *.symvers *.order *.markers
endif
