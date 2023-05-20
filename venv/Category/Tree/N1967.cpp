#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 10'001
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
vector<pair<int,int>> g[MAX]; // 자식 번호, 가중치
int res;
bool visit[MAX];
void dfs(int curnode,int weight){
    res=max(res, weight);
    for(auto next: g[curnode]){
        int tmp=next.first;
        if(visit[tmp]) continue;
        visit[tmp]=true;
        dfs(tmp, weight+next.second);
        visit[tmp]=false;
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin>>N;
    fse(0,N-1,1){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    // 자식 노드 두개면 끝까지 들어가봄
    for(int i(1);i<=N;i++){
        if(g[i].size()==1){
            visit[i]=true;
            dfs(i, 0);
            visit[i]=false;
        }
    }
    cout<<res;
}