#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#define MAX 66
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N;
int g[MAX][MAX];
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
void rotate(pair<int,int> startPos, int level){
    int x=startPos.first, y=startPos.second;
    int L=pow(2,level);
    int tmp[L][L]={0};
    for(int i(x);i<x+L;i++){
        for(int j(y);j<y+L;j++){
            tmp[j-y][L-1-i+x]=g[i][j];
        }
    }
    for(int i(x);i<x+L;i++){
        for(int j(y);j<y+L;j++){
            g[i][j]=tmp[i-x][j-y];
        }
    }
}
int findIce(int a,int b, bool visit[][MAX]){
    queue<pair<int,int>> q;
    q.push({a,b});
    visit[a][b]=1;
    int cnt=0;
    while(!q.empty()){
        int x=q.front().first, y=q.front().second;
        cnt++;
        q.pop();
        for(int i(0);i<4;i++){
            int nx=x+dx[i], ny=y+dy[i];
            if(0<=nx&&nx<MAX&&0<=ny&&ny<MAX && !visit[nx][ny] && g[nx][ny]!=0){
                visit[nx][ny]=true;
                q.push({nx,ny});
            }
        }
    }
    return cnt;
}
vector<int> calculateResult(){
    int total=0;
    int area=0;
    bool visit[MAX][MAX]={0};
    for(int i(1);i<=N;i++){
        for(int j(1);j<=N;j++){
            total+=g[i][j];
            if(!visit[i][j]&&g[i][j]>0){
                area= max(area, findIce(i,j,visit));
            }
        }
    }
    return {total, area};
}
void adjustCount(int x, int y,int visit[][MAX]){
    for(int i(0);i<4;i++){
        int nx=x+dx[i], ny=y+dy[i];
        if(0<=nx&&nx<MAX&&0<=ny&&ny<MAX){
            visit[nx][ny]++;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,Q,level;
    cin>>n>>Q;
    N=pow(2,n);
    for(int i(1);i<=N;i++){
        for(int j(1);j<=N;j++){
            cin>>g[i][j];
        }
    }
    while(Q--){
        cin>>level;
        // 격자 시계방향 회전
        if(level>0){
            int L=pow(2,level);
            for(int i(1);i<=N;i+=L){
                for(int j(1);j<=N;j+=L){
                    rotate({i,j}, level);
                }
            }
        }

        // 2개 이하 인접 얼음 -1
        int visit[MAX][MAX]={0};
        for(int i(0);i<MAX;i++){
            for(int j(0);j<MAX;j++){
                if(g[i][j]==0){
                    adjustCount(i,j,visit);
                }
            }
        }
        for(int i(1);i<=N;i++){
            for(int j(1);j<=N;j++){
                if(g[i][j]>0 && visit[i][j]>=2){
                    g[i][j]--;
                }
            }
        }
    }
    auto answer= calculateResult();
    cout<<answer[0]<<'\n'<<answer[1];
}