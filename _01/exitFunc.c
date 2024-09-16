#include"headers.h"
#include"defaults.h"
#include"declarations.h"
//cleanup function

static void __exit myDevExit(void)
{
	int i;
	printk(KERN_INFO "%s: Begin.\n", __func__);

	for ( i = 0 ; i < nod ; i++)
	{
		//dev[i].c_dev.dev = MKDEV(majorNo, i);
		cdev_del(&dev[i].c_dev);
	}
	kfree(dev);
	unregister_chrdev_region(devid, nod);	
//	printk(KERN_INFO "Bye for now!!\n");
	printk(KERN_INFO "%s: End.\n", __func__);
}
module_exit(myDevExit);
