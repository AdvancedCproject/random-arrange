#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

void ship(int *arr[][10], int randx, int randy, int ori, int size);
int check_arrange(int *arr[][10], int randx, int randy, int ori, int length);
int positionCheck(int *arr[][10], int x, int y);
void mapprint(int *arr[][10]);

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
	int i, j, k, h;
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
			//4Ä­ ¹è ¹èÄ¡
			ship(arr, randx, randy, ori, 4);

			yValue--;
		} 
		else if (yValue ==3) {
			if (count < 2) {
				//3Ä­ ¹è ¹èÄ¡
				ship(arr, randx, randy, ori, 3);

				count++;
			}
			else {
				yValue--;
				count = 0;
			}
				
		}
		else if (yValue == 2) {
			//2Ä­ ¹è ¹èÄ¡
			if (count < 4) {
				ship(arr, randx, randy, ori, 2);

				count++;
			}
			else {
				yValue--;
				count = 0;
			}
		}
		else if (yValue == 1) {
			if (count < 4) {
				//1Ä­ ¹è ¹èÄ¡
				ship(arr, randx, randy, ori, 1);

				count++;
			}
			else {
				yValue--;
				count = 0;
			}
		}
	}

	gotoxy(0, 0);mapprint(arr);
	
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
	int k, h, i, j;
	if (ori == 1)
	{
		for (i = -1;i <= 1;i++)
		{
			for (j = -1;j < size+1;j++)
			{
				if(randy+i >= 0 && randx+j >= 0 && randy+i <= 9 && randx+j <= 9)
					arr[randy + i][randx + j] = 5;
			}
		}gotoxy(0, 0);mapprint(arr);
		for (k = 0;k < size;k++)
		{
			arr[randy][randx + k] = 1;
		}gotoxy(0, 0);mapprint(arr);
	} 
	else if (ori == 2)
	{
		for (i = -1;i < size+1;i++)
		{
			for (j = -1;j <= 1;j++)
			{
				if (randy + i >= 0 && randx + j >= 0 && randy + i <= 9 && randx + j <= 9)
				arr[randy + i][randx + j] = 5;
			}
		}gotoxy(0, 0);mapprint(arr);
		for (k = 0;k < size;k++)
		{
			arr[randy + k][randx] = 1;
		}gotoxy(0, 0);mapprint(arr);
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