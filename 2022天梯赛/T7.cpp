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

long long n, m, q;
bool h[100010], l[100010];

int main()
{
#ifdef chenhao
    freopen("chenhao.txt", "r", stdin);
#endif
    long long i, a, b, nn, mm;
    cin >> n >> m >> q;
    nn = n;
    mm = m;
    for (i = 1; i <= q; i++)
    {
        cin >> a >> b;
        if (a)
        {
            mm -= !h[b];
            h[b] = 1;
        }

        else
        {
            nn -= !l[b];
            l[b] = 1;
        }
    }
    printf("%lld\n", nn * mm);
    return 0;
}