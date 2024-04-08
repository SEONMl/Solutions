#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<queue>
#define MAX 50002
#define INF 99999999

using namespace std;
vector<pair<int,int>> g[MAX];
bool isSummit[MAX];
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    for(auto path: paths){
        int i=path[0], j=path[1], k=path[2];
        g[i].push_back({k,j});
        g[j].push_back({k,i});
    }
    for(int su: summits){
        isSummit[su]=true;
    }
    
    int visit[MAX];
    fill_n(visit, MAX, INF);
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(auto gate:gates){
        pq.push({0, gate});
        visit[gate]=0;
    }
    
    while(!pq.empty()){
        int w = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if(visit[node] != w) continue; //??
        for(auto next: g[node]){
            int nextW = next.first;
            int nextNode = next.second;
            
            if(visit[nextNode] <= max(visit[node], nextW)) continue; // 뻘짓..
            visit[nextNode] = max(visit[node], nextW);
            
            
            if(!isSummit[nextNode]) pq.push({visit[nextNode], nextNode});
        }
    }
    
    int answer = summits[0];
    for(auto summit: summits){
        if (visit[answer] > visit[summit]){
            answer=summit;
        } else if(visit[answer]==visit[summit] && answer>summit) answer=summit;
    }
    
    return vector<int>({answer, visit[answer]});
}