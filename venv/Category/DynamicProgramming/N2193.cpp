#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 91
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
long long dp[MAX][2];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    dp[1][0]=0;
    dp[1][1]=1;
    fse(2,n+1,1){
        dp[i][0]=dp[i-1][0]+dp[i-1][1];
        dp[i][1]=dp[i-1][0];
    }
    cout<<dp[n][0]+dp[n][1];
}