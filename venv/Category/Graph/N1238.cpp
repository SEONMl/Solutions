#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define MAX 1001
using namespace std;
int N,M,X;
vector<pair<int,int>> graph[MAX];
int result[MAX];
void dijkstra(int start){
    priority_queue<pair<int,int>> q;
    q.push({0,start});

    int dist[MAX];
    for(int i(1);i<N+1;i++){
        dist[i]=1e9;
    }
    dist[start]=0;
    while(!q.empty()){
        int weight= -q.top().first;
        int node= q.top().second;
        q.pop();

        if(dist[node]>weight) continue;

        for(auto next:graph[node]){
            int next_node=next.first;
            int next_weight=next.second;
            if(dist[next_node]>weight+next_weight){
                dist[next_node]=weight+next_weight;
                q.push({-dist[next_node],next_node});
            }
        }
    }
    
    if(start==X){
        for(int i=1;i<N+1;i++){
            result[i]+=dist[i];
        }
    }else{
        result[start]+=dist[X];
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>M>>X;
    for(int i=0;i<M;i++){
        int s,e,t;
        cin>>s>>e>>t;
        graph[s].push_back({e,t});
    }

    for(int i=1;i<N+1;i++){
        dijkstra(i);
    }
    cout<<*max_element(begin(result),end(result));
}