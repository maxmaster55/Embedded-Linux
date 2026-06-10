obj-m := my_module.o

KERNEL_DIR ?= /lib/modules/$(shell uname -r)/build
BUILD_DIR := $(PWD)/build

all: $(BUILD_DIR)
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules
	@mv -f *.ko *.o *.mod *.mod.c modules.order Module.symvers $(BUILD_DIR)/ 2>/dev/null || true
	@mv -f .*.o .*.cmd .*.d $(BUILD_DIR)/ 2>/dev/null || true

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) clean
	rm -rf $(BUILD_DIR)

modules_install:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules_install
