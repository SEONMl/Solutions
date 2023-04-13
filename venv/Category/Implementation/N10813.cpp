#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 101
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N,M,a,b;
    cin>>N>>M;
    int ball[MAX];
    fse(1,N+1,1){
        ball[i]=i;
    }
    fse(0,M,1){
        cin>>a>>b;
        int tmp=ball[b];
        ball[b]=ball[a];
        ball[a]=tmp;
    }
    fse(1,N+1,1) cout<<ball[i];
}