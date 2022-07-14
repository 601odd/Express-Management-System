#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

#define KEY_RETURN 2
#define KEY_NEXT 4

#define SPACE_OUT 0
#define WALL 1
#define SPACE 2
#define TARGET 3
#define BOX 4
#define TARGET_IN 5
#define PERSON 6

/*��������*/
void SelectColor(int iColor);
void DesignUI();
int WelcomePage(); /*��ʼ���棬ÿ��ͨ�غ�����*/
void GetLevel1();
void GetLevel2();
void GetLevel3();
void GetLevel4();
int PlayGame(int aiMap[][16], int aiMap2[][16], int iSum, int iImp);
int PrintMap(int aiMap[][16], int iImp);
void MoveBox(int aiMap[][16], int iPlayerX, int iPlayerY, int iSelect, int aiMap2[][16]);

/*������*/
int main()
{
	while (1)
		DesignUI();
}

/*������ɫ����*/
void SelectColor(int iColor) //��ɫ����
{
	HANDLE hConsole =
		GetStdHandle((STD_OUTPUT_HANDLE));	   //�õ�����̨����豸�ľ��
	SetConsoleTextAttribute(hConsole, iColor); //���ÿ���̨�豸������
}

/*�����溯��*/
void DesignUI()
{
	int iCh;
	char cNum;
	iCh = WelcomePage();
	if (iCh == 49) /*��������1����ʼ��һ����Ϸ*/
		GetLevel1();
	else if (iCh == 50)
	{ /*��������2��ѡ��1��4�ص���Ϸ*/
		printf("\n\t\t ����������Ҫ��Ĺؿ�!(�� 1 �� 4):");
		getchar();
		cNum = getchar();
		switch (cNum)
		{
		case '1':
			GetLevel1();
			break;
		case '2':
			GetLevel2();
			break;
		case '3':
			GetLevel3();
			break;
		case '4':
			GetLevel4();
			break;
		default:
			printf("�������!\n");
			Sleep(1000);
			exit(0);
			break;
		}
	}
	else if (iCh == 51)
	{ /*��������3���˳���Ϸ*/
		system("cls");
		exit(0);
	}
}

/*��ʼ��ӭ����*/
int WelcomePage()
{
	int i = 0;
	system("cls");		/*����*/
	system("color 0E"); /*������ɫ*/
	printf("\n\n\t\t ��ӭ������������Ϸ!\n\n");
	printf("\t\t ����:��  �߽�:�� ����: ��  Ŀ��:��  ���Ŀ�꣺��\n");
	printf("\t\t ����:��\n\t\t ����:��\n\t\t ����:�� \n\t\t ����:��\n\n");
	printf("\t\t ��1��ʼ����Ϸ\n\t\t\n");
	printf("\t\t ��2��ʼѡ��ؿ�\n\t\t\n");
	printf("\t\t ��3�˳���Ϸ\n\t\t\n");
	printf("\t\t ��������������:");
	while (1)
	{
		i = getchar();
		if (i >= 49 && i <= 51)
			return i;
	}
}

/*��ӡ��ͼ����*/
int PrintMap(int aiMap[][16], int iImp)
{ /*����iImp������Ϸ�ؿ�*/
	int i, j;
	int iCount = 0;
	for (i = 0; i < 14; i++)
	{
		for (j = 0; j < 16; j++)
		{
			switch (aiMap[i][j])
			{
			case 0: /*�յ�*/
				printf("  ");
				break;
			case 1:
				SelectColor(14); /*ǽ*/
				printf("��");
				break;
			case 2: /*�ڲ��յ�*/
				printf("  ");
				break;
			case 3:
				SelectColor(11); /*Ŀ�ĵ�*/
				printf("��");
				break;
			case 4: /*����*/
				SelectColor(11);
				printf("��");
				break;
			case 5: /*�����Ƶ�Ŀ�ĵغ���ʾ*/
				iCount++;
				SelectColor(9);
				printf("��");
				break;
			case 6: /*С��*/
				SelectColor(10);
				printf("��");
				break;
			}
		}
		printf("\n");
	}
	SelectColor(14);
	printf("\n");
	printf("\t���ڵ� %d��!\t\t\n", iImp);
	printf("\t�����ⷽ�����ʼ��Ϸ!\t\n");
	printf("\t��N�������ؿ�ֱ�ӽ�����һ��!\t\n");
	printf("\t��Q������ҳ!\t\n");
	return iCount; /*����ֵ��ʾ����ȷ�����������*/
}

