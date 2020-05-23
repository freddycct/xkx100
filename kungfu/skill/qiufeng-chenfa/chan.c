// chan.c 秋风尘法 缠字诀
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "「缠」字诀"
int perform(object me, object target)
{
	string msg;
	object weapon;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname))
   return notify_fail("你所使用的外功中没有这种功能。\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "whip")
		return notify_fail("你使用的武器不对。\n");

	fskill = "yunv-xinfa";
	bskill = "whip";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(fskill)+"火候不够使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(sskill)+"的修为不够，不能使用"+PNAME+"。\n");

	if( (int)me->query("neili") < 200 )
		return notify_fail("你的内力还不够高！\n");

	if( target->is_busy() )
		return notify_fail(target->name()+"目前正自顾不暇，放胆攻击吧。\n");

	msg = CYN"$N"CYN"使出秋风尘法「缠」字诀，拂尘连挥企图把$n"CYN"的全身缠住。\n";
	me->start_busy(random(1));
	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/2)
	{
		msg += "结果$p被$P攻了个措手不及。\n" NOR;
		target->start_busy((int)me->query_skill(bskill)/20+2);
	} else {
		msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
		me->start_busy(4);
	}
	message_combatd(msg, me, target);
	me->add("neili",-100);
	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		迟滞对方出手

	出手要求：
		秋风尘法60级
		内力200
HELP
	);
	return 1;
}

