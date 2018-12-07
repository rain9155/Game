#include <stdio.h>
#include <windows.h>
#include "Gamelib.h"
#define Length "-----------------------------------------------------------------------------"//��Ϸ����ĳ���78
#define Gap 20 //��Ϸ�ı߾�
#define Map_y 3//��ͼ����
#define Inform_y 12//��Ϣ������
#define Menu_y 21//�˵��ĳ���

//���ÿ���̨���ڱ���
void ShowTitle(char*title)
{
   SetConsoleTitle(title);
}
//���ÿ���̨��ɫ
void ShowColour(int forecolour,int backcolour)
{
  HANDLE winhandle;
  winhandle=GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(winhandle,forecolour+backcolour*0x10);
}
//���ù��λ��
void Position(int x,int y)
{

  COORD pos={x,y};
  HANDLE winhandle;
  winhandle=GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleCursorPosition(winhandle,pos);
}
//��������������Ϣ��
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
//��������������Ϣ�����һ��
void  ClearEndLine()
{
    int i;
    Position(Gap+1,Inform_y+8);
    for(i=0;i<75;i++)
    {
        printf(" ");
    }
}
//��������---��Ϸ�������
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

