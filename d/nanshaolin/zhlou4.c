// Room: /d/nanshaolin/zhlou4.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��¥�Ĳ�");
	set("long", @LONG
������¥�ݴ��ֻ����һ�����£�ǽ��Ҳ�Ա���Щ������Խ��������
���ߵ����䳡���޺��ã�������������Ŀ������ɮ�����㼯�����䳡��
ϰ�䣬ߺ����һ���󴫽����ġ����ߵ������ɽ�ŵ�Ҳ��¶ȫò��
LONG );
	set("exits", ([
		"up"   : __DIR__"zhlou5",
		"down" : __DIR__"zhlou3",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1840);
	set("coor/y", -6280);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}


