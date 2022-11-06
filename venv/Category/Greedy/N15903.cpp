#include<iostream>
#include<queue>
using namespace std;
typedef long long ll;
int N,M;
priority_queue<ll> q;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        int t;
        cin>>t;
        q.push(-t);
    }
    for(int i=0;i<M;i++){
        ll first=-q.top();
        q.pop();
        ll second=-q.top();
        q.pop();
        q.push(-(first+second));
        q.push(-(first+second));
    }
    ll ans=0;
    while(!q.empty()){
        ans+=-q.top();
        q.pop();
    }
    cout<<ans;
return 0;
}