#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100'000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N,K;
    cin>>N>>K;
    int fact[11]={0}; // 10! == 3'628'800
    fact[0]=fact[1]=1;
    for(int i(2);i<=N;i++){
        fact[i]=fact[i-1]*i; 
    }
    cout<< fact[N]/(fact[K]*fact[N-K]);
}