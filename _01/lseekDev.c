#include"headers.h"
#include"defaults.h"
#include"declarations.h"
//#include"operations.h"
loff_t lseek_dev(struct file *filep, loff_t offset, int origin)
{
#ifdef DEBUG
	printk(KERN_INFO "Begin: %s\n", __func__);
	printk(KERN_INFO "f_pos: %d\n", (int)filep->f_pos);
	printk(KERN_INFO "offset: %d\n", (int)offset);
#endif


#ifdef DEBUG
	printk(KERN_INFO "f_pos: %d\n", (int)filep->f_pos);
	printk(KERN_INFO "offset: %d\n", (int)offset);
	printk(KERN_INFO "End: %s\n", __func__);
#endif
	return filep->f_pos;
}
