#include"headers.h"
#include"defaults.h"
#include"declarations.h"
//#include"operations.h"

int releaseDevice(struct inode *inode, struct file *file)
{
	#ifdef DEBUG
	printk(KERN_INFO "Begin: %s\n", __func__);
	#endif



	#ifdef DEBUG
	printk(KERN_INFO "End: %s\n", __func__);
	#endif

	return 0;
}
