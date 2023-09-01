#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100'001
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N;
vector<pair<int,int>> g[MAX];
bool visit[MAX];
pair<int,int> res;
void dfs(int node, int weight){
    visit[node]=true;
    if(res.second<weight) res={node, weight};
    for(auto next: g[node]){
        int n=next.first, w=next.second;
        if(visit[n]) continue;
        dfs(n, weight+w);
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    fse(0,N,1){
        int node;
        cin>>node;
        while(1){
            int n,w;
            cin>>n;
            if(n==-1) break;
            cin>>w;
            g[node].push_back({n,w});
        }
    }
    dfs(1,0);
    int b=res.first;
    dfs(b, 0);
    cout<<res.second;
}