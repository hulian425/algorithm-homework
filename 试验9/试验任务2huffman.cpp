/*有一个英文句子 str=“The following code computes the 
intersection of two arrays.”，请统计各个字符出现的次数，以其
为频率构造对应的哈夫曼编码，将该英文句子进行编码以得到
enstr。编写程序实现上述功能。*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef struct HMT
{
	char a;
	int num;
	HMT* l;
	HMT* r;
	vector<char> code;
}*hmt;
struct cmp
{
	bool operator ()(hmt &a, hmt &b)const
	{
		return a->num > b->num;
	}
};
vector<int> code;
void dfs(hmt t)
{
	if (t->l != 0)
	{
		code.push_back(0);
		dfs(t->l);
		code.pop_back();
	}
	if (t->r != 0)
	{
		code.push_back(1);
		dfs(t->r);
		code.pop_back();
	}
	if (t->a != '\0')
	{
		cout << t->a << " ";
		for (int i = 0; i < code.size(); i++)
		{
			cout << code[i];
		}
		cout << endl;
		return;
	}
	
}
int main()
{
	int judge[300] = { 0 };
	string str = "The following code computes the intersection of two arrays.";
	for (int i = 0; i < str.size(); i++)
	{
		judge[str[i]]++;
	}
	/*for (int i = 0; i < 300; i++)
	{
		printf("%d = %d\n", i, judge[i]);
	}*/
	// printf("******");
	priority_queue<hmt,vector<hmt>, cmp> huf;
	//printf("******");
	for (int i = 0; i < 300; i++)
	{
		if (judge[i] > 0)
		{
			//cout << i << endl;
			//printf("%d = %d\n", i, judge[i]);
			hmt t = hmt(new HMT);
			t->a = i;
			t->l = 0;
			t->r = 0;
			t->num = judge[i];
			huf.push(t);

		}
	}
	//printf("******");
	while (huf.size() > 1)
	{
		//printf("******");
		hmt tt = hmt(new HMT);
		tt->num = huf.top()->num;
		tt->l = huf.top();
		huf.pop();
		tt->num += huf.top()->num;
		tt->r =  huf.top();
		huf.pop();
		tt->a = '\0';
		huf.push(tt);
	}
	//printf("******");
	dfs(huf.top());
}
