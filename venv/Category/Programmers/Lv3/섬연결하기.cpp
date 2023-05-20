#include <string>
#include <vector>
#include<iostream>
#include<queue>
using namespace std;

int solution(int N, vector<vector<int>> costs) {
    vector<pair<int,int>> g[100];
    bool visit[100]={0};
    for(auto cost:costs){
        int a=cost[0], b=cost[1], c=cost[2];
        g[a].push_back({-c,b});
        g[b].push_back({-c,a});
    }
    priority_queue<pair<int,int>> pq;
    for(auto k: g[0]){
        pq.push(k);
    }
    int answer=0;
    visit[0]=1;
    while(!pq.empty()){
        auto top=pq.top();
        pq.pop();
        if(!visit[top.second]) {
            answer-=top.first;
            visit[top.second]=1;
        }
        for(auto k:g[top.second]){
            if(visit[k.second]) continue;
            pq.push(k);
        }
    }
    
    return answer;
}