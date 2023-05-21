#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1'000'001
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int dp[MAX],before[MAX];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin>>N;
    fse(2,N+1,1){
        dp[i]=MAX;
    }
    for(int i(1);i<N;i++){
        if(i*2<=MAX && dp[i]+1<dp[i*2]) {
            dp[i*2] = dp[i]+1;
            before[i*2]=i;
        }
        if(i*3<=MAX && dp[i]+1<dp[i*3]) {
            dp[i*3] = dp[i]+1;
            before[i*3]=i;
        }
        if(dp[i]+1<dp[i+1]){
            dp[i+1]=dp[i]+1;
            before[i+1]=i;
        }
    }
    int tmp=N;
    cout<<dp[N]<<'\n';
    while(tmp>0){
        cout<<tmp<<" ";
        tmp=before[tmp];
    }
}