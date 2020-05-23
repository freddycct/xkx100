// Room: /d/xingxiu/shamo2.c
// Last Modified by winder on Feb. 28 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short","大沙漠");
	set("long", @LONG
这是一片一望无际的大沙漠。你一进来就迷失了方向。看来要走出
这块沙漠并非易事。
LONG );
	set("outdoors", "xiyu");
	set("no_clean_up", 0);
	set("exits", ([
		"east" : __FILE__,
		"west" : __DIR__"shamo3",
		"south" : __DIR__"shamo4",
		"north" : "/d/npc/m_weapon/lianjianshi",
	]));
	set("coor/x", -30000);
	set("coor/y", 1000);
	set("coor/z", 0);
	setup();
}

void init()
{
	object ob;
	int water, food;
	ob = this_player();

	water = ob->query("water");
	food = ob->query("food");
	water -= (random(2)+ 1) * water / 20;
	food -= (random(2)+ 1) * food / 20;
	ob->set("water", water);
	ob->set("food", food);
}

int valid_leave(object me, string dir)
{
	if (dir == "west") me->add_temp("mark/steps",1);
	if (dir == "east") me->add_temp("mark/steps",-1); 

	if (me->query_temp("mark/steps") == 10)
	{
		me->move("/d/baituo/gebi");
		me->delete_temp("mark/steps");
		return notify_fail("你累得半死，终於走出了沙漠。\n");
	}
	if (me->query_temp("mark/steps") == -10)
	{
		me->move("/d/xingxiu/silk5");
		me->delete_temp("mark/steps");
		return notify_fail("你累得半死，终於走出了沙漠。\n");
	}
	return ::valid_leave(me, dir);
}
