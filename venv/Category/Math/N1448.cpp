#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1'000'000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N;
int arr[MAX];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    fse(0,N,1)cin>>arr[i];
    sort(arr,arr+N, greater<>());
    int idx=0;
    int ans=-1;
    while(idx+2<N){
        if(arr[idx]<arr[idx+1]+arr[idx+2]){
            ans=arr[idx]+arr[idx+1]+arr[idx+2];
            break;
        }
        idx++;
    }
    cout<<ans;
}