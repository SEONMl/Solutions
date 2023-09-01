#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<memory.h>
#define MAX 10'001
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int V,E;
vector<int> g[MAX], rev[MAX];
vector<int> list;
bool visit[MAX];
void dfs(int cur){
    if(visit[cur]) return;
    visit[cur]=true;
    for(auto next:g[cur]){
        dfs(next);
    }
    list.push_back(cur);
}
void dfs2(int cur, set<int> &res){
    res.insert(cur);
    visit[cur]=true;
    for(auto next:rev[cur]){
        if(visit[next]) continue;
        res.insert(next);
        dfs2(next,res);
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>V>>E;
    fse(0,E,1){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        rev[b].push_back(a);
    }

    for(int i(1);i<=V;i++){
        if(visit[i]) continue;
        dfs(i);
    }

    memset(visit, false, sizeof(bool)*MAX);

    vector<set<int>> answer;
    for(int i(V-1);i>=0;i--){
        if(visit[list[i]]) continue;
        set<int> res={list[i]};
        dfs2(list[i], res);
        answer.push_back(res);
    }

    cout<<answer.size()<<'\n';
    sort(answer.begin(), answer.end());
    for(auto a:answer){
        for(auto n:a){
            cout<<n<<" ";
        }
        cout<<"-1\n";
    }
}