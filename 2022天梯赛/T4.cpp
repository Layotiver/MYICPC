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

long long n, m, ans = 1;

int main()
{
#ifdef chenhao
    freopen("chenhao.txt", "r", stdin);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n + m; i++)
    {
        ans *= i;
    }
    printf("%d\n", ans);
    return 0;
}