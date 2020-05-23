// named.c 随机姓名
//-----nm1与id是一一对应的，改动时要注意
//'司'、'寇'、'南'、'宫'是姓，'司寇'、'南宫'居然也是姓，pfpf呀~~
string* nm1 = ({
"赵","钱","孙","李","周","吴","郑","王","冯","陈","褚","卫",
"蒋","沈","韩","杨","朱","秦","尤","许","何","吕","施","张",
"孔","曹","严","华","金","魏","陶","姜","戚","谢","邹","喻",
"柏","水","窦","章","云","苏","潘","葛","奚","范","彭","郎",
"鲁","韦","昌","马","苗","凤","花","方","俞","任","袁","柳",
"酆","鲍","史","唐","费","廉","岑","薛","雷","贺","倪","汤",
"藤","殷","罗","毕","郝","邬","安","常","乐","于","时","傅",
"皮","卞","齐","康","伍","余","元","卜","顾","盈","平","黄",
"和","穆","萧","尹","姚","邵","湛","汪","祁","毛","禹","狄",
"米","贝","明","臧","计","伏","成","戴","谈","宋","茅","庞",
"熊","纪","舒","屈","项","祝","董","梁","杜","阮","蓝","闵",
"席","季","麻","强","贾","路","娄","危","江","童","颜","郭",
"梅","盛","林","刁","钟","徐","邱","骆","高","夏","蔡","田",
"樊","胡","凌","霍","虞","万","支","柯","咎","管","卢","莫",
"经","房","裘","缪","干","解","应","宗","宣","丁","贲","邓",
"郁","单","杭","洪","包","诸","左","石","崔","吉","钮","龚",
"万俟","司马","上官","欧阳","夏候","诸葛","闻人","东方",
"赫连","皇甫","尉迟","公羊","澹台","公治","宗政","濮阳",
"淳于","单于","太叔","申屠","公孙","仲孙","辕轩","令狐",
"钟离","宇文","长孙","慕容","鲜于","闾丘","司徒","司空",
"亓","官","司","寇","仉","督","子","车","颛孙","端木","巫马","公西",
"漆雕","乐正","壤驷","公良","拓拔","夹谷","宰父","谷梁",
"楚晋","闫法","汝鄢","涂钦","段干","百里","东郭","南门",
"呼延","归海","羊舌","微生","岳","帅","缑","亢","况","后","有","琴",
"梁丘","左丘","东门","西门","商","牟","佘","佴","柏","赏","南","宫",
"墨","哈","谯","笪","年","爱","阳","佟","第","五","言","福",
});

string* id = ({
"zhao","qian","sun","li","zhou","wu","zheng","wang","feng","chen","chu","wei",
"jiang","shen","han","yang","zhu","qin","you","xu","he","lv","shi","zhang",
"kong","cao","yan","hua","jin","wei","tao","jiang","qi","xie","zou","yu",
"bai","shui","dou","zhang","yun","su","pan","ge","xi","fan","peng","lang",
"lu","wei","chang","ma","miao","feng","hua","fang","yu","ren","yuan","liu",
"feng","bao","shi","tang","fei","lian","cen","xue","lei","he","ni","tang",
"teng","yin","luo","bi","hao","wu","an","chang","yue","yu","shi","fu",
"pi","bian","qi","kang","wu","yu","yuan","bu","gu","ying","ping","huang",
"he","mu","xiao","yin","yao","shao","zhan","wang","qi","mao","yu","di",
"mi","bei","ming","zang","ji","fu","cheng","dai","tan","song","mao","pang",
"xiong","ji","shu","qu","xiang","zhu","dong","liang","du","ruan","lan","min",
"xi","ji","ma","qiang","jia","lu","lou","wei","jiang","tong","yan","guo",
"mei","sheng","lin","diao","zhong","xu","qiu","luo","gao","xia","cai","tian",
"fan","hu","ling","huo","yu","wan","zhi","ke","jiu","guan","lu","mo",
"jing","fang","qiu","miao","gan","xie","ying","zong","xuan","ding","ban","deng",
"yu","shan","hang","hong","bao","zhu","zuo","shi","cui","ji","niu","gong",
"moqi","sima","shangguan","ouyang","xiahou","zhuge","wenren","dongfang",
"helian","huangfu","yuchi","gongyang","dantai","gongye","zongzheng","puyang",
"chunyu","chanyu","taishu","shentu","gongsun","zhongsun","xuanyuan","linghu",
"zhongli","yuwen","zhangsun","murong","xianyu","lvqiu","situ","sikong",
"qi","guan","si","kou","zhang","du","zi","che","zhuansun","duanmu","wuma","gongxi",
"qidiao","yuezheng","xiangsi","gongliang","tuoba","jiagu","zaifu","guliang",
"chujin","yanfa","ruyan","tuqin","duangan","baili","dongguo","nanmen",
"huyan","guihai","yangshe","weisheng","yue","shuai","gou","kang","kuang","hou","you","qin",
"liangqiu","zuoqiu","dongmen","ximen","shang","mou","she","nai","bai","shang","nan","gong",
"mo","ha","qiao","da","nian","ai","yang","tong","di","wu","yan","fu",
});

