#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include "Gamelib.h"
#include "Game.h"
#define Length "-----------------------------------------------------------------------------"//��Ϸ����ĳ���78
#define Gap 20 //��Ϸ�ı߾�
#define Map_y 3//��ͼ����
#define Inform_y 12//��Ϣ������
#define Menu_y 22//�˵��ĳ���
int X=3,Y=2;
Map mapArray[8][8]=
{
    {   {1,"��ɽ",1,"�����ɣ��л���ѧ��̩������������ɮϰ��֮��ԴԶ��������ĩ�������ڶ���˲��У�����պͼ��������Ϊһ�ȡ����У���ճ���Ϊɮ���������׼ҵ��ӡ���ʱ�����˳�����˫��������������ɮ�������ϵĴ����²μ��˽����غ��������ܵ�ս�����ڸ�·Ӧļ�����б��ֵ���Ϊ���¡���������֮�£�Ҳʹ�����е��ڶ����ɲ�����ì�ܣ������������ֺ�������̡���ա����������ȴ��콭��ͬ�ʹ��Ϲ�������������������̺�Ѫ�����ɽ�Ϊͬ�ˣ����ο�а���и������ƣ����Լ���Χ��δ�����գ��ڰ���������",{0,0}},
        {2,"¥��",1,"����յ���",{1,0}},
        {3,"����ɽ",1,"�����᣺�����������������һ��������֯���������·�ʮ���ã��ֱ�����Ϊ���ţ������¡�����Ŀ�ꡮ���¡�������͸�����¡����𴫵���Ϣ�����¡������Դ�����¡������̷������¡�����ѵ�������¡�����߻����ˡ��š�ʮ�¡������ж���ʮһ�¡������������桮ʮ���¡�����ɱĿǰ���������������Ϊ�����������˳ƺ���ү����������ѷ����Ϊ�ſ�������Ա�󽫣�һΪ��Ѫ������Ϊ��ˮ��",{2,0}},
        {4,"Ұ����",1,"����յ���",{3,0}},
        {5,"ˮ����",1,"����յ���",{4,0}},
        {6,"��϶�",1,"����յ���",{5,0}},
        {7,"�ڷ�կ",1,"����յ���",{6,0}},
        {8,"����",1,"����յ���",{7,0}},
    },
    {   {9,"�Թ�",1,"ؤ������ԭ������������Ϊ�ڶ��һ�����ɣ�Ҳ�����µ�һ����ɣ��Ա鲼������ؤ����ؤ��ɣ���Ϊ���°�;��°ؤ�����˴�඼������λ�Ƚϵ͵��ˣ������Ǹ�����Ӳ�ǣ�Ʒ����У����ٳ��ֱ���֮�ˡ�ؤ����һ���ڶ���������Ϊ�ף������������������塢��ǿ������������ΪΪ������������ֵ���",{0,1}},
        {10,"������",1,"����յ���",{1,1}},
        {11,"��ԯ��",1,"����յ���",{2,1}},
        {12,"��ɽ",1,"�������ɣ�̩ɽ�ɣ���ɽ�ɣ���ɽ�ɣ���ɽ�ɣ���ɽ�ɽ�Ϊͬ��֦���ĵ��������ɣ��ڽ���������������������һ������Ĳ��ͣ��������ɵ�ʽ΢��������������֣����������ڲ�ì�ܼ��������ںĵĽ�����ڲ��Ĺ��Ķ�����Ȼ�����Կ���Ϊ��ڳ��֣�ʵ����Ϊ������������ɱ��Ȩ��",{3,1}},
        {13,"��ɽ",1,"����յ���",{4,1}},
        {14,"�Ͻ���",1,"����յ���",{5,1}},
        {15,"�����",1,"����յ���",{6,1}},
        {16,"������",1,"Ѫ���ɣ��Դ�Ѫ���ɵ�����һ������������ƮȻ��ȥ��Ѫ��������˥�䡣Ѫ���ɻ�ķ�ΧҲԽ��Խ�٣�������ֻ��������ʯ�ߡ��������ϵľŴ������Ѿ���Ѫ������Ϊаħ��������Ѵ���Ӣ���ֻҪ�Ŵ����ɵ���������Ѫ���ɵ��ˣ�һ�ɸ�ɱ���ۡ��ڽ������Ѿ�û��ʲôѪ���ɵ��������ߡ������޺ޣ�û����֪�������Ժη�������ֻ֪��������Ѫ���ɡ�û����֪�������书�ж�ߣ���Ϊ�������Ľ����˶��Ѿ�......",{7,1}},
    },
    {   {17,"����",1,"����յ���",{0,2}},
        {18,"��«��",1,"����յ���",{1,2}},
        {19,"����",1,"�Ĵ����ţ������ڽ������԰������������Դ����ŵ�����̫̫�������Ƽұ�һ�ȼҵ����䣬��֮����Ϊ�ư����������������ʹ�����������ٶȵĺƽ٣�����һ�겻��������Σ�ѵ�ʱ�����ų�����һȺ������������磡���ն����ȱ�������������������������������˿︴������������ģ������ڽ������������壬��������ŵ�������ʹ���ų�Ϊ�˽����ϵ��������ɡ�",{2,2}},
        {20,"����ɽ",1,"����յ���",{3,2}},
        {21,"ʯ��",1,"����յ���",{4,2}},
        {22,"��ջ",1,"����յ���",{5,2}},
        {23,"��ʶ�",1,"�����̣��������ǽ���а�ɣ����ڽ�ַԶ����ԭ�����Բ����Ԥ��ԭ���ֵ�Ѫ��ɱ¾��Ŀǰ����������λ����һΪ���񣬴����书����Ī�⣬�Ը��Ƨ�������ϲ���˽ӽ�����Ϊ�������书��ǿ��Ƣ�����꣬����û�����ԡ�",{6,2}},
        {24,"���ߵ�",1,"����յ���",{7,2}},
    },
    {   {25,"������",1,"ȫ�����ڵ��̵ķ�֧֮һ���ֽ�ȫ���������Ȩ��������һ������СС���ˣ�����һ˫���䵭��������Զ������ʲô�仯���۾����������·��ǻ�ɫ�ġ���������һ���ǳ��������ˣ���ϲ����ɫ��ϲ��������˻������ƣ�ϲ�����ܡ���ÿһ�����������ǳ������ޣ�����ÿһ���¶��������ܼƻ��������϶��˷�һ��������Ҳ������һ������������ȫ�溣�š�",{0,3}},
        {26,"Ħ����",1,"����յ���",{1,3}},
        {27,"����ׯ",1,"����յ���",{2,3}},
        {28,"��ɽ",1,"����յ���",{3,3}},
        {29,"�䵱ɽ",1,"��ɽ�ɣ���ɽ�����������ɣ�Ҳ��Ŀǰ��������Ϊ�Ž��һ�����ɡ���ɽ��Ҳ�ǽ�����Ů������Ϊ�ڶ��һ�����ɣ��Ҹ����书���費������ò���㡣��ɽ�ɴ�ʦ�֣���˫ ��ɽ�ɶ�ʦ�֣�������ɽ����ʦ�֣�������ɽ����ʦ�֣�����",{4,3}},
        {30,"���⸮",1,"����յ���",{5,3}},
        {31,"��ʮ����",1,"����յ���",{6,3}},
        {32,"�����ɵ�",1,"����յ���",{7,3}},
    },
    {   {33,"�޹�̨",1,"����յ���",{0,4}},
        {34,"��üɽ",1,"�䵱�ɣ��䵱�ڽ������������������С��������֡��������䵱��֮˵���䵱��һ�������������һλǫǫ���ӣ�һ�������������������Ǵ���ˬ�ʵ�Ц�ݣ��������ĳ�ж����ܲ������������ټ������Ӻ������˴�ʮ�������𽭺�������С��ʮ��ս�������δ�ܹ�һ�Ρ�����һ����������ܵ������¾���ʧ�ܺʹ������䵱���ֻ��������ͼ��������˶�λ��񽭺��粨�ն񣬶�Թ��ɱ��Ҳ��׷������ҵ�����Զ�����������������ɡ�",{1,4}},
        {35,"������",1,"����յ���",{2,4}},
        {36,"�廢��",1,"����յ���",{3,4}},
        {37,"������",1,"����յ���",{4,4}},
        {38,"������",1,"����յ���",{5,4}},
        {39,"�򽭸�",1,"����յ���",{6,4}},
        {40,"�һ���",1,"�һ������ԴӶ�а��ҩʦ���������ڴ˺����Ĵ��˾����������Ӳ����������һ������������ɵ��ܶ档�һ�����ҩʦ�Ĺ��ŵ��ӳ�Ӣһ��δ�ޣ��ڵ������˼���ͽ�ܣ��һ������书��˵õ������ͷ���ֽ��и�����һ�п��ĵ�Ů�ӣ���Ů������°����壬��ϲ���˽Ӵ���������ĥ��͸�����Ĳ���ѧ���黭���塢������ԣ�����ҽ�������������У���һ���ᣬ��һ���������ഫ������һ����ǰ�������꽭���˳ơ����èͷӥ����",{7,4}},
    },
    {   {41,"���˹�",1,"����յ���",{0,5}},
        {42,"����",1,"������ϣ���������˶��ڶ࣬�������ơ�������һλ���ｭ������Ů��������ѩ������ѩ���������㣬��ɫ��𪣬��΢������������ȥ��������ȴ�������书������ô����书�ĵá���������ֻ��кúú�ĬĬ�����˶�����Ӽ����������ʽ������£����Է���������ѩ���ڽ����ϵ���ͷ������",{1,5}},
        {43,"�ٻ���",1,"����յ���",{2,5}},
        {44,"��ȸɽׯ",1,"����յ���",{3,5}},
        {45,"��Ը�",1,"�嶾�̣�һ����ʹ��Ϊר�������ɣ������˸��������ö����֡����ɸ����˳����ʣ�����ʹ�����뻯��������������ĥ������ͬ������Ī���Ƶ����С�����Ʒ��ʱ��ʱ����������׿��������ɳա�",{4,5}},
        {46,"������",1,"����յ���",{5,5}},
        {47,"ǧ���ɲ",1,"����յ���",{6,5}},
        {48,"������",1,"����յ���",{7,5}},
    },
    {   {49,"��żׯ",1,"��żɽׯ��������һ�����ص����ɣ���ʼ�ˣ��书���顣�ܶ������żɽׯ������������������⡣��żɽׯ�����ڶ࣬���󶼾���������ֻ�����⾭�������˼����������������ã������������˲�֪����ôһ�����ɴ��ڡ�",{0,6}},
        {50,"��ľ��",1,"����յ���",{1,6}},
        {51,"������",1,"����յ���",{2,6}},
        {52,"������",1,"�����ţ�������������ٸ���������Ҳ�����ڽ����ϴ������õ����ָ��֡�������һ��һ���˲�����һλ�ºŽС����������ģ����˴Ӳ�������Ŀ���ˣ�������Ļ��߻�һЩ���顣�����������л���һ�����ｭ���˳ơ��ɰ��Ĳ�Ӭ������Ϊ�˴���ȴΪ����ͬ�������ܡ�",{3,6}},
        {53,"������",1,"����յ���",{4,6}},
        {54,"�ص���",1,"����յ���",{5,6}},
        {55,"����ׯ",1,"����յ���",{6,6}},
        {56,"���깬",1,"Ȩ���а��֮һ��Ŀǰ�����������Ϊһ�а��ɵ������ˡ����ɣ�һ���������쳣��㨵��ˡ�û�����佻���ֵ����ָ��֣��޷������������������������������ô���Ǳ�����������������������֧����Ȩ����ĵ��ӵġ�",{7,6}},
    },
    {   {57,"ʯ��",1,"��Ĺ�ɣ���Ĺ����һ���Ĵ���������������һŮ�ӣ�������������������浾������࿡������ֹƮ�ݣ���������ȴ����ʦ��С��Ů��������һ������ķ���书��Ϊ��ɲ⣬ͬ��ϲ�����¡����Ṧ׿Խ��������ȭ���鶯���������ȫ��̵Ŀ��ǡ���Ĺ���˵Ĵ���ԭ���ǡ��²��ؼ����߸߹��𡱣������������������ӣ������������ð���˹�Ĺ���ˣ�����һ�������úܲҡ�",{0,7}},
        {58,"������",1,"����յ���",{1,7}},
        {59,"�����",1,"����յ���",{2,7}},
        {60,"ͨ�Ե�",1,"ͨͨ�ԣ�������һ�����ص����ɣ���ʼ�ˣ��书���顣�ܶ�����ͨ�Ե�����������������Ժ��������ֶ��Ͽᣬ�������ˡ�ƽ��������̤����ԭ���֣�Ǳ�������书",{3,7}},
        {61,"ͨ���",1,"������̣����ڸý̸����ڶ࣬���˴˻�����������Խ�����ӡ����е��Ӷ�Ϊа��֮ͽ��ר�������������ԣ�ɱ�����࣬������ã��ʱ���������֮�˱�Ϊħ�̡��ֽ�������̶�����������ˣ� ħ����ģ��������Ժ������ѣ��������˿��ü��ص���������벻�����ģ������¼�Ϊƫ��������Ϊͼһʱ֮�����ɱ���ˡ�а���Ӱ���������Է������Σ���ò���ף��������֮���������Ը�����������һ�����������֪����ɷ���齣�����������������ƣ����ٹ��죬�������˵ü���������Ŀ������ȫƾ���˺ö񣬲���ԭ��",{4,7}},
        {62,"��ϼͤ",1,"����յ���",{5,7}},
        {63,"����",1,"����յ���",{6,7}},
        {64,"���͵�",1,"���ڽ����������ڽ��������˲żüã����������񣬴���Ұ�Ĳ�������������һ�������չ����ųƵ�ǹ���룬�书ʵ����ɲ⡣����Ϊ�˻��ǣ���ͨ�������б�ʱ�ܽ�ǧ��������ʹ����ͬ��ʮ�������ʮ�㡣����С���������书֮���⻹��ͨҽ�����ųư��ΰٲ�������������֮�ܣ����Ӳ����׸����β����˶��˶�Ϊ�������ˣ���ֻ��Ͷ����ڽ����������������ɼ�����һЩ������Υ���£������Զ��Ǽ�����������������������е�ְȨ���˲��ٱ��ݺ�������ͬ����",{7,7}},
    }
};
//����
Martial martialArray[]={{1,"������",{0,0}},{2,"������",{2,0}},{3,"ؤ��",{0,1}},{4,"��������",{3,1}},{5,"Ѫ����",{7,1}},{6,"�Ĵ�����",{2,2}},{7,"������",{6,2}},{8,"ȫ���",{0,3}},{8,"��ɽ��",{4,3}},{9,"�䵱��",{1,4}},{10,"�һ���",{7,4}},{11,"�������",{1,5}},{12,"�嶾��",{4,5}},{13,"��żɽׯ",{0,6}},{14,"������",{3,6}},{15,"Ȩ����",{7,6}},{16,"��Ĺ��",{0,7}},{17,"ͨͨ��",{3,7}},{18,"�������",{4,7}},{19,"���ڽ�����",{7,7}},};
Prop propArray[5][3]={
                      {
                        {1,"��аϬ",1,100,10,Weapon,.U.Attack=20},{2,"̫����",1,100,10,Armor,.U.Defence=20},{3,"С��ƿ",1,100,10,Consumables,.U.Power=20}
                      },
                      {
                        {4,"����� ",3,500,10,Weapon,.U.Attack=80},{5,"������ ",3,500,10,Armor,.U.Defence=80},{6,"����ƿ",1,500,10,Consumables,.U.Power=200}
                      },
                      {
                        {7,"һ�ַ�",5,1000,10,Weapon,.U.Attack=150},{8,"Ѫ����",5,1000,10,Armor,.U.Defence=150},{9,"СѪƿ",1,100,10,Consumables,.U.Power=20}
                      },
                      {
                        {10,"�廢��",8,3000,10,Weapon,.U.Attack=250},{11,"������",8,3000,10,Armor,.U.Defence=300},{12,"��Ѫƿ",1,500,10,Consumables,.U.Power=200}
                      },

                       {
                        {13,"ӭ��ǹ",10,5000,10,Weapon,.U.Attack=500},{14,"�ⱦ����",10,5000,10,Armor,.U.Defence=450},{15,"��¶��",1,1000,10,Consumables,.U.Power=500}
                      },

            };
