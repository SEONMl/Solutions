#include <string>
#include <vector>
#include<queue>
#include<algorithm>
#include<iostream>
#include<set>
#define MAX 300'000
using namespace std;
typedef long long ll;
int N;
long long solution(vector<int> initial, vector<vector<int>> edges) {
    N=initial.size();
    bool visit[MAX]={0};
    vector<int> g[MAX];
    for(auto edge:edges){
        int a=edge[0], b=edge[1];
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    queue<int> q;
    vector<ll> weight;
    set<int> idx;
    for(int i(0);i<N;i++){
        weight.push_back(initial[i]);
        if(g[i].size()==1){ //말단노드
            q.push(i);
            idx.insert(i);
        }
    }
    
    ll answer = 0;
    while(!q.empty()){
        int cur= q.front();
        visit[cur]=true;
        q.pop();
        for(int next:g[cur]){
            if(visit[next]) continue;
            
            weight[next]+=weight[cur];
            answer+=abs(weight[cur]);
            
            weight[cur]=0;
            if(idx.find(next)==idx.end()){
                idx.insert(next);
                q.push(next);
            }
            idx.erase(cur);
        }
    }
    for(auto w:weight){
        cout<<w<<" ";
        if(w==0) continue;
        answer=-1;
        break;
    }
    return answer;
}