#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int N,M;
ll a[1000001];
ll h=0;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>M;
    for(int i=0;i<N;i++) cin>>a[i];
    sort(a,a+N);
    ll s=0;
    ll e=a[N-1];
    while(s<=e){
        ll mid=(s+e)/2;
        int tar=0;
        for(int i=0;i<N;i++){
            if(a[i]>mid){
                tar+=a[i]-mid;
            }
        }
        if(tar>=M){
            h=max(h,mid);
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
    cout<<h;
}