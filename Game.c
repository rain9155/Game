#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include "Gamelib.h"
#include "Game.h"
#define Length "-----------------------------------------------------------------------------"//游戏界面的长度78
#define Gap 20 //游戏的边距
#define Map_y 3//地图长度
#define Inform_y 12//信息区长度
#define Menu_y 22//菜单的长度
int X=3,Y=2;
Map mapArray[8][8]=
{
    {   {1,"天山",1,"少林派：中华武学的泰斗，少林寺众僧习武之惯源远流长。明末，少林众多的人才中，以悟空和箭神二人排为一等。其中，悟空出家为僧，箭神乃俗家弟子。当时江湖人称少林双绝。少林寺中众僧在两大长老的带领下参加了江浙沿海抗击倭寇的战斗，在各路应募兵马中表现得最为骁勇。但正因抗倭之事，也使江湖中的众多门派产生了矛盾，其中首推少林和日月神教。悟空、箭神曾几度带领江湖同仁攻上光明顶，但由于日月神教和血河两派结为同盟，更何况邪派中高手如云，所以几次围剿未果而终，黑白两道都损",{0,0}},
        {2,"楼兰",1,"这里空荡荡",{1,0}},
        {3,"百陀山",1,"青龙会：江湖上绵延数百年的一个神秘组织。青龙会下分十二堂，分别以月为代号；‘正月’负责目标‘二月’负责渗透‘三月’负责传递消息‘四月’负责财源‘五月’负责刑罚‘六月’负责训练‘七月’负责策划‘八、九、十月’负责行动‘十一月’负责肃清叛逆‘十二月’负责暗杀目前青龙会的首领人物为韩冰，江湖人称韩三爷。此人桀骜不逊，行为张狂。手下两员大将：一为冷血刀，二为香水。",{2,0}},
        {4,"野猪林",1,"这里空荡荡",{3,0}},
        {5,"水晶洞",1,"这里空荡荡",{4,0}},
        {6,"天蚕洞",1,"这里空荡荡",{5,0}},
        {7,"黑风寨",1,"这里空荡荡",{6,0}},
        {8,"冰火岛",1,"这里空荡荡",{7,0}},
    },
    {   {9,"迷宫",1,"丐帮是中原武林中人数最为众多的一个门派，也是天下第一大帮派，以遍布天下乞丐的乞丐组成，分为污衣帮和净衣帮。丐帮中人大多都是社会地位比较低的人，但他们各个铮铮硬骨，品格高尚，很少出现卑劣之人。丐帮新一代众多弟子以天葵为首，除暴安良、行侠丈义、抑强扶弱，所作所为为天下人所津津乐道。",{0,1}},
        {10,"凌霄城",1,"这里空荡荡",{1,1}},
        {11,"轩辕岭",1,"这里空荡荡",{2,1}},
        {12,"华山",1,"五岳剑派：泰山派，恒山派，衡山派，华山派，嵩山派结为同气枝连的的五岳剑派，在江湖上扬名立万。五派中人一向面和心不和，所以五派的式微不是由于外敌入侵，而纯粹是内部矛盾激化走向内耗的结果，内部的勾心斗角虽然常常以抗倭为借口出现，实则是为了掌握五岳生杀大权。",{3,1}},
        {13,"崇山",1,"这里空荡荡",{4,1}},
        {14,"紫禁城",1,"这里空荡荡",{5,1}},
        {15,"快活林",1,"这里空荡荡",{6,1}},
        {16,"神龙岛",1,"血河派：自从血河派的掌门一代大侠方歌吟飘然而去后，血河派日益衰落。血河派活动的范围也越来越少，基本上只限与龙门石窟。而江湖上的九大门派已经把血河派视为邪魔歪道。并已传出英雄令，只要九大门派的门人遇上血河派的人，一律格杀无论。在江湖上已经没有什么血河派的人在行走。除了无恨！没有人知道他来自何方，人们只知道他来自血河派。没有人知道他的武功有多高，因为看见他的剑的人都已经......",{7,1}},
    },
    {   {17,"西域",1,"这里空荡荡",{0,2}},
        {18,"葫芦岛",1,"这里空荡荡",{1,2}},
        {19,"唐门",1,"四川唐门：唐门在江湖上以暗器闻名。但自从唐门的唐老太太过世后唐家堡一度家道中落，加之唐甜为称霸武林挑起纷争，又使唐门陷入了再度的浩劫，几乎一蹶不振。在这种危难的时刻唐门出现了一群新生力量：唐纾、唐斩、唐缺、唐玉。他们整顿内务，肃清奸佞，打出了匡复武林正义的旗帜，并且在江湖上行侠仗义，挽回了唐门的声誉，使唐门成为了江湖上的名门正派。",{2,2}},
        {20,"岭南山",1,"这里空荡荡",{3,2}},
        {21,"石窟",1,"这里空荡荡",{4,2}},
        {22,"客栈",1,"这里空荡荡",{5,2}},
        {23,"玉皇顶",1,"神龙教：神龙教是江湖邪派，由于教址远离中原，所以不大干预中原武林的血腥杀戮。目前神龙教有两位高手一为刀神，此人武功高深莫测，性格孤僻冷傲，不喜与人接近。二为恶龙，武功高强但脾气暴躁，做事没有耐性。",{6,2}},
        {24,"灵蛇岛",1,"这里空荡荡",{7,2}},
    },
    {   {25,"光明顶",1,"全真属于道教的分支之一。现今全真教中最有权威的人是一个瘦瘦小小的人，长着一双冷冷淡淡好象永远不会有什么变化的眼睛，看起来仿佛是灰色的。但他又是一个非常讲究的人，他喜欢紫色，喜欢名马佳人华衣美酒，喜欢享受。对每一件事情他都非常的挑剔，做的每一件事都经过精密计划，绝不肯多浪费一分力气，也不会有一点疏忽。这就是全真海雅。",{0,3}},
        {26,"摩天崖",1,"这里空荡荡",{1,3}},
        {27,"聚贤庄",1,"这里空荡荡",{2,3}},
        {28,"后山",1,"这里空荡荡",{3,3}},
        {29,"武当山",1,"天山派：天山派是名门正派，也是目前江湖中最为团结的一个门派。天山派也是江湖中女弟子最为众多的一个门派，且各个武功造诣不凡，相貌清秀。天山派大师兄：无双 天山派二师兄：飞仙天山派三师兄：多情天山派四师兄：步惊",{4,3}},
        {30,"开封府",1,"这里空荡荡",{5,3}},
        {31,"二十四桥",1,"这里空荡荡",{6,3}},
        {32,"蓬莱仙岛",1,"这里空荡荡",{7,3}},
    },
    {   {33,"擂鼓台",1,"这里空荡荡",{0,4}},
        {34,"峨眉山",1,"武当派：武当在江湖上与少林齐名，有‘北崇少林’‘南尊武当’之说，武当新一代的首领人物，是一位谦谦君子，一张轮廓分明的脸上总是带着爽朗的笑容，就连他的仇敌都不能不承认他是条少见的男子汉。凡人从十八岁崛起江湖，身经大小三十三战，至今从未败过一次。凡人一生中最不能忍受的两件事就是失败和错误。另：武当高手还有乌龙和假名，但此二位厌恶江湖风波险恶，恩怨仇杀，也不追求功名事业，所以独善其身，安享个性自由。",{1,4}},
        {35,"迷踪林",1,"这里空荡荡",{2,4}},
        {36,"五虎岭",1,"这里空荡荡",{3,4}},
        {37,"天宁寺",1,"这里空荡荡",{4,4}},
        {38,"积善堂",1,"这里空荡荡",{5,4}},
        {39,"镇江府",1,"这里空荡荡",{6,4}},
        {40,"桃花岛",1,"桃花岛：自从东邪黄药师扬名立万于此后，他的传人就在这里绵延不绝，竟将桃花岛建成了门派的总舵。桃花岛黄药师的关门弟子程英一生未嫁，在岛上收了几个徒弟，桃花岛的武功因此得到延续和发扬。现今岛中高手是一叫开心的女子，该女子性情孤傲乖戾，不喜与人接触，让人琢磨不透。但文才武学、书画琴棋、算术韬略，以至医卜星象，奇门五行，无一不会，无一不精。另相传岛上有一隐居前辈，当年江湖人称‘凤凰猫头鹰’。",{7,4}},
    },
    {   {41,"恶人谷",1,"这里空荡荡",{0,5}},
        {42,"大理",1,"大理段氏：大理段氏人丁众多，高手如云。其中有一位名扬江湖顶尖女侠——香雪儿。香雪儿面相灵秀，肤色白皙，但微显瘦弱，看上去弱不禁风却身怀绝世武功，已深得大理武功心得。另：大理高手还有好好和默默，但此二人深居简出，不大过问江湖中事，所以反而不如香雪儿在江湖上的名头响亮。",{1,5}},
        {43,"百花岛",1,"这里空荡荡",{2,5}},
        {44,"孔雀山庄",1,"这里空荡荡",{3,5}},
        {45,"五霸岗",1,"五毒教：一个以使毒为专长的门派，派中人各个都是用毒高手。此派高手人称梦魇，其人使毒已入化境，令人难以琢磨，江湖同道对其莫不绕道而行。此人品行时好时坏，但坚韧卓绝，嗜武成痴。",{4,5}},
        {46,"万仞堂",1,"这里空荡荡",{5,5}},
        {47,"千年古刹",1,"这里空荡荡",{6,5}},
        {48,"六和塔",1,"这里空荡荡",{7,5}},
    },
    {   {49,"玩偶庄",1,"玩偶山庄：江湖上一个神秘的门派，创始人，武功不祥。总舵就在玩偶山庄，教中首领人物——阳光。玩偶山庄门人众多，但大都绝迹江湖，只有阳光经常独自浪迹江湖并闯出了名堂，所以武林中人才知有这么一个门派存在。",{0,6}},
        {50,"黑木崖",1,"这里空荡荡",{1,6}},
        {51,"蝴蝶岛",1,"这里空荡荡",{2,6}},
        {52,"铁花岛",1,"名捕门：名捕门历属与官府，但其中也不乏在江湖上闯出名堂的武林高手。名捕门一等一的人才中有一位绰号叫‘惊天泣鬼’的，此人从不以真面目视人，总是在幕后策划一些事情。另即：名捕门中还有一号人物江湖人称‘可爱的苍蝇’，其为人处世却为武林同道所不耻。",{3,6}},
        {53,"霹雳堂",1,"这里空荡荡",{4,6}},
        {54,"关帝庙",1,"这里空荡荡",{5,6}},
        {55,"麒麟庄",1,"这里空荡荡",{6,6}},
        {56,"销魂宫",1,"权力帮：邪派之一，目前派中最高首脑为一叫阿飞的年轻人。阿飞，一个表面上异常忧悒的人。没有与其交过手的武林高手，无法想象他那弱不禁风的身躯隐藏着那么大的潜力，更不能想象他是如何用支撑起权利帮的担子的。",{7,6}},
    },
    {   {57,"石府",1,"古墓派：古墓派这一代的传人名叫暄雯，是一女子，来历不明。暄雯生性娴静，长相俊美，举止飘逸，但做事情却不似师祖小龙女，倒颇有一点杨过的风格，武功修为深不可测，同样喜穿白衣。此轻功卓越，剑法、拳法灵动妙绝，更是全真教的克星。古墓传人的处世原则是“事不关己，高高挂起”，过着与世无争的日子，但是如果有人冒犯了古墓传人，那他一定会死得很惨。",{0,7}},
        {58,"金三角",1,"这里空荡荡",{1,7}},
        {59,"忏悔崖",1,"这里空荡荡",{2,7}},
        {60,"通吃岛",1,"通通吃：江湖上一个神秘的门派，创始人，武功不祥。总舵设在通吃岛，教中首领人物——辉翰。此人手段严酷，以威服人。平常不轻易踏足中原武林，潜心修炼武功",{3,7}},
        {61,"通天馆",1,"日月神教：由于该教高手众多，并彼此互不相服，所以教务混杂。教中弟子多为邪恶之徒，专与名门正派作对，杀人良多，罪恶昭彰，故被江湖正派之人贬为魔教。现今日月神教顶尖高手有四人： 魔神九幽：此人生性豪放洒脱，对于世人看得极重的生死荣辱浑不放在心，但做事极为偏激，经常为图一时之快而错杀好人。邪神绝影：此人生性风流倜傥，相貌不俗，神采潇洒之极，最大心愿就是象楚留香一样有无数红粉知己。煞神灵剑：此人身法快捷如电著称，行踪诡异，从来无人得见他的真面目。行事全凭个人好恶，不问原因。",{4,7}},
        {62,"紫霞亭",1,"这里空荡荡",{5,7}},
        {63,"天庵",1,"这里空荡荡",{6,7}},
        {64,"侠客岛",1,"大内锦衣卫：大内锦衣卫中人才济济，尤其是雷神，此人野心勃勃，自幼练得一身大力金刚功，号称刀枪不入，武功实是深不可测。而且为人机智，精通兵法，行兵时能将千军万马人使得如同数十万般威力十足。另有小霸王除了武功之能外还精通医道，号称包治百病，有起死回生之能，但从不轻易给人治病。此二人都为性情中人，但只因投身大内锦衣卫，经常会身不由己，做一些阳奉阴违的事，但本性都是疾恶如仇，尤其是雷神，利用手中的职权救了不少被陷害的武林同道。",{7,7}},
    }
};
//门派
Martial martialArray[]={{1,"少林派",{0,0}},{2,"青龙会",{2,0}},{3,"丐帮",{0,1}},{4,"五岳剑派",{3,1}},{5,"血河派",{7,1}},{6,"四川唐门",{2,2}},{7,"神龙教",{6,2}},{8,"全真教",{0,3}},{8,"天山派",{4,3}},{9,"武当派",{1,4}},{10,"桃花岛",{7,4}},{11,"大理段氏",{1,5}},{12,"五毒教",{4,5}},{13,"玩偶山庄",{0,6}},{14,"名捕门",{3,6}},{15,"权力帮",{7,6}},{16,"古墓派",{0,7}},{17,"通通吃",{3,7}},{18,"日月神教",{4,7}},{19,"大内锦衣卫",{7,7}},};
Prop propArray[5][3]={
                      {
                        {1,"辟邪犀",1,100,10,Weapon,.U.Attack=20},{2,"太极袍",1,100,10,Armor,.U.Defence=20},{3,"小蓝瓶",1,100,10,Consumables,.U.Power=20}
                      },
                      {
                        {4,"穿云戟 ",3,500,10,Weapon,.U.Attack=80},{5,"玲珑扇 ",3,500,10,Armor,.U.Defence=80},{6,"大蓝瓶",1,500,10,Consumables,.U.Power=200}
                      },
                      {
                        {7,"一字筏",5,1000,10,Weapon,.U.Attack=150},{8,"血披风",5,1000,10,Armor,.U.Defence=150},{9,"小血瓶",1,100,10,Consumables,.U.Power=20}
                      },
                      {
                        {10,"五虎锤",8,3000,10,Weapon,.U.Attack=250},{11,"阴阳衣",8,3000,10,Armor,.U.Defence=300},{12,"大血瓶",1,500,10,Consumables,.U.Power=200}
                      },

                       {
                        {13,"迎凤枪",10,5000,10,Weapon,.U.Attack=500},{14,"镶宝裤子",10,5000,10,Armor,.U.Defence=450},{15,"玉露琼浆",1,1000,10,Consumables,.U.Power=500}
                      },

            };
