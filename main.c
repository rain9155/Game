#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Gamelib.h"
#include "Game.h"
extern X,Y;
int main()
{
    ShowTitle("笑傲江湖之精忠报国");
    ShowColour(10,0);
    GameWelcom();//进入游戏的欢迎界面
    ClearGameWelcome();//清屏
    GameRegister();//游戏的登录与注册界面
    GameMain();//进入游戏
    return 0;
}
