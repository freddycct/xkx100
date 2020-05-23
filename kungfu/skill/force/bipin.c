// Last Modified by winder on Feb. 28 2001
// bipin.c 内力比拼
 
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int start_bipin(object me);

int exert(object me, string arg)
{
	object target;
	int myint,taint,mydex,tadex,mydodge,tadodge;
	int myexp,taexp,myneili,taneili;
	
	seteuid(getuid());

	if(!arg) return notify_fail("你想和谁比拼内力？\n");

	if(!objectp(target = present(arg, environment(me))))
		return notify_fail("这里没有这个人。\n"); 

	if( !target->is_fighting() ||
		!target->is_character() ||
		!me->is_fighting() )
		return notify_fail("内力比拼只能在战斗中使用。\n");

	if ( !living(target) || target->query_temp("noliving") )
		return notify_fail("你似乎不用再和"+target->name()+"比拼内力。\n"); 

	if(target==me) return notify_fail("想和自己比拼内力？\n"); 

	if(!me->is_fighting(target))
		return notify_fail("你必须在"+target->name()+"和你战斗的时候，才能使用内力比拼。\n");		

	if(me->query_temp("weapon") || target->query_temp("weapon"))
		return notify_fail("在双方空手战斗的时候才能使用内力比拼。\n");

	myneili = me->query("neili");
	taneili = target->query("neili");

	if(me->query_skill("force", 1) < 50 )
		return notify_fail("你的内功修为不足，无法和对手较量内力。\n");

	if(myneili < 500 )
		return notify_fail("你的真气太弱，无法和对手较量内力。\n");

	if(myneili*2/3 >= taneili)
		return notify_fail("对手的内功修为远不如你，还用比拼什么内力呢？\n");

	if((int)me->query("max_neili") < 500 )
		return notify_fail("你的内力修为太弱，无法和对手较量内力。\n");

	if(me->query_temp("neili/bipin")) 
		return notify_fail("你正在和人比拼内力。\n");

	if(target->query_temp("neili/bipin")) 
		return notify_fail(target->name()+"正在和人比拼内力。\n");  

	myint = me->query_int();
	taint = target->query_int();
	mydex = me->query_dex();
	tadex = target->query_dex();
	myexp = me->query("combat_exp",1);
	taexp = target->query("combat_exp",1); 
	mydodge = me->query("dodge");
	tadodge = target->query("dodge");
	me->set_temp("bipin/target", target->query("id"));
	target->set_temp("bipin/target", me->query("id"));

	write(HIY"你凝聚毕生功力缓缓推出一掌，一股劲风已然压向" + target->name() + "压了过去。\n"NOR);
	tell_room( environment(me), HIY+me->name()+"运起毕生功力缓缓推出一掌，一股劲风已然向" + target->name() + "压去。\n"NOR, ({ me })); 

	if (((myint*5+mydex*5+mydodge+myexp*2/100000) >= (taint*5+tadex*5+tadodge+taexp*2/100000)*2/3)&&(random(5)>=2))
	{
		message_combatd(HIW"$n骇然至极，连忙双腿弹起，向后跃出数丈，才勉强躲开$N这凶猛一击。\n"NOR, me, target);
		me->add("neili", -200);
		if( me->query("neili") < 0) me->set("neili", 0);
		me->start_busy(3);
		target->start_busy(2);
                return 0;
	} 
	else 
	{
	message_combatd(HIY"$n眼看无法躲闪，急忙运足真气，硬接了$N的双掌。\n"NOR, me, target);

	me->add("neili",-200);
	if( me->query("neili") < 0) me->set("neili", 0);
	target->add("neili",-200);
	if( target->query("neili") < 0) target->set("neili", 0);
	me->set_temp("neili/bipin",1);
	target->set_temp("neili/bipin",1);
	me->set_temp("bipin/target", target->query("id"));
	target->set_temp("bipin/target", me->query("id"));
	target->start_busy((: start_bipin :));
	me->start_busy((: start_bipin :));
	me->set_temp("bipin/period", 1);
	return 1;
        }
}
int start_bipin(object me)
{
	string tar;
	object target, *all;
	int myneili_lost, obneili_lost, period, neili, neili2, count, ok=1;

	if(!me) return 0;
	all = all_inventory(environment(me));
	for (count=0; count<sizeof(all); count++)
		if( all[count]->query("id") == me->query_temp("bipin/target"))
		{
			ok = 0;
			target = all[count];
		}
	if (ok == 1) return 0;

	neili = me->query("neili");
	neili2 = target->query("neili");
	myneili_lost = target->query("max_neili")/200 + target->query("force")/20 + random (3);
	obneili_lost = me->query("max_neili")/200 + me->query("force")/20 + random (3);
	period = (int)me->query_temp("bipin/period"); 

	me->add("neili", -myneili_lost);
	if( me->query("neili") < 0) me->set("neili", 0);
	me->receive_damage("jing", 3+random(target->query_skill("force")/10));	
	me->receive_damage("qi", target->query("jiali")/10);
	me->improve_skill("force", random(2));

	target->add("neili", -obneili_lost);
	if( target->query("neili") < 0) target->set("neili", 0);
	target->receive_damage("jing", 3+random(me->query_skill("force")/20));	
	target->receive_damage("qi", me->query("jiali")/10);
	target->improve_skill("force", random(2));

	if(me->is_ghost()) return 0;
	if(!target || target->is_ghost() ||
		environment(me)!=environment(target))
	{
		message_combatd(CYN"$N当下内劲一收，一双衣袖便即垂下，摇摇幌幌地站了起来。\n"NOR, me);
		return 0;
	}

	if(neili < myneili_lost)
	{
		message_combatd(RED"$N只觉压力越来越重，胸口烦恶，渐渐每喘一口气都感艰难，突然身体一阵摇晃，晕到在一旁。\n"NOR, me);
		me->unconcious();
		me->add("max_neili",-5); 
		me->set_delete("bipin/target",);
		target->set_delete("bipin/target",);
		me->delete_temp("neili/bipin");
		target->delete_temp("neili/bipin");
		message_combatd(HIW"$N只觉得心神俱衰，深深吸了口气，但脸色惨白如纸。\n"NOR,target);
		return 0;
	} 
	if( (!living(target) || target->query_temp("noliving") ) &&
		(living(me) && !me->query_temp("noliving")) )
	{
		message_combatd(RED"$N只觉压力越来越重，胸口烦恶，渐渐每喘一口气都感艰难，突然身体一阵摇晃，晕到在一旁。\n"NOR, target);
		target->unconcious();
		target->add("max_neili",-5);
		target->unconcious();
		message_combatd(HIW"$N深深吸了口气，压住散乱的真气，脸色惨白如纸。\n"NOR,me);
		me->delete_temp("bipin/target",);
		target->delete_temp("bipin/target",);  
		me->delete_temp("neili/bipin");
		target->delete_temp("neili/bipin");  
		return 0;
	}
	if( (!living(target) || target->query_temp("noliving") ) &&
		(!living(me) || me->query_temp("noliving")) )
	{
		me->set_delete("bipin/target");
		target->set_delete("bipin/target");
		me->delete_temp("neili/bipin");
		target->delete_temp("neili/bipin");
		message_combatd(HIW"此时$N脸上都已无半点血色，看来已经到了油尽灯枯之时！\n"NOR, me);
		me->set_temp("last_damage_from","和"+target->name()+"同归于尽");
		me->die();
		return 0;
	}

	switch(period)
	{
		case 3: 
		case 9:
		case 15:
		case 21: 
		case 27:
		case 33:
		case 39:
		case 45:
		case 51:
		case 57:
			if((neili+neili2) >=1500)
			{
				message_combatd(HIW"不一会，$N和$n头顶都透出一缕缕的白气，渐渐越来越浓，就如蒸笼一般。\n"NOR, me, target);
			}
			break;
		case 63:
		case 69:
		case 75:
		case 81:
		case 87:
		case 93:
		case 99:
		case 115:
		case 145:
		case 175:
		case 205:  
			if(neili > neili2)
			{
				message_combatd(HIR"$N催动内劲，头顶白气越聚越浓，双掌缓缓的向$n推去。\n"NOR,me, target);
			}
			else
			{
				message_combatd(HIR"$N催动内劲，头顶白气越聚越浓，双掌缓缓的向$n推去。\n"NOR,target,me);
			}
			break;
		case 12:
		case 24:
		case 42:
		case 60:
		case 78:  
		case 96: 
		case 125:
		case 155:
		case 185:
			if(neili > neili2)
			{
				message_combatd(HIR"$N头顶白气凝聚不散，面色越来越严峻，不断鼓动内劲向$n推去。\n"NOR, me, target);
			}
			else
			{
				message_combatd(HIR"$N头顶白气凝聚不散，面色越来越严峻，不断鼓动内劲向$n推去。\n"NOR, target, me);
			}
			break; 
		case 36:
		case 54:
		case 72:
		case 90:
		case 105:
		case 135:
		case 165:
		case 195:
			if(me->query("jiali") < target->query("jiali"))
			{
				message_combatd(HIR"$N只觉手上一沉，对方力道涌来，忙加劲反击。\n"NOR,me);
			}
			else
			{
				message_combatd(HIR"$N只觉手上一沉，对方力道涌来，忙加劲反击。\n"NOR,target);
			}
			break;
	} 

	period++;
	me->set_temp("bipin/period", period);
//	target->set_temp("bipin/period", period);
//	me->delete_temp("neili/bipin");
//	target->delete_temp("neili/bipin");
	return 1;	
}

int help(object me)
{
	write(WHT"\n基本内功之内力比拼："NOR"\n");
	write(@HELP

	使用功效：
		与对手比拚内力至不死不休，抑或两败俱伤

	出手要求：
		基本内功50级
		内力修为500
		内力500
HELP
	);
	return 1;
}

