#ifndef GAMELIB_H_INCLUDED
#define GAMELIB_H_INCLUDED
#include <stdio.h>
//���ÿ���̨���ڱ���
void ShowTitle(char*title);
//���ÿ���̨��ɫ
void ShowColour(int forecolour,int backcolour);
//���ù��λ��
void Position(int x,int y);
//��������--��Ϣ��
void Clear();
//��������������Ϣ�����һ��
void  ClearEndLine();
//��������---��Ϸ�������
void ClearGameWelcome();
#endif // GAMELIB_H_INCLUDED
