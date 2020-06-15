obj-m+= hello.o
​
hello.o:
	make -C /lib/modules/$(shell uname -r)/build M=$(pwd) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(pwd) clean
