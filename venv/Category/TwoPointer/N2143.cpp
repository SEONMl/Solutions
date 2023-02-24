#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int T,N,M, a[MAX],b[MAX];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T>>N>>a[0];
    int tmp,cnt=0;
    fse(1,N,1){
        cin>>tmp;
        a[i]=a[i-1]+tmp;
    }
    cin>>M>>b[0];
    fse(1,N,1){
        cin>>tmp;
        b[i]=b[i-1]+tmp;
    }

    int as=0,bs=0,ae=N-1,be=M-1;
    
}