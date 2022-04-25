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

char s1[100010], s2[100010];
int l1, l2, p1, p2;
char a1[100010], a2[100010];

int main()
{
#ifdef chenhao
    freopen("chenhao.txt", "r", stdin);
#endif
    int i;
    scanf("%s%s", a1, a2);
    l1 = strlen(a1);
    l2 = strlen(a2);
    for (i = 1; i < l1; i++)
    {
        if (a1[i] % 2 == a1[i - 1] % 2)
            s1[p1++] = a1[i] > a1[i - 1] ? a1[i] : a1[i - 1];
    }
    for (i = 1; i < l2; i++)
    {
        if (a2[i] % 2 == a2[i - 1] % 2)
            s2[p2++] = a2[i] > a2[i - 1] ? a2[i] : a2[i - 1];
    }
    if (strcmp(s1, s2))
    {
        printf("%s\n%s\n", s1, s2);
    }
    else
    {
        printf("%s\n", s1);
    }
    return 0;
}