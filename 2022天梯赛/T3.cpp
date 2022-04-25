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

int x, y, n, m;

int main()
{
#ifdef chenhao
    freopen("chenhao.txt", "r", stdin);
#endif
    cin >> x >> y >> n >> m;
    int a = 1, b = 2;
    bool flag = 0;
    if (n > m)
    {
        n = n + m;
        m = n - m;
        n = n - m;
        a++;
        b--;
        flag = 1;
    }
    if (m < x)
    {
        if (flag)
        {
            printf("%d-N %d-N\n", m, n);
        }
        else
        {
            printf("%d-N %d-N\n", n, m);
        }
        printf("zhang da zai lai ba\n");
    }
    else if (n >= x)
    {
        if (flag)
        {
            printf("%d-Y %d-Y\n", m, n);
        }
        else
        {
            printf("%d-Y %d-Y\n", n, m);
        }
        printf("huan ying ru guan");
    }
    else if (m >= y)
    {
        if (flag)
        {
            printf("%d-Y %d-Y\n", m, n);
        }
        else
        {
            printf("%d-Y %d-Y\n", n, m);
        }
        printf("qing %d zhao gu hao %d", b, a);
    }
    else
    {
        if (flag)
        {
            printf("%d-Y %d-N\n", m, n);
        }
        else
        {
            printf("%d-N %d-Y\n", n, m);
        }
        printf("%d: huan ying ru guan", b);
    }
    return 0;
}