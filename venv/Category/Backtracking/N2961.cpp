#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 999999999
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N,sour[10],bitter[10];
bool used[10];
int answer=MAX;
int getDiff(){
    long long s=1,b=0;
    fse(0,N,1){
        if(!used[i]) continue;
        s*=sour[i];
        b+=bitter[i];
    }
    return abs(s-b);
}
void bt(int start,int cnt){
    if(cnt>0){
        answer=min(answer, getDiff());
    }
    if(start==N) return;

    fse(start,N,1){
        used[i]=1;
        bt(i+1,cnt+1);
        used[i]=0;
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    fse(0,N,1){
        cin>>sour[i]>>bitter[i];
    }
    bt(0,0);
    cout<<answer;
}