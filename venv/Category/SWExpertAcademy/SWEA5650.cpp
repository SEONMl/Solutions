
#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 100
#define fse(A,B,C) for(int i(A);i<B;i+=C)
using namespace std;
vector<pair<int,int>> wormhole[5];
int N;

int encountBlock(int idx, int curDir){
    int block[6][4]={
        {0,0,0,0},
        {2,3,1,0},
        {1,3,0,2},
        {3,2,0,1},
        {2,0,3,1},
        {2,3,0,1}
    };
    return block[idx][curDir];
}
int encountWall(int curDir){
    return (curDir+2)%4;
}
pair<int,int> encountWormhole(pair<int,int> pos, int idx){
    auto hole=wormhole[idx][0];
    if(hole.first==pos.first && hole.second==pos.second){
        return wormhole[idx][1];
    }
    return wormhole[idx][0];
}
int gameStart(int a,int b, int dir, int g[][MAX]){
    int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};
    int x=a,y=b;
    int score=0;
    while(1){
        int nx=x+dx[dir], ny=y+dy[dir];
        if(0>nx||nx>=N||0>ny||ny>=N){ //벽
            score++;
            dir=encountWall(dir);
            nx=x; ny=y;
        }
        if(g[nx][ny]>=6 && g[nx][ny]<=10){ // 웜홀
            int idx=g[nx][ny]-6;
            auto next= encountWormhole({nx,ny}, idx);
            x=next.first; y=next.second;
            continue;
        }
        if(g[nx][ny]>=1 && g[nx][ny]<=5){ // 블록 만남
            score++;
            dir=encountBlock(g[nx][ny], dir);
        }
        if(g[nx][ny]==-1 || (nx==a&&ny==b)){ // 블랙홀 || 시작자리
            break;
        }
        x=nx; y=ny;
    }
    return score;
}
void init(){
    fse(0,5,1) wormhole[i].clear();
}
int main(int argc, char** argv)
{
	int test_case;
	int T;

	freopen("input.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
        init();
        int g[MAX][MAX]={0};
        cin>>N;
        for(int i(0);i<N;i++){
            for(int j(0);j<N;j++){
                cin>>g[i][j];
                if(6<=g[i][j] && g[i][j]<=10) wormhole[g[i][j]-6].push_back({i,j});
            }
        }
        int answer=0;
        for(int i(0);i<N;i++){
            for(int j(0);j<N;j++){
                if(g[i][j]!=0) continue;
                for(int k(0);k<4;k++){
                    answer=max(answer, gameStart(i,j,k, g));
                }
            }
        }
        cout<<"#"<<test_case<<" "<<answer<<"\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}