//玩家
Player playerArray[10]={{1,"大侠","1847796089",1,100,1000,500,800,3000,.bag.maxcount=6,{0,0}}};
//当前玩家
Player*currentplayer=NULL;
//怪物
Monster monsterArray[]={{1,"鬼子","楼兰",1,500,10,10,500,100,500,100,{1,0},1},{2,"鬼子","楼兰",1,500,10,10,500,100,500,100,{1,0},1},{3,"鬼子","楼兰",1,500,10,10,500,100,500,100,{1,0},1},{4,"鬼子","楼兰",1,500,10,10,500,100,500,100,{1,0},1},{5,"鬼子","楼兰",1,500,10,10,500,100,500,100,{1,0},1},{6,"鬼子","楼兰",1,500,10,10,500,100,500,100,{1,0},1},
                         {1,"汉奸","天蚕洞",2,800,20,20,600,200,600,200,{5,0},1},{2,"汉奸","天蚕洞",2,800,20,20,600,200,600,200,{5,0},1},{3,"汉奸","天蚕洞",2,800,20,20,600,200,600,200,{5,0},1},{4,"汉奸","天蚕洞",2,800,20,20,600,200,600,200,{5,0},1},{5,"汉奸","天蚕洞",2,800,20,20,600,200,600,200,{5,0},1},{6,"汉奸","天蚕洞",2,800,20,20,600,200,600,200,{5,0},1},
                         {1,"狼人","凌霄城",3,1000,30,30,800,300,800,400,{1,1},1},{2,"狼人","凌霄城",3,1000,30,30,800,300,800,400,{1,1},1},{3,"狼人","凌霄城",3,1000,30,30,800,300,800,400,{1,1},1},{4,"狼人","凌霄城",3,1000,30,30,800,300,800,400,{1,1},1},{5,"狼人","凌霄城",3,1000,30,30,800,300,800,400,{1,1},1},{6,"狼人","凌霄城",3,1000,30,30,800,300,800,400,{1,1},1},
                         {1,"狗腿子","快活林",4,1000,40,40,800,400,800,500,{6,1},1},{2,"狗腿子","快活林",4,1000,40,40,800,400,800,500,{6,1},1},{3,"狗腿子","快活林",4,1000,40,40,800,400,800,500,{6,1},1},{4,"狗腿子","快活林",4,1000,40,40,800,400,800,500,{6,1},1},{5,"狗腿子","快活林",4,1000,40,40,800,400,800,500,{6,1},1} ,{6,"狗腿子","快活林",4,1000,40,40,800,400,800,500,{6,1},1},
                         {1,"死匪徒","西域",5,1200,80,60,1000,400,1000,500,{0,2},1},{2,"死匪徒八胞","西域",5,1200,80,60,1000,400,1000,500,{0,2},1},{3,"狗腿子","西域",4,1000,40,40,800,400,800,500,{0,2},1},{4,"鬼子","西域",1,500,10,10,500,100,500,100,{0,2},1},{5,"汉奸","西域",2,800,20,20,600,200,600,200,{0,2},1},{6,"死匪徒八胞","西域",5,1200,80,60,1000,400,1000,500,{0,2},1},
                         {1,"死匪徒八胞","摩天崖",6,1400,100,80,1000,500,1000,600,{1,3},1},{2,"死匪徒八胞","摩天崖",6,1400,100,80,1000,500,1000,600,{1,3},1},{3,"山本一木","摩天崖",6,1400,100,80,1000,500,1000,600,{1,3},1},{4,"死匪徒八胞","摩天崖",6,1400,100,80,1000,500,1000,600,{1,3},1},{5,"死匪徒八胞","摩天崖",6,1400,100,80,1000,500,1000,600,{1,3},1},{6,"死匪徒八胞","摩天崖",6,1400,100,80,1000,500,1000,600,{1,3},1},{7,"山本一木","摩天崖",6,1400,100,80,1000,500,1000,600,{1,3},1},{8,"山本一木","摩天崖",6,1400,100,80,1000,500,1000,600,{1,3},1},{9,"山本一木","摩天崖",6,1400,100,80,1000,500,1000,600,{1,3},1},
                         {1,"山本一木","迷踪林",6,1400,100,80,1000,500,1000,600,{2,4},1},{2,"山本一木","迷踪林",6,1400,100,80,1000,500,1000,600,{2,4},1},{3,"山本一木","迷踪林",6,1400,100,80,1000,500,1000,600,{2,4},1},{4,"筱冢义男","迷踪林",7,1500,120,70,1200,500,1200,600,{2,4},1},{5,"筱冢义男","迷踪林",7,1500,120,70,1200,500,1200,600,{2,4},1},{6,"筱冢义男","迷踪林",7,1500,120,70,1200,500,1200,600,{2,4},1},{7,"筱冢义男","迷踪林",7,1500,120,70,1200,500,1200,600,{2,4},1},{8,"筱冢义男","迷踪林",7,1500,120,70,1200,500,1200,600,{2,4},1},
                         {1,"筱冢义男","百花岛",7,1500,120,70,1200,500,1200,600,{2,5},1},{2,"筱冢义男","百花岛",7,1500,120,70,1200,500,1200,600,{2,5},1},{3,"天雨","迷踪林",8,2000,120,100,1200,900,1200,800,{2,4},1},{4,"天雨","迷踪林",8,2000,120,100,1200,900,1200,800,{2,4},1},{5,"天雨","迷踪林",8,2000,120,100,1200,900,1200,800,{2,4},1},{6,"天雨","迷踪林",8,2000,120,100,1200,900,1200,800,{2,4},1},{7,"天雨","迷踪林",8,2000,120,100,1200,900,1200,800,{2,4},1},{8,"天雨","迷踪林",8,2000,120,100,1200,900,1200,800,{2,4},1},{9,"天雨","迷踪林",8,2000,120,100,1200,900,1200,800,{2,4},1},
                         {1,"天雨","关帝庙",8,2000,120,100,1200,900,1200,800,{5,6},1},{2,"安培晋三","关帝庙",9,3000,550,300,2000,1000,2000,1000,{5,6},1},
                         {1,"小泉纯一郎","金三角",10,9000,1000,700,12000,9000,5000,4000,{1,7},1},{2,"鬼子","金三角",9,1000,1000,500,1000,500,1000,500,{1,7},1},{3,"汉奸","金三角",9,1000,1000,500,1000,500,1000,500,{1,7},1},{4,"狼人","金三角",9,1000,1000,500,1000,500,1000,500,{1,7},1},{5,"狗腿子","金三角",9,1000,1000,500,1000,500,1000,500,{1,7},1},{6,"鬼子","金三角",9,1000,1000,500,1000,500,1000,500,{1,7},1},{7,"鬼子","金三角",9,1000,1000,500,1000,500,1000,500,{1,7},1},{8,"山本一木","金三角",9,1000,1000,500,1000,500,1000,500,{1,7},1},{9,"山本一木","金三角",9,1000,1000,500,1000,500,1000,500,{1,7},1},{10,"山本一木","金三角",9,1000,1000,500,1000,500,1000,500,{1,7},1},{11,"山本一木","金三角",9,1000,1000,500,1000,500,1000,500,{1,7},1},{12,"山本一木","金三角",9,1000,1000,500,1000,500,1000,500,{1,7},1},{13,"山本一木","金三角",9,1000,1000,500,1000,500,1000,500,{1,7},1},{14,"山本一木","金三角",9,1000,1000,500,1000,500,1000,500,{1,7},1},{15,"山本一木","金三角",9,1000,1000,500,1000,500,1000,500,{1,7},1},
                         };
