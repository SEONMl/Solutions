#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1001
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    int arr[MAX],dp[MAX];
    cin>>N;
    fse(0,N,1){
        cin>>arr[i];
        dp[i]=1;
    }
    for(int i(0);i<N;i++){
        for(int j(0);j<i;j++){
            if(arr[j]>arr[i]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    cout<<*max_element(dp,dp+N);
}