#include <string>
#include <vector>
#include<queue>
#include<tuple>
#define SIZE 5

using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

bool bfs(vector<string> g,int a,int b){
    queue<tuple<int,int,int>> q;
    q.push({a,b,0});
    bool visit[SIZE][SIZE]={0};
    visit[a][b]=1;
    while(!q.empty()){
        int x=get<0>(q.front());
        int y=get<1>(q.front());
        int dis=get<2>(q.front());
        q.pop();
        if(dis>2) return true;
        
        for(int i(0);i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(0<=nx&&nx<SIZE && 0<=ny&&ny<SIZE && !visit[nx][ny]&& g[nx][ny]!='X'){
                if(g[nx][ny]=='P' && dis+1<=2) return false;
                
                q.push({nx,ny,dis+1});
                visit[nx][ny]=true;
            }
        }
    }
    return true;
}
bool checkPlace(vector<string> place){
    bool res=true;
    for(int i(0);i<SIZE;i++){
        for(int j(0);j<SIZE;j++){
            if(place[i][j]=='P'){
                res&=bfs(place, i,j);
            }
        }
    }
    return res;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(auto place:places){
        answer.push_back(checkPlace(place));
    }
    return answer;
}