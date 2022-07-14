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

/*函数声明*/
void SelectColor(int iColor);
void DesignUI();
int WelcomePage(); /*初始界面，每次通关后跳回*/
void GetLevel1();
void GetLevel2();
void GetLevel3();
void GetLevel4();
int PlayGame(int aiMap[][16], int aiMap2[][16], int iSum, int iImp);
int PrintMap(int aiMap[][16], int iImp);
void MoveBox(int aiMap[][16], int iPlayerX, int iPlayerY, int iSelect, int aiMap2[][16]);

/*主函数*/
int main()
{
	while (1)
		DesignUI();
}

/*文字颜色函数*/
void SelectColor(int iColor) //颜色函数
{
	HANDLE hConsole =
		GetStdHandle((STD_OUTPUT_HANDLE));	   //得到控制台输出设备的句柄
	SetConsoleTextAttribute(hConsole, iColor); //设置控制台设备的属性
}

/*主界面函数*/
void DesignUI()
{
	int iCh;
	char cNum;
	iCh = WelcomePage();
	if (iCh == 49) /*键盘输入1，开始第一关游戏*/
		GetLevel1();
	else if (iCh == 50)
	{ /*键盘输入2，选择1到4关的游戏*/
		printf("\n\t\t 请输入您想要玩的关卡!(从 1 到 4):");
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
			printf("输入错误!\n");
			Sleep(1000);
			exit(0);
			break;
		}
	}
	else if (iCh == 51)
	{ /*键盘输入3，退出游戏*/
		system("cls");
		exit(0);
	}
}

/*初始欢迎界面*/
int WelcomePage()
{
	int i = 0;
	system("cls");		/*清屏*/
	system("color 0E"); /*设置颜色*/
	printf("\n\n\t\t 欢迎来到推箱子游戏!\n\n");
	printf("\t\t 人物:♀  边界:▓ 箱子: ●  目标:○  完成目标：☆\n");
	printf("\t\t 向上:↑\n\t\t 向下:↓\n\t\t 向左:← \n\t\t 向右:→\n\n");
	printf("\t\t 按1开始新游戏\n\t\t\n");
	printf("\t\t 按2开始选择关卡\n\t\t\n");
	printf("\t\t 按3退出游戏\n\t\t\n");
	printf("\t\t 请输入您的数字:");
	while (1)
	{
		i = getchar();
		if (i >= 49 && i <= 51)
			return i;
	}
}

/*打印地图函数*/
int PrintMap(int aiMap[][16], int iImp)
{ /*参数iImp代表游戏关卡*/
	int i, j;
	int iCount = 0;
	for (i = 0; i < 14; i++)
	{
		for (j = 0; j < 16; j++)
		{
			switch (aiMap[i][j])
			{
			case 0: /*空地*/
				printf("  ");
				break;
			case 1:
				SelectColor(14); /*墙*/
				printf("▓");
				break;
			case 2: /*内部空地*/
				printf("  ");
				break;
			case 3:
				SelectColor(11); /*目的地*/
				printf("○");
				break;
			case 4: /*箱子*/
				SelectColor(11);
				printf("●");
				break;
			case 5: /*箱子推到目的地后显示*/
				iCount++;
				SelectColor(9);
				printf("☆");
				break;
			case 6: /*小人*/
				SelectColor(10);
				printf("♀");
				break;
			}
		}
		printf("\n");
	}
	SelectColor(14);
	printf("\n");
	printf("\t您在第 %d关!\t\t\n", iImp);
	printf("\t按任意方向键开始游戏!\t\n");
	printf("\t按N跳过本关卡直接进入下一关!\t\n");
	printf("\t按Q返回主页!\t\n");
	return iCount; /*返回值表示以正确放入的箱子数*/
}

/*第一关*/
void GetLevel1()
{
	int aiMap2[14][16]; /*表示原始地图*/
	int i, j, iSum = 0; /*iSum表示箱子的数量*/

	/*地图形状
	1代表墙，2代表空地，3代表未放箱子的目标，4代表箱子，5代表以放箱子的目标，6代表小人
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
			if (aiMap[i][j] == TARGET || aiMap[i][j] == TARGET_IN) /*记录箱子个数*/
				iSum++;
		}

	/*PlayGame函数返回值为4的情况代表键盘输入Q返回到主界面，
	其他情况（过关，进入下一关）执行GetLevel2函数，进入第二关
	*/
	if (PlayGame(aiMap, aiMap2, iSum, 1) != KEY_RETURN)
		GetLevel2();
}