//���
Player playerArray[10]={{1,"����","1847796089",1,100,1000,500,800,3000,.bag.maxcount=6,{0,0}}};
//��ǰ���
Player*currentplayer=NULL;
//����
Monster monsterArray[]={{1,"����","¥��",1,500,10,10,500,100,500,100,{1,0},1},{2,"����","¥��",1,500,10,10,500,100,500,100,{1,0},1},{3,"����","¥��",1,500,10,10,500,100,500,100,{1,0},1},{4,"����","¥��",1,500,10,10,500,100,500,100,{1,0},1},{5,"����","¥��",1,500,10,10,500,100,500,100,{1,0},1},{6,"����","¥��",1,500,10,10,500,100,500,100,{1,0},1},
                         {1,"����","��϶�",2,800,20,20,600,200,600,200,{5,0},1},{2,"����","��϶�",2,800,20,20,600,200,600,200,{5,0},1},{3,"����","��϶�",2,800,20,20,600,200,600,200,{5,0},1},{4,"����","��϶�",2,800,20,20,600,200,600,200,{5,0},1},{5,"����","��϶�",2,800,20,20,600,200,600,200,{5,0},1},{6,"����","��϶�",2,800,20,20,600,200,600,200,{5,0},1},
                         {1,"����","������",3,1000,30,30,800,300,800,400,{1,1},1},{2,"����","������",3,1000,30,30,800,300,800,400,{1,1},1},{3,"����","������",3,1000,30,30,800,300,800,400,{1,1},1},{4,"����","������",3,1000,30,30,800,300,800,400,{1,1},1},{5,"����","������",3,1000,30,30,800,300,800,400,{1,1},1},{6,"����","������",3,1000,30,30,800,300,800,400,{1,1},1},
                         {1,"������","�����",4,1000,40,40,800,400,800,500,{6,1},1},{2,"������","�����",4,1000,40,40,800,400,800,500,{6,1},1},{3,"������","�����",4,1000,40,40,800,400,800,500,{6,1},1},{4,"������","�����",4,1000,40,40,800,400,800,500,{6,1},1},{5,"������","�����",4,1000,40,40,800,400,800,500,{6,1},1} ,{6,"������","�����",4,1000,40,40,800,400,800,500,{6,1},1},
                         {1,"����ͽ","����",5,1200,80,60,1000,400,1000,500,{0,2},1},{2,"����ͽ�˰�","����",5,1200,80,60,1000,400,1000,500,{0,2},1},{3,"������","����",4,1000,40,40,800,400,800,500,{0,2},1},{4,"����","����",1,500,10,10,500,100,500,100,{0,2},1},{5,"����","����",2,800,20,20,600,200,600,200,{0,2},1},{6,"����ͽ�˰�","����",5,1200,80,60,1000,400,1000,500,{0,2},1},
                         {1,"����ͽ�˰�","Ħ����",6,1400,100,80,1000,500,1000,600,{1,3},1},{2,"����ͽ�˰�","Ħ����",6,1400,100,80,1000,500,1000,600,{1,3},1},{3,"ɽ��һľ","Ħ����",6,1400,100,80,1000,500,1000,600,{1,3},1},{4,"����ͽ�˰�","Ħ����",6,1400,100,80,1000,500,1000,600,{1,3},1},{5,"����ͽ�˰�","Ħ����",6,1400,100,80,1000,500,1000,600,{1,3},1},{6,"����ͽ�˰�","Ħ����",6,1400,100,80,1000,500,1000,600,{1,3},1},{7,"ɽ��һľ","Ħ����",6,1400,100,80,1000,500,1000,600,{1,3},1},{8,"ɽ��һľ","Ħ����",6,1400,100,80,1000,500,1000,600,{1,3},1},{9,"ɽ��һľ","Ħ����",6,1400,100,80,1000,500,1000,600,{1,3},1},
                         {1,"ɽ��һľ","������",6,1400,100,80,1000,500,1000,600,{2,4},1},{2,"ɽ��һľ","������",6,1400,100,80,1000,500,1000,600,{2,4},1},{3,"ɽ��һľ","������",6,1400,100,80,1000,500,1000,600,{2,4},1},{4,"��ڣ����","������",7,1500,120,70,1200,500,1200,600,{2,4},1},{5,"��ڣ����","������",7,1500,120,70,1200,500,1200,600,{2,4},1},{6,"��ڣ����","������",7,1500,120,70,1200,500,1200,600,{2,4},1},{7,"��ڣ����","������",7,1500,120,70,1200,500,1200,600,{2,4},1},{8,"��ڣ����","������",7,1500,120,70,1200,500,1200,600,{2,4},1},
                         {1,"��ڣ����","�ٻ���",7,1500,120,70,1200,500,1200,600,{2,5},1},{2,"��ڣ����","�ٻ���",7,1500,120,70,1200,500,1200,600,{2,5},1},{3,"����","������",8,2000,120,100,1200,900,1200,800,{2,4},1},{4,"����","������",8,2000,120,100,1200,900,1200,800,{2,4},1},{5,"����","������",8,2000,120,100,1200,900,1200,800,{2,4},1},{6,"����","������",8,2000,120,100,1200,900,1200,800,{2,4},1},{7,"����","������",8,2000,120,100,1200,900,1200,800,{2,4},1},{8,"����","������",8,2000,120,100,1200,900,1200,800,{2,4},1},{9,"����","������",8,2000,120,100,1200,900,1200,800,{2,4},1},
                         {1,"����","�ص���",8,2000,120,100,1200,900,1200,800,{5,6},1},{2,"�������","�ص���",9,3000,550,300,2000,1000,2000,1000,{5,6},1},
                         {1,"СȪ��һ��","������",10,9000,1000,700,12000,9000,5000,4000,{1,7},1},{2,"����","������",9,1000,1000,500,1000,500,1000,500,{1,7},1},{3,"����","������",9,1000,1000,500,1000,500,1000,500,{1,7},1},{4,"����","������",9,1000,1000,500,1000,500,1000,500,{1,7},1},{5,"������","������",9,1000,1000,500,1000,500,1000,500,{1,7},1},{6,"����","������",9,1000,1000,500,1000,500,1000,500,{1,7},1},{7,"����","������",9,1000,1000,500,1000,500,1000,500,{1,7},1},{8,"ɽ��һľ","������",9,1000,1000,500,1000,500,1000,500,{1,7},1},{9,"ɽ��һľ","������",9,1000,1000,500,1000,500,1000,500,{1,7},1},{10,"ɽ��һľ","������",9,1000,1000,500,1000,500,1000,500,{1,7},1},{11,"ɽ��һľ","������",9,1000,1000,500,1000,500,1000,500,{1,7},1},{12,"ɽ��һľ","������",9,1000,1000,500,1000,500,1000,500,{1,7},1},{13,"ɽ��һľ","������",9,1000,1000,500,1000,500,1000,500,{1,7},1},{14,"ɽ��һľ","������",9,1000,1000,500,1000,500,1000,500,{1,7},1},{15,"ɽ��һľ","������",9,1000,1000,500,1000,500,1000,500,{1,7},1},
                         };
