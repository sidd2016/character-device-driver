extern dev_t devid, devno;
extern int majorNo, minorNo, nod;
extern int size_of_device, no_of_reg, size_of_reg, size_of_data;


typedef struct item
{
	struct item *next;
	void **data;
}Item;

// user defined data structure
// it will describe the hardware device architecture 
typedef struct Device
{
	int MajorNo;
	int MinorNo;
	struct cdev c_dev;
	Item *first;
	int size_of_device;
	int no_of_reg;
	int size_of_reg;
	int size_of_data;
	struct semaphore sem;
}Dev;

extern Dev *dev;

int openDevice(struct inode *, struct file *);
int releaseDevice(struct inode *, struct file *);
ssize_t writeDevice(struct file*, const char __user*, size_t, loff_t*);
ssize_t readDevice(struct file*, char __user*, size_t, loff_t*);
Item* creatScull(size_t);
int trimDevice(Dev*);
loff_t lseek_dev(struct file*, loff_t, int);