/*第二关*/
void GetLevel2()
{
	int aiMap2[14][16]; /*表示原始地图*/
	int i, j, iSum = 0; /*iSum表示箱子的数量*/

	/*地图形状
	1代表墙，2代表空地，3代表未放箱子的目标，4代表箱子，5代表以放箱子的目标，6代表小人
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
			if (aiMap[i][j] == TARGET || aiMap[i][j] == TARGET_IN) /*记录箱子个数*/
				iSum++;
		}

	/*PlayGame函数返回值为4的情况代表键盘输入Q返回到主界面，
	其他情况（过关，进入下一关）执行GetLevel3函数，进入第三关
	*/
	if (PlayGame(aiMap, aiMap2, iSum, 2) != KEY_RETURN)
		GetLevel3();
}

/*第三关*/
void GetLevel3()
{
	int aiMap2[14][16]; /*表示原始地图*/
	int i, j, iSum = 0; /*iSum表示箱子的数量*/

	/*地图形状
	1代表墙，2代表空地，3代表未放箱子的目标，4代表箱子，5代表以放箱子的目标，6代表小人
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
			if (aiMap[i][j] == TARGET || aiMap[i][j] == TARGET_IN) /*记录箱子个数*/
				iSum++;
		}

	/*PlayGame函数返回值为4的情况代表键盘输入Q返回到主界面，
	其他情况（过关，进入下一关）执行GetLevel5函数，进入第五关
	*/
	if (PlayGame(aiMap, aiMap2, iSum, 3) != KEY_RETURN)
		GetLevel4();
}

/*第四关*/
void GetLevel4()
{
	int aiMap2[14][16]; /*表示原始地图*/
	int i, j, iSum = 0; /*iSum表示箱子的数量*/

	/*地图形状
	1代表墙，2代表空地，3代表未放箱子的目标，4代表箱子，5代表以放箱子的目标，6代表小人
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
			if (aiMap[i][j] == TARGET || aiMap[i][j] == TARGET_IN) /*记录箱子个数*/
				iSum++;
		}
	/*PlayGame函数返回值为4的情况代表键盘输入Q返回到主界面，
	其他情况（过关，进入下一关）执行GetLevel7函数，进入第七关
	*/
	PlayGame(aiMap, aiMap2, iSum, 4);
}

/*游戏操作函数*/
int PlayGame(int aiMap[][16], int aiMap2[][16], int iSum, int iImp) /*iSum代表箱子个数*/
{
	int i, j;
	int iPlayerX, iPlayerY; /*人的位置x,y坐标*/
	char cOp;				/*所按下的方向键*/
	int iNum = 0;			/*箱子推到目的地的个数*/

	while (1)
	{
		for (i = 0; i < 14; i++)
		{
			for (j = 0; j < 16; j++) /*循环遍历寻找人的位置*/
			{
				if (aiMap[i][j] == PERSON) /*6代表人的位置*/
					break;
			}
			if (j < 16)
				break;
		}

		iPlayerX = i; /*将二维数组中的人的x,y坐标赋值给iPlayerX和iPlayerY*/
		iPlayerY = j;
		system("cls");
		iNum = PrintMap(aiMap, iImp);
		if (iNum == iSum)
		{ /*将所有箱子都推到目的地*/
			printf(" 恭喜通关！\n");
			Sleep(3000);
			return 0;
		}
		else
		{									  /*还有箱子没有推到目的地*/
			cOp = getch();					  /*捕获用户键盘输入*/
			if ((cOp == 'n') || (cOp == 'N')) /*输入N进入下一关*/
				return KEY_NEXT;
			else if ((cOp == 'q') || (cOp == 'Q')) /*输入Q返回主界面*/
				return KEY_RETURN;
		}
		switch (cOp)
		{			 /*用户输入方向键*/
		case KEY_UP: /*上箭头*/
			MoveBox(aiMap, iPlayerX, iPlayerY, 1, aiMap2);
			break;
		case KEY_LEFT: /*左箭头*/
			MoveBox(aiMap, iPlayerX, iPlayerY, 2, aiMap2);
			break;
		case KEY_RIGHT: /*右箭头*/
			MoveBox(aiMap, iPlayerX, iPlayerY, 3, aiMap2);
			break;
		case KEY_DOWN: /*下箭头*/
			MoveBox(aiMap, iPlayerX, iPlayerY, 4, aiMap2);
			break;
		default:
			break;
		}
	}
}

