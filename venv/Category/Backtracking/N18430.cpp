#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 6
using namespace std;
int N,M;
int a[MAX][MAX];
bool visit[MAX][MAX];
int dx[4][2]={{0,1},{-1,0},{-1,0},{1,0}};
int dy[4][2]={{1,0},{0,1},{0,-1},{0,-1}};
int ans;
void bt(int p,int q,int power){
    if(q==M){
        q=0;
        p++;
    }
    if(p==N) {
        ans=max(ans,power);
        return;
    }
    
    if(!visit[p][q]){
        for(int i=0;i<4;i++){
            int nx1=p+dx[i][0];
            int ny1=q+dy[i][0];
            int nx2=p+dx[i][1];
            int ny2=q+dy[i][1];
            if(0<=nx1&&nx1<N&&0<=nx2&&nx2<N&&\
                0<=ny1&&ny1<M&&0<=ny2&&ny2<M&&\
                !visit[nx1][ny1] && !visit[nx2][ny2])
            {
                visit[p][q]=1;
                visit[nx1][ny1]=1;
                visit[nx2][ny2]=1;
                int tmp=a[p][q]*2+a[nx1][ny1]+a[nx2][ny2];
                bt(p,q+1,power+tmp);
                visit[p][q]=0;
                visit[nx1][ny1]=0;
                visit[nx2][ny2]=0;
            }
        }
    }   
    bt(p,q+1,power); // 부메랑을 만들지 않고 넘기기
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>a[i][j];
        }
    }
    bt(0,0,0);
    cout<<ans;
}

/*
3 2
7 5 4
3 2 9
46

3 3
1 2 3
4 5 6
7 8 9
52?

5 5
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1

*/