//��ǰ�������ڵ�ͼ��������
int currentmapmonster[15];
//������Ϸ�Ļ�ӭ����
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
    printf("��ӭ����������Ϸ֮Ц������1.0");
    Position(Gap+35,8);
    printf("-----jianyuchen");
    Position(Gap+26,10);
    printf("�������������Ϸ.....");
    getch();
}
//��Ϸ��¼��ע�����
void GameRegister()
{
    int choice,i;
    Position(Gap,0);
    printf("1��ע����Ϸ������Ҽ��룩");
    Position(Gap,1);
    printf("2����¼��Ϸ������һع飩");
    Position(Gap,2);
    printf("��ѡ��1��2��");
    while(scanf("%d",&choice)==0||choice<1||choice>2)
    {
        fflush(stdin);
        Position(Gap+12,2);
        printf("�������");
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
//��¼
void LoginGame()
{
    int i;
    char name[20],password[20];
    Position(Gap,0);
    printf("����ǳƣ�");
    scanf("%s",name);
    while(Init(name)==0)
    {
        Position(Gap+10,0);
        scanf("%s",name);
    }
    Position(Gap,1);
    printf("���룺");
    scanf("%s",password);
    while(strcmp(password,currentplayer->password)!=0)
    {
        Position(Gap+6,1);
        printf("�������....");
        getch();
        Position(Gap+6,1);
        for(i=0;i<75;i++)
        printf(" ");
        Position(Gap+6,1);
        scanf("%s",password);
    }
    ClearGameWelcome();
}
//ע��
void RegisterGame()
{
  int i,t,count,choice;
  for(i=0,count=0;i<sizeof(playerArray)/sizeof(Player);i++)
  {
     if(playerArray[i].id==0)
     {
        count++;
        Position(Gap,0);
        printf("����������֣�");
        scanf("%s",playerArray[i].name);
        Position(Gap,1);
        printf("�������룺");
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
  printf("��ѡ���������(������)��");
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
      printf("�������");
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
  printf("ע��ɹ�......�������������Ϸ��");
  getch();
  Init(playerArray[t].name);
  ClearGameWelcome();
}
//��ʼ����Ϸ����
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
        printf("ϵͳ��û�и����....");
        getch();
        Position(Gap+10,0);
        for(i=0;i<78;i++)
            printf(" ");
        Position(Gap+10,0);
        return(0);
    }
    return(1);
}
//��ʾ��Ϸ��ӭ����
void ShowWelcom()
{
    Position(Gap,0);
    printf("%s",Length);
    Position(Gap,1);
    printf("|");
    Position(Gap+30,1);
    printf("��ӭ����Ц������");
    Position(Gap+76,1);
    printf("|");
    Position(Gap,2);
    printf("%s",Length);
}
//��ʾ��Ϸ��ͼ
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
//��ʾ��Ϸ��Ϣ��
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
//��ʾ��ͼ��Ϣ
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
      printf("��%s���ܶ�",martialArray[j].name);
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
//��ʾ������Ϣ
void ShowIndividual()
{
    int i;
    Clear();
    Position(Gap+2,Inform_y);
    printf("*******************************������Ϣ*********************************");
    Position(Gap+10,Inform_y+1);
    printf("�ǳƣ�%s",currentplayer->name);
    Position(Gap+33,Inform_y+1);
    printf("�ȼ���%d",currentplayer->lever);
    Position(Gap+53,Inform_y+1);
    printf("���飺%d",currentplayer->experience);
    Position(Gap+10,Inform_y+2);
    printf("����ֵ��%d",currentplayer->hp);
    Position(Gap+33,Inform_y+2);
    printf("������%d",currentplayer->mp);
    Position(Gap+53,Inform_y+2);
    printf("��ң�%d",currentplayer->gold);
    Position(Gap+10,Inform_y+3);
    printf("������");
    Position(Gap+33,Inform_y+3);
    printf("���ߣ�");
    Position(Gap+53,Inform_y+3);
    printf("����Ʒ��");
    Position(Gap+2,Inform_y+4);
    printf("********************************����************************************");
    if(currentplayer->bag.countt==0)
    {
        Position(Gap+21,Inform_y+5);
        printf("��ı����յ��������߽���ҪС���ϣ�");
    }
    else
    {
        Position(Gap+4,Inform_y+5);
        for(i=0;i<3;i++)
        {
            printf("%-10s%-6s%-7s","����","�ӳ�","����");
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
    printf("�밴�����������..........");
    getch();
    ClearEndLine();
}
//�̵�
void Shop()
{
    int i,j;
    Clear();
    Position(Gap+1,Inform_y);
    printf("******************************��ӭ�����̵�*********************************");
    Position(Gap+1,Inform_y+1);
    printf("����    ����  �ȼ�  ���");
    Position(Gap+26,Inform_y+1);
    printf("����    ����  �ȼ�  ���");
    Position(Gap+51,Inform_y+1);
    printf("����Ʒ  ����  �ȼ�  ���");
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
//�̵�ѡ��
void Shopnext()
{
    int a,b,i;
    do
    {
    Position(Gap+10,Inform_y+8);
    printf("��������Ҫ�����װ�����(�����˳�)��");
    while(((b=scanf("%d",&a))==0)||a<0||a>15)
    {
        fflush(stdin);
        Position(Gap+46,Inform_y+8);
        printf("������1~15�����֣�");
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
//����
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
                    printf("��������!");
                 }
                 else
                    printf("�Բ���û������");
               }
               else
                printf("���������Ǯ�����������ֵ��");
             }
        }
    }
}
//��ʾ����
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
        printf("����һ�����ﶼû�У�����ȥ�ɣ�");
    }
    else
    {
        Position(Gap+3,Inform_y);
        printf("%s��ͼ�Ĺ������£�",mapArray[Y][X].name);
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
//�鿴����
void ScanMonster()
{
    int i,Hp;
    Hp=currentplayer->hp;
    char key;//�鿴���ﰴť
    Clear();
    ShowMonster();
    do{
        ClearEndLine();
        Position(Gap+2,Inform_y+8);
        printf("������Ҫ��Ĺ����Ż��ķ��ƶ��鿴����(�����˳�)��");
        key=getch();
        fflush(stdin);
        switch (key)
        {
        case 75:
            X--;
            currentplayer->hp=Hp;//�˳���ͼ���Ѫ
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
            printf("������󣡰����������");
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
//ս��
void Fight(int key)
{
    int i,gold,exp;
    srand(time(NULL));
    key-=48;
    if(currentplayer->hp==0)
    {
        ClearEndLine();
        Position(Gap+5,Inform_y+8);
        printf("%s��ûѪ,���ɼ�����ս!�����������......",currentplayer->name);
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
                printf("�����Ѫ���� %d��%s��Ѫ�� %d",monsterArray[currentmapmonster[i]].hp,currentplayer->name,currentplayer->hp);
                Sleep(1000);

            }
            if(currentplayer->hp==0&&monsterArray[currentmapmonster[i]].hp>0)
            {
                ClearEndLine();
                Position(Gap+5,Inform_y+8);
                printf("�ѵй��%s��������սʧ��!�����������......",currentplayer->name);
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
                printf("��ð�ร�%s����������%d��ң�%d����!�����������.....",monsterArray[currentmapmonster[i]].name,gold,exp);
                getch();
            }
            if(monsterArray[currentmapmonster[i]].hp<=0&&currentplayer->hp==0)
            {
                ClearEndLine();
                monsterArray[currentmapmonster[i]].sign=0;
                Position(Gap+5,Inform_y+8);
                printf("�ܲ��ң�ͬ���ھ�.......�����������........");
                getch();
            }
        break;
       }
    }
    ShowMonster();
}

//���ܶ�
void Move()
{
Y=currentplayer->department.coord.Y;
X=currentplayer->department.coord.X;
ShowMap();
}
//��ʾ�˵�
void ShowMenu()
{
    Position(Gap,Menu_y);
    printf("��Ϸ�˵�");
    Position(Gap,Menu_y+1);
    printf("1,��������");
    Position(Gap,Menu_y+2);
    printf("2,��̽");
    Position(Gap,Menu_y+3);
    printf("3,���ܲ�");
    Position(Gap,Menu_y+4);
    printf("4,����װ��");
    Position(Gap,Menu_y+5);
    printf("������ѡ����ķ��ƶ�(�����˳���Ϸ)��");
}
//������Ϸ����
void GameMain()
{
    char key;//�˵���ť
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
            printf("�������");*/
        }
    }
    return;
}
