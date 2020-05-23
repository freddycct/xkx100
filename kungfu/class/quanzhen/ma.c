// ma.c 马钰
// last modified 01/05/05

#include <ansi.h>
inherit NPC;

string ask_me();
string ask_ling();
string ask_array();
string ask_shu();
int do_qixing(object me, object ob);

void create()
{
        set_name("马钰", ({"ma yu", "ma"}));
        set("gender", "男性");
        set("age", 42);
        set("class", "quanzhen");
        set("nickname",MAG"丹阳子"NOR);
        set("long",
                "他就是王重阳的大弟子，全真七子之首，丹阳子马钰马真人。\n"
                "他慈眉善目，和蔼可亲，正笑着看着你。\n"
                "你可以向他要求全真令挑战你的师尊。\n");
        set("attitude", "peaceful");
        set("shen_type",1);
        set("str", 28);
        set("int", 32);
        set("con", 31);
        set("dex", 30);

        set("title","全真七子之首");

//       set("env/wimpy", 60);
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
        	(: exert_function, "powerup" :),
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                (: perform_action, "strike.ju" :),                
                (: perform_action, "whip.wuguang" :),                                
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.sanqing" :),  
		(: command("wield changjian") :),
        }));

        set("qi", 4000);
        set("max_qi", 4000);
        set("jing", 1600);
        set("max_jing", 1600);
        set("neili", 6000);
        set("max_neili", 6000);
        set("jiali", 100);

        set("combat_exp", 500000);
        set("score", 300000);

        set_skill("array", 100);
        set_skill("force", 150);
        set_skill("xiantian-qigong", 150);    //先天气功
        set_skill("sword", 140);
        set_skill("quanzhen-jian",210);  //全真剑
        set_skill("dodge", 120);
        set_skill("jinyan-gong", 180);   //金雁功
        set_skill("parry", 150);
        set_skill("unarmed", 140);
        set_skill("strike", 120);
        set_skill("haotian-zhang", 180);    //昊天掌
        set_skill("cuff", 120);
        set_skill("chunyang-quan", 180);    //纯阳拳
        set_skill("whip", 120);
        set_skill("duanyun-bian", 180);    //断云拳
        set_skill("literate", 100);
        set_skill("taoism", 110);

        map_skill("force", "xiantian-qigong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "duanyun-bian");
        map_skill("whip", "duanyun-bian");
        map_skill("strike", "haotian-zhang");
        map_skill("cuff", "chunyang-quan");
        prepare_skill("cuff", "chunyang-quan");
        prepare_skill("strike", "haotian-zhang");

        create_family("全真教", 2, "弟子");

        set("book_count",1);
        set("shu_count",1);
        set("inquiry", ([
                "全真教" :  "我全真教是天下道家玄门正宗。\n",
                "全真令" :  (: ask_ling :),
                "升级"   :  (: ask_ling :),
                "金雁功" :   (: ask_me :),
                "金雁图谱" : (: ask_me :),
                "天罡北斗阵" : (: ask_array :),
                "北斗七星阵" : (: ask_array :),
                "秘籍"      : (: ask_shu :),
                "鞭法总诀"   : (: ask_shu :),
                "shu" : (: ask_shu :),
                ]) );

        setup();

        carry_object("/clone/weapon/changbian")->wield();
        carry_object("/clone/weapon/changjian");
        carry_object(__DIR__"obj/greenrobe")->wear();
}

string ask_me()
{
        mapping fam;
        object ob;

        if (!(fam=this_player()->query("family"))||fam["family_name"]!="全真教")
                return RANK_D->query_respect(this_player()) +
                "与本教毫无瓜葛，我教的武功典籍可不能交给你。";
        if (query("book_count") < 1)
                return "你来晚了，金雁图谱已经被人取走了。";
        add("book_count", -1);
        ob = new("/clone/book/jinyantu");
        ob->move(this_player());
        return "好吧，这本「金雁图谱」你拿回去好好研读。";
}

string ask_shu()
{
	object ob;
	
	if (this_player()->query("family/master_id")!="ma yu")
		return RANK_D->query_respect(this_player()) + 
		"非我弟子，不知此话从何谈起？";
	if (query("shu_count") < 1)
		return "你来晚了，本派的秘籍不在此处。";
	add("shu_count", -1);
	ob = new("/clone/book/whip");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"拿到鞭法总诀啦。\n");
	return "好吧，这本「鞭法总诀」你拿回去好好钻研。";
}

