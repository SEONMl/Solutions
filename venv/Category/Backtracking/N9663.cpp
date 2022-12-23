#include<iostream>
#define MAX 15
using namespace std;
int g[MAX];
int ans;
int N;
bool isOverapped(int col){
    for(int i=0;i<col;i++){
        if(g[i]==g[col] || abs(g[i]-g[col])==col-i){
            return true;
        }
    }
    return false;
}
void bt(int depth){
    if(depth==N) {
        ans++;
        return;
    }
    for(int i=0;i<N;i++){
        g[depth]=i;
        if(!isOverapped(depth)){
            bt(depth+1);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    bt(0);
    cout<<ans;
}
/*
비트마스킹으로 푼 풀이도 존재
*/