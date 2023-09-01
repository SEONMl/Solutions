#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#define MAX 10'001
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int V,E, id[MAX],idx=1;
bool already[MAX];
vector<int> g[MAX];
vector<int> stk;
vector<set<int>> answer;
int dfs(int cur){
    stk.push_back(cur);
    int remember=idx;
    id[cur]=idx++;
    
    for(auto next: g[cur]){
        // 아직 방문하지 않은 노드
        if(id[next]==0) remember=min(remember,dfs(next));

        // 방문한 노드지만 scc가 아닌 노드
        if(!already[next]) remember=min(remember, id[next]);
    }

    if(remember==id[cur]){
        set<int> scc;
        while(1){
            int top=stk.back();
            stk.pop_back();
            scc.insert(top);
            id[top]=remember;
            already[top]=true;
            if(top==cur) break;
        }
        answer.push_back(scc);
    }
    return remember;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>V>>E;
    fse(0,E,1){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }

    for(int i(1);i<V+1;i++){
        if(id[i]) continue;
        dfs(i);
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