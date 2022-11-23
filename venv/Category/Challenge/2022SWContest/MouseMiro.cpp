#include<iostream>
#include<string.h>
#include<tuple>
#include<queue>
#include<vector>
#define MAX 1000
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int R,C;
char g[MAX][MAX];
bool visit[MAX][MAX];
pair<int,int> src;
pair<int,int> dst;
vector<pair<int,int>> bfs(int a,int b){
    visit[a][b]=1;
    queue<tuple<int,int,vector<pair<int,int>>>> q;
    vector<pair<int,int>> past;
    q.push(make_tuple(a,b,past));
    while(!q.empty()){
        int x=get<0>(q.front());
        int y=get<1>(q.front());
        vector<pair<int,int>> tmpPast=get<2>(q.front());
        if(g[x][y]=='D') {
            past=tmpPast;
            past.pop_back();
            break;
        }
        q.pop();

        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(0>nx) nx=R-1;
            if(nx>=R) nx=0;
            if(0>ny) ny=C-1;
            if(ny>=C) ny=0;

            if(g[nx][ny]!='#' && !visit[nx][ny]){
                tmpPast.push_back(make_pair(nx,ny));
                visit[nx][ny]=1;
                q.push(make_tuple(nx,ny,tmpPast));
                tmpPast.pop_back();
            }
        }
    }
    return past;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>R>>C;
    for(int i=0;i<R;i++){
        cin>>g[i];
        for(int j=0;j<C;j++){
            if(g[i][j]=='M')src=make_pair(i,j);
            if(g[i][j]=='D')dst=make_pair(i,j);
        }
    }
    vector<pair<int,int>> result=bfs(src.first,src.second);
    if(result.size()==0){
        cout<<"NO";
    }else{
        cout<<"YES"<<'\n';
        for(auto p:result){
            g[p.first][p.second]='x';
        }
        for(int i=0;i<R;i++){
            cout<<g[i];
            cout<<'\n';
        }
    }
}