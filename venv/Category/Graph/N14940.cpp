#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define MAX 1000
#define INF 99999999
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N,M;
int g[MAX][MAX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void bfs(int a,int b){
    queue<pair<int,int>> q;
    q.push({a,b});
    g[a][b]=0;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i(0);i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(0<=nx&&nx<N&&0<=ny&&ny<M && g[nx][ny]!=0 &&g[x][y]+1<g[nx][ny]){
                g[nx][ny]=g[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>M;
    pair<int,int> target;
    for(int i(0);i<N;i++){
        for(int j(0);j<M;j++){
            cin>>g[i][j];
            if(g[i][j]==1) g[i][j]=INF;
            if(g[i][j]==2) target={i,j};
        }
    }
    bfs(target.first, target.second);
    for(int i(0);i<N;i++){
        for(int j(0);j<M;j++){
            if(g[i][j]==INF) cout<<-1<<" ";
            else cout<<g[i][j]<<" ";
        }
        cout<<'\n';
    }
}