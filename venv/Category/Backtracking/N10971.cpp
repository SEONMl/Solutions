#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 10
using namespace std;
int N;
bool visit[MAX];
int g[MAX][MAX];
int ans=9e8;
void bt(int depth, int start, int prev, int cost){
    if(depth==N){
        if(g[prev][start]==0) return;
        cost+=g[prev][start];
        ans=min(ans,cost);
        return;
    }
    for(int i=0;i<N;i++){
        if(visit[i] || g[prev][i]==0) continue;
        visit[i]=1;
        bt(depth+1, start,i, cost+g[prev][i]);
        visit[i]=0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>g[i][j];
        }
    }
    for(int i=0;i<N;i++){
        visit[i]=1;
        bt(1,i,i,0);
        visit[i]=0;
    }
    cout<<ans;
}