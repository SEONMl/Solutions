#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;
int answer,N;
int sheep, wolf;
vector<int> g[17];
vector<int> copyInfo;
bool visit[17];
void dfs(int cur){
    if(sheep>wolf){
        answer=max(answer, sheep);
    }
    if(sheep+wolf == N || wolf>=sheep){
        return;
    }
    for(int next: g[cur]){
        if(visit[next]) dfs(next);
        else{
            if(copyInfo[next]==1) wolf++;
            else sheep++;
            visit[next]=true;
            dfs(next);
            if(copyInfo[next]==1) wolf--;
            else sheep--;
            visit[next]=false;
        }
    }
}
int solution(vector<int> info, vector<vector<int>> edges) {
    // 0양, 1늑대
    N=info.size();
    copyInfo=info;
    for(auto edge:edges){
        int a=edge[0], b=edge[1];
        g[a].push_back(b);
        // g[b].push_back(a);
    }

    sheep=1;
    visit[0]=1;
    dfs(0);
    return answer;
}