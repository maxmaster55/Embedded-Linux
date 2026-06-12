#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <linux/io.h>

#define PROC_NAME "led_driver"

#define BCM2837_GPIO_BASE	0x3F200000
#define GPIO_REG_SIZE		0xB4

#define GPFSEL0	0x00   /* GPFSEL0..GPFSEL5 = 0x00, 0x04, 0x08, 0x0C, 0x10, 0x14 */
#define GPSET0	0x1C
#define GPSET1	0x20
#define GPCLR0	0x28
#define GPCLR1	0x2C

static void __iomem *gpio_base;

static ssize_t led_read(struct file *file, char __user *buf, size_t count, loff_t *ppos)
{
	char tmp[128];
	int len;

	if (*ppos != 0)
		return 0;

	len = snprintf(tmp, sizeof(tmp),
		"write '<gpio> <0|1>' to control a GPIO pin\n",
		PROC_NAME);

	if (len > count)
		return -EINVAL;

	if (copy_to_user(buf, tmp, len))
		return -EFAULT;

	*ppos = len;
	return len;
}

static ssize_t led_write(struct file *file, const char __user *buf, size_t count, loff_t *ppos)
{
	char tmp[32];
	unsigned int gpio, value;
	u32 reg;
	u32 fsel_offset;

	if (count >= sizeof(tmp))
		return -EINVAL;

	if (copy_from_user(tmp, buf, count))
		return -EFAULT;

	tmp[count] = '\0';

	if (sscanf(tmp, "%u %u", &gpio, &value) != 2)
		return -EINVAL;

	if (gpio > 53 || value > 1)
		return -EINVAL;

	/* --- Configure pin as output (FSEL = 001) --- */
	fsel_offset = GPFSEL0 + (gpio / 10) * 4;

	reg = ioread32(gpio_base + fsel_offset);
	reg &= ~(7u << ((gpio % 10) * 3));
	reg |= (1u << ((gpio % 10) * 3));
	iowrite32(reg, gpio_base + fsel_offset);

	if (gpio < 32) {
		if (value)
			iowrite32(1u << gpio, gpio_base + GPSET0);
		else
			iowrite32(1u << gpio, gpio_base + GPCLR0);
	} else {
		if (value)
			iowrite32(1u << (gpio - 32), gpio_base + GPSET1);
		else
			iowrite32(1u << (gpio - 32), gpio_base + GPCLR1);
	}

	printk(KERN_INFO "led_driver: GPIO%u set to %u\n", gpio, value);

	return count;
}

static struct proc_ops led_fops = {
	.proc_read  = led_read,
	.proc_write = led_write,
};

static int __init led_init(void)
{
	gpio_base = ioremap(BCM2837_GPIO_BASE, GPIO_REG_SIZE);
	if (!gpio_base) {
		printk(KERN_ERR "led_driver: ioremap failed\n");
		return -ENOMEM;
	}

	if (!proc_create(PROC_NAME, 0666, NULL, &led_fops)) {
		printk(KERN_ERR "led_driver: failed to create /proc/%s\n", PROC_NAME);
		iounmap(gpio_base);
		return -ENOMEM;
	}

	printk(KERN_INFO "led_driver: /proc/%s created, GPIO mapped at %px\n", PROC_NAME, gpio_base);
	return 0;
}

static void __exit led_exit(void)
{
	remove_proc_entry(PROC_NAME, NULL);
	iounmap(gpio_base);
	printk(KERN_INFO "led_driver: /proc/%s removed\n", PROC_NAME);
}

module_init(led_init);
module_exit(led_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Youssef");
MODULE_DESCRIPTION("Proc driver using ioremap to control a GPIO LED on RPi3B");