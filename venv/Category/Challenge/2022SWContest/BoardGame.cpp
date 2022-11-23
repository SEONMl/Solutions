#include<iostream>
#define MAX 10000
using namespace std;
int N,M;
int dice;
char tmp;
int board[10000];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>tmp;
        if(tmp=='+') board[i]=1;
        else board[i]=-1;
    }
    int ans=1;
    int now=0;
    for(int i=0;i<M;i++){
        cin>>dice;
        int next=now+dice*board[now];
        if(next>=0&&next<N){
            now=next;
        }
        if(now==0) ans++;
    }
    cout<<ans;
}