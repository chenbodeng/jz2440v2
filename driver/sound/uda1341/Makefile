KERN_DIR ?= $(KERNEL_ROOT_PATH)
PWD := $(shell pwd)

CROSS_COMPILE = arm-linux-
CC = $(CROSS_COMPILE)gcc

# module objects
obj-m += s3c2410-uda1341.o
# test binary file
test-out :=


all:
	make -C $(KERN_DIR) M=$(PWD) modules


test: $(test-out)

$(test-out): %.out: %.o
	@echo "linking ..."
	$(CC) -o $@ $^

%.o: %.c
	@echo "compiling ..."
	$(CC) $(CFLAGS) -c -o $@ $^


clean:
	@echo "cleaning ..."
	rm -rf *.o *.symvers .*.d .*.cmd *.mod.c .tmp_versions

distclean: clean
	@echo "distcleaning ..."
	rm -f *.ko *.out

.PHONY: all test clean distclean

