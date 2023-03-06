#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 300'001
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N,K;
int child[MAX];
int diff[MAX];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>K;
    fse(0,N,1)cin>>child[i];
    fse(0,N-1,1){
        diff[i]=child[i+1]-child[i];
    }
    sort(diff,diff+N-1);
    int cost=0;
    fse(0,N-K,1){
        cost+=diff[i];
    }
    cout<<cost;
}