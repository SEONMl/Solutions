#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 11
#define INF 1'099'999'999
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N,arr[MAX];
vector<int> giho(4);// 덧, 뺄, 곱, 나
int maxV=-INF, minV=INF;
int cal(int idx, int cur, int next){
    switch (idx)
    {
    case 0: return cur+next;
    case 1: return cur-next;
    case 2: return cur*next;
    case 3: return cur/next;
    }
}
void dfs(int depth, int cur){
    if(depth==N){
        minV=min(cur, minV);
        maxV=max(cur, maxV);
        return ;
    }
    for(int j(0);j<4;j++){
        if(giho[j]==0) continue;
        int next=cal(j, cur, arr[depth]);
        giho[j]--;
        dfs(depth+1, next);
        giho[j]++;
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    fse(0,N,1) cin>>arr[i];
    fse(0,4,1) cin>>giho[i];
    dfs(1,arr[0]);
    cout<<maxV<<'\n'<<minV;
    
}