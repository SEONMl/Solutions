#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N,M,K;
int dx[]={-1,1,0,0}; 
int dy[]={0,0,1,-1};
class Shark{
    public:
    int x; int y; int speed; int dir; int size;
    Shark(int x,int y,int s,int d,int z){
        this->x=x; this->y=y; this->speed=s; this->dir=d; this->size=z;
    }
    int getSize(){
        return this->size;
    }
    Shark move(){
        int count=(dir==0||dir==1)? speed%(2*N-2) : speed%(2*M-2);
        int d=this->dir;

        while(count--){
            int nx=x+dx[d];
            int ny=y+dy[d];
            if(0<=nx&&nx<N&&0<=ny&&ny<M){
                x=nx; y=ny;
            }else{
                d=(d==0||d==2)? d+1 : d-1;
                x+=dx[d];
                y+=dy[d];
            }
        }
        return Shark(x,y,speed,d,size);
    }
};
vector<Shark> g[MAX][MAX];
int fishing(int col){
    int result=0;
    for(int i(0);i<N;i++){
        if(g[i][col].size()==0) continue;
        result=g[i][col][0].getSize();        
        g[i][col].clear();
        break;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>M>>K;
    fse(0,K,1){
        int x,y,speed,dir,size;
        cin>>x>>y>>speed>>dir>>size;
        g[x-1][y-1].push_back(Shark(x-1,y-1,speed, dir-1, size));
    }
    int answer=0;
    fse(0,M,1){ // 오른쪽으로 이동
        // 상어 잡기
        answer+=fishing(i);

        // 상어 이동
        vector<Shark> moved;
        for(int i(0);i<N;i++){
            for(int j(0);j<M;j++){
                if(g[i][j].size()==0) continue;
                moved.push_back(g[i][j][0].move());
                g[i][j].clear();
            }
        }

        for(auto each:moved){
            int x=each.x, y=each.y;
            if(g[x][y].size()==0){
                g[x][y].push_back(each);
            }else{
                if(g[x][y][0].getSize()<each.getSize()){ // 중복되는 상어 제거
                    g[x][y].clear();
                    g[x][y].push_back(each);
                }
            }
        }
    }
    cout<<answer;
}