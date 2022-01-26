//树状数组
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <cctype>
#include <set>
#include <map>
#include <cmath>
using namespace std;
#define maxn 500010

int n, m, num[maxn], tree[maxn];

int lowbit(int a)
{
    return a & -a;
}

void init()
{
    int i, a;
    for (i = 1; i <= n; i++)
    {
        tree[i] += num[i];
        a = i + lowbit(i);
        if (a <= n)
            tree[a] += tree[i];
    }
}

void add(int a, int b)
{
    while (a <= n)
    {
        tree[a] += b;
        a += lowbit(a);
    }
}

int sum(int a)
{
    int ret = 0;
    while (a)
    {
        ret += tree[a];
        a -= lowbit(a);
    }
    return ret;
}

int main()
{
#ifdef chenhao
    freopen("chenhao.txt", "r", stdin);
#endif
    int i, a, b;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        cin >> num[i];
    }
    init();
    for (i = 1; i <= m; i++)
    {
        cin >> a;
        if (a == 1)
        {
            cin >> a >> b;
            add(a, b);
        }
        else
        {
            cin >> a >> b;
            printf("%d\n", sum(b) - sum(a - 1));
        }
    }
}