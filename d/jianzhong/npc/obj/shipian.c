#include <ansi.h>
inherit ITEM;
int do_study(string arg);
void init()
{
	add_action("do_study","yanxi");
}
void create()
{
        set_name(HIC"��ʯƬ"NOR, ({ "chang shipian", "stone", "shipian" }) );
        set_weight(5000);
        set("unit", "��");
        set("long",HIC@LONG
һ������ͨͨ�ĳ���ʯƬ��������Щϸϸ����·��������ʲô�ر�֮����
LONG
NOR
);
        set("value", 1);
        set("material", "stone");
        setup();
}
int do_study(string arg)
{
	object me = this_player();
	int dugulevel = me->query_skill("dugu-jiujian-sword",1);
	if ( (arg != "stone") && (arg != "shipian") && (arg != "chang shipian") )
		return notify_fail("��Ҫѧʲô��\n");
	if ((dugulevel >= 150) && (dugulevel <= 250) )
	{
	       if( (int)me->query("combat_exp") < (int)dugulevel*dugulevel*dugulevel/10 ) 
			return notify_fail("��ֻ����ʯͷ���������ϡ����¾Ž����Ľ��⣬���Ǿ���������\nͷ����������ʵս���鲻����\n");
	       if( (int)me->query("jing") < 25 ) 
        		return notify_fail("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
        	me->receive_damage("jing", 25);
		me->improve_skill("dugu-jiujian-sword", (me->query("int"))*(me->query("combat_exp")/20000));
		message("vision","���ó���ʯ����ϸ�о�������ʯ��������������������¾Ž���\n�Ľ��⣬�����¾Ž������г�����\n",me);
		message("vision",me->query("name")+"��ϸ�ж�һ��ʯƬ��\n",environment(me),me);
		return 1;
	}
	return notify_fail("�����ʯͷ������ȥ��û����ʲô����������\n");
}