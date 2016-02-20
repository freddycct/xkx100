// check.c
inherit F_CLEAN_UP;

#include <ansi.h>



/*string *skill_level_desc = ({
	BLU "��ѧէ��" NOR,
	HIB "��ͨƤë" NOR,
	HIB "��������" NOR,
	HIB "��������" NOR,
	HIB "�������" NOR,
	CYN "�������" NOR,
	CYN "����似" NOR,
	CYN "�����뻯" NOR,
	HIC "�Ƿ��켫" NOR,
	HIC "һ����ʦ" NOR,
	HIW "��ɲ�" NOR
});

string *knowledge_level_desc = ({
	BLU "��ѧէ��" NOR,
	HIB "�����ž�" NOR,
	HIB "��֪һ��" NOR,
	HIB "��������" NOR,
	HIB "����С��" NOR,
	CYN "�������" NOR,
	CYN "��Ȼ���" NOR,
	CYN "��Ȼ��ͨ" NOR,
	HIC "������˫" NOR,
	HIC "������" NOR,
	HIW "��ɲ�" NOR
});
*/
string *skill_level_desc = ({
	BLU"����һ��",BLU"��������",BLU"����ҳ�",BLU"��ѧէ��",BLU"����ǿǿ",
	HIB"�����ž�",HIB"����é®",HIB"��֪һ��",HIB"����ͨͨ",HIB"ƽƽ����",
	CYN"ƽ������",CYN"��ͨƤë",CYN"��������",CYN"��������",CYN"����С��",
	HIC"����С��",HIC"������Ⱥ",HIC"�������",HIC"�������",HIC"�ڻ��ͨ",
	HIG"�������",HIG"¯����",HIG"��Ȼ����",HIG"���д��",HIG"���д��",
	YEL"��Ȼ��ͨ",YEL"�������",YEL"�޿�ƥ��",YEL"����Ⱥ��",YEL"����似",
	HIY"�����뻯",HIY"��ͬ����",HIY"����Ⱥ��",HIY"�Ƿ��켫",HIY"�����ױ�",
	RED"��������",RED"һ����ʦ",RED"�������",RED"�񹦸���",RED"������˫",
	WHT"��������",WHT"���춯��",WHT"������",WHT"������ʥ",WHT"�������",
	HIW"��ǰ����",HIW"���˺�һ",MAG"��ز�¶",HIM"��ɲ�",HIR"��豹���" 
});

string *knowledge_level_desc = ({
	BLU"��ѧէ��",BLU"�����ž�",HIB"��֪һ��",HIB"��������",
	CYN"��������",CYN"����С��",HIC"�ڻ��ͨ",HIC"�������",
	GRN"��Ȼ���",GRN"��Ȼ��ͨ",YEL"��ͬ����",YEL"������˫",
	HIY"������",RED"�����ױ�",WHT"������ʥ",HIW"��ǰ����",
});
string skill_level(string, int);

