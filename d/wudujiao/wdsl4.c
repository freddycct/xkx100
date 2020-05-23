// Room: /d/wudujiao/wdsl4.c

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
                "eastup" : __DIR__"wdsl5",
                "south" : __DIR__"baidu1",
                "westdown" : __DIR__"wdsl3",
                "north" : __DIR__"qiandu1",
        ]));

	set("coor/x", -44960);
	set("coor/y", -81060);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}