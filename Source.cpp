#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define n 5
int a[n][n];
int i, j, k, r;
double f, F;
void input(int a[n][n])
{
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < n;j++)
		{
			printf("a[%d][%d]=", i + 1, j + 1);
			scanf_s("%d", &a[i][j]);
		}
	}
}
void sort(int a[n][n])
{
	for (j = 0;j < n;j++)
	{
		for (i = 0;i < n;i++)
		{
			for (k = i + 1;k < n;k++)
			{
				if (a[i][j] > a[k][j])
				{
					a[i][j] += a[k][j];
					a[k][j] = a[i][j] - a[k][j];
					a[i][j] -= a[k][j];
				}
			}
		}
	}
}
void output(int a[n][n])
{
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < n;j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}
void calc(int a[n][n])
{
	F = 0;
	for (i = 0;i < n - 1;i++)
	{
		f = 1;
		for (j = 0;j < n - 1 - i;j++)
		{
			f *= a[i][j];
		}
		printf("f(%d)=%lf\n", i + 1, f);
		F += f;
	}
	printf("F(f)=%lf", F);
}
void main()
{
	input(a);
	output(a);
	printf("\n\n");
	sort(a);
	output(a);
	printf("\n");
	calc(a);
	system("pause");
}
