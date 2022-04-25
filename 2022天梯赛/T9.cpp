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

int n, m, k, len[1010];
int s1[1010], p1, s2[1010], p2, p3 = 1;

void dump()
{
    int i;
    for (i = 0; i < p1; i++)
    {
        printf("%d", s1[i]);
        if(i!=p1-1) printf(" ");
    }
    printf("\n");
    p1 = 0;
    return;
}

int main()
{
#ifdef chenhao
    freopen("chenhao.txt", "r", stdin);
#endif
    int i;
    cin >> n >> m >> k;
    for (i = 1; i <= n; i++)
    {
        cin >> len[i];
    }
    while (p3 <= n || p2)
    {
        if (p1)
        {
            if (p2 && s2[p2 - 1] <= s1[p1-1])
            {
                s1[p1] = s2[p2 - 1];
                p1++;
                p2--;
                if (p1 == k)
                    dump();
            }
            else if (p3 <= n)
            {
                if (len[p3] <= s1[p1-1])
                {
                    s1[p1] = len[p3];
                    p1++;
                    p3++;
                    if (p1 == k)
                        dump();
                }
                else
                {
                    if (p2 < m)
                    {
                        s2[p2] = len[p3];
                        p2++;
                        p3++;
                    }
                    else dump();
                }
            }
            else
                dump();
        }
        else
        {
            if (p2)
            {
                s1[p1] = s2[p2 - 1];
                p1++;
                p2--;
                if (p1 == k)
                    dump();
            }
            else if (p3 <= n)
            {
                s1[p1] = len[p3];
                p1++;
                p3++;
                if (p1 == k)
                    dump();
            }
        }
    }
    if (p1)
        dump();
    return 0;
    return 0;
}