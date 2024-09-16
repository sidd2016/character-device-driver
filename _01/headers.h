#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/slab.h>
#include<linux/cdev.h>
#include<linux/moduleparam.h>
#include<linux/kernel.h>
#include<linux/uaccess.h>
#include<linux/semaphore.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Siddharth");
MODULE_DESCRIPTION("Implementing Device Opening");
