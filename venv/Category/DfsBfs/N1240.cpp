#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define MAX 1001
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N,M;
vector<pair<int,int>> node[MAX];
int bfs(int start,int end){
    queue<pair<int,int>> q;
    bool visit[MAX]={0};
    q.push({start,0});
    visit[start]=true;
    while(!q.empty()){
        int cur=q.front().first;
        int weight=q.front().second;
        q.pop();
        if(cur==end){
            return weight;
        }
        for(auto next:node[cur]){
            if(visit[next.first]) continue;
            visit[next.first]=1;
            q.push({next.first, weight+next.second});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>M;
    fse(0,N-1,1) {
        int s,e,w;
        cin>>s>>e>>w;
        node[s].push_back({e,w});
        node[e].push_back({s,w});
    }
    fse(0,M,1){
        int s,e;
        cin>>s>>e;
        cout<<bfs(s,e)<<'\n';
    }
}