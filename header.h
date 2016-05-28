#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/types.h>
#include<linux/device.h>

#ifdef DEBUG
#define DEBUG 1
#endif

MODULE_LICENSE("GPL");
