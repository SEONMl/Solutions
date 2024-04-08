#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> g[17];
bool visit[17][17];
vector<int> animal;
int answer;
void dfs(vector<int> &info, int cur){
    answer=max(answer, animal[0]);
    if (animal[0]<=animal[1]){
        return;
    }
    
    for(int next:g[cur]){
        if(visit[next][animal[0]]) continue;
        
        if(info[next]!=-1){
            int target=info[next];
            info[next]=-1;
            animal[target]++;
            visit[next][animal[0]]=true;
            dfs(info, next);
            visit[next][animal[0]]=false;
            animal[target]--;
            info[next]=target;
        }else{
            visit[next][animal[0]]=true;
            dfs(info, next);
            visit[next][animal[0]]=false;
        }
    }
}
int solution(vector<int> info, vector<vector<int>> edges) {
    for(auto edge: edges){
        int a=edge[0], b=edge[1];
        g[a].push_back(b);
        g[b].push_back(a);
    }
    animal={1,0};
    info[0]=-1;
    visit[0][1]=true;
    dfs(info, 0);
    
    return answer;
}