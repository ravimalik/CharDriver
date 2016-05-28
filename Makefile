obj-m := lkm.o
lkm-objs := initexit.o operation.o
#lkm-objs := initexit.o operations.o decleration.o
KSOURCE := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

default: 
	make -C $(KSOURCE) M=$(PWD) modules
clean:
	make -C $(KSOURCE) M=$(PWD) clean