//当前怪物所在地图怪物坐标
int currentmapmonster[15];
//进入游戏的欢迎界面
void GameWelcom()
{
    int i,j;
    Position(Gap,0);
    printf("%s",Length);
    Position(Gap,1);
    printf("%s",Length);
    for(i=0;i<15;i++)
    {
        Position(Gap,2+i);
        for(j=0;j<74;j++)
        {
            if(j==0)
            printf("||");
            else
            printf(" ");
        }
        printf("||");
    }
    Position(Gap,i);
    printf("%s",Length);
    Position(Gap,i+1);
    printf("%s",Length);
    Position(Gap+22,6);
    printf("欢迎来到大型游戏之笑傲江湖1.0");
    Position(Gap+35,8);
    printf("-----jianyuchen");
    Position(Gap+26,10);
    printf("按任意键进入游戏.....");
    getch();
}
//游戏登录与注册界面
void GameRegister()
{
    int choice,i;
    Position(Gap,0);
    printf("1、注册游戏（新玩家加入）");
    Position(Gap,1);
    printf("2、登录游戏（老玩家回归）");
    Position(Gap,2);
    printf("请选择1或2：");
    while(scanf("%d",&choice)==0||choice<1||choice>2)
    {
        fflush(stdin);
        Position(Gap+12,2);
        printf("输入错误！");
        getch();
        Position(Gap+12,2);
        for(i=0;i<78;i++)
            printf(" ");
        Position(Gap+12,2);
    }
    ClearGameWelcome();
    if(choice==2)
        LoginGame();
    else
        RegisterGame();
}
//登录
void LoginGame()
{
    int i;
    char name[20],password[20];
    Position(Gap,0);
    printf("玩家昵称：");
    scanf("%s",name);
    while(Init(name)==0)
    {
        Position(Gap+10,0);
        scanf("%s",name);
    }
    Position(Gap,1);
    printf("密码：");
    scanf("%s",password);
    while(strcmp(password,currentplayer->password)!=0)
    {
        Position(Gap+6,1);
        printf("输入错误....");
        getch();
        Position(Gap+6,1);
        for(i=0;i<75;i++)
        printf(" ");
        Position(Gap+6,1);
        scanf("%s",password);
    }
    ClearGameWelcome();
}
//注册
void RegisterGame()
{
  int i,t,count,choice;
  for(i=0,count=0;i<sizeof(playerArray)/sizeof(Player);i++)
  {
     if(playerArray[i].id==0)
     {
        count++;
        Position(Gap,0);
        printf("创建你的名字：");
        scanf("%s",playerArray[i].name);
        Position(Gap,1);
        printf("创建密码：");
        scanf("%s",playerArray[i].password);
        playerArray[i].id=count;
        playerArray[i].experience=1000;
        playerArray[i].gold=5000;
        playerArray[i].hp=1000;
        playerArray[i].lever=1;
        playerArray[i].mp=1000;
        t=i;
        break;
     }
     count++;
  }
  Position(Gap,2);
  printf("请选择你的门派(输入编号)：");
  Position(Gap,3);
  for(i=0;i<sizeof(martialArray)/sizeof(Martial);i++)
  {
      if(i%3==0)
        Position(Gap,3+i/3);
      printf("%d,%s\t",martialArray[i].id,martialArray[i].name);
  }
  Position(Gap+26,2);
  while(scanf("%d",&choice)==0||choice<0||choice>10)
  {
      fflush(stdin);
      Position(Gap+26,2);
      printf("输入错误");
      getch();
      Position(Gap+26,2);
      for(i=0;i<78;i++)
        printf(" ");
      Position(Gap+26,2);
  }
  for(i=0;i<sizeof(martialArray)/sizeof(Martial);i++)
  {
      if(choice==martialArray[i].id)
      {
          playerArray[t].department.coord.X=martialArray[i].coord.X;
          playerArray[t].department.coord.Y=martialArray[i].coord.Y;

      }
  }
  Position(Gap,10);
  printf("注册成功......按任意键进入游戏！");
  getch();
  Init(playerArray[t].name);
  ClearGameWelcome();
}
//初始化游戏数据
int Init(char*p_name)
{
    int i;
    for(i=0;i<sizeof(playerArray)/sizeof(Player);i++)
    {
        if(strcmp(p_name,(playerArray+i)->name)==0)
        {
            currentplayer=playerArray+i;
            break;
        }
    }
    if(i==sizeof(playerArray)/sizeof(Player))
    {
        Position(Gap+10,0);
        printf("系统中没有该玩家....");
        getch();
        Position(Gap+10,0);
        for(i=0;i<78;i++)
            printf(" ");
        Position(Gap+10,0);
        return(0);
    }
    return(1);
}
//显示游戏欢迎界面
void ShowWelcom()
{
    Position(Gap,0);
    printf("%s",Length);
    Position(Gap,1);
    printf("|");
    Position(Gap+30,1);
    printf("欢迎来到笑傲江湖");
    Position(Gap+76,1);
    printf("|");
    Position(Gap,2);
    printf("%s",Length);
}
//显示游戏地图
void ShowMap()
{
    int i,j;
    for(i=0; i<8; i++)
    {
        Position(Gap,Map_y+i);
        for(j=0; j<8; j++)
        {
            if(j==0)
                printf("|   ");
            if(i==Y&&j==X)
                ShowColour(0,10);
            printf("%-9s",mapArray[i][j].name);
            ShowColour(10,0);
        }
        printf("|");
    }
    Position(Gap,Map_y+i);
    printf("%s",Length);
}
//显示游戏信息区
void ShowInformation()
{
    int i,j;
    for(i=0; i<9; i++)
    {
        Position(Gap,Inform_y+i);
        printf("|");
        Position(Gap+76,Inform_y+i);
        printf("|");
    }
    Position(Gap,Inform_y+i);
    printf("%s",Length);

}
//显示地图信息
void ShowMapInform()
{
    int i,k,j;
    k=strlen(mapArray[Y][X].desc);
    Clear();
     Position(Gap+8,Inform_y+1);
    for(j=0;j<sizeof(martialArray)/sizeof(Martial);j++)
    {
     if((mapArray[Y][X].coord.X==martialArray[j].coord.X)&&(mapArray[Y][X].coord.Y==martialArray[j].coord.Y))
     {
      Position(Gap+30,Inform_y);
      printf("《%s》总舵",martialArray[j].name);
      break;
     }
    }
    for(i=0;i<k;i++)
    {
    if(i%68==0)
    Position(Gap+5,Inform_y+1+i/68);
    printf("%c",mapArray[Y][X].desc[i]);
    }
}
//显示个人信息
void ShowIndividual()
{
    int i;
    Clear();
    Position(Gap+2,Inform_y);
    printf("*******************************个人信息*********************************");
    Position(Gap+10,Inform_y+1);
    printf("昵称：%s",currentplayer->name);
    Position(Gap+33,Inform_y+1);
    printf("等级：%d",currentplayer->lever);
    Position(Gap+53,Inform_y+1);
    printf("经验：%d",currentplayer->experience);
    Position(Gap+10,Inform_y+2);
    printf("生命值：%d",currentplayer->hp);
    Position(Gap+33,Inform_y+2);
    printf("内力：%d",currentplayer->mp);
    Position(Gap+53,Inform_y+2);
    printf("金币：%d",currentplayer->gold);
    Position(Gap+10,Inform_y+3);
    printf("武器：");
    Position(Gap+33,Inform_y+3);
    printf("防具：");
    Position(Gap+53,Inform_y+3);
    printf("辅助品：");
    Position(Gap+2,Inform_y+4);
    printf("********************************背包************************************");
    if(currentplayer->bag.countt==0)
    {
        Position(Gap+21,Inform_y+5);
        printf("你的背包空荡荡，行走江湖要小心呦！");
    }
    else
    {
        Position(Gap+4,Inform_y+5);
        for(i=0;i<3;i++)
        {
            printf("%-10s%-6s%-7s","名称","加成","数量");
        }
        Position(Gap+4,Inform_y+6);
        for(i=0;i<currentplayer->bag.countt;i++)
        {
            if(i==3)
                Position(Gap+4,Inform_y+7);
            printf("%-10s",currentplayer->bag.props[i].name);
            if(currentplayer->bag.props[i].proptype==Weapon)
                printf("%-6d",currentplayer->bag.props[i].U.Attack);
            if(currentplayer->bag.props[i].proptype==Armor)
                printf("%-6d",currentplayer->bag.props[i].U.Defence);
            if(currentplayer->bag.props[i].proptype==Consumables)
                printf("%-6d",currentplayer->bag.props[i].U.Power);
            printf("%-7d",currentplayer->bag.props[i].countt);

        }
    }
    Position(Gap+1,Inform_y+8);
    for(i=0;i<74;i++)
    {
        printf(" ");
    }
    Position(Gap+24,Inform_y+8);
    printf("请按任意键继续：..........");
    getch();
    ClearEndLine();
}
//商店
void Shop()
{
    int i,j;
    Clear();
    Position(Gap+1,Inform_y);
    printf("******************************欢迎来到商店*********************************");
    Position(Gap+1,Inform_y+1);
    printf("武器    单价  等级  库存");
    Position(Gap+26,Inform_y+1);
    printf("防具    单价  等级  库存");
    Position(Gap+51,Inform_y+1);
    printf("辅助品  单价  等级  库存");
    for(i=0;i<5;i++)
    {
        Position(Gap+1,Inform_y+2+i);
       for(j=0;j<3;j++)
       {
           Position(Gap+1+25*j,Inform_y+2+i);
           printf("%-8s%-6d%-5d%-3d",propArray[i][j].name,propArray[i][j].price,propArray[i][j].lever,propArray[i][j].stock);
       }
    }
}
//商店选项
void Shopnext()
{
    int a,b,i;
    do
    {
    Position(Gap+10,Inform_y+8);
    printf("请输入你要购买的装备编号(按零退出)：");
    while(((b=scanf("%d",&a))==0)||a<0||a>15)
    {
        fflush(stdin);
        Position(Gap+46,Inform_y+8);
        printf("请输入1~15的数字！");
        getch();
        Position(Gap+45,Inform_y+8);
        for(i=0;i<25;i++)
        {
         printf(" ");
        }
        Position(Gap+45,Inform_y+8);
    }
    Position(Gap+45,Inform_y+8);
    for(i=0;i<25;i++)
    {
     printf(" ");
    }
    trade(a,1);
    Shop();
    }while(a!=0);
     Position(Gap+1,Inform_y+8);
    for(i=0;i<75;i++)
    {
        printf(" ");
    }
}
//交易
void trade(int a,int b)
{
    int i,j,t;
    Position(Gap+50,Inform_y+8);
    for(i=0;i<5;i++)
    {
        for(j=0;j<3;j++)
        {
            if(a==propArray[i][j].id)
             {
               if(currentplayer->gold>=propArray[i][j].price)
               {
                 if(propArray[i][j].stock>=1)
                 {
                   if(currentplayer->bag.countt<currentplayer->bag.maxcount)
                   {
                       currentplayer->gold-=propArray[i][j].price;
                       for(t=0;t<currentplayer->bag.countt;t++)
                        {
                          if(currentplayer->bag.props[t].id==propArray[i][j].id)
                            {
                                currentplayer->bag.props[t].countt++;
                                propArray[i][j].stock--;
                                break;
                            }
                        }
                        if(t==currentplayer->bag.countt)
                        {
                          propArray[i][j].stock--;
                          currentplayer->bag.props[t].countt=1;
                          currentplayer->bag.props[t].id=propArray[i][j].id;
                          strcpy(currentplayer->bag.props[t].name,propArray[i][j].name);
                          currentplayer->bag.props[t].proptype=propArray[i][j].proptype;
                          currentplayer->bag.props[t].U=propArray[i][j].U;
                          currentplayer->bag.countt++;
                        }
                   }
                   else
                    printf("背包满了!");
                 }
                 else
                    printf("对不起，没货啦！");
               }
               else
                printf("大侠，你的钱不够啦！请充值！");
             }
        }
    }
}
//显示怪物
void ShowMonster()
{
    int i,j;
    for(i=0,j=0;i<sizeof(monsterArray)/sizeof(Monster);i++)
    {
        if((mapArray[Y][X].coord.X==monsterArray[i].coord.X)&&(mapArray[Y][X].coord.Y==monsterArray[i].coord.Y))
        currentmapmonster[j++]=i;
    }
    Clear();
    if(j==0)
    {
        Position(Gap+20,Inform_y+3);
        printf("这里一个怪物都没有，到别处去吧！");
    }
    else
    {
        Position(Gap+3,Inform_y);
        printf("%s地图的怪物如下：",mapArray[Y][X].name);
        Position(Gap+3,Inform_y+2);
        for(i=0;i<9;i++)
        {
           if(i==j)
             break;
           if(i%3==0)
             Position(Gap+3,Inform_y+2+i/3);
           if(monsterArray[currentmapmonster[i]].sign==1)
           printf("%-2d%-10s(%d)\t\t",monsterArray[currentmapmonster[i]].id,monsterArray[currentmapmonster[i]].name,monsterArray[currentmapmonster[i]].grade);
           if(i==j)
            break;
        }
    }
}
//查看怪物
void ScanMonster()
{
    int i,Hp;
    Hp=currentplayer->hp;
    char key;//查看怪物按钮
    Clear();
    ShowMonster();
    do{
        ClearEndLine();
        Position(Gap+2,Inform_y+8);
        printf("请输入要打的怪物编号或四方移动查看怪物(按零退出)：");
        key=getch();
        fflush(stdin);
        switch (key)
        {
        case 75:
            X--;
            currentplayer->hp=Hp;//退出地图后回血
            if(X<0) X=7;
            ShowMap();
            ShowMonster();
            break;
        case 72:
            Y--;
            currentplayer->hp=Hp;
            if(Y<0) Y=7;
            ShowMap();
            ShowMonster();
            break;
        case 77:
            X++;
            currentplayer->hp=Hp;
            if(X>7) X=0;
           ShowMap();
           ShowMonster();
            break;
        case 80:
            Y++;
            currentplayer->hp=Hp;
            if(Y>7) Y=0;
            ShowMap();
            ShowMonster();
            break;
        case '0':
            break ;
            /*
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            Position(Gap+51,Inform_y+8);
            putchar(key);
            getch();
            Fight(key);
            break;
        default :
            Position(Gap+52,Inform_y+8);
            printf("输入错误！按任意键继续");
            getch();
            ClearEndLine();
            */
       }
        if(key!=80&&key!=77&&key!=72&&key!=75&&key!='0')
        Fight(key);
    }while(key!='0');
    ClearEndLine();
    Clear();
    Position(Gap+32,Menu_y+5);
    currentplayer->hp=Hp;
}
//战斗
void Fight(int key)
{
    int i,gold,exp;
    srand(time(NULL));
    key-=48;
    if(currentplayer->hp==0)
    {
        ClearEndLine();
        Position(Gap+5,Inform_y+8);
        printf("%s已没血,不可继续作战!按任意键继续......",currentplayer->name);
        getch();
        return;
    }

    for(i=0;i<15;i++)
    {
        if(monsterArray[currentmapmonster[i]].id==key)
        {
            while(monsterArray[currentmapmonster[i]].hp>0&&currentplayer->hp>0)
            {
                monsterArray[currentmapmonster[i]].hp-=100+monsterArray[currentmapmonster[i]].de;
                currentplayer->hp-=monsterArray[currentmapmonster[i]].power+100;
                if(currentplayer->hp<=0)
                    currentplayer->hp=0;
                ClearEndLine();
                Position(Gap+5,Inform_y+8);
                printf("怪物的血量： %d，%s的血量 %d",monsterArray[currentmapmonster[i]].hp,currentplayer->name,currentplayer->hp);
                Sleep(1000);

            }
            if(currentplayer->hp==0&&monsterArray[currentmapmonster[i]].hp>0)
            {
                ClearEndLine();
                Position(Gap+5,Inform_y+8);
                printf("难敌怪物，%s死亡，作战失败!按任意键继续......",currentplayer->name);
                getch();
            }
            if(monsterArray[currentmapmonster[i]].hp<=0&&currentplayer->hp>0)
            {
                ClearEndLine();
                gold=rand()%(monsterArray[currentmapmonster[i]].maxgold-monsterArray[currentmapmonster[i]].mingold)+monsterArray[currentmapmonster[i]].mingold;
                exp=rand()%(monsterArray[currentmapmonster[i]].maxexp-monsterArray[currentmapmonster[i]].minexp)+monsterArray[currentmapmonster[i]].minexp;
                currentplayer->gold+=gold;
                currentplayer->experience+=exp;
                monsterArray[currentmapmonster[i]].sign=0;
                Position(Gap+5,Inform_y+8);
                printf("你好棒喔！%s死亡，你获得%d金币，%d经验!按任意键继续.....",monsterArray[currentmapmonster[i]].name,gold,exp);
                getch();
            }
            if(monsterArray[currentmapmonster[i]].hp<=0&&currentplayer->hp==0)
            {
                ClearEndLine();
                monsterArray[currentmapmonster[i]].sign=0;
                Position(Gap+5,Inform_y+8);
                printf("很不幸，同归于尽.......按任意键继续........");
                getch();
            }
        break;
       }
    }
    ShowMonster();
}

