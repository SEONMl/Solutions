#include<iostream>
#include<stdio.h>
#include<queue>
#include<tuple>
#include<algorithm>
#define MAX 100
using namespace std;
int W,H;
char g[MAX][MAX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int visit[MAX][MAX];
pair<int,int> s,e;
void bfs(int a,int b){
    queue<tuple<int,int,int,int>> q;
    for(int i=0;i<4;i++){
        q.push(make_tuple(a,b,i,0));
        visit[a][b]=0;
    }
    while(!q.empty()){
        int x=get<0>(q.front());
        int y=get<1>(q.front());
        int dir=get<2>(q.front());
        int rot=get<3>(q.front());
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            int nrot=rot;
            if(0<=nx&&nx<H&&0<=ny&&ny<W&&g[nx][ny]!='*'){
                if(dir!=i)nrot++;
                if(visit[nx][ny]>=nrot){
                    visit[nx][ny]=nrot;
                    q.push(make_tuple(nx,ny,i,nrot));
                }
            }
        }
    }
    printf("%d",visit[e.first][e.second]);
}
int main(){
    scanf("%d%d",&W,&H);
    int tmp=0;
    for(int i=0;i<H;i++){
        scanf("%s",&g[i]);
        for(int j=0;j<W;j++){
            visit[i][j]=9e8;
            if(g[i][j]=='C'){
                (tmp==0)?s=make_pair(i,j):e=make_pair(i,j);
                tmp++;
            }
        }
    }
    bfs(s.first,s.second);
    return 0;
}

// 뭐가 틀린겨...