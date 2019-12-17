#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N = 200;
int a[N];
bool used[N];
int sum;
int ans;
int n;
void dfs(int s, int p)
{
    if (s + a[p] > sum)
    {
        return;
    }
    else if (s + a[p] == sum)
    {
        used[p] = true;
        ans += 1;
        for (int i = 1; i <= n; i++)
        {
            if (used[i])
            {
                printf("%d ", a[i]);
            }
        }
        printf("\n");
        used[p] = false;
        return;
    }

    else
    {
        used[p] = true;
        for (int i = p; i <= n; i++)
        {
            if (!used[i])
            {
                dfs(s + a[p], i);
            }
        }
        used[p] = false;
        return;
    }

    return;
}

int main()
{
    freopen("in.txt","r",stdin);
    cin >> n >> sum;
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        used[i] = 0;
    }
    used[0] = 1;
    dfs(0, 0);
    printf("%d\n", ans);
}
