#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x44afce, "module_layout" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0xf0462214, "class_destroy" },
	{ 0xd132b42f, "device_destroy" },
	{ 0xdb96c8a6, "device_create" },
	{ 0x84e8af7f, "__class_create" },
	{ 0x615c316, "__register_chrdev" },
	{ 0xbb72d4fe, "__put_user_1" },
	{ 0x703d4f0f, "try_module_get" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x9966c02e, "module_put" },
	{ 0xc5850110, "printk" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "D53D0E1055F810692F99D9C");
