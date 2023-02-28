#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int arr[MAX],dp[MAX];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin>>N;
    for(int i(0);i<N;i++){
        cin>>arr[i];
        dp[i]=max(dp[i],1);
        for(int j(0);j<i;j++){
            if(arr[i]>arr[j]){
                dp[i]=max(dp[i], dp[j]+1);
            }
        }
    }
    int tmp=*max_element(dp,dp+N);
    cout<<tmp<<'\n';

    vector<int> ans;
    int i=N-1;
    while(tmp>0){
        if(tmp==dp[i]){
            ans.push_back(arr[i]);
            tmp--;
        }
        i--;
    }
    while(!ans.empty()){
        cout<<ans.back()<<" ";
        ans.pop_back();
    }
}