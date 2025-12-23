// Algoritmul lui Dijkstra optimizat.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1000000000
#define NMAX 50001

int n, x0;
vector<pair<int, int>>G[NMAX];
int dmin[NMAX];
int prec[NMAX];
FILE* fout;

class ComparVf
{
public:
	bool operator()(const int& x, const int& y)
	{
		return dmin[x] > dmin[y];
	}
};

priority_queue<int, vector<int>, ComparVf>H;

void citire();
void dijkstra();
void afisare();

int main()
{
	citire();
	dijkstra();
	afisare();
	return 0;
}

void citire()
{
	int i, m, x, y, c;
	FILE* fin;
	errno_t err = fopen_s(&fin, "dijkstra.in", "r");
	fscanf_s(fin, "%d %d %d", &n, &m, &x0);
	for (i = 0; i < n; i++)
	{
		fscanf_s(fin, "%d %d %d", &x, &y, &c);
		G[x].push_back(make_pair(y, c));
	}
}

void dijkstra()
{
	int i, vfmin;
	for (i = 1; i <= n; i++)
	{
		dmin[i] = INF;
		prec[i] = x0;
	}
	dmin[x0] = 0; prec[x0] = 0;
	H.push(x0);
	while (!H.empty())
	{
		vfmin = H.top(); H.pop();
		for (i = 0; i < G[vfmin].size(); i++)
			// Parcurg lista de adiacenta a lui vfmin
			if (dmin[G[vfmin][i].first] > dmin[vfmin] + G[vfmin][i].second) // Optimizez
			{
				dmin[G[vfmin][i].first] = dmin[vfmin] + G[vfmin][i].second;
				prec[G[vfmin][i].first] = vfmin;
				H.push(G[vfmin][i].first);
			}
	}
}

void drum(int x)
{
	if (x)
	{
		drum(prec[x]);
		fprintf_s(fout, "%d ", x);
	}
}

void afisare()
{
	errno_t err = fopen_s(&fout, "dijkstra.out", "w");
	for (int i = 1; i <= n; i++)
		if (i != x0)
			if (dmin[i] == INF)
				fprintf_s(fout, "0\n");
			else
			{
				fprintf_s(fout, "%d: ", dmin[i]);
				drum(i);
				fprintf_s(fout, "\n");
			}
	fclose(fout);
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
