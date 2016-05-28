#include"header.h"
//This is 2nd commit by ashish

//This is added by Ravi

int nod=1;
dev_t dev;
static struct class *cl;

static int __init constructor(void)
{
	int ret;
	ret = alloc_chrdev_region(&dev,0,nod,"ravimodule");						//  Module Registration..
	if(ret<0)
	{
		printk(KERN_ERR "Registration Fail\n");
		return -1;
	}
	
	pr_info("Hello, Module Registered\nMajor No. : %d\tminor : %d\n",MAJOR(dev),MINOR(dev));
	
	cl = class_create(THIS_MODULE, "chardrvclass");							//  Creating device file
	device_create(cl,NULL,dev,NULL,"node");
	return 0;
}

void __exit destructor(void)
{
	device_destroy(cl,dev);										//  Destroying Device file
	class_destroy(cl);

	unregister_chrdev_region(dev,nod);
	pr_info("Bye, Uninstalling Driver...\n");
}

module_init(constructor);
module_exit(destructor);
