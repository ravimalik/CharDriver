#include"header.h"
#include"decleration.h"

/*
static int myopen(struct inode *in, struct file *fp)
{
	pr_info("Device opened\n");
	return 0;
}
static int myclose(struct inode *in, struct file *fp)
{
	pr_info("Device closed\n");
	return 0;
}

ssize_t mywrite(struct file *, const char __user *,size_t , loff_t *)
{
	pr_info("Write function\n");
	return 0;
}
ssize_t myread(struct file *, char __user *, size_t , loff_t *)
{
	pr_info("Read function\n");
	return 0;
}
*/

int nod=1;
dev_t dev;
struct cdev mydev;
static struct class *cl;

struct file_operations fops={
	owner   : THIS_MODULE,
	open    : myopen,
	release : myclose,
	read	: myread,
	write	: mywrite
};

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

	cdev_init(&mydev,&fops);
	ret = cdev_add(&mydev,dev,1);
	if(ret<0)
	{
		pr_info("Cdev add failed\n");
	}
	
	cl = class_create(THIS_MODULE, "charclass");							//  Creating device file
	device_create(cl,NULL,dev,NULL,"node");
	
	return 0;
}

void __exit destructor(void)
{
	device_destroy(cl,dev);										//  Destroying Device file
	class_destroy(cl);
	cdev_del(&mydev);
	unregister_chrdev_region(dev,nod);
	pr_info("Bye, Uninstalling Driver...\n");
}

module_init(constructor);
module_exit(destructor);
