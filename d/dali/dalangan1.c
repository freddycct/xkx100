//Room: /d/dali/dalangan1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�����");
	set("long",@LONG
����һ�ô��������������ڴ˽���һ���൱��ĸ������²�����
��һ��Ȧ��ʮ��ͷţ���Աߵ�¥���޵��Ŀ������������Ǳ��ص���
���˼ҡ�
LONG);
	set("objects", ([
	   __DIR__"npc/shanyang": 3,
	   __DIR__"npc/cow": 2,
	]));
	set("outdoors", "dalie");
	set("exits",([ /* sizeof() == 1 */
	    "west"  : __DIR__"nongtian4",
	    "up"    : __DIR__"dalangan2",
	]));
	set("coor/x", -30940);
	set("coor/y", -70600);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}