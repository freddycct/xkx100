// zhixiang.c 制香道长

#include "daozhang.h"
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

string ask_job();
void greeting(object);
int do_say(string);
int do_kill(string);

void create()
{
	set_name("凌虚道长", ({ "lingxu daozhang", "lingxu", "daozhang" }));
	set("long","他就是武当的制香道长，殷梨亭的弟子。每天来武当烧香的人太多了，他和\n他手下的几个伐木道士都忙不过来了。\n");
	set("gender", "男性");
	set("nickname", "制香道长");
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "taoist");
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("max_qi", 800);
	set("max_jing", 400);
	set("neili", 700);
	set("max_neili", 700);
	set("jiali", 30);
	set("combat_exp", 50000);
	set("score", 5000);

	set_skill("force", 70);
	set_skill("taiji-shengong", 60);
	set_skill("dodge", 70);
	set_skill("tiyunzong", 70);
	set_skill("unarmed", 70);
	set_skill("taiji-quan", 70);
	set_skill("parry", 70);
	set_skill("sword", 70);
	set_skill("wudang-jian", 60);
	set_skill("wudang-quan", 60);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "wudang-jian");
	map_skill("sword", "wudang-jian");

	set("inquiry", 
	([
		"香火" : "香火练制不易，不能随便于人，虔诚奉献者方能得之。\n",
		"进香" : "进香？童言无忌！童言无忌！要说敬香才是！\n",
		"敬香" : "殿堂的香火能绵延不断，都因为我武当弟子和山外香客及时敬奉。\n",
		"虔诚奉献" : "虔诚奉献就是主动多捐献香火钱，多作义工。\n",
		"敬奉" : "敬奉就是主动多捐献香火钱，多作义工。\n",
		"松林" : "武当松林在山门附近。\n",
		"柏林" : "武当柏林就在遇真宫后。\n",
		"材料" : "材料就是红松和青柏，我每天都要派人去砍伐。\n",
		"砍树" : (: ask_job :),
		"伐木" : (: ask_job :),
		"job"  : (: ask_job :),
		"wook" : (: ask_job :),
		"工作" : "我这里每天都需要人去砍树，如果你能主动送些过来，那更好。\n",
		"干活" : "我这里每天都需要人去砍树，如果你能主动送些过来，那更好。\n",
	]));
	set("chat_chance", 5);
	set("chat_msg", ({
		"凌虚道长说道：香火练制不易，不能随便于人，虔诚奉献者方能得之。\n",
		"凌虚道长说道：红松和青柏都是炼制香火的好材料。\n",
		"凌虚道长说道：制香材料是从林子里砍伐而来。\n",
		"凌虚道长说道：武当的松林和柏林都长了几百年了，还没有人走通过。\n",
		"凌虚道长说道：砍树的时候要多加小心，我派出砍树的道士，有些就有去无回。\n",
	}) );
	set("wanted", ({ HIR"红松树干"NOR, HIG"青柏树干"NOR }));
	create_family("武当派", 3, "弟子");

	setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object(CLOTH_DIR"dao-cloth")->wear();
	carry_object(CLOTH_DIR"dao-shoe")->wear();
}

void init()
{
	object me = this_player();
	
	::init();
	if( interactive(me) )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me);
	}
}

