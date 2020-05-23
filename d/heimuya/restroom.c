// Room: /d/heimuya/restroom.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short","休息室");
	set("long", @LONG
这里是间休息室，里面有张大床。在这里睡觉非常舒服，没人能打
扰。南面是气派的长廊。
LONG );
	set("exits",([
		"east" : __DIR__"houting",
	]));
	set("sleep_room", 1);
	set("no_fight",1);
	set("no_steal",1);
	set("no_clean_up", 0);
	set("coor/x", -3260);
	set("coor/y", 4210);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
