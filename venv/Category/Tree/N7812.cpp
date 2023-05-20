#include <iostream>
#include <cstdio>
#include <vector>
#include <memory.h>
#include <limits.h>
 
#define min(a,b)(a < b ? a : b)
 
using namespace std;
 
typedef pair<int, int> pii;
typedef long long ll;
 
vector<pii> vc[10001];
 
int n;
int cnt[10001];
ll sum[10001];
ll ans;
 
void getTree(int here, int prev)
{
    cnt[here] = 1;
 
    for (int i = 0; i < vc[here].size(); i++)
    {
        int next = vc[here][i].first;
        int cost = vc[here][i].second;
 
        if (next == prev)
            continue;
 
        getTree(next, here);
 
        cnt[here] += cnt[next];
        sum[here] += cost * cnt[next] + sum[next];
    }
}
 
void getSum(int here, int prev, ll total)
{
    ans = min(ans, total);
 
    for (int i = 0; i < vc[here].size(); i++)
    {
        int next = vc[here][i].first;
        int cost = vc[here][i].second;
 
        if (next == prev)
            continue;
 
        getSum(next, here, total - (cnt[next] * cost) + ((n - cnt[next]) * cost));
    }
}
 
int main()
{
    while(1)
    {
        scanf("%d", &n);
 
        if (n == 0)
            break;
 
        memset(cnt, 0, sizeof(cnt));
        memset(sum, 0, sizeof(sum));
        ans = LLONG_MAX;
 
        for (int i = 0; i < n; i++)
            vc[i].clear();
 
        for (int i = 0; i < n - 1; i++)
        {
            int from, to, val;
            scanf("%d %d %d", &from, &to, &val);
 
            vc[from].push_back(pii(to, val));
            vc[to].push_back(pii(from, val));
        }
 
        getTree(0, -1);
 
        getSum(0, -1, sum[0]);
 
        printf("%lld\n", ans);
    }
 
    return 0;
}