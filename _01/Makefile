INSTALL_DIR=modules
ifneq (${KERNELRELEASE},)
	obj-m := mycdd.o

mycdd-objs := initFunc.o exitFunc.o openDevice.o releaseDevice.o writeDevice.o readDevice.o creatScull.o trimDevice.o lseekDev.o

else
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
	@rm -rf ${INSTALL_DIR}
	@mkdir ${INSTALL_DIR}
	@mv -f *.o *.ko *.mod.c .*.cmd ${INSTALL_DIR}
clean:
	rm -rf ${INSTALL_DIR}
endif
