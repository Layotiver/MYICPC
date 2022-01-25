// 平衡树splay
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
#define MAXN 100010

int root, total, child[MAXN][2], father[MAXN], cnt[MAXN], size[MAXN], value[MAXN];

int n;

// 更新节点a的size
inline void maintain(int a)
{
    size[a] = size[child[a][0]] + size[child[a][1]] + cnt[a];
    return;
}

//判断a是父亲的左儿子还是右儿子
inline bool get(int a)
{
    return a == child[father[a]][1];
}

//销毁节点a
inline void clear(int a)
{
    child[a][0] = child[a][1] = father[a] = value[a] = size[a] = cnt[a] = 0;
    return;
}

void rotate(int a)
{
    int b = father[a];
    int c = father[b];
    int chk = get(a);
    child[b][chk] = child[a][chk ^ 1];
    if (child[a][chk ^ 1])
        father[child[a][chk ^ 1]] = b;
    child[a][chk ^ 1] = b;
    father[b] = a;
    father[a] = c;
    if (c)
        child[c][b == child[c][1]] = a;
    maintain(a);
    maintain(b);
    return;
}

//将节点a旋转至根节点
void splay(int a)
{
    for (int f = father[a]; f = father[a], f; rotate(a))
    {
        if (father[f])
            rotate(get(a) == get(f) ? f : a);
    }
    root = a;
}

//插入数值a
void insert(int a)
{
    if (!root)
    {
        value[++total] = a;
        cnt[total]++;
        root = total;
        maintain(root);
        return;
    }
    int cur = root, f = 0;
    while (1)
    {
        if (value[cur] == a)
        {
            cnt[cur]++;
            maintain(cur);
            maintain(f);
            splay(cur);
            break;
        }
        f = cur;
        cur = child[cur][value[cur] < a];
        if (!cur)
        {
            value[++total] = a;
            cnt[total]++;
            father[total] = f;
            child[f][value[f] < a] = total;
            maintain(total);
            maintain(f);
            splay(total);
            break;
        }
    }
}

//查询数值a的排名
int rk(int a)
{
    int res = 0, cur = root;
    while (1)
    {
        if (a < value[cur])
        {
            cur = child[cur][0];
        }
        else
        {
            res += size[child[cur][0]];
            if (a == value[cur])
            {
                splay(cur);
                return res + 1;
            }
            res += cnt[cur];
            cur = child[cur][1];
        }
    }
}

//查询排名a的数
int kth(int a)
{
    int cur = root;
    while (1)
    {
        if (child[cur][0] && size[child[cur][0]] >= a)
        {
            cur = child[cur][0];
        }
        else
        {
            a -= size[child[cur][0]] + cnt[cur];
            if (a <= 0)
            {
                splay(cur);
                return value[cur];
            }
            cur = child[cur][1];
        }
    }
}

int pre()
{
    int cur = child[root][0];
    if (!cur)
        return cur;
    while (child[cur][1])
        cur = child[cur][1];
    splay(cur);
    return cur;
}

int nxt()
{
    int cur = child[root][1];
    if (!cur)
        return cur;
    while (child[cur][0])
        cur = child[cur][0];
    splay(cur);
    return cur;
}

//删除数值a
void del(int a)
{
    rk(a);
    if (cnt[root] > 1)
    {
        cnt[root]--;
        maintain(root);
        return;
    }
    if (!child[root][0] && !child[root][1])
    {
        clear(root);
        root = 0;
        return;
    }
    if (!child[root][0])
    {
        int cur = root;
        root = child[root][1];
        father[root] = 0;
        clear(cur);
        return;
    }
    if (!child[root][1])
    {
        int cur = root;
        root = child[root][0];
        father[root] = 0;
        clear(cur);
        return;
    }
    int cur = root, b = pre();
    father[child[cur][1]] = b;
    child[b][1] = child[cur][1];
    clear(cur);
    maintain(root);
}

inline void re(int &a)
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

int main()
{
#ifdef chenhao
    freopen("chenhao.txt", "r", stdin);
    freopen("out.txt","w",stdout);
#endif
    int i, a, b;
    re(n);
    for (i = 1; i <= n; i++)
    {
        re(a);
        re(b);
        switch (a)
        {
        case (1):
            insert(b);
            break;
        case (2):
            del(b);
            break;
        case (3):
            printf("%d\n", rk(b));
            break;
        case (4):
            printf("%d\n", kth(b));
            break;
        case (5):
            insert(b);
            printf("%d\n", value[pre()]);
            del(b);
            break;
        default:
            insert(b);
            printf("%d\n", value[nxt()]);
            del(b);
            break;
        }
    }
    return 0;
}