// 洛谷线段树模板1
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
typedef long long ll;

ll n, m, num[100010];

struct node
{
    ll l, r, v, tag;
} nd[1700010];

inline void re(ll &a)
{
    char c = ',', f = ',';
    while (!isdigit(c = getchar()))
        f = c;
    a = c - '0';
    while (isdigit(c = getchar()))
        a = a * 10 + c - '0';
    if (f == '-')
        a = -a;
    return;
}

void build(ll bh, ll left, ll right)
{
    nd[bh].l = left;
    nd[bh].r = right;
    if (left == right)
        nd[bh].v = num[left];
    else
    {
        ll mid = left + right >> 1;
        build(bh << 1, left, mid);
        build(bh << 1 | 1, mid + 1, right);
        nd[bh].v = nd[bh << 1].v + nd[bh << 1 | 1].v;
    }
    return;
}

void pushdown(ll bh)
{
    nd[bh << 1].v += (nd[bh << 1].r - nd[bh << 1].l + 1) * nd[bh].tag;
    nd[bh << 1].tag += nd[bh].tag;
    nd[bh << 1 | 1].v += (nd[bh << 1 | 1].r - nd[bh << 1 | 1].l + 1) * nd[bh].tag;
    nd[bh << 1 | 1].tag += nd[bh].tag;
    nd[bh].tag = 0;
    return;
}

void add(ll bh, ll left, ll right, ll js)
{
    if (left > nd[bh].r || right < nd[bh].l)
        return;
    if (left <= nd[bh].l && right >= nd[bh].r)
    {
        nd[bh].tag += js;
        nd[bh].v += js * (nd[bh].r - nd[bh].l + 1);
        return;
    }
    pushdown(bh);
    add(bh << 1, left, right, js);
    add(bh << 1 | 1, left, right, js);
    nd[bh].v = nd[bh << 1].v + nd[bh << 1 | 1].v;
    return;
}

ll ask(ll bh, ll left, ll right)
{
    if (left > nd[bh].r || right < nd[bh].l)
        return 0;
    if (left <= nd[bh].l && right >= nd[bh].r)
    {
        return nd[bh].v;
    }
    pushdown(bh);
    return ask(bh << 1, left, right) + ask(bh << 1 | 1, left, right);
}

int main()
{
#ifdef chenhao
    freopen("chenhao.txt", "r", stdin);
#endif
    ll i, a, b, c;
    re(n);
    re(m);
    for (i = 1; i <= n; i++)
    {
        re(num[i]);
    }
    build(1, 1, n);
    for (i = 1; i <= m; i++)
    {
        re(a);
        if (a == 1)
        {
            re(a);
            re(b);
            re(c);
            add(1, a, b, c);
        }
        else
        {
            re(a);
            re(b);
            printf("%lld\n", ask(1, a, b));
        }
    }
    return 0;
}