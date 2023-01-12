#include<iostream>
#include<tuple>
#include<queue>
#define MAX 125
#define INF 99999999
using namespace std;
int visit[MAX][MAX], g[MAX][MAX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int dijkstra(int n){
    priority_queue<tuple<int,int,int>> heap;
    heap.push({-g[0][0],0,0});
    while(!heap.empty()){
        auto top=heap.top();
        int curW=-get<0>(top);
        int curX=get<1>(top);
        int curY=get<2>(top);
        heap.pop();

        for(int i=0;i<4;i++){
            int nx=curX+dx[i];
            int ny=curY+dy[i];
            if(0<=nx&&nx<n&&0<=ny&ny<n){
                int nw=curW+g[nx][ny];
                if(visit[nx][ny]>nw){
                    visit[nx][ny]=nw;
                    heap.push({-nw,nx,ny});
                }
            }
        }
    }
    return visit[n-1][n-1];
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int problem=0;
    while(1){
        int N;
        cin>>N;
        if(N==0){
            break;
        }
        for(int i(0);i<N;i++){
            for(int j(0);j<N;j++){
                cin>>g[i][j];
                visit[i][j]=INF;
            }
        }
        problem++;
        int ans=dijkstra(N);
        printf("Problem %d: %d\n",problem, ans);
    }
}