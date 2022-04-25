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

int n, m, p, ans;
int num[300];

int main()
{
#ifdef chenhao
    freopen("chenhao.txt", "r", stdin);
#endif
    int i, a, b;
    cin >> n >> m >> p;
    for (i = 1; i <= n; i++)
    {
        cin >> a >> b;
        if (a < 175)
            continue;
        if (b >= p)
            ans++;
        else
            num[a]++;
    }
    for (i = 175; i <= 290; i++)
    {
        ans += num[i] < m ? num[i] : m;
    }
    printf("%d\n", ans);
    return 0;
}