//int myopen(struct inode *in, struct file *fp);
//int myclose(struct inode *in, struct file *fp);

extern struct file_operations fops;

//dev_t dev;

int myopen(struct inode *, struct file *);
int myclose(struct inode *, struct file *);
ssize_t mywrite(struct file *, const char __user *,size_t , loff_t *);
ssize_t myread(struct file *, char __user *, size_t , loff_t *);
