#include"header.h"

int nod=1;
dev_t dev;

static int __init constructor(void)
{
	int ret;
//	ret = alloc_chrdev_region(&dev,0,nod,"ravimodule");
	ret = register_chrdev_region((dev_t)dev,nod,"ravimodule");
	if(ret==0)
		pr_info("Hello, Module Registered\nMajor No. : %d\tminor : %d\n",MAJOR(dev),MINOR(dev));
	return 0;
}

void __exit destructor(void)
{
	unregister_chrdev_region(dev,nod);
	pr_info("Bye, Uninstalling Driver...\n");
}

module_init(constructor);
module_exit(destructor);
