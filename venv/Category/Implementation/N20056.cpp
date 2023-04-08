#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define MAX 51
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N,M,K;
int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,1,1,1,0,-1,-1,-1};
int nextDir[][4]={{0,2,4,6}, {1,3,5,7}};
class FireBall{
    public:
    int r,c,m,s,d;
    FireBall(int r,int c,int m,int s,int d){
        this->r=r; this->c=c; this->m=m; this->s=s; this->d=d;
    }
    FireBall(int m,int s,int d){
        this->m=m; this->s=s; this->d=d;
    }
    pair<int,int> nextPos(){
        int nx=this->r + dx[d]*s;
        int ny=this->c + dy[d]*s;
        return {nx,ny};
    }
};
vector<FireBall> g[MAX][MAX]; 
void move(FireBall& fireball){
    auto next=fireball.nextPos();
    int nx=next.first, ny=next.second;
    if(1<=nx&&nx<=N&&1<=ny&&ny<=N) {
        g[nx][ny].push_back(fireball);
    }
}
void mergeAndDivide(pair<int,int> pos) {
    int x=pos.first, y=pos.second;
    int totalM=0;
    int totalS=0;
    bool odd=true, even=true;
    int cnt=0;
    for(auto fireball:g[x][y]){
        cnt++;
        totalM+=fireball.m;
        totalS+=fireball.s;
        odd&=(fireball.d % 2==1);
        even&=(fireball.d % 2==0);
    }
    g[x][y].clear();

    int nextM= totalM/5;
    if(nextM==0){
        return;
    }

    int nextS= totalS/cnt;
    int divideDir = (odd||even)? 1:0;
    
    for(int i(0);i<4;i++){
        int j=nextDir[divideDir][i];
        g[x][y].push_back(FireBall(nextM, nextS, j));
    }
    
}
void afterMove(){
    for(int i(1);i<=N;i++){
        for(int j(1);j<=N;j++){
            if(g[i][j].size()>=2){
                mergeAndDivide({i,j});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int r,c,m,s,d;
    cin>>N>>M>>K;
    fse(0,M,1){
        cin>>r>>c>>m>>s>>d;
        g[r][c].push_back(FireBall(m,s,d));
    }
    while(K--){
        // 이동
        for(int i(1);i<=N;i++){
            for(int j(1);j<=N;j++){
                for(auto fire: g[i][j]){
                    move(fire);
                }
            }
        }
        
        // 합쳐지고 분리되는 연산
        afterMove();
    }

    // 질량 계산
    int answer=0;
    for(int i(1);i<=N;i++){
        for(int j(1);j<=N;j++){
            for(auto fire: g[i][j]){
                answer+=fire.m;
            }
        }
    }
    cout<<answer;
}