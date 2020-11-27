#include <linux/gpio.h> 
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("SAMBUCA");
MODULE_DESCRIPTION("myGPIO_Driver");

#define ADC_MAJOR 63
#define ADC_MINOR 0

static int devno;
static struct  cdev my_cdev;
struct file_operations my_fops;
int gpio = 25;

static int mygpio_init(void)
{ 
    // Request GPIO
    int err_reg = 0;
    err_reg = gpio_request(gpio, "orderCompleteGPIO");
    if(err_reg < 0)
    {
        printk(KERN_ALERT "Error with request!\n");
        goto err_exit;
    }
    printk(KERN_ALERT "Request was successfull!\n");

    // Set GPIO direction (in or out)
    err_reg = gpio_direction_input(gpio);
    if(err_reg < 0)
    {
        printk(KERN_ALERT "Error with direction!\n");
        goto err_exit;
    }
    printk(KERN_ALERT "Direction was successfull!\n");

    // Make device no (vælg - Enten bruger I statisk eller også bruger I dynamisk major/minor nummer allokering) 
    devno = MKDEV(ADC_MAJOR, ADC_MINOR);
    printk(KERN_ALERT "MKDEV was successfull!\n");

    // Register Device
    err_reg = register_chrdev_region(devno, 1, "orderCompleteGPIO");
    if (err_reg < 0)
    {
        printk(KERN_ALERT "Error with register!\n");
        goto err_free_buf;
    }
    printk(KERN_ALERT "Register was successfull!\n");
       
    // Cdev Init
    cdev_init(&my_cdev, &my_fops);
    printk(KERN_ALERT "cdev_init was successfull!\n");
    // Add Cdev
    err_reg = cdev_add(&my_cdev, devno, 1);
    if (err_reg < 0)
    {
        printk(KERN_ALERT "Error with cdev_add!\n");
        goto err_dev_unregister;
    }
    printk(KERN_ALERT "cdev_add was successfull!\n");
    

    printk(KERN_ALERT "mygpio_init was a success!\n");
    return 0; //Success



    printk(KERN_ALERT "Starting goto!\n");
    err_dev_unregister:
        unregister_chrdev_region(devno, 1);
        printk(KERN_ALERT "err_dev_unregister!\n");
    err_free_buf:
        gpio_free(gpio);
        printk(KERN_ALERT "err_free_buf!\n");
    err_exit:
        return err_reg;
        printk(KERN_ALERT "err_exit!\n");
}

static void mygpio_exit(void)
{
    // Delete Cdev
    cdev_del(&my_cdev);
    // Unregister Device
    unregister_chrdev_region(devno, 1);
    // Free GPIO
    gpio_free(gpio);
    printk(KERN_ALERT "mygpio_exit was a success!\n");
}

int mygpio_open(struct inode *inode, struct file *filep)
{
    int major, minor;

    major = MAJOR(inode->i_rdev);
    minor = MINOR(inode->i_rdev);
    printk("Opening MyGpio Device [major], [minor]: %i, %i\n", major, minor);
    return 0;
}

int mygpio_release(struct inode *inode, struct file *filep)
{
    int minor, major;

    major = MAJOR(inode->i_rdev);
    minor = MINOR(inode->i_rdev);
    printk("Closing/Releasing MyGpio Device [major], [minor]: %i, %i\n", major, minor);

return 0;
}

ssize_t mygpio_read(struct file *filep, char __user *buf, size_t count, loff_t *f_pos)
{
// Hvilke trin er det der skal udføres?
// Hint konvertering fra int til string kan gøres via sprintf() - antagelsen er at det er strenge der sendes til og fra user space. Det gør debugging lettere.
int err = 0;
char my_buf[2];
int value = gpio_get_value(gpio);
int len = sprintf(my_buf, "%d", value) +1;

printk("Reading value: %i\n", value);
len = len> count ? count : len;

err = copy_to_user(buf, my_buf,len);
*f_pos += len;
return len;    
}

ssize_t mygpio_write(struct file *filep, const char __user *ubuf, size_t count, loff_t *f_pos)
{
int err = 0;
int len = 2;
char my_buf[2];

len = len > count ? count : len;
err = copy_from_user(my_buf, ubuf, len);
sscanf(my_buf, "%i", &len);

gpio_set_value(gpio, len); 
printk("Writing to GPIO21: %i\n",len);


*f_pos += len;
return len;
}

struct file_operations my_fops = 
{
    .open = mygpio_open,
    .release = mygpio_release,
    .read = mygpio_read,
    .write = mygpio_write,
};

module_init(mygpio_init);
module_exit(mygpio_exit);