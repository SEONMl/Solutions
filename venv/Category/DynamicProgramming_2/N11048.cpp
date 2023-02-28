#include<iostream>
#include<queue>
#include<algorithm>
#define MAX 1000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N,M;
int dx[]={1,0};
int dy[]={0,1};
int dp[MAX][MAX];
int g[MAX][MAX];
void solution(){
    dp[0][0]=g[0][0];

    for(int i(0);i<N;i++){
        for(int j(0);j<M;j++){
            for(int k(0);k<2;k++){
                int nx=i+dx[k], ny=j+dy[k];
                if(0<=nx&&nx<N&&0<=ny&&ny<M && dp[nx][ny]<dp[i][j]+g[nx][ny]){
                    dp[nx][ny]=dp[i][j]+g[nx][ny];
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>M;
    for(int i(0);i<N;i++){
        for(int j(0);j<M;j++){
            cin>>g[i][j];
        }
    }
    solution();
    cout<<dp[N-1][M-1];
}