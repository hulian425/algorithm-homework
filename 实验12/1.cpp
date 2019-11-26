#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int ans = 0;
void dfs(int a)
{
    if (a == n)
    {
        ans += 1;
        return;
    }
    for (int i = 1; i <= 6; ++i)
    {
        if (a + i <= n)
        {
            dfs(a + i);
        }
        if (a + i > n)
        {
            return;
        }
    }
    return ;
}
int main()
{
    cin >> n;
    dfs(0);
    cout << ans;
}
