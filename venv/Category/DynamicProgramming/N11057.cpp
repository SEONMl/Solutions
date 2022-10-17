#include<iostream>
#include<stdio.h>
using namespace std;
int N;
int dp[1001][10];
int main(){
    scanf("%d",&N);
    int ans=0;
    for(int i=0;i<10;i++)dp[1][i]=1;
    for(int i=2;i<=N;i++){
        for(int j=0;j<10;j++){
            for(int k=j;k<10;k++){
                dp[i][j]+=dp[i-1][k];
            }
            dp[i][j]%=10007;
        }
    }
    for(int i=0;i<10;i++)ans+=dp[N][i];
    printf("%d",ans%10007);
    return 0;
}