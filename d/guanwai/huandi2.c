// /guanwai/huandi2.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
�����ǳǶ���һ����·��·�����ҵس�����ϥ�ĻĲݣ�Զ������һ
�ˡ����Ըɿݵ������������˳�Ⱥ����ѻ���������������ڻ�Ұ��ԶԶ
��ȥ��һ�������ľ���
LONG );
	set("exits", ([
		"southwest" : __DIR__"huandi1",
		"enter"     : __DIR__"shanshenmiao",
	]));
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	set("coor/x", 6080);
	set("coor/y", 5230);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}