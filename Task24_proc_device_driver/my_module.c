#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>

#define PROC_NAME "led_driver"

static int my_number;

static ssize_t pin_read(struct file *file, char __user *buf, size_t count, loff_t *ppos)
{
    char tmp[32];
    int len;

    if (*ppos != 0)
        return 0;

    len = snprintf(tmp, sizeof(tmp), "%d\n", my_number);
    if (len > count)
        return -EINVAL;

    if (copy_to_user(buf, tmp, len))
        return -EFAULT;

    *ppos = len;
    return len;
}

static ssize_t pin_write(struct file *file, const char __user *buf, size_t count, loff_t *ppos)
{
    char tmp[32];

    if (count >= sizeof(tmp))
        return -EINVAL;

    if (copy_from_user(tmp, buf, count))
        return -EFAULT;

    tmp[count] = '\0';

    if (kstrtoint(tmp, 10, &my_number))
        return -EINVAL;

    return count;
}

static struct proc_ops pin_fops = {
    .proc_read = pin_read,
    .proc_write = pin_write,
};

static int __init my_module_init(void)
{
    if (!proc_create(PROC_NAME, 0666, NULL, &pin_fops)) {
        printk(KERN_ERR "my_module: failed to create /proc/%s\n", PROC_NAME);
        return -ENOMEM;
    }

    printk(KERN_INFO "my_module: /proc/%s created\n", PROC_NAME);
    return 0;
}

static void __exit my_module_exit(void)
{
    remove_proc_entry(PROC_NAME, NULL);
    printk(KERN_INFO "my_module: /proc/%s removed\n", PROC_NAME);
}

module_init(my_module_init);
module_exit(my_module_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A proc driver that stores and returns a number");