//回总舵
void Move()
{
Y=currentplayer->department.coord.Y;
X=currentplayer->department.coord.X;
ShowMap();
}
//显示菜单
void ShowMenu()
{
    Position(Gap,Menu_y);
    printf("游戏菜单");
    Position(Gap,Menu_y+1);
    printf("1,自我欣赏");
    Position(Gap,Menu_y+2);
    printf("2,查探");
    Position(Gap,Menu_y+3);
    printf("3,回总部");
    Position(Gap,Menu_y+4);
    printf("4,购买装备");
    Position(Gap,Menu_y+5);
    printf("请输入选择或四方移动(按零退出游戏)：");
}
//进入游戏界面
void GameMain()
{
    char key;//菜单按钮
    ShowWelcom();
    ShowMap();
    ShowInformation();
    ShowMenu();
    while(1)
    {
        key=getch();
        fflush(stdin);
        switch (key)
        {
        case 75:
            X--;
            if(X<0) X=7;
            ShowMap();
            ShowMapInform();
            break;
        case 72:
            Y--;
            if(Y<0) Y=7;
            ShowMap();
            ShowMapInform();
            break;
        case 77:
            X++;
            if(X>7) X=0;
           ShowMap();
           ShowMapInform();
            break;
        case 80:
            Y++;
            if(Y>7) Y=0;
            ShowMap();
            ShowMapInform();
            break;
        case '1':
            ShowIndividual();
            ShowMapInform();
            break;
        case '2':
            ScanMonster();
            ShowMapInform();
            break;
        case '3':
            Move();
            ShowMapInform();
            break;
        case '4':
            Shop();
            Shopnext();
            ShowMapInform();
            break;
        /*case 2:
        case 3:
        case 4:
            */
        case '0':
            exit(0);
            break;
       /* default :
            Position(Gap+36,Menu_y+6);
            printf("输入错误！");*/
        }
    }
    return;
}
