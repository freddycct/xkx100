// Room: /d/wudujiao/wdsl5.c

inherit ROOM;

void create()
{
        set("short", "五毒山路");
        set("long", @LONG
这里是五毒山中的山间小路，蜿蜒曲折盘旋而上。山路上寂静
无声，看不到一丝鸟兽的痕迹。你顺手拨开伸向路中的枝条，树枝
忽然一动，缩了回去，“哇...”竟然是一条形似枯枝的毒蛇。
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "eastup" : __DIR__"wdsl8",
                "westdown" : __DIR__"wdsl4",
                "north" : __DIR__"wdsl6",
        ]));

	set("coor/x", -44950);
	set("coor/y", -81060);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}