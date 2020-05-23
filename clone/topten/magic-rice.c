// magic-rice.c
// 1998/12/16 Modified by Winder
// 增加基本赌技排行榜,zeratul 2000.1.13
// Last Modified by winder on Aug. 5 2001 增加宠物排行
// Last Modified by winder on Feb. 21 2002 增加秒杀排行

#define TOPTEN DATA_DIR + "topten"

inherit ITEM;
inherit F_SAVE;

mapping *exp_topten = 
({
	(["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
	(["第6名":"空缺"]),(["第7名":"空缺"]),(["第8名":"空缺"]),(["第9名":"空缺"]),(["第10名":"空缺"]),
});
mapping *richman_topten = 
({
	(["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
	(["第6名":"空缺"]),(["第7名":"空缺"]),(["第8名":"空缺"]),(["第9名":"空缺"]),(["第10名":"空缺"]),
});
mapping *oldman_topten = 
({
	(["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
	(["第6名":"空缺"]),(["第7名":"空缺"]),(["第8名":"空缺"]),(["第9名":"空缺"]),(["第10名":"空缺"]),
});
mapping *force_topten = 
({
	(["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
	(["第6名":"空缺"]),(["第7名":"空缺"]),(["第8名":"空缺"]),(["第9名":"空缺"]),(["第10名":"空缺"]),
});
mapping *literate_topten = 
({
	(["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
	(["第6名":"空缺"]),(["第7名":"空缺"]),(["第8名":"空缺"]),(["第9名":"空缺"]),(["第10名":"空缺"]),
});
mapping *pks_topten = 
({
	(["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
	(["第6名":"空缺"]),(["第7名":"空缺"]),(["第8名":"空缺"]),(["第9名":"空缺"]),(["第10名":"空缺"]),
});
mapping *killer_topten = 
({
	(["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
	(["第6名":"空缺"]),(["第7名":"空缺"]),(["第8名":"空缺"]),(["第9名":"空缺"]),(["第10名":"空缺"]),
});
mapping *thief_topten = 
({
	(["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
	(["第6名":"空缺"]),(["第7名":"空缺"]),(["第8名":"空缺"]),(["第9名":"空缺"]),(["第10名":"空缺"]),
});
mapping *sword_topten = 
({
	(["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
	(["第6名":"空缺"]),(["第7名":"空缺"]),(["第8名":"空缺"]),(["第9名":"空缺"]),(["第10名":"空缺"]),
});
mapping *blade_topten = 
({
	(["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
	(["第6名":"空缺"]),(["第7名":"空缺"]),(["第8名":"空缺"]),(["第9名":"空缺"]),(["第10名":"空缺"]),
});
mapping *unarmed_topten = 
({
	(["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
	(["第6名":"空缺"]),(["第7名":"空缺"]),(["第8名":"空缺"]),(["第9名":"空缺"]),(["第10名":"空缺"]),
});
mapping *dodge_topten = 
({
	(["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
	(["第6名":"空缺"]),(["第7名":"空缺"]),(["第8名":"空缺"]),(["第9名":"空缺"]),(["第10名":"空缺"]),
});
mapping *throwing_topten = 
({
	(["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
	(["第6名":"空缺"]),(["第7名":"空缺"]),(["第8名":"空缺"]),(["第9名":"空缺"]),(["第10名":"空缺"]),
});
mapping *whip_topten = 
({
	(["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
	(["第6名":"空缺"]),(["第7名":"空缺"]),(["第8名":"空缺"]),(["第9名":"空缺"]),(["第10名":"空缺"]),
});
mapping *hammer_topten = 
({
	(["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
	(["第6名":"空缺"]),(["第7名":"空缺"]),(["第8名":"空缺"]),(["第9名":"空缺"]),(["第10名":"空缺"]),
});
mapping *staff_topten = 
({
	(["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
	(["第6名":"空缺"]),(["第7名":"空缺"]),(["第8名":"空缺"]),(["第9名":"空缺"]),(["第10名":"空缺"]),
});
mapping *weapon_topten = 
({
	(["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
	(["第6名":"空缺"]),(["第7名":"空缺"]),(["第8名":"空缺"]),(["第9名":"空缺"]),(["第10名":"空缺"]),
});
mapping *gambling_topten = 
({
	(["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
	(["第6名":"空缺"]),(["第7名":"空缺"]),(["第8名":"空缺"]),(["第9名":"空缺"]),(["第10名":"空缺"]),
});
mapping *petexp_topten = 
({
	(["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
	(["第6名":"空缺"]),(["第7名":"空缺"]),(["第8名":"空缺"]),(["第9名":"空缺"]),(["第10名":"空缺"]),
});
mapping *petobe_topten = 
({
	(["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
	(["第6名":"空缺"]),(["第7名":"空缺"]),(["第8名":"空缺"]),(["第9名":"空缺"]),(["第10名":"空缺"]),
});
mapping *mudage_topten =  
({
	(["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
	(["第6名":"空缺"]),(["第7名":"空缺"]),(["第8名":"空缺"]),(["第9名":"空缺"]),(["第10名":"空缺"]),
});
mapping *score_topten =  
({
	(["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
	(["第6名":"空缺"]),(["第7名":"空缺"]),(["第8名":"空缺"]),(["第9名":"空缺"]),(["第10名":"空缺"]),
});
mapping *handsome_topten =  
({
	(["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
	(["第6名":"空缺"]),(["第7名":"空缺"]),(["第8名":"空缺"]),(["第9名":"空缺"]),(["第10名":"空缺"]),
});
mapping *beauty_topten =  
({
	(["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
	(["第6名":"空缺"]),(["第7名":"空缺"]),(["第8名":"空缺"]),(["第9名":"空缺"]),(["第10名":"空缺"]),
});
mapping *kill_topten =  
({
	(["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
	(["第6名":"空缺"]),(["第7名":"空缺"]),(["第8名":"空缺"]),(["第9名":"空缺"]),(["第10名":"空缺"]),
});


int simple_sort( mapping *,string,int,object );
int simple_sort_skill( mapping *,string,int,object );

int create()
{
	set_name("排行", ({ "hero-board","board"}) );
	set_weight(0);
	if( clonep() )
		set_default_object(__FILE__);
	set("long", "");
	set("unit", "版");
	set("value", 0);
	setup();
		
	 restore();
		if (mapp(query("exp_topten")))	exp_topten = query("exp_topten");
		else set("exp_topten",      exp_topten);
		if (mapp(query("richman_topten")))	richman_topten = query("richman_topten");
		else set("richman_topten",  richman_topten);
		if (mapp(query("oldman_topten")))	oldman_topten    = query("oldman_topten");
		else set("oldman_topten",   oldman_topten);
		if (mapp(query("force_topten")))	force_topten     = query("force_topten");
		else set("force_topten",    force_topten );
		if (mapp(query("literate_topten")))	literate_topten  = query("literate_topten");
		else set("literate_topten", literate_topten );
		if (mapp(query("pks_topten")))	pks_topten       = query("pks_topten");
		else set("pks_topten",      pks_topten );
		if (mapp(query("killer_topten")))	killer_topten    = query("killer_topten");
		else set("killer_topten",   killer_topten );
		if (mapp(query("thief_topten")))	thief_topten     = query("thief_topten");
		else set("thief_topten",    thief_topten );
		if (mapp(query("sword_topten")))	sword_topten     = query("sword_topten");
		else set("sword_topten",    sword_topten );
		if (mapp(query("blade_topten")))	blade_topten     = query("blade_topten");
		else set("blade_topten",    blade_topten );
		if (mapp(query("unarmed_topten")))	unarmed_topten   = query("unarmed_topten");
		else set("unarmed_topten",  unarmed_topten );
		if (mapp(query("dodge_topten")))	dodge_topten     = query("dodge_topten");
		else set("dodge_topten",    dodge_topten );
		if (mapp(query("throwing_topten")))	throwing_topten  = query("throwing_topten");
		else set("throwing_topten", throwing_topten );
		if (mapp(query("whip_topten")))	whip_topten      = query("whip_topten");
		else set("whip_topten",     whip_topten );
		if (mapp(query("hammer_topten")))	hammer_topten    = query("hammer_topten");
		else set("hammer_topten",   hammer_topten );
		if (mapp(query("staff_topten")))	staff_topten     = query("staff_topten");
		else set("staff_topten",    staff_topten );
		if (mapp(query("weapon_topten")))	weapon_topten    = query("weapon_topten");
		else set("weapon_topten",   weapon_topten );
		if (mapp(query("gambling_topten")))	gambling_topten  = query("gambling_topten");		
		else set("gambling_topten", gambling_topten );	
		if (mapp(query("petexp_topten")))	petexp_topten    = query("petexp_topten");		
		else set("petexp_topten",   petexp_topten );	
		if (mapp(query("petobe_topten")))	petobe_topten    = query("petobe_topten");		
		else set("petobe_topten",   petobe_topten );	
		if (mapp(query("mudage_topten")))	mudage_topten    = query("mudage_topten");
		else set("mudage_topten",   mudage_topten);
		if (mapp(query("score_topten")))	score_topten     = query("score_topten");
		else set("score_topten",    score_topten);
		if (mapp(query("handsome_topten")))	handsome_topten  = query("handsome_topten");
		else set("handsome_topten", handsome_topten);
		if (mapp(query("beauty_topten")))	beauty_topten    = query("beauty_topten");
		else set("beauty_topten",   beauty_topten);
		if (mapp(query("kill_topten")))	kill_topten      = query("kill_topten");
		else set("kill_topten",     kill_topten);
	return 1;
}

string query_save_file() { return TOPTEN; }

int savetopten( object me )
{
	object obj;
	int exist,i;

	simple_sort( exp_topten,     "combat_exp",  10,me );
	simple_sort( richman_topten, "balance",     10,me );
	simple_sort( oldman_topten,  "mud_age",     10,me );
	simple_sort( force_topten,   "max_neili",   10,me );
	simple_sort_skill( literate_topten,  "literate", 10,me );
	simple_sort( pks_topten,     "PKS",         10,me );
	simple_sort( killer_topten,  "KILLER",      10,me );
	simple_sort_skill( thief_topten,     "stealing", 10,me );
	simple_sort_skill( sword_topten,     "sword",    10,me );
	simple_sort_skill( blade_topten,     "blade",    10,me );
	simple_sort_skill( unarmed_topten,   "unarmed",  10,me );
	simple_sort_skill( dodge_topten,     "dodge",    10,me );
	simple_sort_skill( throwing_topten,  "throwing", 10,me );
	simple_sort_skill( whip_topten,      "whip",     10,me );
	simple_sort_skill( hammer_topten,    "hammer",   10,me );
	simple_sort_skill( staff_topten,     "staff",    10,me );
	simple_sort_skill( gambling_topten,  "gambling", 10,me );
	simple_sort( weapon_topten,   "weapon/lv",  10,me );
	simple_sort( petexp_topten,   "Pet/exp",    10,me );
	simple_sort( petobe_topten,   "Pet/obe",    10,me );
	simple_sort( mudage_topten,   "marks/mi_age",10,me);
	simple_sort( score_topten,    "score",      10,me);
	simple_sort( handsome_topten, "per1",       10,me);
	simple_sort( beauty_topten,   "per2",       10,me);
	simple_sort( kill_topten,     "MKS",        10,me);

		set("exp_topten",      exp_topten);
		set("richman_topten",  richman_topten);
		set("oldman_topten",   oldman_topten);
		set("force_topten",    force_topten );
		set("literate_topten", literate_topten );
		set("pks_topten",      pks_topten );
		set("killer_topten",   killer_topten );
		set("thief_topten",    thief_topten );
		set("sword_topten",    sword_topten );
		set("blade_topten",    blade_topten );
		set("unarmed_topten",  unarmed_topten );
		set("dodge_topten",    dodge_topten );
		set("throwing_topten", throwing_topten );
		set("whip_topten",     whip_topten );
		set("hammer_topten",   hammer_topten );
		set("staff_topten",    staff_topten );
		set("weapon_topten",   weapon_topten );
		set("gambling_topten", gambling_topten );	
		set("petexp_topten",   petexp_topten );	
		set("petobe_topten",   petobe_topten );	
		set("mudage_topten",   mudage_topten);
		set("score_topten",    score_topten);
		set("handsome_topten", handsome_topten);
		set("beauty_topten",   beauty_topten);
		set("kill_topten",     kill_topten);

	save();
	return 1;
}

int simple_sort( mapping *which_chart,string chart_type,int chart_size,object me )
{
	int i,exist;
	string *c_id=({"空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺",});
	string *c_short=({"空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺",});
	int *c_type=({11,10,9,8,7,6,5,4,3,2,1,0});
	string si;
	object money;

	si="名次";
	c_id[chart_size] = me->query("id");
	c_short[chart_size] = RANK_D->query_rank(me)+me->short(1);
	c_type[chart_size] = me->query(chart_type);
	if (chart_type=="balance")
	{
		  if (money=present("gold_money", me))
		  	c_type[chart_size]+= 10000*money->query_amount();
			if (money=present("silver_money", me))
		  	c_type[chart_size]+= 100*money->query_amount();
		  if (money=present("coin_money", me))
		  	c_type[chart_size]+= 1*money->query_amount();
	}
	if (chart_type == "per1" && me->query("gender")=="男性" )
		c_type[chart_size] = me->query("per");
	if (chart_type == "per2" && me->query("gender")=="女性" )
		c_type[chart_size] = me->query("per");
		
	if (chart_type == "weapon/lv")
		c_type[chart_size] += me->query("gift/weapon");
	if (chart_type == "marks/mi_age")
	{
		c_type[chart_size] =  me->query("marks/mi_age")*86400;
		c_type[chart_size] += me->query("mud_age");
		c_type[chart_size] += me->query("vegetable/huichun")*86400;
	}
	if (chart_type == "score")
	{
		i =  me->query("marks/mi_age")*86400;
		i += me->query("mud_age");
		i += me->query("vegetable/huichun")*86400;
		if (i<86400*6) i = 86400*6; // 不够二十岁按二十岁算
		i /= 3600;
		c_type[chart_size] =  me->query("combat_exp",1);
		c_type[chart_size] += me->query("potential",1)*3;
		c_type[chart_size] /= i;
	}
	exist = 0;
	if (!arrayp(which_chart)) 
	{
		tell_object(find_player("qingyun"),"chart_type="+chart_type+"\n");
		which_chart = 
({
	(["第1名":"空缺"]),(["第2名":"空缺"]),(["第3名":"空缺"]),(["第4名":"空缺"]),(["第5名":"空缺"]),
	(["第6名":"空缺"]),(["第7名":"空缺"]),(["第8名":"空缺"]),(["第9名":"空缺"]),(["第10名":"空缺"]),
});
	}
	for( i = 0; i < chart_size; i++ )
	{
		si=sprintf("第%d名",i+1 );
		sscanf( which_chart[i][si],"%s\n%s\n%d\n",c_id[i],c_short[i],c_type[i] );
		if( c_id[i] == c_id[chart_size] )
		{
			c_short[i] = c_short[chart_size];
			c_type[i]  = c_type[chart_size] ;
			exist = 1;
			continue;
		}
//		if( !(FINGER_D->acquire_login_ob(c_id[i])) )
//			c_type[i]= 0;
	}


	for( i = 0; i < chart_size - exist; i++ )
	{
		if( c_type[i] < c_type[i+1] )
		{
			c_id[chart_size+1]    = c_id[i];
			c_short[chart_size+1] = c_short[i];
			c_type[chart_size+1]  = c_type[i];
			c_id[i]    = c_id[i+1];
			c_short[i] = c_short[i+1];
			c_type[i]  = c_type[i+1];
			c_id[i+1]    = c_id[chart_size+1];
			c_short[i+1] = c_short[chart_size+1];
			c_type[i+1]  = c_type[chart_size+1];
		}

	}

	for( i = chart_size - exist; i > 0; i-- )
		if( c_type[i] > c_type[i-1] )
		{
			c_id[chart_size+1]    = c_id[i-1];
			c_short[chart_size+1] = c_short[i-1];
			c_type[chart_size+1]  = c_type[i-1];
			c_id[i-1]    = c_id[i];
			c_short[i-1] = c_short[i];
			c_type[i-1]  = c_type[i];
			c_id[i]    = c_id[chart_size+1];
			c_short[i] = c_short[chart_size+1];
			c_type[i]  = c_type[chart_size+1];
		}

	for( i = 0; i < chart_size; i++ )
	{
		si=sprintf( "第%d名",i+1 );
		which_chart[i][si]=sprintf( "%s\n%s\n%d\n",c_id[i],c_short[i],c_type[i] );
	}

	return 1;
}

int simple_sort_skill( mapping *which_chart,string chart_type,int chart_size,object me )
{
	int i,exist;
	string *c_id=({"空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺",});
	string *c_short=({"空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺","空缺",});
	int *c_type=({11,10,9,8,7,6,5,4,3,2,1,0});
	string si;
	object *inv;

	si="名次";
	c_id[chart_size] = me->query("id");
	c_short[chart_size] = RANK_D->query_rank(me)+me->short(1);
	if (chart_type=="literate") 
	c_type[chart_size] = me->query_skill(chart_type,1);
	else
	c_type[chart_size] = me->query_skill(chart_type);
	c_type[chart_size]-= me->query_temp("apply/" + chart_type);
	exist = 0;
	for( i = 0; i < chart_size; i++ )
	{
		si=sprintf("第%d名",i+1 );
		sscanf( which_chart[i][si],"%s\n%s\n%d\n",c_id[i],c_short[i],c_type[i] );
		if( c_id[i] == c_id[chart_size] )
		{
			c_short[i] = c_short[chart_size];
			c_type[i]  = c_type[chart_size] ;
			exist = 1;
			continue;
		}
//		if( !(FINGER_D->acquire_login_ob(c_id[i])) )
//			c_type[i]= 0;
	}


	for( i = 0; i < chart_size - exist; i++ )
	{
		if( c_type[i] < c_type[i+1] )
		{
			c_id[chart_size+1]    = c_id[i];
			c_short[chart_size+1] = c_short[i];
			c_type[chart_size+1]  = c_type[i];
			c_id[i]    = c_id[i+1];
			c_short[i] = c_short[i+1];
			c_type[i]  = c_type[i+1];
			c_id[i+1]    = c_id[chart_size+1];
			c_short[i+1] = c_short[chart_size+1];
			c_type[i+1]  = c_type[chart_size+1];
		}

	}

	for( i = chart_size - exist; i > 0; i-- )
		if( c_type[i] > c_type[i-1] )
		{
			c_id[chart_size+1]    = c_id[i-1];
			c_short[chart_size+1] = c_short[i-1];
			c_type[chart_size+1]  = c_type[i-1];
			c_id[i-1]    = c_id[i];
			c_short[i-1] = c_short[i];
			c_type[i-1]  = c_type[i];
			c_id[i]    = c_id[chart_size+1];
			c_short[i] = c_short[chart_size+1];
			c_type[i]  = c_type[chart_size+1];
		}

	for( i = 0; i < chart_size; i++ )
	{
		si=sprintf( "第%d名",i+1 );
		which_chart[i][si]=sprintf( "%s\n%s\n%d\n",c_id[i],c_short[i],c_type[i] );
	}

	return 1;

}

int movein(object me)
{
	move_object(me);
	return 1;
}

