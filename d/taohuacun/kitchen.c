// /d/taohuacun/kitchen.c
// Last Modifiedy by Zeratul June 2000

#include <ansi.h>
inherit ROOM;

string  cooker = "";

void  create()
{
	int line;
	string st,ss,*str;

	set("short","厨房");
	set("long",@LONG
一间厨房，油盐酱醋样样俱全，摆得满灶头都是。灶底火头正大，
灶上大铁锅给烧得“嘶嘶”轻响，冒着清烟。墙上贴着一张油腻腻的纸
片看起来(list)象是菜单。你可以手痒起来，也想在这里照单自己做点
可口菜肴(cook)。
LONG
);
	set("no_fight",1);
	set("no_beg",1);
	set("exits", ([
		"south" : __DIR__"road3",
	]));
	set("objects", ([
		__DIR__"npc/cooker" : 1,
	]));
	set("menus", ([]) );
	line = 1;
	while (1) {
		st = read_file( __DIR__"menu", line, 1 );
		if (!stringp(st))  break;
		st = replace_string( st, "\n", "" );
		line++;
		ss = read_file( __DIR__"menu", line, 1 );
		if (!stringp(ss))  break;
		ss = replace_string( ss, ";", "" );
		ss = replace_string( ss, "\n", "" );		
		str = explode( ss, " " );
		set( "menus/" + st, str );
		line++;
	}
	set("coor/x", -90);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
}	

void init()
{
	add_action( "do_list", "list" );
	add_action( "do_cook", "cook" );
}

int  do_list()
{
	int i, j;
	object ob;
	string line = "";

        line = HIC"\n≡" HIY "─────────" HIG "【侠客行一百菜谱】" HIY "─────────" HIC "≡\n" NOR; 
	for ( i = 0; i < sizeof( query( "menus" ) ); i++ ) {
		ob = new( __DIR__"npc/obj/" + keys( query( "menus" ) )[i] );
		if ( objectp( ob ) )
			line += sprintf( "		" HIC "★" NOR "%s\n", ob->short() );
		line += "\n  ";
		for ( j = 0; j < sizeof ( values( query( "menus" ) )[i] ); j++ ) {
			ob = new( __DIR__"npc/obj/" + values( query( "menus" ) )[i][j] );
			if ( objectp( ob ) )
				line += sprintf( "  %s", ob->query( "name" ) );
		}
		line += "\n";
		if ( i < sizeof( query( "menus" ) ) - 1 )
			line += HIY "  ─────────────────────────── \n" NOR;
	}
	line += HIC "≡" HIY "───────────────────────────" HIC "≡\n" NOR; 	
	this_player()->start_more( line );
	
	return 1;	
}


int do_cook( string arg )
{
	int i,time, sklvl;
	object ob, obj, *objs = ({}), me = this_player();
	string *str;
	string base_name,ob_name;

	sklvl = me->query_skill("cookery",1);
	if ( cooker != "" && cooker != me->query("id") )
		return notify_fail( "大师傅说道：已经有人在做菜了，你得等一会儿。\n" );
	if ( cooker == me->query("id") )
		return notify_fail( "大师傅说道：你已经在做菜了。\n" );	
	if ( !stringp( arg ) ) return notify_fail("大师傅说道：你要煮什么？\n");
	for ( i = 0; i < sizeof( query("menus") ); i ++ )
	{
		ob = new( __DIR__"npc/obj/" + keys( query( "menus" ) )[i] );
		if ( objectp( ob ) && ob->query("id") == arg )
		  	break;
		if ( objectp(ob) ) destruct(ob);
	}
	if ( i >= sizeof( query( "menus" ) ) )
	{
		if ( objectp(ob) ) destruct(ob);
		return notify_fail( "大师傅摇了摇头，说道：你不会做这道菜。\n");
	}
	str = values( query( "menus" ) )[i];
	if ( sizeof( str ) * 20 > sklvl )
	{
		destruct(ob);
		return notify_fail( "大师傅说道：你目前的手艺做不好这道菜。\n");
	}
	for ( i = 0; i < sizeof( str ); i++ )
	{
		if ( !objectp( obj = present( str[i], me ) ) ) {
               		obj = new( __DIR__"npc/obj/" + str[i] );
               		base_name = obj->query("name");
               		ob_name   = ob->query("name");
               		if ( objectp(ob) ) destruct(ob);
               		destruct(obj);
		        return notify_fail( "大师傅笑着说道：没有" + base_name + "怎么做" + ob_name + "？\n" );
		}
		objs += ({obj});
	}
	for ( i = 0; i < sizeof( objs ); i++ ) 
	  	destruct( objs[i] );
	message_vision( "$N开始做" + ob->query( "name" ) + "。\n", me );
	cooker = me->query( "id" );
	time = 5 + random( 10 );
	me->start_busy(time);
	call_out( "do_finish", time, ob, me );
	return 1;
}

void do_finish( object ob, object me )
{
	if ( environment( me ) != this_object() )  return;
	message_vision( HIC + ob->query( "cook_msg" ) + NOR, me );
	message_vision( ob->query( "name" ) + "做成了！\n\n", me );
	ob->move( me );
	cooker = "";
	ob->set("values",me->query_skill("cookery",1));
	ob->set("make_by",me->query("id"));
	if ( me->query_skill("cookery",1) >= 150 
		&& me->query_skill("cookery",1) <= 200)
	 me->improve_skill("cookery",25000);
}