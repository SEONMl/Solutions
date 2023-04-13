#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#define MAX 21
#define INF 9999999
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int g[MAX][MAX], N,M;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool used[MAX*MAX];
vector<pair<int,int>> guest;
vector<pair<int,int>> destination;

int bfs(pair<int,int> src, pair<int,int> des){
    int a=src.first, b=src.second, c=des.first, d=des.second;
    queue<tuple<int,int,int>> q;
    q.push({a,b,0});
    bool visit[MAX][MAX]={0};
    visit[a][b]=1;
    while(!q.empty()){
        int x=get<0>(q.front());
        int y=get<1>(q.front());
        int dis=get<2>(q.front());
        q.pop();
        if(x==c&&y==d){ // 목적지 도착
            return dis;
        }

        for(int i(0);i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(0<=nx&&nx<N&&0<=ny&&ny<N && g[nx][ny]!=1 && !visit[nx][ny]){
                visit[nx][ny]=1;
                q.push({nx,ny,dis+1});
            }
        }
    }
    return INF;
}
bool isSuccess(){
    fse(0,M,1){
        if(!used[i]) return false;
    }
    return true;
}
int guestToDestination(int idx){
    auto src=guest[idx];
    auto des=destination[idx];
    return bfs(src,des);
}
vector<int> findShortestGuest(pair<int,int> taxi){
    int targetIndex=INF;
    int shortest=INF;
    pair<int,int> tar={INF,INF};
    for(int i(0);i<M;i++){
        if(used[i]) continue;

        auto src=guest[i];
        int dis=bfs(taxi, src);

        if(shortest>dis){
            targetIndex=i;
            shortest=dis;
            tar=src;
        }else if(shortest==dis){
            if(src.first<tar.first){
                targetIndex=i;
                tar=src;
            }else if(src.first==tar.first && src.second<tar.second){
                targetIndex=i;
                tar=src;
            }
        }
    }
    return {targetIndex, shortest}; // 승객 인덱스, 택시-승객 거리
}
int work(pair<int,int> taxi,int gas){
    while(1){
        if(isSuccess()){
            return gas;
        }
        // 가까운 승객 찾기
        auto res = findShortestGuest(taxi);
        if(res[1]==INF) return -1;
        int idx=res[0];
        int disToGuest=res[1];

        // 이동
        taxi=destination[idx];
        gas-=disToGuest;
        if(gas<=0) return -1;
        int cost=guestToDestination(idx);
        if(cost==INF) return -1;
        gas-=cost;
        if(gas<0) return -1;

        // 충전
        gas+=cost*2;
        used[idx]=true;
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int x1,x2,y1,y2,gas;
    cin>>N>>M>>gas;
    for(int i(0);i<N;i++){
        for(int j(0);j<N;j++){
            cin>>g[i][j];
        }
    }
    cin>>x1>>y1;
    pair<int,int> taxi={x1-1, y1-1};
    fse(0,M,1){
        cin>>x1>>y1>>x2>>y2;
        guest.push_back({--x1,--y1});
        destination.push_back({--x2,--y2});
    }
    cout<<work(taxi,gas);
}