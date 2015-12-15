//----------------------------------------------------------
//현재 외곽 처리가 좆같다
//----------------------------------------------------------


#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

void ship(int *arr[][10], int randx, int randy, int ori, int size);
void four_ship(int *arr[][10], int randx, int randy, int ori);
void three_ship(int *arr[][10], int randx, int randy, int ori);
void two_ship(int *arr[][10], int randx, int randy, int ori);
void one_ship(int *arr[][10], int randx, int randy, int ori);
void mapprint(int *arr[][10]);
void inactive_block(int *arr[][10], int x, int y, int ori, int size);

void gotoxy(int x, int y)
{

	COORD CursorPosition = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);

}


int main()
{
	int arr[10][10] = { 0,0,0,0,0,0,0,0,0,0,
						0,0,0,0,0,0,0,0,0,0,
						0,0,0,0,0,0,0,0,0,0,
						0,0,0,0,0,0,0,0,0,0,
						0,0,0,0,0,0,0,0,0,0,
						0,0,0,0,0,0,0,0,0,0,
						0,0,0,0,0,0,0,0,0,0,
						0,0,0,0,0,0,0,0,0,0,
						0,0,0,0,0,0,0,0,0,0,
						0,0,0,0,0,0,0,0,0,0, };
	int i, j, k;
	int randx, randy, ori;
	int yValue = 4;
	int count = 0;

	srand((unsigned)time(NULL));

	while (yValue > 0)
	{
		ori = rand() % 2 + 1;
		if (ori == 1) {
			randy = rand() % 10;
			randx = rand() % (10 - yValue);
		}
		else if (ori == 2) {
			randy = rand() % (10 - yValue);
			randx = rand() % 10;
		}

		// position check
		if (check_arrange(arr, randx, randy, ori, yValue) == 0)
			continue;
		
		if (yValue == 4) {
			//4칸 배 배치
			ship(arr, randx, randy, ori, 4);

			inactive_block(arr, randx, randy, ori, 4);


			yValue--;
		} 
		else if (yValue ==3) {
			if (count < 2) {
				//3칸 배 배치
				ship(arr, randx, randy, ori, 3);
			
				inactive_block(arr, randx, randy, ori, 3);

				count++;
			}
			else {
				yValue--;
				count = 0;
			}
				
		}
		else if (yValue == 2) {
			//2칸 배 배치
			if (count < 4) {
				ship(arr, randx, randy, ori, 2);

				inactive_block(arr, randx, randy, ori, 2);

				count++;
			}
			else {
				yValue--;
				count = 0;
			}
		}
		else if (yValue == 1) {
			if (count < 4) {
				//1칸 배 배치
				ship(arr, randx, randy, ori, 1);

				inactive_block(arr, randx, randy, ori, 1);

				count++;
			}
			else {
				yValue--;
				count = 0;
			}
		}
	}

	mapprint(arr);
	
	return 0;
}

void mapprint(int *arr[][10]) {
	int i, j;
	for (i = 0;i < 10;i++)
	{
		for (j = 0;j < 10;j++)
		{
			printf("%5d", arr[i][j]);
		}
		puts("");
		puts("");
	}
}

void ship(int *arr[][10], int randx, int randy, int ori, int size)
{
	int k;
	if (ori == 1)
	{
		for (k = 0;k < size;k++)
		{
			arr[randy][randx + k] = 1;
		}
	}
	else if (ori == 2)
	{
		for (k = 0;k < size;k++)
		{
			arr[randy + k][randx] = 1;
		}
	}
}


void four_ship(int *arr[][10], int randx, int randy, int ori)
{
	int k;
	if (ori == 1)
	{
		for (k = 0;k < 4;k++)
		{
			arr[randy][randx + k] = 1;
		}
	}
	else if (ori == 2)
	{
		for (k = 0;k < 4;k++)
		{
			arr[randy + k][randx] = 1;
		}
	}
}



void three_ship(int *arr[][10], int randx, int randy, int ori)
{
	int k;

	if (ori == 1)
	{
		for (k = 0;k < 3;k++)
		{
			arr[randy][randx + k] = 1;
		}
	}
	else if (ori == 2)
	{
		for (k = 0;k < 3;k++)
		{
			arr[randy + k][randx] = 1;
		}
	}
}



void two_ship(int *arr[][10], int randx, int randy, int ori)
{
	int k;

	if (ori == 1)
	{
		for (k = 0;k < 2;k++)
		{
			arr[randy][randx + k] = 1;
		}
	}
	else if (ori == 2)
	{
		for (k = 0;k < 2;k++)
		{
			arr[randy + k][randx] = 1;
		}
	}
}



