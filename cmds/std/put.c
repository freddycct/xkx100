// put.c

inherit F_CLEAN_UP;

int do_put(object me, object obj, object dest);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item;
	object obj, dest, *inv, obj2;
	int i, amount, res;

	if(!arg) return notify_fail("��Ҫ��ʲô�����Ž����\n");

	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");

	if( sscanf(arg, "%s in %s", item, target)!=2 )
		return notify_fail("��Ҫ��˭ʲô������\n");

	dest = present(target, me);
	if( !dest || (living(dest) && !dest->query_temp("noliving")))
		dest = present(target, environment(me));
	if( !dest || (living(dest) && !dest->query_temp("noliving")))
		return notify_fail("����û������������\n");

	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("������û������������\n");
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "���ܱ��ֿ���\n");
		if( amount < 1 )
			return notify_fail("����������������һ����\n");
		if( amount > obj->query_amount() )
			return notify_fail("��û����ô���" + obj->name() + "��\n");
		else if( amount == (int)obj->query_amount() )
			return do_put(me, obj, dest);
		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
//			return do_put(me, obj2, dest);
		  res = do_put(me,obj2,dest);
		  if (!res) 
		  {
		  	obj2->move(environment(obj));
		  	return 0;
		  }
		  return res;
		}
	}

	if(item=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			if( inv[i] != dest ) do_put(me, inv[i], dest);
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("������û������������\n");
	return do_put(me, obj, dest);
}

int do_put(object me, object obj, object dest)
{
	if (!dest->is_container() )
	{
//		tell_object(me,dest->name()+"�����������㲻�ܰѶ����Ž�ȥ��\n");
//		return 1;
	 return notify_fail(dest->name()+"�����������㲻�ܰѶ����Ž�ȥ��\n");
	}
	if (obj->is_container())
	{
//		tell_object(me,"�㲻�ܰ�"+obj->name()+"�Ž�"+dest->name()+"��\n");
//		return 1;
	return notify_fail("�㲻�ܰ�"+obj->name()+"�Ž�"+dest->name()+"��\n");	
		}
	if( obj->query("no_put") )
	{
//		tell_object(me, "�㲻�ܰ�"+obj->name()+"�Ž�ȥ��\n");
//		return 1;
	 return notify_fail("�㲻�ܰ�"+obj->name()+"�Ž�ȥ��\n");
	}
	if( obj->query("id") == "corpse" )
	{
//		tell_object(me, "�㲻�ܰ�"+obj->name()+"����ȥ��\n");
//		return 1;
	  return notify_fail("�㲻�ܰ�"+obj->name()+"����ȥ��\n");
	}
	if( userp(obj) )
	{
//		tell_object(me, "�㲻�ܰ�"+obj->name()+"����ȥ��\n");
//		return 1;
	 return notify_fail("�㲻�ܰ�"+obj->name()+"����ȥ��\n");
	}
//	if( obj->is_character() )
//	{
//		tell_object(me, "�㲻�ܰ�"+obj->name()+"����ȥ��\n");
//		return 1;
//	}
	if( obj->move(dest) ) {
		message_vision( sprintf("$N��һ%s%s�Ž�%s��\n",
			obj->query("unit"), obj->name(), dest->name()),
			me );
		me->save();
		return 1;
	}
	else return 0;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : put <��Ʒ����> in <ĳ����>
 
    ���ָ��������㽫ĳ����Ʒ�Ž�һ����������Ȼ��������Ҫӵ��
������Ʒ��
 
HELP
	);
	return 1;
}