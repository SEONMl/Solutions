#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1001
#define MOD 10007
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
typedef long long ll;
ll dp[MAX][MAX];
ll combi(int n,int k){
    if(k==0 || n==k) {
        dp[n][k]=1;
        return 1;
    }
    if(dp[n][k]!=0) return dp[n][k];
    dp[n][k]=(combi(n-1,k) + combi(n-1,k-1))%MOD;
    return dp[n][k] %MOD;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N,K;
    cin>>N>>K;

    dp[1][0]=dp[1][1]=1;
    cout<<combi(N,K);
}