void one_ship(int *arr[][10], int randx, int randy, int ori)
{
	int k;

	if (ori == 1)
	{
		for (k = 0;k < 1;k++)
		{
			arr[randy][randx + k] = 1;
		}
	}
	else if (ori == 2)
	{
		for (k = 0;k < 1;k++)
		{
			arr[randy][randx + k] = 1;
		}
	}
}

int check_arrange(int *arr[][10], int randx, int randy, int ori, int length)
{
	int i, j, k, p;
	if (positionCheck(arr, randx, randy) == 1)
	{
		if (ori == 1)
		{
			for (k = 0;k < length;k++)
			{
				if (arr[randy][randx + k] != 0)
					return 0;
			}
		}
		else if (ori == 2)
		{
			for (k = 0;k < length;k++)
			{
				if (arr[randy + k][randx] != 0)
					return 0;
			}
		}
		return 1;
	}
	else
		return 0;
}

int positionCheck(int *arr[][10], int x, int y) {
	if (arr[y][x] != 0)
	{
		return 0;
	}
	else
		return 1;
}

void inactive_block(int *arr[][10], int x, int y, int ori, int size)
{
	int i, j, k;

	for (y = 0;y < 10;y++)
	{
		for (x = 0;x < 10;x++)
		{
			//----------------------------
			// 배가 가로 일 때
			//----------------------------
			if (ori == 1)
			{
				if (arr[y][x] == 1 && arr[y][x - 1] == 0 && arr[y][x + 1] == 1)
				{
					if (x == 0 && y == 9)
					{
						arr[y + 1][x] = 5;
					}
					else if (x == 0 && y != 0 && y != 9)
					{
						arr[y - 1][x] = 5;							//
						arr[y + 1][x] = 5;							//
					}
					else if (y == 0 && x == 0)
					{
						arr[y + 1][x] = 5;							//
					}
					else if (y == 9 && x != 0)
					{
						arr[y - 1][x - 1] = 5;						//
						arr[y][x - 1] = 5;							//	
						arr[y - 1][x] = 5;
					}

					else if (y == 0 && x != 0)
					{
						arr[y][x - 1] = 5;							//	
						arr[y + 1][x - 1] = 5;						//	맨 왼쪽 끝 외곽 처리
						arr[y + 1][x] = 5;							//
					}
					else 
					{
						arr[y - 1][x - 1] = 5;						//
						arr[y][x - 1] = 5;							//	
						arr[y + 1][x - 1] = 5;						//	맨 왼쪽 끝 외곽 처리
						arr[y - 1][x] = 5;							//
						arr[y + 1][x] = 5;							//
					}
				}
				else if (arr[x][y] == 1 && arr[x][y - 1] == 1 && arr[x][y + 1] == 1)
				{
					if (y == 9)
					{
						arr[y - 1][x] = 5;							// 중간 부분 처리
					}
					else if (y == 0)
					{
						arr[y + 1][x] = 5;
					}
					else {
						arr[y - 1][x] = 5;							// 중간 부분 처리
						arr[y + 1][x] = 5;
					}
				}
				else if (arr[y][x] == 1 && arr[y][x + 1] == 0)
				{
					if (y == 9 && x == 9)
					{
						arr[y - 1][x] = 5;							//
					}
					else if (x == 9 && y != 0 && y != 9)
					{
						arr[y - 1][x] = 5;							//
						arr[y + 1][x] = 5;							//
					}
					else if (y == 0 && x == 9)
					{
						arr[y + 1][x] = 5;							//
					}
					else if (y == 0 && x != 9)
					{
						arr[y][x + 1] = 5;							//
						arr[y + 1][x + 1] = 5;						// 맨 오른쪽 끝 외곽 처리
						arr[y + 1][x] = 5;							//
					}
					else if (y == 9 && x != 9)
					{
						arr[y - 1][x] = 5;							//
						arr[y - 1][x + 1] = 5;						// 맨 오른쪽 끝 외곽 처리
						arr[y][x + 1] = 5;							//
					}
					else {
						arr[y - 1][x + 1] = 5;						//
						arr[y][x + 1] = 5;							//
						arr[y + 1][x + 1] = 5;						// 맨 오른쪽 끝 외곽 처리
						arr[y - 1][x] = 5;							//
						arr[y + 1][x] = 5;							//
					}

				} 
				else if (arr[y][x - 1] == 0 && arr[y][x] == 1 && arr[y][x + 1] == 0)
				{
					for (i = -1;i < 1;i++)
					{
						for (j = -1;j < 1;j++)
						{
							if (y+i >= 0 && x+j >= 0 && y+i <= 9 && x+j <= 9)
								arr[y + i][x + i] = 5;				//배가 한 칸일 때의 처리
						}
					}
					arr[y][x] = 1;
				}  /*
				if (arr[y][x] == 1) {
					for (i = 0;i < size - 1;i++) { //size를 검사 
						if (arr[y][x + size] == 1)  { // 지정한 size까지 1이 있으면
							for (k = -1;k < 1;k++)  { // 주위를 검사하기 시작
								for (j = -1;j < 1;j++) {
									switch (y)
									{
									case 9:
										while (y + j != 10)
										{
											arr[y + k][x + j] = 5;
										}
										break;
									case 0:
										while (y + j != -1)
										{
											arr[y + k][x + k] = 5;
										}
										break;
									default:
										arr[y + k][x + j] = 5;
										break;
									}
								}
							}
							for (i = 0;i < size - 1;i++)
								arr[y][x + i] = 1;
						}
					}
				} */
			}
			//--------------------------------
			//배가 세로로 배치되었을 때
			//--------------------------------
			else if (ori == 2)
			{	
				if ( arr[y - 1][x] == 0 && arr[y][x] == 1 && arr[y + 1][x] == 1)
				{
					if (y == 0 && x == 9)
					{
						arr[y][x - 1] = 5;							//
					}
					if (y == 0 && x != 9 && x != 0)
					{
						arr[y][x - 1] = 5;							//
						arr[y][x + 1] = 5;							//
					}
					if (x == 9 && y != 0)
					{
						arr[y - 1][x - 1] = 5;						//
						arr[y - 1][x] = 5;							//
						arr[y][x - 1] = 5;							//
					}
					else if (y == 0 && x == 0)
					{
						arr[y][x + 1] = 5;							//
					}
					else if (x == 0 && y != 0)
					{
						arr[y - 1][x] = 5;							//	
						arr[y - 1][x + 1] = 5;						//	맨 윗쪽 끝 외곽 처리
						arr[y][x + 1] = 5;							//
					}
					else {
						arr[y - 1][x - 1] = 5;						//
						arr[y - 1][x] = 5;							//	
						arr[y - 1][x + 1] = 5;						//	맨 윗쪽 끝 외곽 처리
						arr[y][x - 1] = 5;							//
						arr[y][x + 1] = 5;							//
					}

				}
				else if (arr[y - 1][x] == 1 && arr[y][x] == 1 && arr[y + 1][x] == 1)
				{
					if (x == 9)
					{
						arr[y][x - 1] = 5;							// 중간 부분 처리
					}
					else if (x == 0)
					{
						arr[y][x + 1] = 5;
					}
					else {
						arr[y][x - 1] = 5;							// 중간 부분 처리
						arr[y][x + 1] = 5;
					}

				}
				else if (arr[y][x] == 1 && arr[y + 1][x] == 0)
				{
					if (y == 9 && x == 9)
					{
						arr[y][x - 1] = 5;							//
					}
					else if (y == 9 && x != 0 && x != 9)
					{
						arr[y][x - 1] = 5;							//
						arr[y][x + 1] = 5;							//
					}
					else if (x == 9 && y != 9)
					{
						arr[y + 1][x - 1] = 5;						//
						arr[y + 1][x] = 5;							//
						arr[y][x - 1] = 5;							//
					}
					else if (y == 9 && x == 0)
					{
						arr[y][x + 1] = 5;							//
					}
					else if (x == 0 && y != 9)
					{
						arr[y + 1][x] = 5;							//
						arr[y + 1][x + 1] = 5;						// 맨 아랫쪽 끝 외곽 처리
						arr[y][x + 1] = 5;							//
					}
					else {
						arr[y + 1][x - 1] = 5;						//
						arr[y + 1][x] = 5;							//
						arr[y + 1][x + 1] = 5;						// 맨 아랫쪽 끝 외곽 처리
						arr[y][x - 1] = 5;							//
						arr[y][x + 1] = 5;							//
					}

				}
				else if (arr[y - 1][x] == 0 && arr[y][x] == 1 && arr[y + 1][x] == 0)
				{
					for (i = -1;i < 1;i++)
					{
						for (j = -1;j < 1;j++)
						{
							if (y+i >= 0 && x+j >= 0 && y+i <= 9 && x+j <= 9)
								arr[y + i][x + i] = 5;				//배가 한 칸일 때의 처리
						}
					}
					arr[y][x] = 1;
				} /*
				if (arr[y][x] == 1) {
					for (i = 0;i < size - 1;i++) { //size를 검사 
						if (arr[y + size][x] == 1) { // 지정한 size까지 1이 있으면
							for (k = -1;k < 1;k++) { // 주위를 검사하기 시작
								for (j = -1;j < 1;j++) {
									switch (x)
									{
									case 9:
										while (x + j != 10)
										{
											arr[y + k][x + j] = 5;
										}
										break;
									case 0:
										while (x + j != -1)
										{
											arr[y + k][x + j] = 5;
										}
										break;
									default:
										arr[y + k][x + j] = 5;
										break;
									}
								}
							}
							for (i = 0;i < size - 1;i++)
								arr[y + i][x] = 1;
						}
					}
				} */
			}
		}
	}
}