/*方向移动函数*/
void MoveBox(int aiMap[][16], int iPlayerX, int iPlayerY, int iSelect, int aiMap2[][16])
{
	int iPlayerX1, iPlayerY1; /*小人下一个要走的位置坐标*/
	int iPlayerX2, iPlayerY2; /*小人下下一个要走的位置坐标*/
	switch (iSelect)
	{
	case 1: /*向上移动*/
		iPlayerX1 = iPlayerX - 1;
		iPlayerY1 = iPlayerY;
		iPlayerX2 = iPlayerX - 2;
		iPlayerY2 = iPlayerY;
		break;
	case 2: /*向左移动*/
		iPlayerX1 = iPlayerX;
		iPlayerY1 = iPlayerY - 1;
		iPlayerX2 = iPlayerX;
		iPlayerY2 = iPlayerY - 2;
		break;

	case 3: /*向右移动*/
		iPlayerX1 = iPlayerX;
		iPlayerY1 = iPlayerY + 1;
		iPlayerX2 = iPlayerX;
		iPlayerY2 = iPlayerY + 2;
		break;

	case 4: /*向下移动*/
		iPlayerX1 = iPlayerX + 1;
		iPlayerY1 = iPlayerY;
		iPlayerX2 = iPlayerX + 2;
		iPlayerY2 = iPlayerY;
		break;
	default:
		break;
	}

	/*对地图的操作*/
	switch (aiMap[iPlayerX1][iPlayerY1]) /*判断小人下一步要走的位置*/
	{
	case WALL: /*下一位置是墙，不能移动*/
		break;
	case SPACE: /*下一位置为墙内空地和下一位置为空目的地的情况相同处理*/
	case TARGET:
		aiMap[iPlayerX1][iPlayerY1] = PERSON; /*小人移动到下一位置*/
		if (aiMap2[iPlayerX][iPlayerY] == TARGET || aiMap2[iPlayerX][iPlayerY] == TARGET_IN)
			/*小人所在位置初始为空目的地或满目的地，小人移动后此处恢复为空目的地*/
			aiMap[iPlayerX][iPlayerY] = TARGET;
		else
			/*小人所在位置初始为墙内空地、箱子或者小人，小人移动后此处恢复为墙内空地*/
			aiMap[iPlayerX][iPlayerY] = SPACE;
		break;
	case BOX: /*下一位置是箱子和下一位置是已放箱子目的地的情况相同处理*/
	case TARGET_IN:
		if (aiMap[iPlayerX2][iPlayerY2] == TARGET)
		{
			/*下下位置为空目的地，箱子和小人一起移动，箱子落入目的地*/
			aiMap[iPlayerX2][iPlayerY2] = TARGET_IN;
			aiMap[iPlayerX1][iPlayerY1] = PERSON;
		}
		else if (aiMap[iPlayerX2][iPlayerY2] == SPACE)
		{
			/*下下位置为空地，箱子和小人一起移动，箱子落入空地*/
			aiMap[iPlayerX2][iPlayerY2] = BOX;
			aiMap[iPlayerX1][iPlayerY1] = PERSON;
		}
		else /*下下位置为墙、箱子或者满目的地，不能移动，直接退出*/
			break;
		if (aiMap2[iPlayerX][iPlayerY] == TARGET || aiMap2[iPlayerX][iPlayerY] == TARGET_IN)
			/*小人所在位置初始为空目的地或满目的地，小人移动后此处恢复为空目的地*/
			aiMap[iPlayerX][iPlayerY] = TARGET;
		else /*小人所在位置初始为墙内空地、箱子或者小人，小人移动后此处恢复为墙内空地*/
			aiMap[iPlayerX][iPlayerY] = SPACE;
		break;
	}
}
