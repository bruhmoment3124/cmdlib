#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* fill screen matrix with a selected character */
void fillscreen(int width, int height, int mat[height][width], int chr)
{
	for(int i = 0; i<height; i++)
	{
		for(int k = 0; k<width; k++)
		{	
			mat[i][k] = chr;
		}
	}
}

/* print screen matrix with a selected format */
void printscreen(int width, int height, int mat[height][width], char *format)
{
	for(int i = 0; i<height; i++)
	{
		for(int k = 0; k<width; k++)
		{	
			printf(format, mat[i][k]);
		}
		printf("\n");
	}
}

/* replace the x and y values on the matrix to the selected character */
void drawpoint(int x, int y, int width, int height, int mat[height][width], int chr)
{
	mat[y][x] = chr;
}

/* draw a line from point 1 to point 2 with a selected character; Bresenham's algorithm adapted from wikipedia */
void drawline(int x1, int y1, int x2, int y2, int width, int height, int mat[height][width], int chr)
{
	int dx = abs(x2 - x1), dy = -abs(y2 - y1); /* dx and dy */
	int sx = x1 < x2 ? 1 : -1, sy = y1 < y2 ? 1 : -1; /* sx and sy */
	int error = dx + dy;
	
	while(1)
	{
		mat[y1][x1] = chr;
		
		if(x1 == x2 && y1 == y2) break;
		
		int e2 = 2 * error;
		
		if(e2 >= dy)
		{
			if(x1 == x2) break;
			error = error + dy;
			x1 = x1 + sx;
		}
		
		if(e2 <= dx)
		{
			if(y1 == y2) break;
			error = error + dx;
			y1 = y1 + sy;
		}
	}
}

/* draw a triangle from 3 points */
int drawtri(int x1, int y1, int x2, int y2, int x3, int y3, int width, int height, int mat[height][width], int chr)
{
	drawline(x1, y1, x2, y2, width, height, mat, chr);
	drawline(x2, y2, x3, y3, width, height, mat, chr);
	drawline(x3, y3, x1, y1, width, height, mat, chr);
}

int main(void)
{
	int height = 32, width = 32;
	int mat[height][width];
	
	int x = 0, y = 0;
	while(1)
	{
		fillscreen(width, height, mat, '.');
			
			drawtri(9, 10, x, y, 31, 31, width, height, mat, '#');
			
		printscreen(width, height, mat, "%c ");	
		system("cls");
	}
	
	return 0;
}