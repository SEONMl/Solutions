#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>
#define MAX 101
#define INF 99999999
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N,M;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
string g[MAX];
int bfs(pair<int,int> start, pair<int,int> end){
    int a=start.first,b=start.second, c=end.first,d=end.second;
    queue<tuple<int,int,int>> q;
    q.push({a,b,4});
    int visit[MAX][MAX][5];
    for(int i(0);i<N;i++){
        for(int j(0);j<M;j++){
            for(int k(0);k<4;k++){
                visit[i][j][k]=INF;
            }
        }
    }
    visit[a][b][0]=0;
    visit[a][b][1]=0;
    visit[a][b][2]=0;
    visit[a][b][3]=0;
    while(!q.empty()){
        int x=get<0>(q.front());
        int y=get<1>(q.front());
        int dir=get<2>(q.front());
        q.pop();

        for(int i(0);i<4;i++){
            int nx=x+dx[i], ny=y+dy[i];
            int tmp=(dir==i)? 0:1;
            if(0<=nx&&nx<N&&0<=ny&&ny<M && g[nx][ny]!='*' && visit[nx][ny][i]>visit[x][y][dir]+tmp){
                q.push({nx,ny,i});
                visit[nx][ny][i]=visit[x][y][dir]+tmp;
            }
        }
    }

    return *min_element(visit[c][d], visit[c][d]+4)-1;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>M>>N;
    vector<pair<int,int>> cpos;
    fse(0,N,1){
        cin>>g[i];
        for(int j(0);j<M;j++){
            if(g[i][j]=='C'){
                cpos.push_back({i,j});
            }
        }
    }
    cout<<bfs(cpos[0], cpos[1]);
}