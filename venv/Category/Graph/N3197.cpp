#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 1500
using namespace std;
int R,C;
char lake[MAX][MAX];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
struct Swan{
    int x;
    int y;
    Swan(int a,int b){
        x=a;y=b;
    }
};
void bfs(int a,int b){
    queue<pair<int,int>> q;
    bool visit[MAX][MAX]={};
    q.push({a,b});
    visit[a][b]=1;

    vector<pair<int,int>> next_ice;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(0<=nx&&nx<R&&0<=ny&&ny<C && !visit[nx][ny]){
                if(lake[nx][ny]=='X'){
                    next_ice.push_back({nx,ny});
                }
                if(lake[nx][ny]=='.'){
                    q.push({nx,ny});
                    visit[nx][ny]=1;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>R>>C;
    vector<Swan> swan;
    for(int i(0);i<R;i++){
        cin>>lake[i];
        for(int j(0);j<C;j++){
            if(lake[i][j]=='L'){
                swan.push_back(Swan(i,j));
                lake[i][j]='.';
            }
        }
    }
}