/*��һ��*/
void GetLevel1()
{
	int aiMap2[14][16]; /*��ʾԭʼ��ͼ*/
	int i, j, iSum = 0; /*iSum��ʾ���ӵ�����*/

	/*��ͼ��״
	1����ǽ��2����յأ�3����δ�����ӵ�Ŀ�꣬4�������ӣ�5�����Է����ӵ�Ŀ�꣬6����С��
	*/
	int aiMap[14][16] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 1, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 3, 4, 2, 1, 1, 2, 1, 1, 0, 0, 0},
		{0, 0, 0, 1, 2, 3, 4, 6, 4, 2, 2, 3, 1, 0, 0, 0},
		{0, 0, 0, 1, 2, 3, 2, 4, 2, 4, 3, 1, 1, 0, 0, 0},
		{0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	};
	for (i = 0; i < 14; i++)
		for (j = 0; j < 16; j++)
		{
			aiMap2[i][j] = aiMap[i][j];
			if (aiMap[i][j] == TARGET || aiMap[i][j] == TARGET_IN) /*��¼���Ӹ���*/
				iSum++;
		}

	/*PlayGame��������ֵΪ4����������������Q���ص������棬
	������������أ�������һ�أ�ִ��GetLevel2����������ڶ���
	*/
	if (PlayGame(aiMap, aiMap2, iSum, 1) != KEY_RETURN)
		GetLevel2();
}

/*�ڶ���*/
void GetLevel2()
{
	int aiMap2[14][16]; /*��ʾԭʼ��ͼ*/
	int i, j, iSum = 0; /*iSum��ʾ���ӵ�����*/

	/*��ͼ��״
	1����ǽ��2����յأ�3����δ�����ӵ�Ŀ�꣬4�������ӣ�5�����Է����ӵ�Ŀ�꣬6����С��
	*/
	int aiMap[14][16] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
		{0, 0, 0, 1, 2, 2, 1, 1, 2, 2, 2, 1, 0, 0, 0, 0},
		{0, 0, 0, 1, 2, 2, 2, 4, 2, 2, 2, 1, 0, 0, 0, 0},
		{0, 0, 0, 1, 2, 2, 1, 1, 1, 2, 4, 1, 0, 0, 0, 0},
		{0, 0, 0, 1, 2, 1, 3, 3, 3, 1, 2, 1, 0, 0, 0, 0},
		{0, 0, 1, 1, 2, 1, 3, 3, 1, 1, 2, 1, 1, 0, 0, 0},
		{0, 0, 1, 2, 4, 2, 2, 4, 2, 2, 4, 2, 1, 0, 0, 0},
		{0, 0, 1, 2, 2, 2, 2, 2, 2, 2, 6, 2, 1, 0, 0, 0},
		{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	};

	for (i = 0; i < 14; i++)
		for (j = 0; j < 16; j++)
		{
			aiMap2[i][j] = aiMap[i][j];
			if (aiMap[i][j] == TARGET || aiMap[i][j] == TARGET_IN) /*��¼���Ӹ���*/
				iSum++;
		}

	/*PlayGame��������ֵΪ4����������������Q���ص������棬
	������������أ�������һ�أ�ִ��GetLevel3���������������
	*/
	if (PlayGame(aiMap, aiMap2, iSum, 2) != KEY_RETURN)
		GetLevel3();
}

/*������*/
void GetLevel3()
{
	int aiMap2[14][16]; /*��ʾԭʼ��ͼ*/
	int i, j, iSum = 0; /*iSum��ʾ���ӵ�����*/

	/*��ͼ��״
	1����ǽ��2����յأ�3����δ�����ӵ�Ŀ�꣬4�������ӣ�5�����Է����ӵ�Ŀ�꣬6����С��
	*/
	int aiMap[14][16] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0},
		{0, 0, 1, 1, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 0, 0},
		{0, 0, 1, 2, 4, 2, 1, 1, 1, 1, 4, 2, 2, 1, 0, 0},
		{0, 0, 1, 2, 2, 4, 3, 3, 3, 3, 2, 4, 2, 1, 0, 0},
		{0, 0, 1, 1, 2, 2, 2, 2, 1, 2, 6, 2, 1, 1, 0, 0},
		{0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	};

	for (i = 0; i < 14; i++)
		for (j = 0; j < 16; j++)
		{
			aiMap2[i][j] = aiMap[i][j];
			if (aiMap[i][j] == TARGET || aiMap[i][j] == TARGET_IN) /*��¼���Ӹ���*/
				iSum++;
		}

	/*PlayGame��������ֵΪ4����������������Q���ص������棬
	������������أ�������һ�أ�ִ��GetLevel5��������������
	*/
	if (PlayGame(aiMap, aiMap2, iSum, 3) != KEY_RETURN)
		GetLevel4();
}

