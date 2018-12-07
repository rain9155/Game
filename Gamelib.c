#include <stdio.h>
#include <windows.h>
#include "Gamelib.h"
#define Length "-----------------------------------------------------------------------------"//游戏界面的长度78
#define Gap 20 //游戏的边距
#define Map_y 3//地图长度
#define Inform_y 12//信息区长度
#define Menu_y 21//菜单的长度

//设置控制台窗口标题
void ShowTitle(char*title)
{
   SetConsoleTitle(title);
}
//设置控制台颜色
void ShowColour(int forecolour,int backcolour)
{
  HANDLE winhandle;
  winhandle=GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(winhandle,forecolour+backcolour*0x10);
}
//设置光标位置
void Position(int x,int y)
{

  COORD pos={x,y};
  HANDLE winhandle;
  winhandle=GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleCursorPosition(winhandle,pos);
}
//清屏函数——信息区
void Clear()
{
   Position(Gap+1,Inform_y);
   int i,j;
   for(i=0;i<8;i++)
   {
        Position(Gap+1,Inform_y+i);
       for(j=0;j<75;j++)
       {
           printf(" ");
       }
       printf("|");
   }
}
//清屏函数——信息区最后一行
void  ClearEndLine()
{
    int i;
    Position(Gap+1,Inform_y+8);
    for(i=0;i<75;i++)
    {
        printf(" ");
    }
}
//清屏函数---游戏进入界面
void ClearGameWelcome()
{
    int i,j;
    for(i=0;i<17;i++)
    {
        Position(Gap,i);
        for(j=0;j<78;j++)
            printf(" ");
    }
}

