#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"



void menu()
{
	printf("*******************************\n");
	printf("*****     0.exit              *\n");
	printf("***** 1. �����ϵ����Ϣ       *\n");
	printf("***** 2. ɾ��ָ����ϵ����Ϣ   *\n");
	printf("***** 3. ����ָ����ϵ����Ϣ   *\n");
	printf("***** 4. �޸�ָ����ϵ����Ϣ   *\n");
	printf("***** 5. ��ʾ������ϵ����Ϣ   *\n");
	printf("***** 6. ���������ϵ��       *\n");
	printf("***** 7. ����������������ϵ�� *\n");
	printf("***** 8. ������ϵ�˵��ļ�     *\n");
	printf("***** 9. ������ϵ��           *\n");
	printf("*******************************\n");

}




int main()
{
	Peo peo[PEO_MAX] = { {0, 0, 0, 0, 0} };
	int input = 0;
	do
	{
		int same_num = 0;
		int delete_ret = 0;
		int save_ret = 0;
		int load_ret = 0;
		char  name[MAX_NAME];
		char  pos[MAX_POSITION];
		Peo* find = NULL;
		Peo** all_same_name = NULL;
		size_t num_stu = sizeof(peo) / sizeof(Peo);
		menu();
		(void)scanf("%d", &input);
		switch (input)
		{

		case 1:
			add_stru_peo(peo);
			break;

		case 2:
			printf("������Ҫɾ������ϵ�˵�����:>\n");
			(void)scanf("%s", name);

			all_same_name = all_same_name_peo(peo, name); //��������������ѯ����ϵ��ͬ������ϵ��
			show_find_one_peo(peo, name, &same_num);   //��������������ѯ����ϵ��ͬ������ϵ�˲���ӡ����ͬ����ϵ��

			if (same_num == 0) 
				printf("û���ҵ�����ƥ�����ϵ��\n");
			else if (same_num == 1) 
				delete_only_peo(peo, name);
			else
			{
				printf("ƥ�䵽%d��ͬ����ϵ�ˣ�������Ҫɾ������ϵ�˵ĵ�ַ:>\n", same_num);
				(void)scanf("%s", pos);
				delete_delicate_peo(peo, name, pos);
			}

			break;

		case 3:
			printf("������Ҫ��ѯ�ĵ���ϵ������");
			(void)scanf("%s", name);

			printf("��ӡ��������ƥ�����ϵ��\n");
			show_find_one_peo(peo, name, &same_num);   //��������������ѯ����ϵ��ͬ������ϵ�˲���ӡ����ͬ����ϵ��
			if (same_num == 0) printf("û���ҵ�����ƥ�����ϵ��\n");

			//all_same_name = all_same_name_peo(peo, name); //��������������ѯ����ϵ��ͬ������ϵ��
			//printf("��ӡ��������ƥ�����ϵ��\n");
			//show_all_same_peo(*all_same_name);        //��ӡ����ƥ�����ϵ�ˣ�������������ƥ���ͬ����ϵ��
			break;

		case 4:
			printf("������Ҫ��ѯ�ĵ���ϵ������");
			(void)scanf("%s", name);

			printf("��ӡ��������ƥ�����ϵ��\n");
			show_find_one_peo(peo, name, &same_num);   //��������������ѯ����ϵ��ͬ������ϵ�˲���ӡ����ͬ����ϵ��

			if (same_num == 0) 
				printf("û���ҵ�����ƥ�����ϵ��\n");
			else if (same_num == 1)
			{
				printf("ƥ�䵽һ����ϵ��\n");
				rewrite_only_peo(peo, name);
			}
			else
			{
				printf("ƥ�䵽%d��ͬ����ϵ��,�밴��ʾ������Ҫ�޸ĵ���ϵ�˵ĵ�ַ���о�ȷƥ��\n", same_num);
				(void)scanf("%s", pos);
				delicate_rewrite_tru_peo(peo, name, pos);
			}
			break;

		case 5:
			show_all_peo(peo);
			break;

		case 6:
			delete_ret = delete_all_peo(peo);
			if (delete_ret)
				printf("������ϵ��ɾ���ɹ�\n");
			else
				printf("������ϵ��ɾ��ʧ��\n");
			break;

		case 7:
			qsort((void*)peo, num_stu, sizeof(Peo), compare_stru_name);
			break;

		case 8:
			save_ret = save_all_peo(peo);
			if (save_ret)
				printf("������ϵ���ѳɹ����浽�ļ�\n");
			else
				printf("������ϵ�˱��浽�ļ�ʧ��\n");
			break;

		case 9:
			load_ret = load_contact(peo);
			if (save_ret)
				printf("������ϵ���ѳɹ����ص��ļ�\n");
			else
				printf("������ϵ�˼��ص��ļ�ʧ��\n");
			break;
		default:
			break;
		}

	} while (input);


	return 0;
}

//2.ʵ��һ��ͨѶ¼��
//ͨѶ¼���������洢1000���˵���Ϣ��ÿ���˵���Ϣ������
//�������Ա����䡢�绰��סַ
//
//�ṩ������
//1. �����ϵ����Ϣ
//2. ɾ��ָ����ϵ����Ϣ
//3. ����ָ����ϵ����Ϣ
//4. �޸�ָ����ϵ����Ϣ
//5. ��ʾ������ϵ����Ϣ
//6. ���������ϵ��
//7. ����������������ϵ��
//8. ������ϵ�˵��ļ�
//9. ������ϵ��
