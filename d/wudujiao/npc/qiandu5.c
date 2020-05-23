// qiandu5.c
inherit NPC;
#include <ansi.h>

void create()
{
        set_name("莽牯朱蛤",({"chan chu"}));

        set("race", "野兽");
        set("long", "一只拳头大小，叫声洪亮的毒蛤蟆。\n");
        set("age", 1000);
        set("attitude", "peaceful");

        set("max_jing", 500);
        set("max_qi", 500);

        set("str", 30);
        set("con", 50);

        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/armor", 100);
        set_skill("unarmed",80);
        set_skill("parry",80);
        set_skill("dodge",80);
        set_skill("force",80);
        set("combat_exp", 150000);
        set_weight(500000);

        setup();
}
void init()
{
        object me,ob;
        add_action("do_train", "xun");
        if (interactive(me = this_player()) && 
            (string)me->query("family/family_name") != "五毒教")
        if (interactive(me = this_player()))
        {
               remove_call_out("kill_ob");
               call_out("kill_ob", 1, me);
        }
        ::init();
}

int hit_ob(object me, object ob, int damage)
{
       if ((string)ob->query("family/family_name") != "五毒教") {
                ob->apply_condition("chanchu_poison", 20
              +(int)ob->query_condition("chanchu_poison") );
              tell_object(ob, HIG "你觉得被咬中的地方一阵麻木！\n" NOR );
       }
}

#include "qiandu.h";
