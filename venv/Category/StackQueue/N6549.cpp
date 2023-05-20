#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100'003
using namespace std;
typedef long long ll;
#define fse(A,B,C) for(ll i=A;i<B;i+=C)
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(1){
        int N;
        cin>>N;
        if(N==0) break;
        
        ll arr[MAX]={0};
        fse(1,N+1,1){
            cin>>arr[i];
        }
        
        vector<ll> stk;
        stk.push_back(0);
        ll answer=0;
        fse(1,N+2,1){
            while(!stk.empty()&& arr[stk.back()]>arr[i]){
                int idx=stk.back();
                stk.pop_back();
                ll area = (i-1 - stk.back()) * (arr[idx]);
                answer=max(answer, area);
            }
            stk.push_back(i);
        }
        cout<<answer<<'\n';
    }
}