
#define unprotect_memory() \
({ \
	orig_cr0 =  read_cr0();\
	write_cr0(orig_cr0 & (~ 0x10000)); /* Set WP flag to 0 */ \
});
#define protect_memory() \
({ \
	write_cr0(orig_cr0); /* Set WP flag to 1 */ \
});

asmlinkage long (*orig_shutdown)(int, int);
unsigned long *sys_call_table;

hooking_syscall(void *hook_addr, uint16_t syscall_offset, unsigned long *sys_call_tabe)
{
	unprotect_memory();
	sys_call_table[syscall_offset] = (unsigned long)hook_addr;
	protect_memory();
}

unhooking_syscall(void *orig_addr, uint16_t syscall_offset)
{
	unprotect_memory();
	sys_call_table[syscall_offset] = (unsigned long)hook_addr;
	protect_memory();
}

asmlinkage int hooked_shutdown(int magic1, int magic2)
{
	printk("Hello from hook!");
	return orig_shutdown(magic1, magic2);
}

static int __init module_init(void)
{
	unsigned long *sys_call_table = kallsyms_lookup_name("sys_call_table"));
	orig_shutdown = (void*)sys_call_table[__NR_shutdown];
	hooking_syscall(hooked_shutdown, __NR_shutdown, sys_call_tabe);
}

static void __exit module_cleanup(void)
{
	unhooking_syscall(orig_shutdown, __NE_shutdown, sys_call_table);
}
