#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#define MAX 50'001
#define INF 99999999
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N,M;
vector<pair<int,int>> g[MAX];
int visit[MAX];
void dijkstra(){
    priority_queue<pair<int,int>> heap;
    heap.push({0,1});

    while(!heap.empty()){
        int curW=-heap.top().first;
        int curNode=heap.top().second;
        heap.pop();

        for(auto road:g[curNode]){
            int nextW=road.first;
            int nextNode=road.second;
            int tmp=nextW+curW;

            if(visit[nextNode]>tmp) {
                visit[nextNode]=tmp;
                heap.push({-tmp,nextNode});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>M;
    int a,b,c;
    fse(0,N+1,1){
        visit[i]=INF;
    }
    fse(0,M,1){
        cin>>a>>b>>c;
        g[a].push_back({c,b});
        g[b].push_back({c,a});
    }
    dijkstra();
    cout<<visit[N];
}