#include<iostream>
#define MAX 1000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N,K,g[MAX][MAX];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
pair<int,int> remember;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>K;
    int cur=N*N;
    int dir=0;
    int x=0;
    int y=0;
    while(cur>0){
        if(cur==K) remember={x+1,y+1};
        g[x][y]=cur;
        cur--;

        int nx=x+dx[dir];
        int ny=y+dy[dir];
        if(0<=nx&&nx<N&&0<=ny&&ny<N&& g[nx][ny]==0){
            x=nx;
            y=ny;
        }else{
            dir=(dir+1)%4;
            x+=dx[dir];
            y+=dy[dir];
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<g[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<remember.first<<" "<<remember.second;
}