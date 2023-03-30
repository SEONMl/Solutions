#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 500'000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin>>N;
    vector<pair<int,int>> v;
    fse(0,N,1){
        int a;
        cin>>a;
        while(!v.empty()&&v.back().first<a){
            v.pop_back();
        }
        if(v.empty()) cout<<0<<" ";
        else{
            cout<<v.back().second<<" ";
        }
        v.push_back({a,i+1});
    }
}