string ask_ling()
{
	mapping fam, skl; 
	object ob, me = this_player();
	string *skillname;
	int i;
	
	if (!(fam = me->query("family")) || fam["family_name"] != "全真教")
		return RANK_D->query_respect(me) + 
		"与本教毫无瓜葛，不知此话从何谈起？";

	skl = me->query_skills();
	skillname  = sort_array( keys(skl), (: strcmp :) );

	for(i=0; i<sizeof(skl); i++) {
		if (skl[skillname[i]] < 30) 
		return RANK_D->query_respect(me) + "功力不够，不能领取全真令。";
	}

	ob = new("/d/quanzhen/obj/quanzhen-ling");
	ob->move(me);
	message_vision("$N获得一面全真令。\n", me);

	return "好吧，凭这面全真令，你可自由向你的师尊挑战。";
}

string ask_array()
{
	object room, qizi, obj, ob = this_player(), me = this_object();
	mapping ob_fam, skl; 
	string *skillname;
	int i;

	ob_fam  = ob->query("family");
	skl = ob->query_skills();

	if (sizeof(skl) <= 1)
		return RANK_D->query_respect(ob) + 
		"功力不够，不够资格闯天罡北斗阵。";
	if (ob->query("score") < 20000)
	        return RANK_D->query_respect(ob) + 
		"阅历不足，不够资格闯天罡北斗阵。";

	skillname  = keys(skl);
	for(i=0; i<sizeof(skl); i++) {
		if ((skl[skillname[i]] < 80) || (sizeof(skl) == 0))
		return RANK_D->query_respect(ob) + 
		"功力不够，不够资格闯天罡北斗阵。";
	}
	if( ob->query("qixing") )
		return RANK_D->query_respect(ob) + 
		"已然闯过天罡北斗阵，可不要拿老道开这等玩笑。";
/*
	if ( ob_fam["family_name"] != "全真教" || ob_fam["generation"] != 3)
		return RANK_D->query_respect(ob) + "，你没资格闯天罡北斗阵。";
*/
	if ( me->query("assigned_qixing") )
		return RANK_D->query_respect(ob) + "，今日有人挑战天罡北斗阵，你过一段时间再来吧。";

	me->set("assigned_qixing", ob->query("id")); 		
	command("smile");
	say("\n马钰道长说道：好吧，我去召集众师弟。稍候在大校场上等你。\n");
        message_vision("\n马钰道长往南离开。\n\n", ob);

/* 谭处端 */
	if(!( room = find_object("/d/quanzhen/rongwutang")) )
		room = load_object("/d/quanzhen/rongwutang");
  		me->move(room);
	if( !objectp(obj = present("tan chuduan", room) ))
	{
		me->move("/d/quanzhen/shiweishi");
		message_vision("\n马钰道长走了过来。\n\n", ob);
		return "真是对不起，全真七子有人不在，无法布天罡北斗阵。\n";	
	}
	message("vision","\n马钰道长走了过来，跟谭处端说了几句。\n", room, obj);
	obj->move("/d/quanzhen/daxiaochang");
	message("vision", "谭处端点了点头，快步跟了出去。\n", room, obj);

/* 刘处玄 */
	if(!( room = find_object("/d/quanzhen/jingxiushi")) )
		room = load_object("/d/quanzhen/jingxiushi");
  		me->move(room);
	if( !objectp(obj = present("liu chuxuan", room) ))
	{
		me->move("/d/quanzhen/shiweishi");
		message_vision("\n马钰道长走了过来。\n\n", ob);
		return "真是对不起，全真七子有人不在，无法布天罡北斗阵。\n";	
	}
	message("vision","\n马钰道长走了过来，跟刘处玄说了几句。\n", room, obj);
	obj->move("/d/quanzhen/daxiaochang");
	message("vision", "刘处玄点了点头，快步跟了出去。\n", room, obj);

/* 丘处机 */
	if(!( room = find_object("/d/quanzhen/laojundian")) )
		room = load_object("/d/quanzhen/laojundian");
  		me->move(room);
	if( !objectp(obj = present("qiu chuji", room) ))
	{
		me->move("/d/quanzhen/shiweishi");
		message_vision("\n马钰道长走了过来。\n\n", ob);
		return "真是对不起，全真七子有人不在，无法布天罡北斗阵。\n";	
	}
	message("vision","\n马钰道长走了过来，跟丘处机说了几句。\n", room, obj);
	obj->move("/d/quanzhen/daxiaochang");
	message("vision", "丘处机点了点头，快步跟了出去。\n", room, obj);

/* 王处一 */
	if(!( room = find_object("/d/quanzhen/wanwutang")) )
		room = load_object("/d/quanzhen/wanwutang");
  		me->move(room);
	if( !objectp(obj = present("wang chuyi", room) ))
	{
		me->move("/d/quanzhen/shiweishi");
		message_vision("\n马钰道长走了过来。\n\n", ob);
		return "真是对不起，全真七子有人不在，无法布天罡北斗阵。\n";	
	}
	message("vision","\n马钰道长走了过来，跟王处一说了几句。\n", room, obj);
	obj->move("/d/quanzhen/daxiaochang");
	message("vision", "王处一点了点头，快步跟了出去。\n", room, obj);

/* 郝大通 */
	if(!( room = find_object("/d/quanzhen/guangning")) )
		room = load_object("/d/quanzhen/guangning");
  		me->move(room);
	if( !objectp(obj = present("hao datong", room) ))
	{
		me->move("/d/quanzhen/shiweishi");
		message_vision("\n马钰道长走了过来。\n\n", ob);
		return "真是对不起，全真七子有人不在，无法布天罡北斗阵。\n";	
	}
	message("vision","\n马钰道长走了过来，跟郝大通说了几句。\n", room, obj);
	obj->move("/d/quanzhen/daxiaochang");
	message("vision", "郝大通点了点头，快步跟了出去。\n", room, obj);

/* 孙不二 */
	if(!( room = find_object("/d/quanzhen/qingjing")) )
		room = load_object("/d/quanzhen/qingjing");
  		me->move(room);
	if( !objectp(obj = present("sun buer", room) ))
	{
		me->move("/d/quanzhen/shiweishi");
		message_vision("\n马钰道长走了过来。\n\n", ob);
		return "真是对不起，全真七子有人不在，无法布天罡北斗阵。\n";	
	}
	message("vision","\n马钰道长走了过来，跟孙不二说了几句。\n", room, obj);
	obj->move("/d/quanzhen/daxiaochang");
	message("vision", "孙不二点了点头，快步跟了出去。\n", room, obj);
	ob->set_temp("pre_qixing", 1);

        me->move("/d/quanzhen/daxiaochang");
        call_out("waiting", 1, me,1);
	return "好！大家都出来了。\n";
}

