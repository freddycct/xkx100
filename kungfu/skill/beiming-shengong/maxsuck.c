// maxsuck.c
// Last Modified by sega on . i4 10 2000

#include <ansi.h>

inherit F_SSERVER;
int exert(object me, object target)
{
	int sp, dp;
	int my_max, tg_max;

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/maxsuck") &&
  !me->query("can_perform/beiming-shengong/maxsuck") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("����ʹ�õ��ڹ���û�����ֹ��ܡ�");
	if ( target == me ) target = offensive_target(me);

	if( environment(me)->query("no_fight") )
		return notify_fail("�����ﲻ�ܹ������ˡ�\n");

	if( !objectp(target) ||
		target->query("id") == "mu ren" ||
		target->query("id") == "shi ren" ||
		target->query("id") == "jiguan ren" ||
		target->query("id") == "xiangpi ren" ||
		target->query("id") == "zhang men" ||
		target->query("id") == "jin ren" ||
		target->query("id") == "gongping zi" ||
		target->query("id") == "du jiangshi")
		return notify_fail("��Ҫ��ȡ˭�ĵ�Ԫ��\n");

	notify_fail("������Ҫץ���ˣ���ʲô���֣�\n");
	if (!userp(target) && !target->accept_hit(me)) return 0;
	if (target->query("race") != "����")
		return notify_fail("����ˣ�ֻ���˲����е�Ԫ��\n");
       
	my_max = me->query("max_neili");
	tg_max = target->query("max_neili");

	if ( me->query_temp("sucked") )
		return notify_fail("��ո���ȡ����Ԫ��\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʩ�ñ�ڤ�����˵�Ԫ��\n");

//	if( !me->is_fighting() || !target->is_fighting())

	if( (int)me->query_skill("beiming-shengong",1) < 90 )
		return notify_fail("��ı�ڤ�񹦹���������������ȡ�Է��ĵ�Ԫ��\n");

	if( (int)me->query("neili") > 2*(int)me->query("max_neili")  )
		return notify_fail(HIR "��ֻ�����������ƺ�Ҫ���ѿ�һ�㣬���������ѵ�֮����\n"NOR);

	if( (int)me->query("neili") < 20 )
		return notify_fail("�����������������ʹ�ñ�ڤ�񹦡�\n");

	if( (int)me->query_skill("force") < (int)me->query("max_neili") /10 )
		return notify_fail("����ڹ�̫���ˣ�����ȡҲ��ͽ�͡�\n");

	if( (int)target->query("max_neili") < 100 )
		return notify_fail( target->name() + "��Ԫ��ɢ������δ�ۣ����޷�����������ȡ�κζ�����\n");

	if( (int)target->query("max_neili") < (int)me->query("max_neili")/10 )
		return notify_fail( target->name() + "���ڹ���ΪԶ�����㣬���޷�����������ȡ��Ԫ��\n");

	message_combatd(HIG"$Nȫ��һ��������֣���������$n���ֱ��ϡ�\n\n" NOR,me,target);

	if ( living(target) && !target->query_temp("noliving") )
	{
		if( !target->is_killing(me) ) target->kill_ob(me);
	}

	sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("lingboweibu",1)/2;
	dp = target->query_skill("force") + target->query_skill("dodge"); 
	me->set_temp("sucked", 1);

	if (( random(sp) > random(dp) ) ||
		!living(target) || target->query_temp("noliving") )
	{
		tell_object(target, HIR"��ֻ��ȫ��������ȫ����������ѩ����ʧ����Ӱ���٣�\n" NOR);
		tell_object(me, HIG"�����" + target->name() + "�ĵ�Ԫ������ԴԴ���������˽�����\n" NOR);

		target->add("max_neili",  -1*(1+(me->query_skill("beiming-shengong", 1)-90)/5) );
		me->add("max_neili", 1*(1+(me->query_skill("beiming-shengong",1)-90)/5) );
		if ( target->query("max_neili") <1) target->set("max_neili",0);

/*
		if((int)me->query("potential")-(int)me->query("learned_points")<90) me->add("potential",  5);
		me->add("combat_exp", 10);
*/
		me->start_busy(7);
		target->start_busy(random(7));
		me->add("neili", -10);

		call_out("del_sucked", 10, me);
	}
	else
	{	
		message_combatd(HIY "����$p������$P����ͼ����������˿�ȥ��\n" NOR, me, target);
		me->start_busy(7);
		call_out("del_sucked", 20, me);
	}
	return 1;
}

void del_sucked(object me)
{
	if ( me->query_temp("sucked") ) me->delete_temp("sucked");
}

int help(object me)
{
	write(WHT"\n��ڤ��֮��ȡ��Ԫ��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		��ȡ�Է���Ԫ
		��ǿ�Լ���������

	����Ҫ��
		��ڤ��90��
		����20
HELP
	);
	return 1;
}
