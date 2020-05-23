// sanjue.c  达摩剑 [达摩三绝剑]
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "「达摩三绝剑」"
int perform(object me, object target)
{
	object weapon, ob;
	string msg, string1;
	int count;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname) )
   return notify_fail("你所使用的外功中没有这种功能。\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
			return notify_fail("你使用的武器不对。\n");

	if((int)me->query_dex() < 30)
		return notify_fail("你的身法不够, 目前还不能使用这项绝技! \n");
	fskill = "hunyuan-yiqi";
	bskill = "dodge";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(fskill)+"的修为不够, 不能使用"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 135 )
		return notify_fail("你的"+to_chinese(sskill)+"修为不够，目前不能使用"+PNAME+"。\n");
	if( (int)me->query_skill(bskill, 1) < 135 )
		return notify_fail("你的"+to_chinese(bskill)+"修为不够, 不能使用"+PNAME+"。\n");
	if( (int)me->query("neili") < 500 )
		return notify_fail("你的真气不够！\n");

	msg = HIG "$N使出达摩剑的绝技「达摩三绝剑」，身法陡然加快！\n" NOR;
	 message_combatd(msg, me);

	for (count=0;count<3;count++)
	{
		if (flag == 1) target = offensive_target(me);
		if (!objectp(target)) break;
 		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
	}
	me->add("neili", -150);
	me->start_busy(1+random(2));

	if(!ob->is_fighting(me)) target->fight_ob(me);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		连续出手三剑

	出手要求：
		混元一气功60级
		达摩剑135级
		基本轻功135级
		后天身法30
		内力500
HELP
	);
	return 1;
}