//----nm2需要一定的空字，以便产生出单名--------------
string* nm2 = ({
"忠","孝","礼","义","智","勇","仁","匡","宪","令","福","禄","大","小","晓",
"高","可","阿","金","世","克","叔","之","公","夫","时","若","庆","文","武",
"多","才","长","子","永","友","自","人","为","铁","","","","","","","","",
"","","","","","","","","","","","","","",
});

string* nm3 = ({
"霸","白","班","斌","宾","昌","超","诚","川","鼎","定","斗",
"法","飞","风","锋","钢","罡","贯","光","海","虎","华",
"浩","宏","济","坚","健","剑","江","进","杰","俊","康",
"良","麟","民","明","鸣","宁","培","启","强","荣","山",
"泰","涛","挺","伟","熙","祥","雄","旭",
"毅","瑜","羽","宇","岳","舟",
});

string* nm4 = ({	  //女性专用
"爱","春","丹","芳","芬","凤","姑","红","虹","娇","娟",
"菊","兰","岚","丽","莉","莲","玲","琳","娜","琴","芹",
"倩","萍","婷","霞","香","艳","燕","英","瑛","玉","珍",
"珠",
});

//-日本名-----nm_jp与id_jp是一一对应的，改动或增加也要注意对应----------------
string *nm1_jp =({
"山本","龟田","姿三","大岛","松下","横田","东芝","候本","川野","山口",
"铃木","岗仓","小岛","井上","安奈","浅田","佐藤","广末","大竹","大村",
"伯佐","富冈","东乡",
});

string *id_jp =({
"shanben","guitian","zisan","dadao","songxia","hengtian","dongzhi","houben","chuanye","shankou",
"lingmu","gangcang","xiaodao","jinshang","annai","qiantian","zuoteng","guangmo","dazhu","dacun",
"bozuo","fugang","dongxiang",
});	
	
string *nm2_jp =({
"太郎","次郎","三郎","四郎","五郎","十一郎","十四郎","二十六","俊树",
"宁次","英机","冶字","俊雄","牧夫","光夫","敬一","英世","漱石","渝吉",
"一叶","子规","稻造","伊冲","松园","深水","大观","丰国","孝和","茂",
"川","卫","岛寿","光云","安治","山乐","梦二",
});


mapping man_name()
{
	mapping name;
	int i;
	i = random(sizeof(nm1));
	name = ([
		"name" : nm1[i]+nm2[random(sizeof(nm2))]+nm3[random(sizeof(nm3))],
		"id"   : id[i],
	]);
	return name;
}

mapping woman_name()
{
	mapping name;
	int i;
	i = random(sizeof(nm1));
	name = ([
		"name" : nm1[i]+nm2[random(sizeof(nm2))]+nm4[random(sizeof(nm4))],
		"id"   : id[i],
	]);
	return name;
}

mapping jap_name()
{
	mapping name;
	int i;
	i = random(sizeof(nm1_jp));
	name = ([
		"name" : nm1_jp[i]+nm2_jp[random(sizeof(nm2_jp))],
		"id"   : id_jp[i],
	]);
	return name;
}

