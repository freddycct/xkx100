// powerup.c 九阳神功加力
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/powerup") &&
  !me->query("can_perform/jiuyang-shengong/powerup") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的内功中没有这种功能。");

	if( target != me ) 
		return notify_fail("你只能用九阳神功来提升自己的战斗力。\n");

	if( (int)me->query("neili") < 100 ) 
		return notify_fail("你的内力不够。\n");
	if( (int)me->query_temp("powerup") ) 
		return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("force");
	me->add("neili", -100);
	me->receive_damage("qi", 0);

	message_combatd(HIR"$N微一凝神，运起九阳神功，全身骨节发出一阵爆豆般的声响, 将全身潜能尽数提起！\n" NOR, me);

	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/dodge", skill/3);
	me->set_temp("powerup", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill);

	if( me->is_fighting() ) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
	if ( (int)me->query_temp("powerup") )
	{
		me->add_temp("apply/attack", - amount);
		me->add_temp("apply/dodge", - amount);
		me->delete_temp("powerup");
		tell_object(me, "你的九阳神功运行完毕，将内力收回丹田。\n");
	}
}
int help(object me)
{
	write(WHT"\n九阳神功之加力："NOR"\n");
	write(@HELP

	使用功效：
		提升自己的攻击防御能力

	出手要求：
	        内力100
HELP
	);
	return 1;
}

