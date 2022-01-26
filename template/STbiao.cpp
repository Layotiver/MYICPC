//ST表
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
#define maxn 100010
#define maxlogn 21

int Log2[maxn], f[maxn][maxlogn];

int n, m;

inline void re(int &a)
{
    char c = ',';
    while (!isdigit(c = getchar()))
        ;
    a = c - '0';
    while (isdigit(c = getchar()))
        a = a * 10 + c - '0';
}

inline void init()
{
    for (int i = 2; i <= n; i++)
    {
        Log2[i] = Log2[i >> 1] + 1;
    }
}

inline int maxx(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
#ifdef chenhao
    freopen("chenhao.txt", "r", stdin);
#endif
    int i, j, a, b, c;
    re(n), re(m);
    for (i = 1; i <= n; i++)
    {
        re(f[i][0]);
    }
    init();

    //这里ij的枚举顺序要对
    for (j = 1; j <= maxlogn; j++)
    {
        for (i = 1; i + (1 << j) - 1 <= n; i++)
        {
            f[i][j] = maxx(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (i = 1; i <= m; i++)
    {
        re(a), re(b);
        c = Log2[b - a + 1];
        printf("%d\n", maxx(f[a][c], f[b - (1 << c) + 1][c]));
    }
    return 0;
}