#include<iostream>
#include<algorithm>
#define MAX 1001
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N,seq[MAX],dp[MAX],reverse_dp[MAX];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    fse(0,N,1) cin>>seq[i];

    for(int i=0;i<N;i++){
        int re_i=N-1-i;
        dp[i]=1;
        for(int j=0;j<i;j++){
            int re_j=N-1-j;
            if(seq[i]>seq[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
            if(seq[re_i]>seq[re_j]){
                reverse_dp[re_i]=max(reverse_dp[re_i],reverse_dp[re_j]+1);
            }
        }
    }

    int ans=0;
    fse(0,N,1){
        ans=max(ans,dp[i]+reverse_dp[i]);
    }
    cout<<ans;
}
/*
7
9 1 2 3 2 1 9

10
10 1 3 5 7 6 3 2 1 10
*/