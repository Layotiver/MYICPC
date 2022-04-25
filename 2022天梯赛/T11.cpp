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

int n;
int bn[510][510];

struct peo
{
    bool xb;
    int dis, bh;
} p[510];

inline void re(int &a)
{
    char c = ',';
    while (!isdigit(c = getchar()))
        ;
    a = c - '0';
    while (isdigit(c = getchar()))
        a = a * 10 + c - '0';
    return;
}

bool cmp(peo a, peo b)
{
    return a.dis < b.dis;
}

int main()
{
#ifdef chenhao
    freopen("chenhao.txt", "r", stdin);
#endif
    int i, j, k, a, b, d;
    char c;
    re(n);
    for (i = 1; i <= n; i++)
    {
        p[i].bh = i;
        for (j = i + 1; j <= n; j++)
        {
            bn[i][j] = 1e7;
            bn[j][i] = 1e7;
        }
    }
    for (i = 1; i <= n; i++)
    {
        c = getchar();
        p[i].xb = c == 'M';
        re(a);
        for (j = 1; j <= a; j++)
        {
            re(b);
            re(d);
            bn[i][b] = d;
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            for (k = 1; k <= n; k++)
            {
                if (bn[j][i] + bn[i][k] < bn[j][k])
                    bn[j][k] = bn[j][i] + bn[i][k];
                if (bn[k][i] + bn[i][j] < bn[k][j])
                    bn[k][j] = bn[k][i] + bn[i][j];
            }
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (p[i].xb != p[j].xb)
            {
                p[i].dis = p[i].dis > bn[j][i] ? p[i].dis : bn[j][i];
            }
        }
    }
    sort(p + 1, p + n + 1, cmp);
    int low = -1;
    for (i = 1; i <= n; i++)
    {
        if (p[i].xb)
            continue;
        if (low == -1)
        {
            low = p[i].dis;
            printf("%d", p[i].bh);
        }
        else if (p[i].dis == low)
        {
            printf(" %d", p[i].bh);
        }
        else
            break;
    }
    low = -1;
    printf("\n");
    for (i = 1; i <= n; i++)
    {
        if (!p[i].xb)
            continue;
        if (low == -1)
        {
            low = p[i].dis;
            printf("%d", p[i].bh);
        }
        else if (p[i].dis == low)
        {
            printf(" %d", p[i].bh);
        }
        else
            break;
    }
    return 0;
}