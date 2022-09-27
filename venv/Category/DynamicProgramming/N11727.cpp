#include<stdio.h>
#include<iostream>
using namespace std;
int N;
int dp[1001];
int main(){
    scanf("%d",&N);
    dp[1]=1;
    dp[2]=3;
    for(int i=3;i<=N;i++){
        dp[i]=(dp[i-2]*2+dp[i-1])%10007;
    }
    printf("%d",dp[N]);
return 0;
}