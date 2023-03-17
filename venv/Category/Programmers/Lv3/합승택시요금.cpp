#include <string>
#include <vector>
#include<queue>
#define MAX 201
#define INF 200'000'000

using namespace std;
typedef long long ll;
vector<pair<int,int>> g[MAX];
int djikstra(int start,int end){
    queue<pair<int,int>> q;
    q.push({start,0});
    int visit[MAX];
    for(int i(0);i<MAX;i++) visit[i]=INF;
    visit[start]=0;
    
    while(!q.empty()){
        int curNode=q.front().first;
        int curW=q.front().second;
        q.pop();
        for(auto next:g[curNode]){
            int nNode=next.first;
            int nW=next.second;
            int tmp=curW+nW;
            if(visit[nNode]>tmp){
                visit[nNode]=tmp;
                q.push({nNode,tmp});
            }
        }
    }
    return visit[end];
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;

    for(auto f:fares){
        int s=f[0],e=f[1],fee=f[2];
        g[s].push_back({e,fee});
        g[e].push_back({s,fee});
    }
    
    for(int c(1);c<=n;c++){
        int sToc=djikstra(s,c);
        int cToa=djikstra(c,a);
        int cTob=djikstra(c,b);
        answer=min(answer,sToc+cToa+cTob);
    }
    return answer;
}

/*
위 다익스트라(TLE, 완탐, 단일 출발점 최단경로)

아래 플로이드와샬(모든 정점쌍 최단경로)
*/

int arr[MAX][MAX];

void floyd(int n){
    for(int i(1);i<=n;i++){
        for (int j(1);j<=n;j++){
            if(i==j) arr[i][j]=0;
            else arr[i][j]=INF;
            for(auto tmp:g[i]){
                int node=tmp.first;
                int wei=tmp.second;
                if(node==j) arr[i][j]=wei;
            }
        }
    }
    for(int i(1);i<=n;i++){
        for (int j(1);j<=n;j++){
            for(int k(1);k<=n;k++){
                arr[j][k]=min(arr[j][k],arr[j][i]+arr[i][k]);
            }
        }
    }
}
int solution2(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    
    for(auto f:fares){
        int s=f[0],e=f[1],fee=f[2];
        g[s].push_back({e,fee});
        g[e].push_back({s,fee});
    }
    floyd(n);
    for(int i(1);i<=n;i++){
        int stoc=arr[s][i];
        int ctoa=arr[i][a];
        int ctob=arr[i][b];
        answer=min(answer,stoc+ctoa+ctob);
    }
    return answer;
}