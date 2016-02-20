// Room: /d/shaolin/wuxing3.c
// Date: YZC 96/02/06

#include <ansi.h>

inherit ROOM;

string* dirs = ({"east", "south", "west", "north"});

void create()
{
	set("short", HIR "���ж�" NOR);
	set("long", HIR @LONG
�������ж��������پ�һ��������������������������
��ȥ������һƬͨ�죬������ð��˿˿�������ŵ׾��ҵ���ʹʹ
�㼸�����Ų�ס���ȷ����¡¡�������Ŷ��ģ������������
��¯֮�У�ȫ����ˮ�ֶ��ڱ�һ�εεؿ��ɡ�ǽ���ϼ��߿ݲ��
�ĸ�ʬ��֤������һ�㡣
LONG
NOR	);
	set("exits", ([
		"east" : __DIR__"wuxing1",
		"south" : __DIR__"wuxing2",
		"west" : __DIR__"wuxing0",
		"north" : __DIR__"wuxing4",
	]));
	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 785);
	set("coor/z", 100);
	set("no_quest",1);
	setup();
}

int check_out(object me)
{
	int metal, wood, water, fire, earth;

	metal = me->query_temp("wuxing/��");
	wood = me->query_temp("wuxing/ľ");
	water = me->query_temp("wuxing/ˮ");
	fire = me->query_temp("wuxing/��");
	earth = me->query_temp("wuxing/��");

	if ( metal > 0 &&
		metal == wood && metal == water &&
		metal == fire && metal == earth )
	{
		me->delete_temp("wuxing");
		me->move(__DIR__"andao2");
		return (1);
	}
	return (0);
}

int valid_leave(object me, string dir)
{
	int count;

	if (member_array(dir, dirs) != -1)
	{
		if (dir == "north")
		{
//			write("*������*\n");
			count = me->query_temp("wuxing/��");
			count++;
			me->set_temp("wuxing/��", count);
			if (check_out(me))
				return notify_fail("��˳�����߳��������Թ���\n");
		}
		else if (dir == "west")
		{
//			write("*��˽�*\n");
			me->delete_temp("wuxing");
			me->move(__DIR__"jianyu1");
			return notify_fail("��������أ�����ɮ�ࡣ\n");
		}
	}
	return ::valid_leave(me, dir);
}