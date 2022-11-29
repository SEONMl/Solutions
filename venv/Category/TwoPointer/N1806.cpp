#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100'001
using namespace std;
int N,K;
int arr[MAX];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>K;
    for(int i(0);i<N;i++) {
        cin>>arr[i];
        if(i!=0)arr[i]+=arr[i-1];
    }
    int left=0,right=0; // right 0부터 시작해야 함 || arr[0]>=K 인 경우
    int ans=9e8;
    while(right<N){
        int tmp=arr[right]-arr[left-1];
        if(tmp>=K) {
            ans=min(ans,right-left+1);
            left++;
            if(left>right) right++;
        }
        else{
            right++;
        }
    }
    
    if(ans==9e8) ans=0;
    cout<<ans;
}