/*���Ĺ�*/
void GetLevel4()
{
	int aiMap2[14][16]; /*��ʾԭʼ��ͼ*/
	int i, j, iSum = 0; /*iSum��ʾ���ӵ�����*/

	/*��ͼ��״
	1����ǽ��2����յأ�3����δ�����ӵ�Ŀ�꣬4�������ӣ�5�����Է����ӵ�Ŀ�꣬6����С��
	*/
	int aiMap[14][16] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 1, 2, 2, 2, 1, 3, 2, 1, 0, 0, 0},
		{0, 0, 0, 0, 1, 1, 2, 2, 4, 3, 3, 3, 1, 0, 0, 0},
		{0, 0, 0, 0, 1, 2, 2, 4, 2, 1, 5, 3, 1, 0, 0, 0},
		{0, 0, 0, 1, 1, 2, 1, 1, 4, 1, 2, 1, 1, 0, 0, 0},
		{0, 0, 0, 1, 2, 2, 2, 4, 2, 2, 4, 2, 1, 0, 0, 0},
		{0, 0, 0, 1, 2, 2, 2, 1, 2, 2, 2, 2, 1, 0, 0, 0},
		{0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 6, 2, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	};
	for (i = 0; i < 14; i++)
		for (j = 0; j < 16; j++)
		{
			aiMap2[i][j] = aiMap[i][j];
			if (aiMap[i][j] == TARGET || aiMap[i][j] == TARGET_IN) /*��¼���Ӹ���*/
				iSum++;
		}
	/*PlayGame��������ֵΪ4����������������Q���ص������棬
	������������أ�������һ�أ�ִ��GetLevel7������������߹�
	*/
	PlayGame(aiMap, aiMap2, iSum, 4);
}

/*��Ϸ��������*/
int PlayGame(int aiMap[][16], int aiMap2[][16], int iSum, int iImp) /*iSum�������Ӹ���*/
{
	int i, j;
	int iPlayerX, iPlayerY; /*�˵�λ��x,y����*/
	char cOp;				/*�����µķ����*/
	int iNum = 0;			/*�����Ƶ�Ŀ�ĵصĸ���*/

	while (1)
	{
		for (i = 0; i < 14; i++)
		{
			for (j = 0; j < 16; j++) /*ѭ������Ѱ���˵�λ��*/
			{
				if (aiMap[i][j] == PERSON) /*6�����˵�λ��*/
					break;
			}
			if (j < 16)
				break;
		}

		iPlayerX = i; /*����ά�����е��˵�x,y���긳ֵ��iPlayerX��iPlayerY*/
		iPlayerY = j;
		system("cls");
		iNum = PrintMap(aiMap, iImp);
		if (iNum == iSum)
		{ /*���������Ӷ��Ƶ�Ŀ�ĵ�*/
			printf(" ��ϲͨ�أ�\n");
			Sleep(3000);
			return 0;
		}
		else
		{									  /*��������û���Ƶ�Ŀ�ĵ�*/
			cOp = getch();					  /*�����û���������*/
			if ((cOp == 'n') || (cOp == 'N')) /*����N������һ��*/
				return KEY_NEXT;
			else if ((cOp == 'q') || (cOp == 'Q')) /*����Q����������*/
				return KEY_RETURN;
		}
		switch (cOp)
		{			 /*�û����뷽���*/
		case KEY_UP: /*�ϼ�ͷ*/
			MoveBox(aiMap, iPlayerX, iPlayerY, 1, aiMap2);
			break;
		case KEY_LEFT: /*���ͷ*/
			MoveBox(aiMap, iPlayerX, iPlayerY, 2, aiMap2);
			break;
		case KEY_RIGHT: /*�Ҽ�ͷ*/
			MoveBox(aiMap, iPlayerX, iPlayerY, 3, aiMap2);
			break;
		case KEY_DOWN: /*�¼�ͷ*/
			MoveBox(aiMap, iPlayerX, iPlayerY, 4, aiMap2);
			break;
		default:
			break;
		}
	}
}

