#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#define MAX 1001
using namespace std;
string a,b;
char ta[MAX],tb[MAX];
string lcs[MAX][MAX];
int dp[MAX][MAX];
int main(){
    scanf("%s%s",&ta,&tb);
    a=string(ta);
    b=string(tb);
    for(int i=1;i<a.size()+1;i++){
        for(int j=1;j<b.size()+1;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                lcs[i][j]=lcs[i-1][j-1]+a[i-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                lcs[i][j]=(lcs[i][j-1].length()>lcs[i-1][j].length())?lcs[i][j-1]:lcs[i-1][j];
            }
        }
    }
    printf("%d\n%s",dp[a.length()][b.length()],lcs[a.length()][b.length()]);    
    return 0;
}
/*
시간초과 떠서 string[][] 사용 x
역추적 해야 함 =_=

include <iostream>
#include <string>
using namespace std;

int dp[1005][1005] = {0, };
int Max(int a, int b) { return a>b?a:b; }
string A, B;

void print_LCS(int i, int j) {
    if(!dp[i][j]) return;
    if(A[i-1] == B[j-1]) {
        print_LCS(i-1, j-1);
        cout << A[i-1];
    }
    else {
        if(dp[i-1][j] > dp[i][j-1]) print_LCS(i-1, j);
        else print_LCS(i, j-1);
    }
}

int main() {
    cin >> A >> B;
    for(int i=1; i<=A.length(); i++)
        for(int j=1; j<=B.length(); j++) {
            if(A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = Max(dp[i-1][j], dp[i][j-1]);
        }
    cout << dp[A.length()][B.length()] << "\n";
    print_LCS(A.length(), B.length());
}
*/