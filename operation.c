#include"header.h"
#include"decleration.h"

int myopen(struct inode *in, struct file *fp)
{
	pr_info("Device opened\n");
	return 0;
}

int myclose(struct inode *in, struct file *fp)
{
	pr_info("Device closed\n");
	return 0;
}

ssize_t mywrite(struct file *fp, const char __user *buf,size_t SIZE, loff_t *loff)
{
	pr_info("Writing function\n");
	return 0;
}

ssize_t myread(struct file *fp, char __user *buf, size_t SIZE, loff_t *loff)
{
	pr_info("Reading function\n");
	return 0;
}
