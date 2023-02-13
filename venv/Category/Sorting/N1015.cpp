#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1001
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N, per[MAX];
    pair<int,int> seq[MAX];
    cin>>N;
    fse(0,N,1){
        int tmp;
        cin>>tmp;
        seq[i]={tmp,i};
    }
    sort(seq,seq+N);
    fse(0,N,1){
        int idx=seq[i].second;
        per[idx]=i;
    }
    fse(0,N,1) cout<<per[i]<<" ";
}

/*
순열: permutation
수열: sequence
*/