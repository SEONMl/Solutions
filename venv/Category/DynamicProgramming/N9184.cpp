#include<iostream>
#define MAX 21
using namespace std;
int dp[MAX][MAX][MAX];
int W(int a,int b,int c){
    if(a<=0 || b<=0 || c<=0) return 1;
    if(a>20 || b>20 || c>20) return W(20,20,20);
    
    if(dp[a][b][c]) return dp[a][b][c];

    if(a<b && b<c) {
        dp[a][b][c]= W(a,b,c-1)+W(a,b-1,c-1)-W(a,b-1,c);
        return dp[a][b][c];
    }
    dp[a][b][c]= W(a-1,b,c)+W(a-1,b-1,c)+W(a-1,b,c-1)-W(a-1,b-1,c-1);
    return dp[a][b][c];
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int a,b,c;
    while(1){
        cin>>a>>b>>c;
        if(a==-1&&b==-1&&c==-1) break;
        printf("W(%d, %d, %d) = %d\n",a,b,c,W(a,b,c));
    }
}