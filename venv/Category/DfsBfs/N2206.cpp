#include<iostream>
#include<queue>
#include<tuple>
#define MAX 9e8
using namespace std;
int N,M;
int g[1000][1000];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int visit[1000][1000];
int bfs(){
    queue<tuple<int,int,int,int>> q;
    q.push(make_tuple(0,0,1,0));
    visit[0][0]=1;
    while(!q.empty()){
        int x=get<0>(q.front());
        int y=get<1>(q.front());
        int dis=get<2>(q.front());
        int wall=get<3>(q.front());
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(0<=nx&&nx<N&&0<=ny&&ny<M && visit[nx][ny]>dis+1){
                if(g[nx][ny]==1&&wall==0){
                    visit[nx][ny]=dis+1;
                    q.push(make_tuple(nx,ny,dis+1,1));
                }else{
                    visit[nx][ny]=dis+1;
                    q.push(make_tuple(nx,ny,dis+1,wall));
                }

            }
        }
    }
    return visit[N-1][M-1];
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        string s;
        cin>>s;
        for(int j=0;j<M;j++){
            g[i][j]=s[j]-'0';
            visit[i][j]=MAX;
        }
    }
    cout<<bfs();

return  0;
}