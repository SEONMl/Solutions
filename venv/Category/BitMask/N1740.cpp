#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef unsigned long long ll;
ll getResult(ll N){
    vector<ll> nums;
    while(N>0){
        nums.push_back(N%2);
        N/=2;
    }
    ll res=0;
    for(int i(0);i<nums.size();i++){
        if(nums[i]) {
            ll tmp=1;
            for(int j(0);j<i;j++){
                tmp*=3;
            }
            res+=tmp;
        }
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll N;
    cin>>N;
    cout<<getResult(N);
}
/*
1 1   1
2 10  3
3 11  4
4 100  9
5 101  7
6 110
7 111
8 1010

*/