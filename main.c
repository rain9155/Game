#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Gamelib.h"
#include "Game.h"
extern X,Y;
int main()
{
    ShowTitle("Ц������֮���ұ���");
    ShowColour(10,0);
    GameWelcom();//������Ϸ�Ļ�ӭ����
    ClearGameWelcome();//����
    GameRegister();//��Ϸ�ĵ�¼��ע�����
    GameMain();//������Ϸ
    return 0;
}
