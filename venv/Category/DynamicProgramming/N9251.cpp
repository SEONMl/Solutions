#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1001
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int dp[MAX][MAX];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string a,b;
    cin>>a>>b;
    int n=a.length(), m=b.length();
    for(int i(1);i<=n;i++){
        for(int j(1);j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout<<dp[n][m];
}