#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 101
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool visit[MAX][MAX];
int g[MAX][MAX], col, row;
class Pos {
    public:
    int x;
    int y;
    Pos(int x,int y){
        this->x=x;
        this->y=y;
    }
};
int bfs(int a,int b){
    queue<Pos> q;
    q.push(Pos(a,b));
    int area=g[a][b];
    visit[a][b]=1;

    while(!q.empty()){
        Pos cur = q.front();
        int x=cur.x;
        int y=cur.y;
        q.pop();

        fse(0,4,1){
            int nx=x+dx[i];
            int ny=y+dy[i];
            // cout<<nx<<" "<<ny<<endl;
            if(0<=nx&&nx<col && 0<=ny&&ny<row &&!visit[nx][ny] && g[nx][ny]!=0){
                area+=g[nx][ny];
                visit[nx][ny]=1;
                q.push(Pos(nx,ny));
            }
        }
    }
    return area;
}
vector<int> solution(vector<string> maps) {
    vector<int> answer;
    col=maps.size();
    row=maps[0].length();
    fse(0,col,1){
        for(int j(0);j<row;j++){
            int tmp=maps[i].at(j)-'0';
            if(tmp==40) g[i][j]=0;
            else g[i][j]=tmp;
        }
    }
    fse(0,col,1){
        for(int j(0);j<row;j++){
            if(g[i][j]!=0 && !visit[i][j]) {
                int res=bfs(i,j);
                answer.push_back(res);
                cout<<res<<" ";
            }
        }
    }
    sort(answer.begin(),answer.end());
    if(answer.empty()) answer.push_back(-1);
    return answer;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solution({"X591X","X1X5X","X231X", "1XXX1"}); //1,1,27
    cout<<endl;
    //solution({"XXX","XXX","XXX"});// -1
}