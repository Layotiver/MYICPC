#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <vector>
#include <cctype>
#include <cstring>
#include <cmath>
using namespace std;

int a[10];
int n;
int ans[10];

int main()
{
#ifdef chenhao
    freopen("chenhao.txt", "r", stdin);
#endif
    int i;
    for (i = 1; i <= 6; i++)
    {
        cin >> a[i];
        ans[i] = a[i] == 6 ? 5 : 6;
    }
    cin >> n;
    for (i = 1; i < n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            ans[j] = ans[j] - 1 == a[j] ? ans[j] - 2 : ans[j] - 1;
        }
    }
    for(i=1;i<=6;i++)
    {
        printf("%d",ans[i]);
        if(i!=6) printf(" ");
    }
    return 0;
}