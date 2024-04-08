// 느리게 갱신되는 세그트리

#include<vector>
#include<algorithm>
#define MAX 1000000
using namespace std;
typedef long long ll;
int R = 10000, C;
struct Result {
    int top;
    int count;
};

int minTree[MAX*4];
int maxTree[MAX*4];
int sumTree[MAX*4]; // 분리시키는 게 훨씬 빠름, 메모리도 적게 사용

ll tot = 0;
void init(int col)
{
    tot = 0;
    C = col;
    for (int i = 0; i < MAX * 4; i++) {
        minTree[i]=0;
        maxTree[i]=0;
        sumTree[i]=0;
    }
}

void update(int node, int height, int left, int right, int start = 0, int end = -1) {
    if (end == -1) end = C - 1;
    if (right < start || end < left) return;

    if (left <= start && end <= right) {
        minTree[node] += height;
        maxTree[node] += height;
        sumTree[node] += height;
    }
    else {
        int mid = (start + end) / 2;
        update(node * 2, height, left, right, start, mid);
        update(node * 2 + 1, height, left, right, mid + 1, end);

        minTree[node] = min(minTree[node*2], minTree[node*2+1]) + sumTree[node];
        maxTree[node] = max(maxTree[node*2], maxTree[node*2+1]) + sumTree[node];
    }
}

Result droptree(int mCol, int mHeight, int mLength) // 3000
{
    tot += mHeight * mLength;

    update(1, mHeight, mCol, mCol + mLength - 1);

    Result ret;
    ret.top = maxTree[1]-minTree[1];
    ret.count = (tot - 1LL * minTree[1] * C) % MAX;
    return ret;
}









#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

void init(int C);
Result droptree(int mCol, int mHeight, int mLength);

#define CMD_INIT 100
#define CMD_DROP 200

static bool run()
{
    int query_num;
    scanf("%d", &query_num);

    int ans_top, ans_count;
    bool ok = false;

    for (int q = 0; q < query_num; q++)
    {
        int query;
        scanf("%d", &query);
        if (query == CMD_INIT)
        {
            int C;
            scanf("%d", &C);
            init(C);
            ok = true;
        }
        else if (query == CMD_DROP)
        {
            int mCol, mHeight, mLength;
            scanf("%d %d %d", &mCol, &mHeight, &mLength);
            Result ret = droptree(mCol, mHeight, mLength);
            scanf("%d %d", &ans_top, &ans_count);
            if (ans_top != ret.top || ans_count != ret.count)
            {
                ok = false;
            }
        }
    }
    return ok;
}

int main()
{
    setbuf(stdout, NULL);
    freopen("C:\\Dev\\projects\\Solutions\\venv\\Category\\.vscode\\input.txt", "r", stdin);
    int T, MARK;
    scanf("%d %d", &T, &MARK);

    for (int tc = 1; tc <= T; tc++)
    {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }
    return 0;
}