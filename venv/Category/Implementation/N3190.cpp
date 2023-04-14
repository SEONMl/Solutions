#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define MAX 100
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int dx[]={0,1,0,-1}; // 우 하 좌 상
int dy[]={1,0,-1,0};
int g[MAX][MAX];
deque<pair<int,int>> snake; // front 꼬리, back 머리
queue<pair<int,char>> games;
int N;
bool isEnd(pair<int,int> pos){ // 다음 머리 위치
    int x=pos.first, y=pos.second;
    if(0<=x&&x<N&&0<=y&&y<N && g[x][y]!=1){
        return false;
    }
    return true;
}
void ifAppleExistGrowUp(pair<int,int> pos){
    int x=pos.first, y=pos.second;
    snake.push_back(pos);
    if(g[x][y]!=9){
        auto tail=snake.front();
        g[tail.first][tail.second]=0;
        snake.pop_front();
    }
    g[x][y]=1;
}
int rotate(int curDir, char c){
    switch (c)
    {
    case 'L':
        return (curDir+3)%4;
    case 'D':
        return (curDir+1)%4;
    default:
        break;
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    int K,L,x,y;
    char c;
    cin>>K;
    fse(0,K,1){
        cin>>x>>y;
        g[x-1][y-1]=9; // 0 빈칸, 1 자기몸, 9 사과
    }

    int sec=0;
    int curDir=0;
    g[0][0]=1;
    snake.push_back({0,0});
    cin>>L;
    fse(0,L,1){
        cin>>x>>c;
        games.push({x,c});
    }

    while(1){        
        sec++;
        
        // 머리 이동
        auto head=snake.back();
        int nx=head.first+dx[curDir];
        int ny=head.second+dy[curDir];
        // 게임이 끝?
        if(isEnd({nx,ny})){
            break;
        }
        // 사과 유무
        ifAppleExistGrowUp({nx,ny});

        // c방향으로 머리 회전
        if(!games.empty() && games.front().first == sec){
            char cmd = games.front().second;
            curDir=rotate(curDir, cmd);
            games.pop();
        }
    }
    cout<<sec;
}