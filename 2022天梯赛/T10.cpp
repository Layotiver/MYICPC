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

struct TP
{
    int h1, h2, m1, m2, s1, s2;
} tp[100010];

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

bool cmp(TP a, TP b)
{
    return a.h1 * 3600 + a.m1 * 60 + a.s1 < b.h1 * 3600 + b.m1 * 60 + b.s1;
}

void prin(TP a,int b)
{
    if(b)
    {
        if(a.h2<10) putchar('0');
        printf("%d:",a.h2);
        if(a.m2<10) putchar('0');
        printf("%d:",a.m2);
        if(a.s2<10) putchar('0');
        printf("%d",a.s2);
    }
    else
    {
        if(a.h1<10) putchar('0');
        printf("%d:",a.h1);
        if(a.m1<10) putchar('0');
        printf("%d:",a.m1);
        if(a.s1<10) putchar('0');
        printf("%d",a.s1);
    }
}

int main()
{
#ifdef chenhao
    freopen("chenhao.txt", "r", stdin);
#endif
    int i;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        re(tp[i].h1);
        re(tp[i].m1);
        re(tp[i].s1);
        re(tp[i].h2);
        re(tp[i].m2);
        re(tp[i].s2);
    }
    sort(tp + 1, tp + n + 1, cmp);
    if (tp[1].h1 || tp[1].m1 || tp[1].s1)
    {
        printf("00:00:00 - ");
        prin(tp[1],0);
        putchar('\n');
    }
    for (i = 2; i <= n; i++)
    {
        if (tp[i].h1 != tp[i - 1].h2 || tp[i].m1 != tp[i - 1].m2 || tp[i].s1 != tp[i - 1].s2)
        {
            prin(tp[i-1],1);
            printf(" - ");
            prin(tp[i],0);
            putchar('\n');
        }
    }
    if(tp[n].h2!=23 || tp[n].m2!=59 || tp[n].s2!=59)
    {
        prin(tp[n],1);
        printf(" - 23:59:59");
    }
    return 0;
}