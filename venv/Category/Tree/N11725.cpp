#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100000
using namespace std;
int N;
vector<int> v1[MAX+1];
bool visit[MAX+1];
int ans[MAX+1];
void dfs(int t){
    for(auto child:v1[t]){
        if(!visit[child]){
            visit[child]=1;
            ans[child]=t;
            dfs(child);
        }
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    int p,q;
    for(int i=0;i<N-1;i++){
        cin>>p>>q;
        v1[p].push_back(q);
        v1[q].push_back(p);
    }
    dfs(1);
    for(int i=2;i<N+1;i++){
        cout<<ans[i]<<'\n';
    }
}