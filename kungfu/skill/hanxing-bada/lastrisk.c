// hanxing-fada/lastrisk.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "��עһ��"
int perform(object me, object target)
{
	int i,s;
	string msg;
	object *ob;
	object weapon;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
/*  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname) )
   return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");
*/
	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "throwing")
		return notify_fail("��������а�����\n");

	fskill = "honghua-shengong";
	bskill = "throwing";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 60 )
		return notify_fail("���"+to_chinese(fskill)+"��Ϊ̫ǳ���޷�ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 60 )
		return notify_fail("���"+to_chinese(sskill)+"��Ϊ̫ǳ���޷�ʹ��"+PNAME+"��\n");

	if( me->query("max_neili") < 300)
		return notify_fail("���������Ϊ̫ǳ��\n");

	if( me->query("neili") < 200)
		return notify_fail("�������������\n");

	s = me->query_skill(bskill, 1);

	msg = CYN "$N"CYN"��עһ�����������а�������$n"CYN"��"NOR;
	me->start_busy(2);
	if(random(me->query("combat_exp"))>(int)target->query("combat_exp")/2)
	{
		msg += "���$p��$P���˸����ֲ�����\n" NOR;
		target->receive_wound("qi", random(s)*2,me);
	}
	else
	{
		msg += "����$p�����$P�����һ����\n" NOR;
	}
	message_combatd(msg, me, target);
	ob = all_inventory(me);	 //use out all throwing
	for(i=sizeof(ob)-1; i>=0; i--)
	{
		if( (string)ob[i]->query("equipped")!="wielded" ) continue;
		ob[i]->unequip();
		ob[i]->move(environment(me));
	}
	me->reset_action();
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		Ͷ���������а��������˶Է���Ѫ

	����Ҫ��
		�컨��60��
		���ǰ˴�60��
		������Ϊ300
		����200
HELP
	);
	return 1;
}