mapping cn_sname = ([
        "阿" : "a",
        "艾" : "ai",
        "白" : "bai",
        "蔡" : "cai",
        "曹" : "cao",
        "陈" : "chen",
        "戴" : "dai",
        "窦" : "dou",
        "邓" : "deng",
        "狄" : "di",
        "杜" : "du",
        "段" : "duan",
        "范" : "fan",
        "樊" : "fan",
        "房" : "fang",
        "风" : "feng",
        "符" : "fu",
        "福" : "fu",
        "高" : "gao",
        "古" : "gu",
        "关" : "guan",
        "郭" : "guo",
        "毛" : "mao",
        "韩" : "han",
        "胡" : "hu",
        "花" : "hua",
        "洪" : "hong",
        "侯" : "hou",
        "黄" : "huang",
        "贾" : "jia",
        "蒋" : "jiang",
        "金" : "jin",
        "孔" : "kong",
        "匡" : "kuang",
        "廖" : "liao",
        "梁" : "liang",
        "李" : "li",
        "林" : "lin",
        "刘" : "liu",
        "龙" : "long",
        "陆" : "lu",
        "卢" : "lu",
        "罗" : "luo",
        "马" : "ma",
        "牛" : "niu",
        "庞" : "pang",
        "裴" : "pei",
        "彭" : "peng",
        "戚" : "qi",
        "齐" : "qi",
        "钱" : "qian",
        "乔" : "qiao",
        "秦" : "qin",
        "邱" : "qiu",
        "裘" : "qiu",
        "仇" : "qiu",
        "沙" : "sha",
        "商" : "shang",
        "尚" : "shang",
        "邵" : "shao",
        "沈" : "shen",
        "师" : "shi",
        "施" : "shi",
        "宋" : "song",
        "孙" : "sun",
        "童" : "tong",
        "万" : "wan",
        "王" : "wang",
        "魏" : "wei",
        "卫" : "wei",
        "吴" : "wu",
        "武" : "wu",
        "萧" : "xiao",
        "肖" : "xiao",
        "项" : "xiang",
        "许" : "xu",
        "徐" : "xu",
        "薛" : "xue",
        "杨" : "yang",
        "羊" : "yang",
        "阳" : "yang",
        "易" : "yi",
        "尹" : "yin",
        "俞" : "yu",
        "赵" : "zhao",
        "钟" : "zhong",
        "周" : "zhou",
        "郑" : "zheng",
        "朱" : "zhu",

        "东方" : "dongfang",
        "独孤" : "dugu",
        "慕容" : "murong",
        "欧阳" : "ouyang",
        "司马" : "sima",
        "西门" : "ximen",
        "尉迟" : "yuchi",
        "长孙" : "zhangsun",
        "诸葛" : "zhuge",
        "上官" : "shangguan",
        "夏侯" : "xiahou",
        "闻人" : "wenren",
        "皇甫" : "huangfu",
        "澹台" : "tantai",
        "公治" : "gongzhi",
        "淳于" : "chunyu",
        "申屠" : "shentu",
        "公孙" : "gongsun",
        "公羊" : "gongyang",
        "轩辕" : "xuanyuan",
        "令狐" : "linghu",
        "钟离" : "zhongli",
        "宇文" : "yuwen",
        "慕容" : "murong",
        "仲孙" : "zhongsun",
        "司徒" : "situ",
        "司空" : "sikong",
        "端木" : "duanmu",
        "公良" : "gongliang",
        "百里" : "baili",
        "东郭" : "dongguo",
        "鲜于" : "xianyu",
        "南郭" : "nanguo",
        "呼延" : "huyan",
        "羊舌" : "yangshe",
        "东门" : "dongmen",
        "纳兰" : "nalan",
        "南官" : "nanguan",
        "南宫" : "nangong",
        "拓拔" : "tuoba",
        "完颜" : "wanyan",
        "耶律" : "yelv",
]);

