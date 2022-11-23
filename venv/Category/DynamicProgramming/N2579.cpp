#include<iostream>
#include<algorithm>
#define MAX 10001
using namespace std;
int N;
int dp[MAX];
int a[MAX];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) cin>>a[i];
    dp[0]=a[0];
    dp[1]=a[1]+a[0];
    dp[2]=max(a[0]+a[2],a[1]+a[2]);
    for(int i=3;i<N;i++){
        dp[i]=max(a[i-1]+dp[i-3],dp[i-2])+a[i];
    }
    cout<<dp[N-1];
}