int waiting(object me,int wait_time)
{
	object ob;

	if( wait_time == 300 )
	{
		say( "马钰说道：看来他不会来了，我们回去罢！\n\n");
		call_out("do_back", 0, me);
		ob->add("score",-5000);				
	}
	else if(!objectp(ob = present(me->query("assigned_qixing"),environment(me))))
	{
		wait_time++;
		call_out("waiting", 1, me,wait_time);
	}
	else call_out("preparing", 0, me, ob);

	return 1;
}

int preparing(object me, object ob)
{
	object *obs, room, obj1, obj2, obj3, obj4, obj5, obj6;
	string myname = me->query("name");
	int i;

	if(!( room = find_object("/d/quanzhen/daxiaochang")) )
	room = load_object("/d/quanzhen/daxiaochang");
	if(!objectp( obj1 = present("tan chuduan", environment(me))))
		return notify_fail("二师弟怎么不在？\n");
	if(!objectp( obj2 = present("liu chuxuan", environment(me))))
		return notify_fail("三师弟怎么不在？\n");
	if(!objectp( obj3 = present("qiu chuji", environment(me))))
		return notify_fail("四师弟怎么不在？\n");
	if(!objectp( obj4 = present("wang chuyi", environment(me))))
		return notify_fail("五师弟怎么不在？\n");
	if(!objectp( obj5 = present("hao datong", environment(me))))
		return notify_fail("六师弟怎么不在？\n");
	if(!objectp( obj6 = present("sun buer", environment(me))))
		return notify_fail("小师妹怎么不在？\n");

	me->dismiss_team();
	me->set_leader();
	me->add_team_member(obj1);
	me->add_team_member(obj2);
	me->add_team_member(obj3);
	me->add_team_member(obj4);
	me->add_team_member(obj5);
	me->add_team_member(obj6);

	say( "马钰说道：不相干的人，如不欲观摩天罡北斗阵，请即刻离开。\n");


  obs=me->query_team();
	for(i=0;i<sizeof(obs);i++)
	{
		ob->fight_ob(obs[i]);
		obs[i]->fight_ob(ob);
		if(obs[i] != me)
			message_vision(myname+"道："+obs[i]->query("name")+"请做好准备！\n",me);
	}
//	command("say chat " + ob->query("title") + ob->query("name") + 
//		"于今日" + NATURE_D->game_time() + "挑战全真天罡北斗阵！\n");
	message("channel:snow", HIC"【闯阵】马钰[Ma yu]：" + ob->query("title") + ob->query("name") + 
		HIC+"于今日" + NATURE_D->game_time() + "挑战全真天罡北斗阵！\n"NOR,users());
	say(HIC"马钰吟道：“一住行窝几十年。”\n");
	say("谭处端吟道：“蓬头长日走如颠。”\n");
	say("刘处玄吟道：“海棠亭下重阳子。”\n");
	say("丘处机接口道：“莲叶舟中太乙仙。”\n");
	say("王处一吟道：“无物可离虚壳外。”\n");
	say("郝大通吟道：“有人能悟未生前。”\n");
	say("孙不二吟道：“出门一笑无拘碍。”\n");
	say("马钰收句道：“云在西湖月在天！”\n\n\n"NOR);

	message_vision(myname+ "清了清喉咙，大声说道：好，时辰已到，现在开始启动「天罡北斗阵」！\n",me);
	message_vision(myname+ "突然身形移动，发动众全真弟子抢占位置，左边四人，右边三人，正是摆的「天罡北斗阵」阵法。\n",me);
	say("马钰位当天枢，谭处端位当天璇，刘处玄位当天玑，丘处机位当天权，四人组成斗魁；\n");
	say("王处一位当玉衡，郝大通位当开阳，孙不二位当摇光，三人组成斗柄。\n");
	remove_call_out("do_qixing");
	call_out("do_qixing", 2, me, ob);
	return 1;
}


