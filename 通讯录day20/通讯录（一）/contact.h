#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define PEO_MAX 1000

//�������Ա����䡢�绰��סַ
#define MAX_NAME 20
#define MAX_POSITION 30
typedef struct people
{
	char  name[MAX_NAME];
	char  sex[7];
	short age;
	char  tele[12];
	char  pos[MAX_POSITION];
}Peo;

void add_stru_peo(Peo* peo);//¼���������Ա����䡢�绰��סַ

void show_one_peo(Peo* peo);

void show_all_peo(Peo* peo);

//���Ҳ���ӡ��ƥ����ʵ�����
void show_find_one_peo(Peo* peo, char name[MAX_NAME], int* same_num);  //���ǵ���ϵ�˿���ͬ��������������˵ݹ�����ʾ����ͬ������ϵ��

Peo** all_same_name_peo(Peo* peo, char name[MAX_NAME]); //�ҵ���������ƥ�����ϵ��

void show_all_same_peo(Peo* all_same_name);  //��ӡ��������ƥ�����ϵ��

void delete_only_peo(Peo* peo, char* name);

void delete_delicate_peo(Peo* peo, char* name, char* pos);

void rewrite_menu();

void rewrite_only_peo(Peo* peo, char* name);

void delicate_rewrite_tru_peo(Peo* peo, char* name, char* pos);

int delete_all_peo(Peo* peo);

int compare_stru_name(const void* elem1, const void* elem2);

int save_all_peo(Peo* peo);

int load_contact(Peo* peo);

