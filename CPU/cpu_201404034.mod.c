#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xf78b803, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xceb7eb2d, __VMLINUX_SYMBOL_STR(single_release) },
	{ 0x190c0530, __VMLINUX_SYMBOL_STR(seq_read) },
	{ 0x73aca93a, __VMLINUX_SYMBOL_STR(seq_lseek) },
	{ 0xb74ea968, __VMLINUX_SYMBOL_STR(proc_create_data) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x91831d70, __VMLINUX_SYMBOL_STR(seq_printf) },
	{ 0x31df644a, __VMLINUX_SYMBOL_STR(init_task) },
	{ 0x671cef46, __VMLINUX_SYMBOL_STR(single_open) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "C22D4AA0273CE7962F4753D");