int main(object me, string arg)
{
	object ob, man, *all;
	mapping fam, skl, lrn, map;
	string *sname, *mapped;
	int sp, dp, i, cost, check_lvl, skl_lvl, adj_lvl;
/* adj_lvl�����𡣵���100-checking���� */

	seteuid(getuid());

	all = all_inventory(environment(me));
	for(i=0; i<sizeof(all); i++)
	{
		if( living(all[i]) && !userp(all[i]) ) man = all[i];
	}
	if ( (!(fam = me->query("family")) || fam["family_name"] != "ؤ��") )
		return notify_fail("ֻ����ؤ���ܴ�̽���˵ļ��ܣ�\n");
	if ( !objectp(man) )
		return notify_fail("��Χû���ܰ���ȥ�˽���˵ļ��ܣ�\n");
	check_lvl = me->query_skill("checking", 1);
	if ( check_lvl < 10 )
		return notify_fail("��Ĵ�̽������δ���죬�޷��˽���˵ļ��ܣ�\n");
	if(check_lvl < 150) adj_lvl = 150 - check_lvl;
	else adj_lvl = 0;

	if ( !arg ) return notify_fail("��Ҫ����˭�ļ��ܣ�\n");
	if ( present(arg, environment(me)) )
		return notify_fail("��Ҫ�������˾��ڱ��ϣ��������ʲ����׵��ɣ�\n");
	ob = find_player(arg);
	if (!ob) ob = find_living(arg);
	if (!ob) return notify_fail("��Ҫ����˭�ļ��ܣ�\n");
	if (!me->visible(ob))
		return notify_fail("��Ҫ����˭�ļ��ܣ�\n");
	if ( ob == me )
		return notify_fail("��û��ô���ɣ�Ҫ���˸������Լ��ļ��ܣ�\n");
	cost = me->query("max_jing")/(check_lvl/10) - 10;
	if ( me->query("jing") <= cost )
		return notify_fail("������̫���ˣ��޷�ȥ�������˵ļ��ܡ�\n");

	tell_object(me, "������ǰȥ��С����������" + man->name() + "��������" + ob->name() + "����� ...\n\n");
	message("vision", "ֻ��" + me->name() + "����Ц����" + man->name() + "˵�Ż��������ڴ���Щʲô��\n\n", environment(me), ({ me, man }) );

	sp = check_lvl*10+me->query("kar")*5+me->query("jing")+man->query("jing");
	dp = ob->query("kar")*5 + ob->query("jing")*2;
	if ( random(sp) < random(dp) && !wizardp(ob))
		return notify_fail(man->name() + "ҡ��ҡͷ��˵���������ҿɲ������" + RANK_D->query_respect(me) + "����ȥ����˴���һ�°ɣ�\n");
	me->receive_damage("jing", cost );
	skl = ob->query_skills();
	if(!sizeof(skl) || ob->query("yinshi"))
	{
		write(man->name() + "�����㣺 " + ob->name() + "Ŀǰ��û��ѧ���κμ��ܡ�\n");
		return 1;
	}
	write(man->name()+"�����㣺"+ob->name()+"Ŀǰ��ѧ���ļ��ܴ���У�\n\n");
	sname = sort_array( keys(skl), (: strcmp :) );
	
	map = ob->query_skill_map();
	if( mapp(map) ) mapped = values(map);
	if( !mapped ) mapped = ({});

	lrn = ob->query_learned();
	if( !mapp(lrn) ) lrn = ([]);
	 
	i = random(sizeof(skl));
	skl_lvl = skl[sname[i]]-adj_lvl/2+random(adj_lvl);
	if(skl_lvl < 0) skl_lvl = random(10) + 1;
	

	printf("%s%s%-40s"NOR" - %-10s"NOR" %3d/%5d\n", 
		(lrn[sname[i]]>=(skl[sname[i]]+1)*(skl[sname[i]]+1)) ? HIM : "",
		(member_array(sname[i], mapped)==-1? "  ": "��"),
		to_chinese(sname[i]) + " (" + sname[i] + ")",
		skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
		skl_lvl, (int)lrn[sname[i]],
	);
	if ( me->query("combat_exp") > (check_lvl*check_lvl*check_lvl)/10)
	{
		me->improve_skill("checking", random(me->query("int")));
	}

	write("\n");
	return 1;
}

string skill_level(string type, int level)
{
	int grade;


	switch(type) {
		case "knowledge":
	grade = level / 30;
			if( grade >= sizeof(knowledge_level_desc) )
				grade = sizeof(knowledge_level_desc)-1;
			return knowledge_level_desc[grade];
		default:
	grade = level / 10;
			if( grade >= sizeof(skill_level_desc) )
				grade = sizeof(skill_level_desc)-1;
			return skill_level_desc[grade];
	}
}

int help(object me)
{
	write(@HELP
ָ���ʽ : check|dating [<ĳ��>]

    ���ָ������������������ѧ���ļ��ܡ���������㼼�ܲ�������
�Ļ����������δ����ƫ�

    ��Ҳ����ָ��һ��������ʦͽ��ϵ�Ķ����� skills|cha ���Բ�֪
�Է��ļ���״����

    ������Ϊؤ�����ר�ã�����ѧϰ��Ӧ�ļ��ܡ�

HELP
	);
	return 1;
}