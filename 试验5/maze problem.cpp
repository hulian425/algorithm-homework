#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 9;

int xx[4] = {1, 0, -1, 0};
int yy[4] = { 0, 1, 0, -1 };
void dfs(int x1, int y1, int x2, int y2, char m[N][N])
{
// print in dfs, if print in main(), ther is not 'l';
	m[x1][y1] = 'l';
	if (x1 == x2 && y1 == y2)
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				printf("%c%c", m[i][j], j == N - 2 ? '\n' : '\0');
			}
		}
		return;
	}
	
	for (int i = 0; i < 4; i++)
	{
		int dx = x1 + xx[i];
		int dy = y1 + yy[i];
		if (0 <= x1 && x1 < N - 1 && 0 <= y1 && y1 < N - 1 && m[dx][dy] == 'O')
		{
			dfs(dx, dy, x2, y2, m);
		}
	}
	m[x1][y1] = 'O';
}
int main()
{
	char m[N][N] = {"OXXXXXXX",
					"OOOOOXXX",
					"XOXXOOOX",
					"XOXXOXXO",
					"XOXXXXXX",
					"XOXXOOOX",
					"XOOOOXOO",
					"XXXXXXXO" };

	int x1 = 0, y1 = 0, x2 = N - 2, y2 = N - 2;
	dfs(x1, y1, x2, y2, m);
	return 0;

}
