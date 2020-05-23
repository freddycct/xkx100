// Room: /d/tiezhang/sslin3.c
// Last Modified by winder on Nov. 17 2000

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "松树林");
	set("long", @LONG
你走进一片黑压压的松树林，这里的松树枝繁叶茂，树冠相叠，遮
天蔽日。几素阳光从树梢间照射下来，在淡淡的雾气中，形成条条白色
的光柱，煞是好看。你走着走着，忽然发现自己已迷失在这片松林中，
找不到出去的路了。
LONG	);
	set("exits", ([ /* sizeof() == 1 */
		"west"  : __DIR__"sslin4",
		"east"  : __FILE__,
		"south" : __DIR__"sslin2",
		"north" : __FILE__,
	]));
	set("objects",([
		__DIR__"npc/laohu" : 1,
	]));
	set("outdoors", "tiezhang");
	set("no_clean_up", 0);

	set("coor/x", -2040);
	set("coor/y", -1880);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}
