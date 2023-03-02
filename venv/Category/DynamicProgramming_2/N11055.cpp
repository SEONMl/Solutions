#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N;
int dp[MAX];
int arr[MAX];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    fse(0,N,1)cin>>arr[i];
    for(int i(0);i<N;i++){
        dp[i]=arr[i];
        for(int j(0);j<i;j++){
            if(arr[j]<arr[i]){
                dp[i]=max(dp[i], dp[j]+arr[i]);
            }
        }
    }
    cout<<*max_element(dp,dp+N);
}