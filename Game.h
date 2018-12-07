#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <windows.h>
#include <stdio.h>
#include "Gamelib.h"
#define Length "-----------------------------------------------------------------------------"//游戏界面的长度78
#define Gap 20 //游戏的边距
#define Map_y 3//地图长度
#define Inform_y 12//信息区长度
#define Menu_y 21//菜单的长度
typedef enum _proptype
{Weapon,Armor,Consumables}PropType;
//地图
typedef struct _map
{
   int id;//地图编号
   char name[10];//地图名称
   int minlever;//玩家进入最低等级
   char desc[500];//地图信息
   COORD coord;//地图坐标
}Map;
//道具
typedef struct _prop
{
    int id;//道具编号
    char name[50];//道具名称
    int lever;//道具等级
    int price;//价钱
    int stock;//道具的库存量
    PropType proptype;//道具类型
    union
    {
        int Attack;//武器的攻击力
        int Defence;//防具的防御力
        int Power;//消耗品的能量值
    }U;
    char desc[500];
    int countt;//背包中道具叠加的数量

}Prop;
//门派
typedef struct _martial
{
    int id;//编号
    char name[10];//门派名字
    COORD coord;//坐标
}Martial;
//怪物
typedef struct _monster
{
    int id;//编号
    char name[20];//名称
    char maps[10];//所在地图
    int grade;//等级
    int hp;//血量
    int de;//防御力
    int power;//攻击力
    //掉落的东西
    int maxgold;//掉落最大的金币
    int mingold;//最小金币
    int maxexp;//掉落的最大经验
    int minexp;//最小经验
    COORD coord;
    int sign;//死亡标志
}Monster;
typedef struct _bag
{
    int id;//玩家编号
    int countt;//道具种类数量
    int maxcount;//最大插槽数
    Prop props[4];
}Bag;
//玩家
typedef struct _player
{
   int id;//玩家编号
   char name[50];//玩家名称
   char password[50];//密码
   int lever;//玩家等级
   int experience;//经验
   int hp;//血量
   int mp;//内力值
   int maxmp;//当前级别的最大内力值
   int gold;//金币
   Martial department;//玩家门派
   Bag bag;
  // Prop weapon;//玩家的武器
   //Prop armor;//防具
   //Prop consumables;//消耗品
   COORD coord;//玩家坐标
}Player;
//交易
void trade(int a,int b);
//显示游戏地图
void ShowMap();
//显示游戏欢迎界面
void ShowWelcom();
//显示游戏信息区
void ShowInformation();
//显示菜单
void ShowMenu();
//显示地图信息
void ShowMapInform();
//显示个人信息
void ShowIndividual();
//商店
void Shop();
void Shopnext();
//回总舵
void Move();
//显示怪物
void ShowMonster();
//查看怪物
void ScanMonster();
//战斗
void Fight(int key);
//进入游戏的欢迎界面
void GameWelcom();
//游戏登录与注册界面
void GameRegister();
//登录
void LoginGame();
//注册
void RegisterGame();
//初始化游戏数据
int Init(char*p_name);
//进入游戏界面
void GameMain();
#endif // GAME_H_INCLUDED
