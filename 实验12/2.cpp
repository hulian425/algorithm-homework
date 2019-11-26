#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 10000;
int n;
int c;
int a[N];
int ans = 0;
bool judge(int d)
{
    int l = 0, r = n;
    while (r - l > 1)
    {
        int mid = (l + r) / 2;
        if (a[mid] <= d)
        {
            l = mid;
        }
        else r = mid;
    }
    return a[l] == d;
}
int main()
{
    cin >> n >> c;
    for (int i = 0; i < n ;i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        int d = a[i] + c;
        if(judge(d))
        {
            ans += 1;
        }
    }
    cout << ans << endl;
}
