#include <string>
#include <vector>
#include<queue>
#include<algorithm>
#include<iostream>

#define MAX 4

using namespace std;
// 키 조작 횟수의 최솟값
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool visit[MAX][MAX];
int g[MAX][MAX];
class Pos{
    public:
    int x;
    int y;
    int dir;
    int btn;
    Pos(int x,int y,int dir,int btn){
        this->x=x; this->y=y; this->dir=dir; this->btn=btn;
    }
};
int bfs(pair<int,int> from, pair<int,int> to){
    int a=from.first, b=from.second;
    for(int i(0);i<MAX;i++)
        for(int j(0);j<MAX;j++)
            visit[i][j]=false;
    visit[a][b]=true;
    queue<Pos*> q;
    q.push(new Pos(a,b,-1,0));
    
    int click=100000;
    while(!q.empty()){
        int x=q.front()->x;
        int y=q.front()->y;
        int prevDir=q.front()->dir;
        int btn=q.front()->btn;
        
        if(x==to.first && y==to.second){
            click=min(btn,click);
        }
        q.pop();
        
        for(int i(0);i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(0<=nx&&nx<MAX&&0<=ny&&ny<MAX && !visit[nx][ny]){
                visit[nx][ny]=true;
                if(prevDir!=i) q.push(new Pos(nx,ny,i,btn+1));
                else q.push(new Pos(nx,ny,i,btn));
            }
        }
    }
    return click;
}
vector<pair<int,int>> card[7];
int N;
int totalClick=9999999;
void dfs(int k, vector<bool> paired, pair<int,int> cur, int sum){
    if(k==N){
        totalClick=min(sum,totalClick);
        return;
    }
    
    for(int i(1);i<=6;i++){
        if(paired[i]) continue;
        int click1=bfs(cur,card[i][0]);
        int click2=bfs(cur,card[i][1]);

        paired[i]=paired[i+6]=true;
        dfs(k+1, paired, card[i][1], sum+click1);
        dfs(k+1, paired, card[i][0], sum+click2);
        paired[i]=paired[i+6]=false;
    }
}
int solution(vector<vector<int>> board, int r, int c) {
    int clicked=0;
    for(int i(0);i<MAX;i++){
        for(int j(0);j<MAX;j++){
            g[i][j]=board[i][j];
            if(g[i][j]!=0){
                card[g[i][j]].push_back({i,j});
                clicked++;
            }
        }
    }
    N=clicked/2;
    vector<bool> paired(13);
    for(int i(0);i<=6;i++){
        paired[i]=paired[i+6]=true;
        if(card[i].size()==0) continue;
        
        paired[i]=paired[i+6]=false;
        clicked+=bfs(card[i][0], card[i][1]);
    }
    dfs(0,paired,{r,c},0);
    
    return totalClick+clicked;
}

/*
1. 이동행위(방향이 바뀔 때만 +1)
2. 엔터행위(카드개수)
*/