// lancaoxie.c
// Last Modified by winder on May. 25 2001

#include <armor.h>
inherit BOOTS;

void create()
{
	set_name("烂草鞋", ({"lan caoxie", "caoxie", "shoes"}));
	set_weight(800);
	if( clonep() ) set_default_object(__FILE__);
	else 
	{
		set("unit", "双");
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}

