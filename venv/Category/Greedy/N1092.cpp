#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 10'000
#define fse(A,B,C) for(int i=A;i<B;i+=C) 
using namespace std;
int N,limit[50],M,box[MAX];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    fse(0,N,1) cin>>limit[i];
    cin>>M;
    fse(0,M,1) cin>>box[i];

    sort(limit,limit+N);
    sort(box,box+M);

    int minute=0;
    if(limit[N-1]<box[M-1]){
        minute=-1;
    }else{
        int idx=0;
        int memory=0;
        while(idx<M){
            for(int j=memory;j<N;j++){
                if(idx>=M) break;
                if(box[idx]<=limit[j]){
                    idx++;
                }
                else{
                    memory=j+1;
                }
            }
            minute++;
        }
    }
    cout<<minute;
}
/*
4
1 2 3 4
8
1 1 2 2 3 3 4 4
*/