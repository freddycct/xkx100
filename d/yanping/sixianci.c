// Room: /d/yanping/sixianci.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "四贤祠");
	set("long", @LONG
延平府名优荟萃，文风昌盛。四贤祠里供奉着杨时(yang)、罗从彦
(luo) 、李炯(li)、朱熹 (zhu)四大名儒。自杨时与游酢 (you)“程门
立雪”之后，不负程颢“吾道南矣”之重望，由杨而罗，由罗而李，直
到集大成的朱子，代代承传。他们上承河洛之学，在此穷首皓经，齐声
倡儒，终于倡大闽学，著一代风流。
LONG );
	set("exits", ([
		"south" : __DIR__"ximen",
	]));
	set("item_desc", ([
		"you" : "
    游酢，北宋著名理学家、教育家、书法家、诗人。元丰四年(1082)，与杨
时同往颍里，就学于程颢。五年，登进士。元佑八年(1093)，偕杨时赴洛阳求
教程颐。一日，程瞑目养神，二人不敢惊动，候立门外，待察觉时雪已盈尺，
留下“程门立雪”的千古美谈。游酢与杨时、吕大临、谢良佐并称程门四大弟
子。先后创办荐山书院、豸山草堂和皖山书院等。
　　游酢与杨时首开武夷山理学之先河。他学成南归，于元符二年(1099)在武
夷山五曲接笋峰下筑水云寮，作为著述立说之所，撰《易学》、《诗二南义》、
《论孟杂解》、《中庸义》等。宣和五年(1123)病逝，谥“文肃”。\n",
		"yang" : "
    杨时，北宋著名理学家、教育家，号龟山，程颢最得意的弟子之一。
    他发展程颢、程颐“理”的学说，吸取张载“气”的思想，使理学更加系
统化。
    杨时、游酢学成南归，程颢送别他们时说：“吾道南唉！”杨时、游酢不
负恩师的重托，选择了武夷山做为他们传播理学的宝地。杨时在武夷山与寓居
武夷山麓五夫里的胡安国及其子侄胡宁、胡寅、胡宏、胡宪，朱熹的岳父、老
师刘勉之等名贤切磋学问，交往甚密，并经常相邀游览武夷山。绍兴五年(113
5年)逝世。清康熙年间，谥“文靖”，敕建书院、道南祠，御赐“龟山书院”
和“程氏正宗”额。传世著作有《校正伊川易》、《三经义辨》、《列予解》、
《经筵讲义》、《辨学治说》、《四书解义》、《周礼》、《毛诗辨疑》、《
杨龟山先生集》42卷、《龟山语录》、《二程粹言》、《春秋孟子义校正》以
及《游武夷》、《武夷纪游》等诗。\n",
		"luo" : "
    罗从彦，北宋理学家、教育家、世称豫章先生。崇宁二年(1103)在沙县讲
学，九年后赴洛阳求学程颐。重和元年(1118)，“筑室罗源山中。绝意仕途”，
潜心著述讲学，收李侗、朱松等为学生，常聚九峰山峡谷处讲道。后在剑浦（
今延平）、连城、广东罗浮山等地讲学。建炎二年至绍兴元年(1128～1131)，
受连城罗姓宗亲聘请，在冠豸山仰止亭讲学达四年。
    他继承和发展程颢、程颐“穷理学说”和杨时“致和必先格物”的“理一
分殊”理论，创立“静中观进”说，在宋代理学发展史上起到承前启后的作用。
卒谥“文质”。清康熙四十年(1706)御赐“奥学清节”祠额。传世著作有《语
孟师说》、《中庸说》、《二程龟山语录》等。\n",
		"li" : "
    李侗，宋学者、理学家、教育家，世称延平先生。政和六年(1116)拜罗从
彦为师，继承和发展程氏思想，主张“默坐澄心以体认天理”。李侗对朱熹的
哲学理论的发展起重大影响。从绍兴二十三年(1153)到绍兴三十二年，朱熹曾
四次到剑浦拜访李侗，登门求教。李侗也曾于隆庆元年(1163)两度到崇安五夫
里紫阳楼看望朱熹。这年，李侗应邀赴福唐(今福清市)讲学，病逝福唐，葬于
延平故里，由朱熹卜筑，并撰写墓志铭。谥“文靖”。清康熙皇帝御书“静中
气象”匾额。传世之作有《延平问答》等。 \n",
		"zhu" : "
    朱熹，南宋著名理学家、教育家、文学家。出生于尤溪。七岁到建州，十
四岁定居崇安，从学胡宪、刘勉之等。绍兴十八年(1148)进士，后师事李侗，
为二程（程颢、程颐）四传弟子。博及群书，广注典籍，对经学、史学、文学、
乐律以及自然科学都有不同程度贡献。
　　朱熹在哲学上发展了二程关于理气关系的学说，集理学之大成，建立一个
完整的客观唯心主义理学体系，认为理气相依而不能相离，“天下未有无理之
气，亦未有无气之理”。把一理和万理看作“理一分殊”的关系，强调“天理”
与“人欲”的对立，要求人们放弃“私欲”，服从“天理”。他从事教育五十
余年，强调启发式，吸收当时科学成果，提出了对自然界变化的某些见解。他
的理学在明清两代被提高到儒学正宗的地位。他集《大学》、《中庸》、《论
语》、《孟子》为《四子书》，成为明清两代科举的“圣典”，凡作经义文都
要依据朱熹的注释和章句。卒谥“文”，清康熙二十六年(1687)，御书“学达
性天”匾额赐朱熹创办的紫阳书院。康熙四十五年，又为朱子祠御书“大儒世
泽”匾额，并亲自撰并书楹联：“诚意正心，阐邹鲁之实学；主敬穷理，绍濂
洛之真传。”\n",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1420);
	set("coor/y", -6180);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
