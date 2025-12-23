// Descompunere pe niveluri a unui graf fara circuite.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define NMax 101
int n;
int A[NMax][NMax];
int np[NMax], Nivel[NMax];

void Citire(void);
int main()
{
    int i, j, total = 0, nr_nivel = 0;
    Citire();
	while (total < n)
	{
		printf_s("Nivelul %d: ", ++nr_nivel);
		for (i = 1; i <= n; i++)
			if (!np[i])
			{
				Nivel[i] = nr_nivel;
				printf_s("%d ", i);
				total++;
			}
		printf_s("\n");
		for (i = 1; i <= n; i++)
			if (Nivel[i] == nr_nivel)
				// Eliminam varful i din graf
			{
				np[i] = -1;
				for (j = 1; j <= A[i][0]; j++)
					np[A[i][j]]--;
			}
	}
}

void Citire()
{
	FILE* fin;
	errno_t err = fopen_s(&fin, "graf.in", "r");
	int x, y, m, i;
	fscanf_s(fin, "%d %d", &n, &m);
	for (i = 0; i < m; i++)
	{
		fscanf_s(fin, "%d %d", &x, &y);
		A[x][0]++; A[x][A[x][0]] = y;
		np[y]++;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
