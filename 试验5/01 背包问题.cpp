// 位运算
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 7;

int n, w;

int f[N];
int dir[N];

int calc(int pp[], int ww[])
{
	int sum = 0;
	int W = 0;
	for (int i = 0; i < 7; i++)
	{
		if (f[i])
		{
			sum += pp[i];
			W += ww[i];
		}
	}
	if (W > w) 
		return -1;
	return sum;
}

int solve(int pp[], int ww[])
{
	int ans = 0;
	for (int i = 0; i < 1 << N; i++)
	{
		memset(f, 0, sizeof(f));
		for (int j = 0; j < N; j++)
		{
			f[N - j - 1] = i >> j & 1;
		}
		
		int num = calc(pp, ww);
		ans = max(ans, num);
	}
	return ans;
}


int main()
{
	n = 7;
	w = 15;
	int p[7] = { 10, 5, 15, 7, 6, 18, 3 };
	int w[7] = { 2, 3, 5, 7, 1, 4, 1 };
	cout << "the ans is "<< solve(p, w) << endl;

} 
