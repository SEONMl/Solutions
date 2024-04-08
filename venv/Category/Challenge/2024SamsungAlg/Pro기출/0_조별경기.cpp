#include<iostream>


#define MAX 100'002
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
int parent[MAX];
int score[MAX];
int total;
unordered_map<int,int> idx;
int find(int x) {
    if (parent[x] != x) return parent[x] = find(parent[x]);
    return parent[x];
}
void unionAll(int a, int b) {
    int x = find(a);
    int y = find(b);
    if (x < y)parent[y] = x;
    else parent[x] = y;
}
int tree[MAX * 4];
void initSegTree(int cur, int start, int end) {
    if (start == end) {
        tree[cur] = find(start);
        return;
    }
    int mid = (start + end) / 2;
    initSegTree(cur * 2, start, mid);
    initSegTree(cur * 2 + 1, mid + 1, end);
    tree[cur] = max(tree[cur * 2], tree[cur * 2 + 1]);
}
void updateTree(int cur, int start, int end, int target, int value) {
    if (start == end) {
        if (tree[cur] == target) {
            score[start] += value;
        }
        return;
    }

    int mid = (start + end) / 2;
    if(tree[cur]<target){
    updateTree(cur * 2 + 1, mid + 1, end, target, value);

    }else if(tree[cur]>target){
    updateTree(cur * 2, start, mid, target, value);

    }else{
    updateTree(cur * 2, start, mid, target, value);
    updateTree(cur * 2 + 1, mid + 1, end, target, value);

    }

    tree[cur] = max(tree[cur * 2], tree[cur * 2 + 1]);
}


void init(int N)
{
    total = N;
    idx.clear();
    for (int i = 0; i < MAX; i++) {
        parent[i] = i;
        score[i] = 0;
    }
    initSegTree(1, 1, N);
}

void updateScore(int mWinnerID, int mLoserID, int mScore)
{
    int winP = find(mWinnerID);
    int loseP = find(mLoserID);
    updateTree(1, 1, total, winP, mScore);
    updateTree(1, 1, total, loseP, -mScore);
}

void unionTeam(int mPlayerA, int mPlayerB)
{
    unionAll(mPlayerA, mPlayerB);
    initSegTree(1, 1, total);
}

int getScore(int mID)
{
    return score[mID];
}














#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define CMD_INIT 100
#define CMD_UPDATE_SCORE 200
#define CMD_UNION_TEAM 300
#define CMD_GET_SCORE 400

extern void init(int N);
extern void updateScore(int mWinnerID, int mLoserID, int mScore);
extern void unionTeam(int mPlayerA, int mPlayerB);
extern int getScore(int mID);

static bool run()
{
    int queryCnt, cmd;
    int ans, res;
    bool okay = false;

    scanf("%d", &queryCnt);
    for (int i = 0; i < queryCnt; i++)
    {
        scanf("%d", &cmd);
        switch (cmd)
        {
        case CMD_INIT:
            int N;
            scanf("%d", &N);
            init(N);
            okay = true;
            break;
        case CMD_UPDATE_SCORE:
            int mWinnerID, mLoserID, mScore;
            scanf("%d%d%d", &mWinnerID, &mLoserID, &mScore);
            updateScore(mWinnerID, mLoserID, mScore);
            break;
        case CMD_UNION_TEAM:
            int mPlayerA, mPlayerB;
            scanf("%d%d", &mPlayerA, &mPlayerB);
            unionTeam(mPlayerA, mPlayerB);
            break;
        case CMD_GET_SCORE:
            int mID;
            scanf("%d", &mID);
            res = getScore(mID);
            scanf("%d", &ans);
            
            //  printf("get score -------------------------%d %d\n", res, ans);
            if (ans != res)
            {
                okay = false;
            }
            break;
        }
    }

    return okay;
}

int main()
{
    setbuf(stdout, NULL);
    freopen("C:\\Dev\\projects\\Solutions\\venv\\Category\\.vscode\\input.txt", "r", stdin);
    // freopen("sample_input.txt", "r", stdin);

    int T, MARK;
    scanf("%d%d", &T, &MARK);

    for (int tc = 1; tc <= T; tc++)
    {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }

    return 0;
}