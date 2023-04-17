// 머리가 지끈지끈 ^^... 최적화..는 못하겠다
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#define MAX 21
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N,M,W;
int g[MAX][MAX];
vector<vector<int>> machine; // x,y,방향
vector<int> walls[MAX][MAX]; // x,y,방향
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

bool isInRange(int x,int y){
    if(1<=x&&x<=N&&1<=y&&y<=M){
        return true;
    }return false;
}
vector<pair<int,int>> nextPos(pair<int,int> p, int dir){
    int x=p.first, y=p.second;
    switch (dir)
    {
    case 0: return {{x-1,y+1}, {x,y+1}, {x+1,y+1}};
    case 1: return {{x-1,y-1}, {x,y-1}, {x+1,y-1}};
    case 2: return {{x-1,y-1}, {x-1,y}, {x-1,y+1}};
    case 3: return {{x+1,y-1}, {x+1,y}, {x+1,y+1}};
    default:return {};
    }
}
bool canWind(pair<int,int> p,int dir){
    int x=p.first, y=p.second;
    switch (dir)
    {
    case 0:
        for(auto wall:walls[x][y-1]){
            if(wall==2) return false;
        }
        return true;
    case 1:
        for(auto wall:walls[x][y]){
            if(wall==2) return false;
        }
        return true;
    case 2: 
        for(auto wall:walls[x+1][y]){
            if(wall==1) return false;
        }
        return true;
    case 3:
        for(auto wall:walls[x][y]){
            if(wall==1) return false;
        }
        return true;
    default:
        return true;
    }
}

void machineOn(pair<int,int> pos, int dir){
    int x=pos.first, y=pos.second;
    set<pair<int,int>> temp[6]; // 퍼질 온도
    temp[5].insert({x+dx[dir], y+dy[dir]});

    for(int i(4);i>0;i--){
        for(auto prev: temp[i+1]){
            auto next= nextPos(prev, dir);
            for(int j(0);j<3;j++){
                if(isInRange(next[j].first, next[j].second)&&canWind(next[j], dir)){
                    if(j==0){
                        if(dir<=1&& canWind({next[j].first, prev.second},2)){
                            temp[i].insert(next[j]);
                        }
                        if(dir>=2&& canWind({prev.first, next[j].second},1) ){
                            temp[i].insert(next[j]);
                        }
                    }
                    if(j==1) temp[i].insert(next[j]);

                    if(j==2){
                        if(dir<=1 && canWind({next[j].first, prev.second},3)){
                            temp[i].insert(next[j]);
                        }
                        if(dir>=2 && canWind({prev.first, next[j].second},0)){
                            temp[i].insert(next[j]);
                        }
                    }
                }   
            }
        }
    }
    for(int i(1);i<=5;i++){
        for(auto pos:temp[i]){
            g[pos.first][pos.second]+=i;
        }
    }
}
void getTempDiff(int tmp[][MAX], int x,int y,int nx,int ny,int dir){
    int diff=abs(g[x][y]-g[nx][ny])/4;
    if(diff==0) return;
    
    if(g[x][y]<g[nx][ny]){
        tmp[x][y]+=diff;
        tmp[nx][ny]-=diff;
    }else{
        tmp[x][y]-=diff;
        tmp[nx][ny]+=diff;
    }
}

void divideTemp(){
    int tmp[MAX][MAX]={0};
    int n[]={0,3};
    for(int i(1);i<=N;i++){
        for(int j(1);j<=M;j++){
            for(int k(0);k<2;k++){
                int nx=i+dx[n[k]], ny=j+dy[n[k]];
                if(!isInRange(nx,ny) || !canWind({nx,ny},n[k])) continue;
                getTempDiff(tmp, i,j,nx,ny, n[k]);
            }
        }
    }
    for(int i(1);i<=N;i++){
        for(int j(1);j<=M;j++){
            g[i][j]+=tmp[i][j];
        }
    }
}

void externalTempDown(){
    for(int i(1);i<=N;i++){
        if(g[i][1]>0)g[i][1]--;
        if(g[i][M]>0)g[i][M]--;
    }
    for(int i=2;i<M;i++){
        if(g[1][i]>0)g[1][i]--;
        if(g[N][i]>0)g[N][i]--;
    }
}
bool isEnd(vector<pair<int,int>> josa, int k){
    for(auto j:josa){
        if(g[j.first][j.second]<k) return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int K,tmp;
    vector<pair<int,int>> josa;
    cin>>N>>M>>K;
    for(int i(1);i<=N;i++){
        for(int j(1);j<=M;j++){
            cin>>tmp;
            if(tmp>=1 && tmp<=4) machine.push_back({i,j,tmp-1});
            if(tmp==5) josa.push_back({i,j});
        }
    }
    int W;
    cin>>W;
    fse(0,W,1){
        int x,y,d;
        cin>>x>>y>>d;
        walls[x][y].push_back(d+1);
    }

    int choco=0;
    int t=1;
    while(1){
        //  온풍기 가동
        for(auto mch:machine){
            int x=mch[0], y=mch[1], dir=mch[2];
            machineOn({x,y}, dir);
        }
        // 온도조절
        divideTemp();

        // 바깥 온도 1감소
        externalTempDown();

        // 초콜렛
        choco++;
        if(choco>=101){
            break;
        }
        // 조사 K 이상?
        if(isEnd(josa, K)) break;
    }
    cout<<choco;
}