#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
#define MAX 16
#define INF 99999999
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N;
int weight[MAX][MAX];
int dp[MAX][(1<<MAX)];
int dfs(int node,int bit){
    if(dp[node][bit]!=0) return dp[node][bit];
    if(bit == ((1<<N)-1)){
        return (weight[node][0])? weight[node][0]: INF;
    }
    
    int tmp=INF;
    for(int i(0);i<N;i++){
        if(!weight[node][i]) continue;
        if(bit&(1<<i)) continue;
        tmp=min(tmp, dfs(i, bit|(1<<i))+weight[node][i]);
    }
    dp[node][bit]=tmp;
    return tmp;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    for(int i(0);i<N;i++){
        for(int j(0);j<N;j++){
            cin>>weight[i][j];
        }
    }
    cout<<dfs(0,1);
}