void greeting(object me)
{
	mapping myfam;
	object where, ob;

	ob = this_object();
	myfam = (mapping)me->query("family");
	where = environment(ob);

	if( !me || !living(ob) ||
		strsrch(file_name(where), "/d/wudang/") < 0 ||
		environment(me) != environment() )
		return;
	if ( (string)me->query("wdjob/supervisor") == "凌虚道长" )
	{
		me->set_temp("apply/short", 
			({ HIW"武当伐木　"NOR+me->query("name")+"("+capitalize(me->query("id"))+")"}));
		message_vision("凌虚道长盯住$N：我托你去找的" + me->query("wdjob/object") +"可有着落了？\n", me);
	}
	else
		if ( myfam && myfam["family_name"] == "武当派" )
		{
			if ( me->query("wudang/offerring") < me->query("age") )
				message_vision("凌虚道长对着$N怒斥道：你疏于敬奉，离被逐出山门不远了！\n", me);
			else if ( me->query("wudang/offerring") <
					me->query("age")*4/3)
				message_vision("凌虚道长对着$N语重心长：凡我武当弟子，都应勤勉奉献，"+RANK_D->query_respect(me)+ "要加强努力啊！\n",me);
			else if ( me->query("wudang/offerring") <
					me->query("age")*2)
				message_vision("凌虚道长对$N说道：" + RANK_D->query_respect(me) + "能尽职贡奉，众道长对你很满意。\n", me);
			else message_vision("凌虚道长指着$N赞叹道：" + RANK_D->query_respect(me) + "勤于敬奉，真乃我辈楷模也！\n", me);
		}
		else if ( me->query("title") == "武当道童" ) 
			message_vision("凌虚道长对着$N说道：继续努力，争取早日入我山门。\n", me);
		else if ( me->query("wudang/offerring") > me->query("age")*2 ) 
			message_vision("凌虚道长对着$N问候道：原来是大香客到了！失迎、失迎！\n", me);
		else if ( me->query("wudang/offerring") > me->query("age") ) 
			message_vision("凌虚道长对着$N问候道：这位香客请了！\n", me);
		else 
		{
			me->set("wudang/yuzhen_block", 1);
			say("凌虚道长说道：如不是敬香，请勿上山！\n");
		}
}

string ask_job()
{
	object ob;
	string what;
	string *wanted;

	ob = this_player();

	if ( ob->query("wdjob/supervisor") )
	{
		command("say 你第一份活儿都没做完就想做第二份？");
		if ( ob->query("wdjob/supervisor") == "凌虚道长") 
		{
			add_action("do_say", "say");
			return("如果你干不了我派给你的活，可以直接跟我说你干不了。");
		}
		return ("如果你干不了，可以直接去告诉"+ob->query("wdjob/supervisor"));
	}
	if (query_temp("stock") > 10)
		return ("你来晚了，今天的活儿我都分派完了。");
	add_temp("stock", 1);
	wanted = query("wanted");
	what = wanted[random(sizeof(wanted))];

	ob->set("wdjob/supervisor", "凌虚道长");
	ob->set("wdjob/object", what);
	ob->set("wdjob/description", what);
	ob->set("wdjob/wage", 3);
	ob->set_temp("apply/short", ({ HIW"武当伐木　"NOR+ob->query("name")+"("+capitalize(ob->query("id"))+")"}));
	message_vision("凌虚道长高兴对$N说道：来得正好，这里正缺人手！\n", ob);
	return ("我需要"+ what +CYN"造香用，你去给我砍些来吧！\n");
}

int accept_kill(object obj)
{
	object ob=this_object();
	if (obj->is_killing(this_object()) ) return 1;
	if ( obj->query("wdjob/supervisor") == "凌虚道长" )
	{
		message_vision("$N想杀掉$n。\n$n厉声对$N道：你想造反哪？！报酬扣消。\n", obj, ob);
		obj->set("wdjob/wage", 0);
		return 0;
	}
	else if ( obj->query("family/family_name") == "武当派" )
	{
		message_vision("$N想杀掉$n。\n$n厉声对$N道：你我本同门，却为何想相害于我！\n$n对$N很不满意！\n", obj, ob);
		obj->add("wudang/offerring", -20);
		return 0;
	}	
	else
	{
		command("family 各位武当同门，" + obj->name() + "这个" + RANK_D->query_rude(obj) + "胆敢在武当撒野，大伙儿一起跟我上！");
	  return 1;
	}
}

int accept_object(object who, object ob)
{

	object obn, wage;
	int i, j, k;
	string *wanted;


	if (ob->query("money_id") && ob->value() >= 100*(int)who->query("age") )
	{
		if ((string)(who->query("family/family_name")) == "武当派") 
			tell_object(who, "凌虚道长哈哈一笑：既然道"+(((string)who->query("gender")=="女性")?"姑":"兄")+"如此诚心向道，我这有新制香火一枝，请拿去贡奉吧。\n");
		else
			tell_object(who, "凌虚道长哈哈一笑：既然施主如此诚心向道，我这有新制香火一枝，请施主拿去贡奉吧。\n");
		obn = new("/d/wudang/obj/incense");
		obn->move(who);
		return 1;
	}
	else
		if (ob->query("money_id") )
		{
			if((string)(who->query("family/family_name"))=="武当派")
				tell_object(who, "凌虚道长对你赞叹道：武当山香火鼎盛，全靠象道"+(((string)who->query("gender")=="女性")?"姑":"兄")+"你这样捐献香火啊！\n");
			else
				tell_object(who, "凌虚道长对你赞叹道：武当山香火鼎盛，全靠象您这样的虔诚香客啊！\n");

			return 1;
		}
		else if (((string)who->query("wdjob/supervisor")=="凌虚道长") &&
				(string)who->query("wdjob/object") ==
				(string)ob->query("name") )
		{
			i = (int)who->query("wdjob/wage");
			if (i < 0 || i >= 13) i = 2;

			wage = new("/clone/money/silver");
			wage->set_amount(i);
			wage->move(who);

			command("say 有劳这位"+RANK_D->query_respect(who)+"了。");
			command("thumb " + who->query("id"));
			message_vision("凌虚道长给$N"+chinese_number(i)+"两白银作为工作报酬。\n", who);

			who->add("combat_exp", 1+random(i));
			who->add("wudang/offerring", 1+random(i/4));
			who->delete_temp("apply/short");
			who->add("wdjob/succeed", 1);
			who->delete("wdjob/supervisor");
			who->delete("wdjob/description");
			who->delete("wdjob/wage");
			who->delete("wdjob/object");

			return 1;
		}
		else if( (int)member_array((string)ob->query("name"), (string *)query("wanted")) != -1 )
		{
			if ( query_temp("stock") > 10 )
			{
				say("凌虚道长摇摇头说：多谢这位" +RANK_D->query_respect(who)+"，可是我要的材料都已经有着落了。\n");
				return 1;
			}
			message_vision("凌虚道长高兴对$N说道：来得正好，这正是我所需要的！\n", who);
			add_temp("stock", 1);
			who->add("wudang/offerring", random(1));
			i = (int)who->query("wdjob/wage");
			j = who->query("wudang/offerring")-who->query("age")*2; 
			if ( (who->query("family/family_name") == "武当派" ) && 
				(j > 0 ) )
			{
				who->add("combat_exp", (j+i)/2 + random(i+j));
				k = j/2 + random(i);
				who->add("potential", k);
				if ( random(2) ) 
				{
					tell_object(who, "我这有新制香火一枝，你拿去贡奉吧。\n");
					who->add("wudang/offerring", -1-random(3));
					obn = new("/d/wudang/obj/incense");
					obn->move(who);
				}
			
			}
			else if ( who->query("family/family_name") == "武当派" )
			{
				who->add("combat_exp", i/2+random(i));
				k = 1+random(i);
				who->add("potential", k);
			}
			else who->add("combat_exp", 1+random(i));
			command("say 你如此自愿为武当效力，日后必成武当栋梁！");
			command("thumb " + who->query("id"));
			return 1;
		}
	return 0;
}


int do_say(string arg)
{
	object ob, who;

	who = this_player();
	ob = this_object();

	if ( (string)arg != "干不了") return 0;
	if ( who->query("wdjob/supervisor") != ob->query("name")) return 0;

	message_vision("$N低声说道：道长分派的活我干不了…\n", who);
	command("pat "+ who->query("id"));
	command("say 没关系，下次好好干！");

	this_object()->add_temp("stock", -1);
	who->delete_temp("apply/short");
	who->add("wdjob/fail", 1);
	who->delete("wdjob/supervisor");
	who->delete("wdjob/description");
	who->delete("wdjob/wage");
	who->delete("wdjob/object");

	return 1;
}
