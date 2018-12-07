#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <windows.h>
#include <stdio.h>
#include "Gamelib.h"
#define Length "-----------------------------------------------------------------------------"//��Ϸ����ĳ���78
#define Gap 20 //��Ϸ�ı߾�
#define Map_y 3//��ͼ����
#define Inform_y 12//��Ϣ������
#define Menu_y 21//�˵��ĳ���
typedef enum _proptype
{Weapon,Armor,Consumables}PropType;
//��ͼ
typedef struct _map
{
   int id;//��ͼ���
   char name[10];//��ͼ����
   int minlever;//��ҽ�����͵ȼ�
   char desc[500];//��ͼ��Ϣ
   COORD coord;//��ͼ����
}Map;
//����
typedef struct _prop
{
    int id;//���߱��
    char name[50];//��������
    int lever;//���ߵȼ�
    int price;//��Ǯ
    int stock;//���ߵĿ����
    PropType proptype;//��������
    union
    {
        int Attack;//�����Ĺ�����
        int Defence;//���ߵķ�����
        int Power;//����Ʒ������ֵ
    }U;
    char desc[500];
    int countt;//�����е��ߵ��ӵ�����

}Prop;
//����
typedef struct _martial
{
    int id;//���
    char name[10];//��������
    COORD coord;//����
}Martial;
//����
typedef struct _monster
{
    int id;//���
    char name[20];//����
    char maps[10];//���ڵ�ͼ
    int grade;//�ȼ�
    int hp;//Ѫ��
    int de;//������
    int power;//������
    //����Ķ���
    int maxgold;//�������Ľ��
    int mingold;//��С���
    int maxexp;//����������
    int minexp;//��С����
    COORD coord;
    int sign;//������־
}Monster;
typedef struct _bag
{
    int id;//��ұ��
    int countt;//������������
    int maxcount;//�������
    Prop props[4];
}Bag;
//���
typedef struct _player
{
   int id;//��ұ��
   char name[50];//�������
   char password[50];//����
   int lever;//��ҵȼ�
   int experience;//����
   int hp;//Ѫ��
   int mp;//����ֵ
   int maxmp;//��ǰ������������ֵ
   int gold;//���
   Martial department;//�������
   Bag bag;
  // Prop weapon;//��ҵ�����
   //Prop armor;//����
   //Prop consumables;//����Ʒ
   COORD coord;//�������
}Player;
//����
void trade(int a,int b);
//��ʾ��Ϸ��ͼ
void ShowMap();
//��ʾ��Ϸ��ӭ����
void ShowWelcom();
//��ʾ��Ϸ��Ϣ��
void ShowInformation();
//��ʾ�˵�
void ShowMenu();
//��ʾ��ͼ��Ϣ
void ShowMapInform();
//��ʾ������Ϣ
void ShowIndividual();
//�̵�
void Shop();
void Shopnext();
//���ܶ�
void Move();
//��ʾ����
void ShowMonster();
//�鿴����
void ScanMonster();
//ս��
void Fight(int key);
//������Ϸ�Ļ�ӭ����
void GameWelcom();
//��Ϸ��¼��ע�����
void GameRegister();
//��¼
void LoginGame();
//ע��
void RegisterGame();
//��ʼ����Ϸ����
int Init(char*p_name);
//������Ϸ����
void GameMain();
#endif // GAME_H_INCLUDED
