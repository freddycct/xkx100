//room: xiaojing.c
inherit ROOM;

void create()
{
	set("short","С��");
	set("long",@LONG
���Ǹ�һ�����ߵ�С�����������һ��С�š���Χ����Ӱ�죬�㲻
��������һ�����˵Ŀ�����������ɽˮ�С�
LONG );
	set("outdoors", "yanziwu");
	set("exits",([
		"west" : __DIR__"xiaoqiao",
		"south" : __DIR__"xiaoting",
	]));
	set("no_clean_up", 0);
	set("coor/x", 820);
	set("coor/y", -1490);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}