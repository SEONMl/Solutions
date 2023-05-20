#include<iostream>
#include<vector>
#include<algorithm>
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
typedef long long ll;
ll N,K;
ll count(ll mid){
    ll res=0;
    for(int i(1);i<=N;i++){
        res+=min(N, mid/i);
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>K;
    ll left=0, right=N*N;
    ll result=0;
    while(left<=right){
        ll mid=(left+right)/2;
        if(count(mid) < K) left=mid+1;
        else{
            result=mid;
            right=mid-1;
        }
    }
    cout<<result;
}