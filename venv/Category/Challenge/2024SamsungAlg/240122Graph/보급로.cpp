#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<queue>
#define MAX 100
#define INF 987654321
#define fse(A,B,C) for(int i=A;i<B;i+=C) 
using namespace std;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int g[MAX][MAX];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int test_case, T;

	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N;
        cin>>N;

        fse(0,N,1){
            string s;
            cin>>s;
            for(int j(0);j<N;j++){
                g[i][j]=s[j]-'0';
            }
        }

        queue<pair<int,int>> q;
        q.push({0,0});

        int visit[MAX][MAX];
        fse(0,N,1){
            fill_n(visit[i],N,INF);
        }
        visit[0][0]=0;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            for(int i(0);i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(0<=nx&&nx<N&&0<=ny&&ny<N && visit[x][y]+g[nx][ny]<visit[nx][ny]){
                    q.push({nx,ny});
                    visit[nx][ny]=visit[x][y]+g[nx][ny];
                }
            }
        }

        cout<<"#"<<test_case<<" "<<visit[N-1][N-1]<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}