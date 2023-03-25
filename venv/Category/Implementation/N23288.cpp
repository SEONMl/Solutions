#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define MAX 21
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N,M,g[MAX][MAX];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0}; // 동 0 남 1 서 2 북 3
vector<int> roll(vector<int> dice, int dir){
    vector<int> next;
    switch (dir)
    {
    case 0: // 동
        next={dice[3],dice[1],dice[0],dice[5],dice[4],dice[2]};
        break;
    case 2: // 서
        next={dice[2],dice[1],dice[5],dice[0],dice[4],dice[3]};
        break;
    case 1: // 남
        next={dice[1],dice[5],dice[2],dice[3],dice[0],dice[4]};
        break;
    case 3: // 북
        next={dice[4],dice[0],dice[2],dice[3],dice[5],dice[1]};
        break;    
    default:
        break;
    }
    return next;
}
int compareDiceAndMap(int dice, int map, int dir){ // A, B
    if(dice>map)dir=(dir+1)%4;
    else if(dice<map) dir=(dir+3)%4;
    return dir;
}
bool isInRange(int nx,int ny){
    return (0<=nx&&nx<N&&0<=ny&&ny<M);
}
int calculateScore(pair<int,int> pos){
    int a=pos.first, b=pos.second;
    bool visit[MAX][MAX]={0};
    visit[a][b]=1;
    queue<pair<int,int>> q;
    q.push({a,b});

    int cnt=0;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        cnt++;
        q.pop();
        for(int i(0);i<4;i++){
            int nx=x+dx[i], ny=y+dy[i];
            if(isInRange(nx,ny) && !visit[nx][ny] && g[nx][ny]==g[a][b]){
                q.push({nx,ny});
                visit[nx][ny]=true;
            }
        }
    }
    return cnt*g[a][b];
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int K;
    cin>>N>>M>>K;
    for(int i(0);i<N;i++){
        for(int j(0);j<M;j++){
            cin>>g[i][j];
        }
    }
    int x=0, y=0, curDir=0;

    int answer = 0;
    vector<int> dice={1,2,3,4,5,6};
    fse(0,K,1){
        // 이동방향 정하기
        int nx=x+dx[curDir], ny=y+dy[curDir];
        if(!isInRange(nx,ny)){
            curDir=(curDir+2)%4;
            nx=x+dx[curDir]; ny=y+dy[curDir];
        }
        // 이동
        x=nx; y=ny;
        dice=roll(dice, curDir);
        // 주사위 밑면, 지도 점수 계산
        answer+=calculateScore({x,y});
        curDir=compareDiceAndMap(dice[5], g[x][y], curDir);
    }
    cout<<answer;
}