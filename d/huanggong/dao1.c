// Room: /d/huanggong/dao1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ͻ�����Ǽ�Ĺ���. ƽ����һЩ��������ڹ�, ��������·
��. �⹬����ÿ�ն��д�����������Ѳ��, �����ҪС��. �������߸�
�ߵĺ�ǽ, ����Ϊ���������ָ��ֵ�.
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"wumen",
		"east" : __DIR__"jiao1",
	]));
	set("no_clean_up", 0);

	set("coor/x", -190);
	set("coor/y", 5210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}