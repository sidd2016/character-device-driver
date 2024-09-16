#include"headers.h"
#include"defaults.h"
#include"declarations.h"
//#include"operations.h"

ssize_t readDevice(struct file *filep, char __user *ubuff, size_t size, loff_t *loff)
{
	unsigned int noq, l, i, not;
	size_t noctr, nocsr, lsize;
	Dev *ldev;
	Item *curr;

#ifdef DEBUG
	printk(KERN_INFO "Begin: %s\n", __func__);
	printk(KERN_INFO "%s: size:%ld.\n", __func__, (long)size);
#endif

	if(size == 0)
	{
		printk(KERN_ERR "%s: ERROR: Nothing to Reading.\n", __func__);
		goto OUT;  // ? use RET or. confuse
	}

	ldev = (Dev*)filep->private_data;
	if(!ldev)
	{
		printk(KERN_ERR "%s: ERROR: Device Not Found for Reading.\n", __func__);
		goto OUT;
	}
	
/*	if( (filep->f_flags & O_ACCMODE) != O_RDONLY )
	{
		printk(KERN_ERR "%s: ERROR: Device Not Opened for Reading.\n", __func__);
		goto OUT;
	}
*/

	if( size > size_of_device )
		noctr = lsize = size_of_device;
	else
		noctr = lsize = size;

	if( lsize > ldev->size_of_data )
		lsize = ldev->size_of_data;


	nocsr = 0;
	if( ldev->first )
	{
		curr = ldev->first;
	}
	else
	{
		printk(KERN_INFO "%s: Nothing To Read\n", __func__);
		goto RET;
	}
	noq = lsize / ldev->size_of_reg;
	if( lsize % ldev->size_of_reg) //check line
		noq++;

	printk(KERN_INFO "%s: size:%ld.\n", __func__, (long)lsize);//testing

	if(down_interruptible(&ldev->sem))   //    apply semaphore
		return -ERESTARTSYS;

	for(i = l = 0 ; l < noq ; l++)
	{

		if( noctr >= ldev->size_of_reg ) // add =
			noctr = ldev->size_of_reg;
		not = copy_to_user(ubuff+nocsr, curr->data[i], noctr);
		if(not == -1)
		{
			printk(KERN_ERR "%s: ERROR: copy_to_user() fail    ure.\n", __func__);
			goto OUT;
		}
		nocsr = nocsr + size_of_reg - not;
		noctr = lsize -nocsr;
		if( i == ldev->no_of_reg-1 )
		{
			curr = curr->next;
			i = 0;
		}
		else
			i++;

	}

	up(&ldev->sem);
RET:
#ifdef DEBUG
	printk(KERN_INFO "End: %s\n", __func__);
#endif

	return nocsr;
OUT:
#ifdef DEBUG
	printk(KERN_ERR "%s: ERROR: End.\n", __func__);
#endif
	return -1;

}
