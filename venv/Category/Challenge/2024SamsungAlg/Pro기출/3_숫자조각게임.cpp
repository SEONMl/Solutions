#define MAX_ROW 40
#define MAX_COL 30
#define INF 987654321
#include<vector>
#include<bitset>
#include<utility>
#include<algorithm>
using namespace std;

struct Result{
    int row;
    int col;
};
int R,C;
const vector<vector<pair<int,int>>> pattern={
    {{0,0},{0,1}},
    {{0,0},{0,1},{0,2}},
    {{0,0},{1,0},{2,0}},
    {{0,0},{0,1},{1,1},{1,2}},
    {{0,0},{1,0},{1,1},{1,2},{2,2}}
};
bitset<MAX_COL> visited[MAX_ROW];
vector<pair<int,int>> hashing[5][1<<15];
vector<pair<int,int>> combi;
struct D {
    int type, hash;
    vector<pair<int,int>> p;
    D(int t,int h, vector<pair<int,int>> ppp):type(t), hash(h), p(ppp) {}
};
vector<D> memorization;
void init(int mRows, int mCols, int mCells[MAX_ROW][MAX_COL])
{
    R=mRows; C=mCols;
    for(auto nxt: combi){
        int i=nxt.first, j=nxt.second;
        hashing[i][j].clear();
    }
    for(int i=0;i<MAX_ROW;i++){
        visited[i].reset(); 
        // bitset.set() 1로 설정
        // bitset.set(idx, value) idx를 value로 설정 
        // bitset.flip() 반전
        // bitset.test(i) i가 true면 true
    }
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){            
            for(int k=0;k<5;k++){
                int mn = INF;
                bool finished = true;

                for(auto nxt: pattern[k]){
                    int pi=nxt.first, pj=nxt.second;
                    if(i+pi >= R || j+pj >=C) {
                        finished = false;
                        break;
                    }
                    mn = min(mn, mCells[i+pi][j+pj]);
                }

                if(!finished) continue;
                int hash=0;
                for(auto nxt: pattern[k]){
                    int pi=nxt.first, pj=nxt.second;
                    hash<<=3;
                    hash += mCells[i+pi][j+pj] - mn;
                }

                // 해당 위치에서 패턴에 해당하는 해시 저장
                hashing[k][hash].push_back({i, j});
                combi.push_back({k, hash});
            }
        }
    }

    sort(combi.begin(), combi.end());
    combi.resize(unique(combi.begin(), combi.end())-combi.begin());
    for(auto c: combi){
        int i=c.first, j=c.second;
        sort(hashing[i][j].rbegin(), hashing[i][j].rend()); // 내림차순
        memorization.push_back(D(i,j, hashing[i][j]));
    }
}

Result putPuzzle(int mPuzzle[3][3]) // 10만
{
    Result ret = {-1, -1};

    int type=-1;
    for(int k=0;k<5;k++){
        bool finished = true;
        for(auto nxt: pattern[k]){
            int pi=nxt.first, pj=nxt.second;
            if(mPuzzle[pi][pj] == 0) {
                finished = false;
                break;
            }
        }
        if(!finished) continue;
        type = k;
    }

    int mn = INF;
    for(auto p: pattern[type]){
        int pi=p.first, pj=p.second;
        mn = min(mn, mPuzzle[pi][pj]);
    }
    int hash=0;
    for(auto nxt: pattern[type]){
        int pi=nxt.first, pj=nxt.second;
        hash<<=3;
        hash+=mPuzzle[pi][pj] - mn;
    }

    // 패턴 맞는 곳 있는지 확인
    auto &target = hashing[type][hash];
    while(!target.empty()){
        auto t = target.back(); target.pop_back();
        int r=t.first, c=t.second;

        bool isUsed = false;
        for(auto nxt : pattern[type]){
            int pi=nxt.first, pj=nxt.second;
            if(visited[r+pi][c+pj]) {
                isUsed = true;
                break;
            }
        }
        if(isUsed) continue;

        ret.row = r;
        ret.col = c;
        for(auto nxt: pattern[type]){
            int pi=nxt.first, pj=nxt.second;
            visited[r+pi].set(c+pj, true);
        }
        break;
    }
    
    return ret;
}

void clearPuzzles()
{
    for(int i=0;i<MAX_ROW;i++){
        visited[i].reset(); 
    }

    for(auto tar: memorization){
        int t=tar.type, h=tar.hash; auto p=tar.p;
        hashing[t][h] = p;
    }

    return;
}










#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define MAX_ROW 40
#define MAX_COL 30


void init(int mRows, int mCols, int mCells[MAX_ROW][MAX_COL]);
Result putPuzzle(int mPuzzle[3][3]);
void clearPuzzles();


#define CMD_INIT 1
#define CMD_PUT 2
#define CMD_CLR 3


static bool run()
{
    int query_num;
    scanf("%d", &query_num);

    bool ok = false;

    for (int q = 0; q < query_num; q++)
    {
        int query;
        scanf("%d", &query);
        if (query == CMD_INIT)
        {
            int mRows, mCols;
            int mCells[MAX_ROW][MAX_COL];
            scanf("%d %d", &mRows, &mCols);
            for (int i = 0; i < mRows; i++){
                for (int j = 0; j < mCols; j++){
                    scanf("%d", &mCells[i][j]);
                }
            }
            init(mRows, mCols, mCells);
            ok = true;
        }
        else if (query == CMD_PUT)
        {
            char strPuzzle[10];
            int mPuzzle[3][3];
            int ans_row, ans_col;
            scanf("%s", strPuzzle);
            int cnt = 0;
            for (int i = 0; i < 3; i++){
                for (int j = 0; j < 3; j++){
                    mPuzzle[i][j] = strPuzzle[cnt] - '0';
                    cnt++;
                }
            }
            Result ret = putPuzzle(mPuzzle);
            scanf("%d %d", &ans_row, &ans_col);
            if (ans_row != ret.row || ans_col != ret.col)
            {
                ok = false;
            }
        }
        else if (query == CMD_CLR)
        {
            clearPuzzles();
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