mapping cn_pname = ([
        "ai"   : "皑哀蔼隘埃瑷嫒捱",
        "an"   : "安黯谙岸鞍埯鹌",
        "ao"   : "奥傲敖骜翱鳌",
        "ang"  : "昂盎肮",
        "ba"   : "罢霸跋魃",
        "bai"  : "白佰",
        "ban"  : "斑般",
        "bang" : "邦",
        "bei"  : "北倍贝备",
        "biao" : "表标彪飚飙",
        "bian" : "边卞弁忭",
        "bu"   : "步不",
        "cao"  : "曹草操漕",
        "cang" : "苍仓",
        "chang": "常长昌敞玚",
        "chi"  : "迟持池赤尺驰炽",
        "ci"   : "此次词茨辞慈",
        "du"   : "独都",
        "dong" : "东侗",
        "dou"  : "都篼",
        "fa"   : "发乏珐",
        "fan"  : "范凡反泛帆蕃",
        "fang" : "方访邡昉",
        "feng" : "风凤封丰奉枫峰锋",
        "fu"   : "夫符弗芙",
        "gao"  : "高皋郜镐",
        "hong" : "洪红宏鸿虹泓弘",
        "hu"   : "虎忽湖护乎祜浒怙",
        "hua"  : "化花华骅桦",
        "hao"  : "号浩皓蒿浩昊灏淏",
        "ji"   : "积极济技击疾及基集记纪季继吉计冀祭际籍绩忌寂霁稷玑芨"
                 "蓟戢佶奇诘笈畿犄",
        "jian" : "渐剑见建间柬坚俭",
        "kan"  : "刊戡龛",
        "ke"   : "可克科刻珂恪溘牁",
        "lang" : "朗浪廊琅阆莨",
        "li"   : "历离里理利立力丽礼黎栗荔沥栎璃",
        "lin"  : "临霖林琳",
        "ma"   : "马犸", 
        "mao"  : "贸冒貌冒懋矛卯瑁",
        "miao" : "淼渺邈",
        "nan"  : "楠南腩赧",
        "pian" : "片翩胼",
        "qian" : "潜谦倩茜乾虔千",
        "qiang": "强羌锖玱",
        "qin"  : "亲琴钦沁芩矜",
        "qing" : "清庆卿晴",
        "ran"  : "冉然染燃",
        "ren"  : "仁刃壬仞",
        "sha"  : "沙煞",
        "shang": "上裳商",
        "shen" : "深审神申慎参莘",
        "shi"  : "师史石时十世士诗始示适炻",
        "shui" : "水",
        "si"   : "思斯丝司祀嗣巳",
        "song" : "松颂诵",
        "tang" : "堂唐棠瑭",
        "tong" : "统通同童彤仝",
        "tian" : "天田忝",
        "wan"  : "万宛晚",
        "wei"  : "卫微伟维威韦纬炜惟玮为",
        "wu"   : "吴物务武午五巫邬兀毋戊",
        "xi"   : "西席锡洗夕兮熹惜",
        "xiao" : "潇萧笑晓肖霄骁校",
        "xiong": "熊雄",
        "yang" : "羊洋阳漾央秧炀飏鸯",
        "yi"   : "易意依亦伊夷倚毅义宜仪艺译翼逸忆怡熠沂颐奕弈懿翊轶屹猗翌",
        "yin"  : "隐因引银音寅吟胤訚烟荫",
        "ying" : "映英影颖瑛应莹郢鹰",
        "you"  : "幽悠右忧猷酉",
        "yu"   : "渔郁寓于余玉雨语预羽舆育宇禹域誉瑜屿御渝毓虞禺豫裕钰煜聿",
        "zhi"  : "制至值知质致智志直治执止置芝旨峙芷挚郅炙雉帜",
        "zhong": "中忠钟衷",
        "zhou" : "周州舟胄繇昼",
        "zhu"  : "竹主驻朱祝诸珠著竺",
        "zhuo" : "卓灼灼拙琢濯斫擢焯酌",
        "zi"   : "子资兹紫姿孜梓秭",
        "zong" : "宗枞",
        "zu"   : "足族祖卒",
        "zuo"  : "作左佐笮凿",
]);

void generate_cn_name(object ob)
{
        string sname, pname, pname2, id1, id2;
        string *ks, *kp;

        ks = keys(cn_sname);
        kp = keys(cn_pname);
        sname = ks[random(sizeof(ks))];
        for (;;)
        {
                pname = kp[random(sizeof(kp))];
                if (pname != cn_sname[sname]) break;
        }
        id1 = cn_sname[sname];

        id2 = pname;
        pname = cn_pname[pname];
        pname = pname[(random(sizeof(pname)) & 0xFFFE)..<1];
        pname = pname[0..1];
        if (random(3) == 0)
        {
                for (;;)
                {
                        pname2 = kp[random(sizeof(kp))];
                        if (pname2 != cn_sname[sname] &&
                            pname2 != pname) break;
                }
                id2 += pname2;
                pname2 = cn_pname[pname2];
                pname2 = pname2[(random(sizeof(pname2)) & 0xFFFE)..<1];
                pname2 = pname2[0..1];
        } else
                pname2 = "";

        if (ob) ob->set_name(sname + pname + pname2,
                             ({ id1 + " " + id2, id1, id2 }));
}
