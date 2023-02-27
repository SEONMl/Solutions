#include<iostream>
#include<vector>
#include<memory.h>
#define MAX 101
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
bool isLocked[MAX];
int N;
void round(int n){
    fse(n,N+1,n){
        isLocked[i]=(isLocked[i]+1)%2;
    }
}
int run(){
    int cnt=0;
    fse(1,N+1,1){
        cnt+=(isLocked[i])?1:0;
    }
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T){
        cin>>N;
        memset(isLocked, true, sizeof(isLocked));
        fse(2,N+1,1){
            round(i);
        }
        cout<<run()<<'\n';
        T--;
    }
}