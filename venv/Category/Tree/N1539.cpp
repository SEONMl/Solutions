#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 300'000
#include<map>
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
typedef long long ll;
map<int,ll> counter;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin>>N;
    counter.insert({-1,0});
    counter.insert({N+1, 0});
    ll answer=0;

    fse(0,N,1){
        int value;
        cin>>value;
        auto r_iter=counter.upper_bound(value);
        auto l_iter=r_iter;
        l_iter--;

        ll tmp=max(r_iter->second, l_iter->second)+1;
        answer+=tmp;
        counter.insert({value, tmp});
    }
    cout<<answer;
}