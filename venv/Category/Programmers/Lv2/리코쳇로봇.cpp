#include <string>
#include <vector>
#include<queue>
#include<tuple>
#define MAX 100
#define INF 999999999
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int N,M;
int visit[MAX][MAX];
pair<int,int> slide(vector<string> g, pair<int,int> cur, int idx){
    int x=cur.first, y=cur.second;
    while((0<=x&&x<N&&0<=y&&y<M && g[x][y]!='D')){
        x+=dx[idx]; y+=dy[idx];
    }
    return {x-dx[idx], y-dy[idx]};
}
void bfs(vector<string> board, pair<int,int> start){
    int a=start.first, b=start.second;
    queue<pair<int,int>> q;
    q.push({a,b});
    visit[a][b]=0;
    
    while(!q.empty()) {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        for(int i(0);i<4;i++){
            auto next=slide(board, {x,y}, i);
            int nx=next.first, ny= next.second;
            if(visit[nx][ny]!=INF) continue;
            visit[nx][ny]=visit[x][y]+1;
            q.push({nx,ny});
        }
    }
}
int solution(vector<string> board) {
    N=board.size();
    M=board[0].length();
    pair<int,int> start,end;
    for(int i(0);i<N;i++){
        for(int j(0);j<M;j++){
            if(board[i][j]=='R') start={i,j};
            if(board[i][j]=='G') end={i,j};
            visit[i][j]=INF;
        }
    }
    bfs(board, start);
    
    return (visit[end.first][end.second]==INF)? -1:visit[end.first][end.second];
}