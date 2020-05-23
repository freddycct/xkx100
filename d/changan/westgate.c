// /d/changan/westgate.c

inherit  ROOM;

void  create  ()
{
        set  ("short",  "安定门");
        set  ("long",  @LONG
这里便是长安西门----安定门。长安为多朝古都，果然不同凡响，
城墙以石灰、糯米和土夯成，固若金汤。出城往西门便可直通兰州，几
名官兵正在守门。
LONG);
        //set("item_desc",  (["  ***  "  :  "  ***  ",  ]));
        set("exits",  ([  //sizeof()  ==  4
            "west"  :  __DIR__"road7",
            "east"  :  __DIR__"westroad1",
        ]));

        set("objects",  ([  //sizeof()  ==  1
                "/d/city/npc/wujiang"  :  1,
                "/d/city/npc/bing"  :  1,
        ]));
        set("outdoors",  "changan");
        set("no_clean_up",  0);
	set("coor/x", -5070);
	set("coor/y", 1000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

