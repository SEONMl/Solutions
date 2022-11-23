#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100001
using namespace std;
int N;
typedef long long ll;
vector<pair<ll,ll>> v;
bool compare(pair<ll,ll> a,pair<ll,ll> b){
    return a.second<b.second;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,a+b));
    }
    sort(v.begin(),v.end(),compare);

    int cnt=1;
    ll end=v[0].second;
    for(int i=1;i<N;i++){
        ll start=v[i].first;
        if(end<start){
            cnt++;
            end=v[i].second;
        }
    }
    cout<<cnt;
}