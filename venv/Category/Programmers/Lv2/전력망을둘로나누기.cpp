#include <string>
#include <vector>
#include <queue>
#define MAX 101
using namespace std;
vector<int> top[MAX];
int bfs(vector<int> deleted){
    bool visit[MAX]={0};
    int a=deleted[0];
    int b=deleted[1];
    queue<int> q;
    q.push(a);
    visit[a]=1;
    int cnt=1;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(auto next:top[cur]){
            if(visit[next] || (cur==a && next==b) || (cur==b&&next==a)) continue;
            visit[next]=true;
            cnt++;
            q.push(next);
        }
    }
    return cnt;
}
int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    for(auto wire:wires){
        int a=wire[0];
        int b=wire[1];
        top[a].push_back(b);
        top[b].push_back(a);
    }
    for(auto wire:wires){
        int tmp_n=bfs(wire);
        answer=min(answer,abs(tmp_n-n+tmp_n));
    }
    return answer;
}