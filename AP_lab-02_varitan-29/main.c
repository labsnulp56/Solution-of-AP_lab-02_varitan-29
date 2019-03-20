#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

double** creation(int lines, int columns);
void initialize(double** A, int lines, int columns);
void output(double** A, int lines, int columns);
void first_element(double** A, double* firstElements, double* minElements, int lines, int columns);

int main()
{
	system("chcp 1251");
	double **A;
	double *firstElements;
	double *minElements;
	int columns, lines;
	printf("%s", "Input matrix size = ");
	scanf("%d %d", &columns, &lines);
	firstElements = (double*)malloc(lines * sizeof(double));
	minElements = (double*)malloc(lines * sizeof(double));
	A = creation(columns, lines);
	initialize(A, columns, lines);
	output(A, columns, lines);
	first_element(A, firstElements, minElements, lines, columns);
	free(A);
	free(firstElements);
	free(minElements);
	system("pause");
	return 0;
}

double** creation(int lines, int columns)
{
	double **A;
	A = (double*)malloc(lines * sizeof(double));
	for (int i = 0; i < lines; i++) {
		A[i] = (double*)malloc(columns * sizeof(double));
	}
	return A;
}

void initialize(double** A, int lines, int columns)
{
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			scanf_s("%lf", &A[i][j]);
		}
	}
}

void output(double** A, int lines, int columns)
{
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			printf("%lf ", A[i][j]);
		}
		printf("\n");
	}
}

void first_element(double** A, double* firstElements, double* minElements, int lines, int columns)
{
	int j = 0;
	for (int i = 0; i < lines; i++)
	{
		firstElements[i] = A[i][0];
		printf("one of the firs element is %lf \n", firstElements[i]);
	}
	for (int k = 0; k < lines; k++)
	{
		double min = A[k][0];
		for (j = 0; j < lines; j++)
		{
			if (A[k][j] < min)
				min = A[k][j];
		}
		minElements[k] = min;
	}
	for (int i = 0; i < lines; i++)
	{
		printf("min element %lf  \n", minElements[i]);
	}
	for (int k = 0; k < lines; k++) {
		if (minElements[k] != firstElements[k])
		{
			k++;
			break;
		}
		for (j = 0; j < lines; j++) {
			printf("%lf ", A[k][j]);
		}
		printf("\n");
	}
}
