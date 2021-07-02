#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"


void add_stru_peo(Peo* peo) //¼���������Ա����䡢�绰��סַ
{
	if (peo->age)
		while (peo->age)  peo++;

	printf("������ ����:>");
	(void)scanf("%s", (peo->name));
	printf("������ �Ա�:>");
	(void)scanf("%s", (peo->sex));
	printf("������ ����:>");
	(void)scanf("%hu", &(peo->age));
	printf("������ �绰:>");
	(void)scanf("%s", (peo->tele));
	printf("������ סַ:>");
	(void)scanf("%s", (peo->pos));

	if (peo->age)
		printf("����ϵ����ӳɹ�\n");
	else
		printf("����ϵ�����ʧ��\n");
}



void show_one_peo(Peo* peo)
{
	printf("%s\t", peo->name);
	printf("%s\t", peo->sex);
	printf("%hu\t", peo->age);
	printf("%s\t", peo->tele);
	printf("%s\n", peo->pos);
}

void show_all_peo(Peo* peo)
{
	if (peo->age)
	{
		printf("����\t�Ա�\t����\t�绰\tסַ\n\n");
		while (peo->age)
		{
			show_one_peo(peo);
			peo++;
		}
	}
	else
		printf("û���κ���ϵ����Ϣ\n");
}

//���Ҳ���ӡ��ƥ����ʵ�����
void show_find_one_peo(Peo* peo, char name[MAX_NAME], int* same_num)  //���ǵ���ϵ�˿���ͬ��������������˵ݹ�����ʾ����ͬ������ϵ��
{
	Peo* first = peo - 1;
	while (*(peo->name) && strcmp(peo->name, name)) peo++;
	if (*(peo->name) && peo > first && (peo - first) < PEO_MAX - 1)
	{
		if (*same_num == 0)
			printf("����\t�Ա�\t����\t�绰\tסַ\n\n");
		show_one_peo(peo);	(*same_num)++;      //same_num���ڴ���ͬ����ϵ�˸���
		show_find_one_peo(peo + 1, name, same_num);
	}
}

Peo** all_same_name_peo(Peo* peo, char name[MAX_NAME])   //�ҵ���������ƥ�����ϵ��
{
	Peo* first = peo - 1;
	static Peo* find_same_name[10] = { 0, 0, 0, 0, 0 };  //���ڶ��ϣ����ڴ���ҵ�������ͬ����ϵ�˵ĵ�ַ

	int i = 0;
	while ((peo - first) && (peo - first) < PEO_MAX - 1)
	{
		first = peo;
		while (*(peo->name) && strcmp(peo->name, name))
			peo++;
		if (!(peo - first))
		{
			find_same_name[i] = peo;
			i++;
		}
	}
	return find_same_name;
}


void show_all_same_peo(Peo* all_same_name)  //��ӡ��������ƥ�����ϵ��
{
	if (all_same_name->age)
	{
		printf("����\t�Ա�\t����\t�绰\tסַ\n\n");
		while (all_same_name->age)
		{
			show_one_peo(all_same_name);
			all_same_name++;
		}
	}
	else
		printf("û���ҵ�����ƥ�����ϵ��\n");
}

void delete_only_peo(Peo* peo, char* name)
{
	Peo tmp = { 0, 0, 0, 0, 0 };
	int flag = 0;
	while (*((peo + 1)->name) && strcmp(peo->name, name))  //�ҵ�����ƥ�����ϵ�˲��Ҳ������һ����ѭ���պ�����
		peo++;
	while (*((peo + 1)->name))    //���������һ����ϵ�˵�ʱ�����ǰ����
	{
		peo->age = (peo + 1)->age;
		strcpy(peo->name, (peo + 1)->name);
		strcpy(peo->pos, (peo + 1)->pos);
		strcpy(peo->sex, (peo + 1)->sex);
		strcpy(peo->tele, (peo + 1)->tele);
		flag++;
		peo++;
	}

	if (strcmp(peo->name, name) == 0 || flag)  //�����һ����ϵ�˵�ʱ��ֱ��ɾ��
	{
		peo->age = tmp.age;
		strcpy(peo->name, tmp.name);
		strcpy(peo->pos, tmp.pos);
		strcpy(peo->sex, tmp.sex);
		strcpy(peo->tele, tmp.tele);
		flag++;
		printf("ɾ���ɹ����ѳɹ�ɾ����ϵ��\n");
	}
	if (!flag)
		printf("ɾ��ʧ�ܣ�û�ҵ�ƥ�����ϵ��\n");


}

void delete_delicate_peo(Peo* peo, char* name, char* pos)
{
	Peo tmp = { 0, 0, 0, 0, 0 };
	int flag = 0;
	while (*((peo + 1)->name) && !(strcmp(peo->name, name) == 0 && strcmp(peo->pos, pos) == 0))  //�ҵ����ֺ͵�ַ��ƥ�����ϵ�˲��Ҳ������һ����ѭ���պ�����
		peo++;
	while (*((peo + 1)->name))    //���������һ����ϵ�˵�ʱ�����ǰ����
	{
		peo->age = (peo + 1)->age;
		strcpy(peo->name, (peo + 1)->name);
		strcpy(peo->pos, (peo + 1)->pos);
		strcpy(peo->sex, (peo + 1)->sex);
		strcpy(peo->tele, (peo + 1)->tele);
		flag++;
		peo++;
	}

	if (strcmp(peo->name, name) == 0 && strcmp(peo->pos, pos) == 0 || flag)  //�����һ����ϵ�˵�ʱ��ֱ��ɾ��
	{
		peo->age = tmp.age;
		strcpy(peo->name, tmp.name);
		strcpy(peo->pos, tmp.pos);
		strcpy(peo->sex, tmp.sex);
		strcpy(peo->tele, tmp.tele);
		flag++;
		printf("ɾ���ɹ����ѳɹ�ɾ����ϵ��\n");
	}
	if (!flag)
		printf("ɾ��ʧ�ܣ�û�ҵ�ƥ�����ϵ��\n");
}








