#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define MAX 4002
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int dp[MAX][MAX];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string a,b;
    cin>>a>>b;
    int n=a.length(), m=b.length();
    int answer=0;
    for(int i(1);i<=n;i++){
        for(int j(1);j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                answer=max(answer, dp[i][j]);
            }
        }
    }
    cout<<answer;
}