#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define INF 999999999
#define MAX 50
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
vector<pair<int,int>> home;
int dx[]={-1,-1,-1, 0,0, 1,1,1};
int dy[]={-1,0,1, -1,1, -1,0,1};
int godo[MAX][MAX];
int N, answer = INF;
bool visit[MAX*MAX];
class Pos{
    public:
    int x; int y; int min; int max;
    Pos(int x,int y,int mn,int mx){
        this->x=x; this->y=y; this->min=mn, this->max=mx;
    }
    bool isDst(pair<int,int> p){
        return (p.first==x && p.second==y);
    }
};
pair<int,int> bfs(pair<int,int> src,pair<int,int> dst){
    queue<Pos> q;
    q.push(Pos(src.first, src.second, INF, -INF));

    bool visit[MAX][MAX]={0};
    visit[src.first][src.second]=true;
    pair<int,int> result={INF, -INF}; //최소 최대
    while(!q.empty()){
        auto top=q.front();
        q.pop();
        if(top.isDst(dst)) {
            result.first= min(result.first, top.min);
            result.second= max(result.second, top.max);
            continue;
        }

        for(int i(0);i<8;i++){
            int nx=top.x + dx[i];
            int ny=top.y+dy[i];
            if(0<=nx&&nx<N&&0<=ny&&ny<N && !visit[nx][ny]){
                visit[nx][ny]=true;
                q.push(Pos(nx,ny, min(top.min, godo[nx][ny]), max(top.max, godo[nx][ny])));
            }
        }
    }

    return result;
}
void dfs(int depth, pair<int,int> src, pair<int,int> cur){
    if(depth==home.size()){
        answer=min(answer, cur.second-cur.first);
        return;
    }
    for(int i(0);i<home.size();i++){
        if(visit[i]) continue;
        visit[i]=true;
        auto next= bfs(src, home[i]);
        cur.first=max(cur.first, next.first);
        cur.second=min(cur.second, next.second);
        dfs(depth+1, home[i], cur);
        visit[i]=false;
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    pair<int,int> person;
    for(int i(0);i<N;i++){
        for(int j(0);j<N;j++){
            char c;
            cin>>c;
            if(c=='P') person={i,j};
            else if(c=='K') home.push_back({i,j});
        }
    }
    for(int i(0);i<N;i++){
        for(int j(0);j<N;j++){
            cin>> godo[i][j];
        }
    }

    dfs(0, person, {INF, -INF});
    cout<<answer;
}