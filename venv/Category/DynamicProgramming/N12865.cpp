#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100001
using namespace std;
int N,K;
int weight[101];
int value[101];
int dp[101][MAX];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>K;
    for(int i=1;i<=N;i++) cin>>weight[i]>>value[i];
    
    for(int i(1);i<=N;i++){
        for(int j(1);j<=K;j++){
            dp[i][j]=dp[i-1][j];
            if(j-weight[i]>=0){
                dp[i][j]=max(dp[i][j], dp[i-1][j-weight[i]]+value[i]);
            }
        }
    }

    cout<<dp[N][K];
}