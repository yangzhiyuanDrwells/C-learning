#include "game.h"
#define _CRT_SECURE_NO_WARNINGS 1

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)  //����׵���Ϣ���ַ�����ȫ����ʼ��Ϊ�ַ�'0'����ʾû����
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = '0';
		}
	}

}

void DisplayBoard(char board[ROWS][COLS], int rows, int cols)//��Ϸʧ��ʱ��ӡ�׵Ĳ���
{
	int i = 0;
	int j = 0;
	printf("\n");
	for (i = 0; i < cols - 1; i++)
		printf("%2d", i);
	printf("\n");
	for (i = 1; i < rows - 1; i++)
	{
		printf("%2d ", i);
		for (j = 1; j < cols - 1; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char board[ROWS][COLS], int rows, int cols, char set) //��������׵Ĳ��֣�EASY_COUNT��ʾ�׵�����
{
	int count = 0;
	int x = 0;
	int y = 0;
	while (count < EASY_COUNT)
	{
		do
		{
			x = rand() % (rows - 2) + 1;
			y = rand() % (cols - 2) + 1;
		} while (board[x][y] != '0');
		board[x][y] = set;
		count++;
	}
}

static int CountMine(char board[ROWS][COLS], int x, int y) //������ǰ�û�����������Χ8�������е��׵��ܸ���
{
	return
		board[x - 1][y - 1] +
		board[x - 1][y] +
		board[x - 1][y + 1] +
		board[x][y - 1] +
		board[x][y + 1] +
		board[x + 1][y - 1] +
		board[x + 1][y] +
		board[x + 1][y + 1] -
		8 * '0';
}
//
//static void RecursionSpread(char board[ROWS][COLS], char show[ROW][COL], int x, int y) //�Եݹ�ķ�ʽչ��
//{
//	if (board[x][y] != '1' && show[x - 1][y - 1] == '*' && (CountMine(board, x, y) + '0') <= 2)
//	{
//		show[x - 1][y - 1] = CountMine(board, x, y) + '0';
//		RecursionSpread(board, show, x, y);
//	}
//	if (board[x - 1][y - 1] != '1' && show[x - 1 - 1][y - 1 - 1] == '*' && (CountMine(board, x, y) + '0') <= 2)
//	{
//		show[x - 1 - 1][y - 1 - 1] = CountMine(board, x - 1, y - 1) + '0';
//		RecursionSpread(board, show, x - 1, y - 1);
//	}
//	if (board[x - 1][y] != '1' && show[x - 2][y - 1] == '*' && (CountMine(board, x, y) + '0') <= 2)
//	{
//		show[x - 2][y - 1] = CountMine(board, x - 1, y) + '0';
//		RecursionSpread(board, show, x - 1, y);
//	}
//	if (board[x - 1][y + 1] != '1' && show[x - 2][y] == '*' && (CountMine(board, x, y) + '0') <= 2)
//	{
//		show[x - 2][y] = CountMine(board, x - 1, y + 1) + '0';
//		RecursionSpread(board, show, x - 1, y + 1);
//	}
//	if (board[x][y - 1] != '1' && show[x - 1][y - 2] == '*' && (CountMine(board, x, y) + '0') <= 2)
//	{
//		show[x - 1][y - 2] = CountMine(board, x, y - 1) + '0';
//		RecursionSpread(board, show, x, y - 1);
//	}
//	if (board[x][y + 1] != '1' && show[x - 1][y] == '*' && (CountMine(board, x, y) + '0') <= 2)
//	{
//		show[x - 1][y] = CountMine(board, x, y + 1) + '0';
//		RecursionSpread(board, show, x, y + 1);
//	}
//	if (board[x + 1][y - 1] != '1' && show[x][y - 2] == '*' && (CountMine(board, x, y) + '0') <= 2)
//	{
//		show[x][y - 2] = CountMine(board, x + 1, y - 1) + '0';
//		RecursionSpread(board, show, x + 1, y - 1);
//	}
//	if (board[x + 1][y] != '1' && show[x][y - 1] == '*' && (CountMine(board, x, y) + '0') <= 2)
//	{
//		show[x][y - 1] = CountMine(board, x + 1, y) + '0';
//		RecursionSpread(board, show, x + 1, y);
//	}
//	if (board[x + 1][y + 1] != '1' && show[x][y] == '*' && (CountMine(board, x, y) + '0') <= 2)
//	{
//		show[x][y] = CountMine(board, x + 1, y + 1) + '0';
//		RecursionSpread(board, show, x + 1, y + 1);
//	}
//
//}

static void RecursionSpread(char board[ROWS][COLS], char show[ROWS][COLS], int x, int y) //�Եݹ�ķ�ʽչ��
{
	if ((x >= 0) && (x <= ROW) && (y >= 0) && (y <= COL))
	{
		if (CountMine(board, x, y) == 0)
		{
			show[x][y] = ' ';
			if (show[x - 1][y - 1] == '*')
			{
				RecursionSpread(board, show, x - 1, y - 1);
			}
			if (show[x - 1][y] == '*')
			{
				RecursionSpread(board, show, x - 1, y);
			}
			if (show[x - 1][y + 1] == '*')
			{
				RecursionSpread(board, show, x - 1, y + 1);
			}
			if (show[x][y - 1] == '*')
			{
				RecursionSpread(board, show, x, y - 1);
			}
			if (show[x][y + 1] == '*')
			{
				RecursionSpread(board, show, x, y + 1);
			}
			if (show[x + 1][y - 1] == '*')
			{
				RecursionSpread(board, show, x + 1, y - 1);
			}
			if (show[x + 1][y] == '*')
			{
				RecursionSpread(board, show, x + 1, y);
			}
			if (show[x + 1][y + 1] == '*')
			{
				RecursionSpread(board, show, x + 1, y + 1);
			}
			
		}
		else
		{
			show[x][y] = CountMine(board, x, y)+ '0';
		}
	}
}

int FindMine(char board[ROWS][COLS], char show[ROWS][COLS], int x, int y)  //�ж��û���������������ǲ������ף������򷵻�0��Ϸ������û������չ������ӡÿ��������Χ���׵ĸ���
{
	if (show[x][y] != '*')
		printf("�����괦���Ų��\n");
	else
	{
		if (board[x][y] == '1')
		{
			printf("��Ϸ����������ը����\n");
			return 0;
		}
		else
		{
			//show[x - 1][y - 1] = CountMine(board, x, y) + '0';
			RecursionSpread(board, show, x, y); //�ݹ�չ��

		}
	}
	return 1;
}