int do_qixing(object me, object en)
{
	object *obs, weapon, enweapon;
	int i, j, power;
	string err;
	string *where = ({
		"天枢",
		"天璇",
		"天玑",
		"天权",
		"玉衡",
		"开阳",
		"摇光"
	});

	if(pointerp(obs=me->query_team()) )
	switch (random (4))
	{
		case 0:
message_vision("天罡北斗阵气势宏大，前攻后击，连环相接，让人眼花撩乱，方寸顿失。\n",me);
			break;
		case 1:
message_vision("天罡北斗阵法滚滚推动，攻势连绵不绝，瞬间将敌人围在垓心。\n",me);
			break;
		case 2:
message_vision("天罡北斗阵越缩越小，无形剑气象浪潮一般逼向中央，令人有窒息之感。\n",me);
			break;
		case 3:
message_vision("只见天罡北斗阵暗合五行八卦之理，阵中人步法精妙，攻守配合得天衣无缝，威力之大，让人叹为观止。\n",me);
			break;
	}
	for(i=0;i<sizeof(obs);i++)
	{
		weapon = obs[i]->query_temp("weapon");
		power = obs[i]->query_skill("force",1)/10;
	  obs[i]->add_temp("apply/attack", power);
	  obs[i]->add_temp("apply/damage", power);
		switch (random(2))
		{
			case 0:
message_vision("\n"+where[i]+"位上的"+obs[i]->query("name")+ "气沉丹田，暗运神功，猛然吐气开声，身形往前一纵, 但见", me);
				break;
			case 1:
message_vision("\n"+where[i]+"位上的"+obs[i]->query("name")+ "挺身而出，步法精妙，长袖飘飘，攻势如虹。只见", me);
				break;
//	               default:
		}
	  err=catch(COMBAT_D->do_attack(obs[i],en,weapon,0));
	  if (err)
	  {
		  message("channel:debug","天罡北斗阵攻击出错 err="+err,users());
	  	return 1;
	  }
		obs[i]->add_temp("apply/attack", -power);
		obs[i]->add_temp("apply/damage", -power);
		if(en->query("qi")*2 <= en->query("max_qi"))
		{
			en->remove_all_enemy();
			remove_call_out("do_end");
			call_out("do_end", 1, me, en, 0);
			return 1;
		}
	}
	j = random(sizeof(me->query_team()));
	enweapon = en->query_temp("weapon");
	if (enweapon)
  	COMBAT_D->do_attack(en,obs[j], enweapon);
	else 
  	COMBAT_D->do_attack(en,obs[j], enweapon);
	if(obs[j]->query("qi")*2 <= obs[j]->query("max_qi"))
	{
		message_vision(HIR+obs[j]->query("name")+"一跤趴在地上，摔出北斗阵。\n"NOR,me);
		en->remove_all_enemy();
		remove_call_out("do_end");
		call_out("do_end", 1, me, en, 1);
		return 1;
	}
	else if(obs[j]->query("qi")*3 <= obs[j]->query("max_qi")*2)
	{
		message_vision(obs[j]->query("name")+ "踉跄了一步，差点摔出北斗阵。\n",me);
	}
	else if(obs[j]->query("qi")*5 <= obs[j]->query("max_qi")*4)
		message_vision(obs[j]->query("name")+"被打得晃了几晃，不过又站稳了步子。\n",me);

	remove_call_out("do_qixing");
	call_out("do_qixing", 1, me, en);
	return 1;
}
int do_end(object me, object en, int result)
{
	if( result == 1)
	{
		if(en->query_temp("pre_qixing"))
		{
			en->set("qixing", 1);
		}
		en->delete_temp("pre_qixing");
		en->add("combat_exp",50000);
		en->add("score",30000);
		en->add("potential",10000);	
		message_vision(HIR"\n天罡北斗阵被"+en->query("name")+"打破了。\n\n"NOR,me);
		message("channel:snow", HIR"【通告】"HIY + en->query("name")+"打破天罡北斗阵了！\n"NOR, users());
	}
	else
	{
		en->delete_temp("pre_qixing");
		message("channel:snow", HIR"【通告】"HIY + en->query("name")+"没能闯出天罡北斗阵！\n"NOR, users());
    message_vision(HIR"\n$N笑了笑：天罡北斗阵不愧为全真镇教之宝。\n"NOR,me);
		en->add("score",-3000);	   
	}
	remove_call_out("do_back");
	call_out("do_back", 1, me);
	return 1;
}
int do_back(object me)
{
	object *obs, weapon;
	int i;

	if(pointerp(obs=me->query_team()) )
	{
		for(i=0;i<sizeof(obs);i++)
		{
			if (objectp(weapon = obs[i]->query_temp("weapon"))
				&& (string)weapon->query("skill_type")=="sword")
message_vision("$N身子向后一纵，使一招『收剑式』，将剑挽了一个剑花，往怀中一抱，退出「天罡北斗阵」。\n", obs[i]);
			else
message_vision("$N身子向后一纵，使一招『收山式』，右拳划了一圈，左掌往怀中一抱，退出「天罡北斗阵」。\n", obs[i]);

message_vision("$N作了个楫道：贫道先告退了！说完就快步离开了。\n", obs[i]);
			if (obs[i]->query("name")== "马钰")
				obs[i]->move("/d/quanzhen/shiweishi");
			if (obs[i]->query("name")== "谭处端")
				obs[i]->move("/d/quanzhen/rongwutang");
			if (obs[i]->query("name")== "刘处玄")
				obs[i]->move("/d/quanzhen/jingxiushi");
			if (obs[i]->query("name")== "丘处机")
				obs[i]->move("/d/quanzhen/laojundian");
			if (obs[i]->query("name")== "王处一")
				obs[i]->move("/d/quanzhen/wanwutang");
			if (obs[i]->query("name")== "郝大通")
				obs[i]->move("/d/quanzhen/guangning");
			if (obs[i]->query("name")== "孙不二")
				obs[i]->move("/d/quanzhen/qingjing");
		}
	}///d/quanzhen/shiweishi
	me->dismiss_team();
}

#include "chu.h";
