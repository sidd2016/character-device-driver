#include"headers.h"
#include"defaults.h"
#include"declarations.h"
//#include"operations.h"

ssize_t writeDevice(struct file *filep, const char __user *ubuff, size_t size, loff_t *loff)
{
	int not, noq, l, i, nocsw, noctw;
	size_t lsize;
	Item *curr;
	Dev *ldev;
#ifdef DEBUG
	printk(KERN_INFO "Begin: %s\n", __func__);
	printk(KERN_INFO "%s: f_fos: %ld\n", __func__, (long)filep->f_pos);
	printk(KERN_INFO "%s: loff: %ld\n", __func__, (long)*loff);
#endif
	
	if (size == 0)
	{
		printk(KERN_INFO "%s: Nothing to Write\n", __func__);
		goto RET;
	}
	ldev = (Dev*)filep->private_data;
	if(!ldev)
	{
		printk(KERN_ERR "%s: ERROR: Device Not Found for Writing.\n", __func__);
		goto OUT;
	}
	
	if( size > ldev->size_of_device )
		noctw = lsize = ldev->size_of_device;
	else
		noctw = lsize = size;
	printk(KERN_INFO "%s: size:%ld.\n", __func__, (long)lsize);

	if(down_interruptible(&ldev->sem))
		return -ERESTARTSYS;

	if(ldev->first || ldev->size_of_data == 0)
		trimDevice(ldev);                        //confuse in

	curr = ldev->first = creatScull(lsize);  //these 2 line. sir dont use else

	noq = lsize / ldev->size_of_reg;
		if( lsize % ldev->size_of_reg) //check line.
			noq++;

	for(nocsw = i = l = 0 ; l < noq ; l++)
	{
		if( noctw >= ldev->size_of_reg ) // add=
			noctw = ldev->size_of_reg;
		not = copy_from_user(curr->data[i], ubuff+nocsw, noctw);
		if(not == -1)
		{
			printk(KERN_ERR "%s: ERROR: copy_from_user() failure.\n", __func__);
			goto OUT;
		}
		nocsw = nocsw + size_of_reg - not;
		*loff = (long)nocsw;
		noctw = lsize -nocsw;
		if( i == ldev->no_of_reg-1 )
		{
			curr = curr->next;
			i = 0;
		}
		else
			i++;
	}
//	ldev->size_of_data = nocsw;
	filep->f_pos = *loff;
	ldev->size_of_data = size_of_data = nocsw;
	up(&ldev->sem);
RET:
//	ldev->size_of_data = size_of_data = nocsw;

#ifdef DEBUG
	printk(KERN_INFO "End: %s\n", __func__);
	printk(KERN_INFO "%s: f_fos: %ld\n", __func__, (long)filep->f_pos);
	printk(KERN_INFO "%s: loff: %ld\n", __func__, (long)*loff);
#endif

	return nocsw;
OUT:
#ifdef DEBUG
	printk(KERN_ERR "%s: ERROR: End.\n", __func__);
#endif
	return -1;
}
