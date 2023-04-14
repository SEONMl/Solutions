#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 4
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,-1,-1,-1,0,1,1,1};
class Fish{
    public:
    int x;int y;int num;int dir; bool eaten;
    Fish(){}
    Fish(int x,int y,int n,int d){
        this->x=x; this->y=y; this->num=n; this->dir=d; eaten=false;
    }
    int getNumber(){
        return num+1;
    }
    void rotate(){
        dir=(dir+1)%8;
    }
    pair<int,int> nextPos(){
        return {x+dx[dir], y+dy[dir]};
    }
    void setPos(int a,int b){
        x=a; y=b;
    }
    void eatenByShark(){
        eaten=true;
    }
    void survive(){
        eaten=false;
    }
};
int answer=0;
vector<int> fishMoving(int num, pair<int,int> shark, vector<Fish> fish){
    auto target=fish[num];
    fse(0,8,1){
        auto next=target.nextPos();
        int nx=next.first, ny=next.second;
        if(0<=nx&&nx<MAX&&0<=ny&&ny<MAX && !(shark.first==nx && shark.second==ny)){
            return {nx,ny,target.dir};
        }
        target.rotate();
    }
    return {target.x, target.y, target.dir};
}

void dfs(pair<int,int> shark,int dir,int ate, vector<vector<int>> g,vector<Fish> fish){
    answer=max(answer, ate);
    // 번호 작은 순 , 물고기 이동, 죽은 물고기 이동 X, 
    fse(0,MAX*MAX,1){
        if(fish[i].eaten) continue;
        int x=fish[i].x, y=fish[i].y;
        auto next =fishMoving(i, shark,fish);
        int nx=next[0], ny=next[1];
        fish[i].dir=next[2];

        int swap=g[nx][ny]; // 바뀔 자리 빈칸||물고기
        g[nx][ny]=i;
        g[x][y]=swap;

        fish[i].setPos(nx,ny);
        if(swap!=-1) fish[swap].setPos(x,y);

    }

    // 상어 이동
    int x=shark.first, y=shark.second;
    for(int i(1);i<=MAX;i++){
        int nx=x+dx[dir]*i, ny=y+dy[dir]*i;
        if(0<=nx&&nx<MAX&&0<=ny&&ny<MAX && g[nx][ny]!=-1){
            int tmp=g[nx][ny];
            g[nx][ny]=-1;
            fish[tmp].eatenByShark();

            int nextDir=fish[tmp].dir;
            int number= fish[tmp].getNumber();
            dfs({nx,ny}, nextDir, ate+number, g,fish);

            g[nx][ny]=tmp;
            fish[tmp].survive();
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector<vector<int>> g;
    vector<Fish> fishes(16);

    for(int i(0);i<4;i++){
        vector<int> v;
        for(int j(0);j<4;j++){
            int a,b;
            cin>>a>>b;
            v.push_back(a-1);
            fishes[a-1]=Fish(i,j, a-1, b-1);
        }
        g.push_back(v);
    }
    int first=g[0][0];
    int sharkDir=fishes[first].dir;
    fishes[first].eatenByShark();
    g[0][0]=-1; // 빈칸

    dfs({0,0},sharkDir ,fishes[first].getNumber() , g, fishes);
    cout<<answer;
}