#include <vector>
#include<set>
#include<queue>
#include<algorithm>
#include<memory.h>

using namespace std;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
bool visit[101][101];
int bfs(vector<vector<int>> g,int a,int b,int N,int M){
    int dx[]={0,1,0,-1};
    int dy[]={1,0,-1,0};
    queue<pair<int,int>> q;
    q.push({a,b});
    visit[a][b]=true;
    int cnt=1;
    
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        for(int i(0);i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(0<=nx&&nx<N&&0<=ny&&ny<M && !visit[nx][ny] && g[nx][ny]==g[a][b]){
                q.push({nx,ny});
                visit[nx][ny]=true;
                cnt++;
            }
        }
    }
    return cnt;
}
vector<int> solution(int N, int M, vector<vector<int>> g) {
    vector<int> answer(2);

    set<int> s;
    memset(visit,false,101*101);
    
    for(int i(0);i<N;i++){
        for(int j(0);j<M;j++){
            s.insert(g[i][j]);
            if(g[i][j]!=0 && !visit[i][j]) answer[1]=max(answer[1],bfs(g,i,j,N,M));
        }
    }
    answer[0]=s.size();
    return answer;
}