#ifndef GAMELIB_H_INCLUDED
#define GAMELIB_H_INCLUDED
#include <stdio.h>
//设置控制台窗口标题
void ShowTitle(char*title);
//设置控制台颜色
void ShowColour(int forecolour,int backcolour);
//设置光标位置
void Position(int x,int y);
//清屏函数--信息区
void Clear();
//清屏函数——信息区最后一行
void  ClearEndLine();
//清屏函数---游戏进入界面
void ClearGameWelcome();
#endif // GAMELIB_H_INCLUDED
