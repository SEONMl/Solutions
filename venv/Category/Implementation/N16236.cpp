#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
bool comp(tuple<int,int,int> a,tuple<int,int,int> b);
int N;
int g[20][20];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
vector<tuple<int,int,int>> fish;
int ans;
struct Shark {
    int x;
    int y;
    int size=2;
    int eatingCount=0;

    Shark(int x,int y){
        x=x;
        y=y;
    }

    void setPos(int x,int y){
        this->x=x;
        this->y=y;
        this->eatingCount++;
    }

    void sizeup(){
        if(this->eatingCount >= this->size){
            this->size++;
            this->eatingCount=0;
        }
    }
};

bool bfs(Shark *shark){
    queue<tuple<int,int,int>> q;
    q.push({shark->x, shark->y,0});
    int disGraph[20][20]={};

    while(!q.empty()){
        int x=get<0>(q.front());
        int y=get<1>(q.front());
        int dis=get<2>(q.front());
        q.pop();

        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(0<=nx&&nx<N&&0<=ny&&ny<N && disGraph[nx][ny]==0 && g[nx][ny]<=shark->size){
                q.push({nx,ny,dis+1});
                disGraph[nx][ny]=dis+1;
            }
        }
    }
    
    int idx=-1;
    tuple<int,int,int> minDis={99999999,0,0};
    for(int i=fish.size()-1;i>=0;i--){
        int fishSize=get<0>(fish[i]);
        int fishX=get<1>(fish[i]);
        int fishY=get<2>(fish[i]);
        cout<<fishSize<<" "<<fishX<<" "<<fishY<<endl;

        if(shark->size<fishSize) break;

        if(!comp(minDis, {disGraph[fishX][fishY],fishX,fishY})){
            idx=i;
            minDis={disGraph[fishX][fishY],fishX,fishY};
        }
    }

    if(idx==-1) return 0;
    ans+=get<0>(minDis);
    fish[idx]={999999,999999,999999};
    return 1;
}

bool comp(tuple<int,int,int> a,tuple<int,int,int> b){
    if(get<0>(a) < get<0>(b)){
        return false;
    }else{
        if(get<1>(a)<get<1>(b)) {
            return false;
        }else{
            if(get<2>(a)<get<2>(b)){
                return false;
            }else return true;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    Shark *shark;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>g[i][j];
            if(g[i][j]==9) {
                g[i][j]=0;
                shark=new Shark(i,j);
            }
            if(1<=g[i][j]&&g[i][j]<=6) fish.push_back({g[i][j],i,j});
        }
    }
    sort(fish.begin(),fish.end(),comp);
    
    while(bfs(shark))
    cout<<ans;
}