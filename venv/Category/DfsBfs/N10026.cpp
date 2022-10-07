#include<stdio.h>
#include<queue>
#include<memory.h> // memset(..)
#include<iostream>
#define MAX 101
using namespace std;
int N;
char g[MAX][MAX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool visit[MAX][MAX];
void bfs(int x,int y){
    visit[x][y]=true;
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    while (!q.empty()){
        int a=q.front().first;
        int b=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=a+dx[i];
            int ny=b+dy[i];
            if(0<=nx&&nx<N&&0<=ny&&ny<N && visit[nx][ny]==false){
                if(g[nx][ny]==g[a][b]) {
                    q.push(make_pair(nx,ny));
                    visit[nx][ny]=true;
            }
            }
        }
    }
}
int main(){
    int cnt=0;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%s",g[i]);
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!visit[i][j]){
                bfs(i,j);
                cnt++;
            }
        }
    }
    printf("%d ",cnt);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(g[i][j]=='R') g[i][j]='G';
        }
    }
    cnt=0;
    memset(visit,false,sizeof(visit));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!visit[i][j]){
                bfs(i,j);
                cnt++;
            }
        }
    }
    printf("%d",cnt);
return 0;
}