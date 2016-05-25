obj-m += initexit.o
KSOURCE := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

default: 
	make -C $(KSOURCE) M=$(PWD) modules
clean:
	make -C $(KSOURCE) M=$(PWD) clean
