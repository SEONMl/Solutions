#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int T,N;
vector<int> a;
void solution(){
    cin>>N;
    ll ans=0;
    int m=0;
    a.clear();
    for(int i=0;i<N;i++){
        int t;
        cin>>t;
        a.push_back(t);
    }
    for(int i=N-1;i>=0;i--){
        m=max(m,a[i]);
        ans+=m-a[i];
    }
    cout<<ans<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    for(int i=0;i<T;i++){
        solution();
    }
    return 0;
}