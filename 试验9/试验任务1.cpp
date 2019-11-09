/*•会议安排问题。有一组会议 A 和一组会议室 B，A[i]表示第 i 个
会议的参加人数，B[j]表示第 j 个会议室最多可以容纳的人数。
当且仅当 A[i] <= B[j]时，第 j 个会议室可以用于举办第 i 个会
议。给定数组 A 和数组 B，请设计算法计算最多可以同时举办
多少个会议。
• 例如，A[]={1,2,3}，B[]={3,2,4}，结果为 3； • 若 A[]={3,4,3,1},B[]={1,2,2,6}，结果为 2*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int a[100];
	int b[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int j = 0; j < n; j++)
	{
		cin >> b[j];
	}
	sort(a, a + n);
	sort(b, b + n);
	int num = 0;
	for (int i = 0, j = 0; i < n && j < n;)
	{
		if (a[i] <= b[j])
		{
			num++;
			i++;
			j++;
		}
		else
		{
			j++;
		}
	}
	printf("会议次数 = %d\n", num);


}