void rewrite_menu()
{
	printf("********************\n");
	printf("***0.�޸����  *****\n");
	printf("***1������2�Ա�*****\n");
	printf("***3���䡢4�绰*****\n");
	printf("***    5סַ  ******\n");
	printf("********************\n");
}

void rewrite_only_peo(Peo* peo, char* name)
{
	Peo tmp = { 0, 0, 0, 0, 0 };
	int flag = 0;
	int input = 0;
	while (*(peo->name) && strcmp(peo->name, name))  //�ҵ�����ƥ�����ϵ��ѭ���պ������������Ҳ�������
		peo++;

	if (strcmp(peo->name, name) == 0)
	{
		printf("��ȷƥ��ɹ�\n");
		do
		{
			rewrite_menu();
			printf("��ѡ����Ҫִ�еĲ���\n");
			(void)scanf("%d", &input);
			switch (input)
			{
			case 1:
				printf("����������:> ");
				(void)scanf("%s", tmp.name);
				strcpy(peo->name, tmp.name);
				flag++;
				break;
			case 2:
				printf("�������Ա�:> ");
				(void)scanf("%s", tmp.sex);
				strcpy(peo->sex, tmp.sex);
				flag++;
				break;
			case 3:
				printf("����������:> ");
				(void)scanf("%hu", &tmp.age);
				peo->age = tmp.age;
				flag++;
				break;
			case 4:
				printf("������绰:> ");
				(void)scanf("%s", tmp.tele);
				strcpy(peo->tele, tmp.tele);
				flag++;
				break;
			case 5:
				printf("�������ַ:> ");
				(void)scanf("%s", tmp.pos);
				strcpy(peo->pos, tmp.pos);
				flag++;
				break;
			default:
				printf("�������,����������\n");
				break;
			}
		} while (input);
	}


	if (flag)
		printf("�޸ĳɹ����ѳɹ��޸���ϵ��\n");
	if (!flag)
		printf("�޸�ʧ�ܣ�û�ҵ�ƥ�����ϵ��\n");
}

void delicate_rewrite_tru_peo(Peo* peo, char* name, char* pos)
{
	Peo tmp = { 0, 0, 0, 0, 0 };
	int flag = 0;
	int input = 0;
	while (*(peo->name) && !(strcmp(peo->name, name) == 0 && strcmp(peo->pos, pos) == 0))  //�ҵ�����ƥ�����ϵ��ѭ���պ������������Ҳ�������
		peo++;

	if (strcmp(peo->name, name) == 0)
	{
		printf("��ȷƥ��ɹ�\n");
		do
		{
			rewrite_menu();
			printf("��ѡ����Ҫִ�еĲ���\n");
			(void)scanf("%d", &input);
			switch (input)
			{
			case 1:
				printf("����������:> ");
				(void)scanf("%s", tmp.name);
				strcpy(peo->name, tmp.name);
				flag++;
				break;
			case 2:
				printf("�������Ա�:> ");
				(void)scanf("%s", tmp.sex);
				strcpy(peo->sex, tmp.sex);
				flag++;
				break;
			case 3:
				printf("����������:> ");
				(void)scanf("%hu", &tmp.age);
				peo->age = tmp.age;
				flag++;
				break;
			case 4:
				printf("������绰:> ");
				(void)scanf("%s", tmp.tele);
				strcpy(peo->tele, tmp.tele);
				flag++;
				break;
			case 5:
				printf("�������ַ:> ");
				(void)scanf("%s", tmp.pos);
				strcpy(peo->pos, tmp.pos);
				flag++;
				break;
			default:
				printf("�������,����������\n");
				break;
			}
		} while (input);
	}


	if (flag)
		printf("�޸ĳɹ����ѳɹ��޸���ϵ��\n");
	if (!flag)
		printf("�޸�ʧ�ܣ�û�ҵ�ƥ�����ϵ��\n");
}

int delete_all_peo(Peo* peo)
{
	Peo* first = peo;
	Peo tmp = { 0, 0, 0, 0, 0 };
	while (*(peo->name))
	{
		peo->age = tmp.age;
		strcpy(peo->name, tmp.name);
		strcpy(peo->pos, tmp.pos);
		strcpy(peo->sex, tmp.sex);
		strcpy(peo->tele, tmp.tele);
		peo++;
	}
	if (!*(first->name))
		return 1;
	else
		return 0;
}


int compare_stru_name(const void* elem1, const void* elem2)
{
	return strcmp(((Peo*)elem1)->name, ((Peo*)elem2)->name);

}



int save_all_peo(Peo* peo)
{
	int i = 0;
	FILE* pf = fopen("contact.txt", "w");
	if (pf == NULL)
	{
		printf("�����ļ�ʧ��\n");
		return -1;
	}
	while (peo->age)
	{
		fwrite(peo + i, sizeof(struct people), 1, pf);
		peo++;
		i++;
	}
	return 1;
	fclose(pf);
	pf = NULL;
}



int load_contact(Peo* peo)
{
	int i = 0;
	FILE* pf = fopen("contact.txt", "r");
	if (pf == NULL)
	{
		printf("�����ļ�ʧ��\n");
		return -1;
	}
	else
	{
	while (fread(peo + i, sizeof(struct people), 1, pf))
		return 1;
	}
	fclose(pf);
	pf = NULL;

}