/*�����ƶ�����*/
void MoveBox(int aiMap[][16], int iPlayerX, int iPlayerY, int iSelect, int aiMap2[][16])
{
	int iPlayerX1, iPlayerY1; /*С����һ��Ҫ�ߵ�λ������*/
	int iPlayerX2, iPlayerY2; /*С������һ��Ҫ�ߵ�λ������*/
	switch (iSelect)
	{
	case 1: /*�����ƶ�*/
		iPlayerX1 = iPlayerX - 1;
		iPlayerY1 = iPlayerY;
		iPlayerX2 = iPlayerX - 2;
		iPlayerY2 = iPlayerY;
		break;
	case 2: /*�����ƶ�*/
		iPlayerX1 = iPlayerX;
		iPlayerY1 = iPlayerY - 1;
		iPlayerX2 = iPlayerX;
		iPlayerY2 = iPlayerY - 2;
		break;

	case 3: /*�����ƶ�*/
		iPlayerX1 = iPlayerX;
		iPlayerY1 = iPlayerY + 1;
		iPlayerX2 = iPlayerX;
		iPlayerY2 = iPlayerY + 2;
		break;

	case 4: /*�����ƶ�*/
		iPlayerX1 = iPlayerX + 1;
		iPlayerY1 = iPlayerY;
		iPlayerX2 = iPlayerX + 2;
		iPlayerY2 = iPlayerY;
		break;
	default:
		break;
	}

	/*�Ե�ͼ�Ĳ���*/
	switch (aiMap[iPlayerX1][iPlayerY1]) /*�ж�С����һ��Ҫ�ߵ�λ��*/
	{
	case WALL: /*��һλ����ǽ�������ƶ�*/
		break;
	case SPACE: /*��һλ��Ϊǽ�ڿյغ���һλ��Ϊ��Ŀ�ĵص������ͬ����*/
	case TARGET:
		aiMap[iPlayerX1][iPlayerY1] = PERSON; /*С���ƶ�����һλ��*/
		if (aiMap2[iPlayerX][iPlayerY] == TARGET || aiMap2[iPlayerX][iPlayerY] == TARGET_IN)
			/*С������λ�ó�ʼΪ��Ŀ�ĵػ���Ŀ�ĵأ�С���ƶ���˴��ָ�Ϊ��Ŀ�ĵ�*/
			aiMap[iPlayerX][iPlayerY] = TARGET;
		else
			/*С������λ�ó�ʼΪǽ�ڿյء����ӻ���С�ˣ�С���ƶ���˴��ָ�Ϊǽ�ڿյ�*/
			aiMap[iPlayerX][iPlayerY] = SPACE;
		break;
	case BOX: /*��һλ�������Ӻ���һλ�����ѷ�����Ŀ�ĵص������ͬ����*/
	case TARGET_IN:
		if (aiMap[iPlayerX2][iPlayerY2] == TARGET)
		{
			/*����λ��Ϊ��Ŀ�ĵأ����Ӻ�С��һ���ƶ�����������Ŀ�ĵ�*/
			aiMap[iPlayerX2][iPlayerY2] = TARGET_IN;
			aiMap[iPlayerX1][iPlayerY1] = PERSON;
		}
		else if (aiMap[iPlayerX2][iPlayerY2] == SPACE)
		{
			/*����λ��Ϊ�յأ����Ӻ�С��һ���ƶ�����������յ�*/
			aiMap[iPlayerX2][iPlayerY2] = BOX;
			aiMap[iPlayerX1][iPlayerY1] = PERSON;
		}
		else /*����λ��Ϊǽ�����ӻ�����Ŀ�ĵأ������ƶ���ֱ���˳�*/
			break;
		if (aiMap2[iPlayerX][iPlayerY] == TARGET || aiMap2[iPlayerX][iPlayerY] == TARGET_IN)
			/*С������λ�ó�ʼΪ��Ŀ�ĵػ���Ŀ�ĵأ�С���ƶ���˴��ָ�Ϊ��Ŀ�ĵ�*/
			aiMap[iPlayerX][iPlayerY] = TARGET;
		else /*С������λ�ó�ʼΪǽ�ڿյء����ӻ���С�ˣ�С���ƶ���˴��ָ�Ϊǽ�ڿյ�*/
			aiMap[iPlayerX][iPlayerY] = SPACE;
		break;
	}
}
