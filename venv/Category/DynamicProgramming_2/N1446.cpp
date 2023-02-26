#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#define MAX 10'001
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N,D;
vector<pair<int,int>> short_road[MAX];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>D;
    int s,e,w;
    fse(0,N,1){
        cin>>s>>e>>w;
        if(e-s<w) continue;
        short_road[e].push_back({s,w});
    }
    int dp[MAX];
    dp[0]=0;
    for(int i=1;i<=D;i++){
        dp[i]=dp[i-1]+1;
        for(auto road:short_road[i]){
            dp[i]=min(dp[i], dp[road.first]+road.second);
        }
    }
    cout<<dp[D];
}