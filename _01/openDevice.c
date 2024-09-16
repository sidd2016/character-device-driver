#include"headers.h"
#include"defaults.h"
#include"declarations.h"
//#include"operations.h"

Dev *ldev;

int openDevice(struct inode *inode, struct file *file)
{
	#ifdef DEBUG
	printk(KERN_INFO "Begin: %s\n", __func__);
	#endif
	
//	Dev *ldev;

	ldev = container_of(inode->i_cdev, Dev, c_dev);
	if(!ldev)
	{
		printk(KERN_ERR "%s: ERROR: container_of() failed.\n", __func__);
		goto OUT;
	}
	file->private_data = ldev;
	if( (file->f_flags & O_ACCMODE) == O_WRONLY )
		file->f_pos = 0;
	else if( (file->f_flags & O_ACCMODE) == O_RDONLY )
		printk(KERN_INFO "%s: Device Opened for Reading\n", __func__);
//	else if( (file->f_flags & O_ACCMODE) == O_APPEND )
//		printk(KERN_INFO "%s: Device Opened for Appending\n", __func__);
	else
	{
		printk(KERN_INFO "%s: Invalid Device Open Mode\n", __func__);
		goto OUT;
	}

	#ifdef DEBUG
	printk(KERN_INFO "End: %s\n", __func__);
	#endif

	return 0;
OUT:
#ifdef DEBUG
	printk(KERN_INFO "End: %s\n", __func__);
#endif
	return -1;
}
