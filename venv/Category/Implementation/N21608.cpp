#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 21
#define INF 99999999
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N;
vector<int> student;
vector<int> like[MAX*MAX];
pair<int,int> seat[MAX*MAX];
int g[MAX][MAX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int getEmptySeat(pair<int,int> pos){
    int x=pos.first, y=pos.second;
    int cnt=0;
    for(int i(0);i<4;i++){
        int nx=x+dx[i], ny=y+dy[i];
        if(0<=nx&&nx<N&&0<=ny&&ny<N && g[nx][ny]==0){
            cnt++;
        }
    }
    return cnt;
}
vector<pair<int,int>> getNearSeatPos(pair<int,int> pos){
    int x=pos.first, y=pos.second;
    vector<pair<int,int>> v;
    for(int i(0);i<4;i++){
        int nx=x+dx[i], ny=y+dy[i];
        if(0<=nx&&nx<N&&0<=ny&&ny<N && g[nx][ny]==0){
            v.push_back({nx,ny});
        }
    }
    return v;
}
void getEmptySeatNearLikeFriends(int cur){
    int count[MAX][MAX]={0};
    for(auto friends: like[cur]){
        int fx=seat[friends].first, fy=seat[friends].second;
        if(fx==INF && fy==INF) continue; // 아직 자리 정해지지 않았을 때
            
        auto tmp =getNearSeatPos({fx,fy});
        for(auto t:tmp){
            count[t.first][t.second]++;
        }
    }
    // count 큰, 인접 빈자리 큰, 행 작, 열 작
    pair<int,int> countAndEmpty={0,0};
    for(int i(0);i<N;i++){
        for(int j(0);j<N;j++){
            if(count[i][j]>countAndEmpty.first){
                seat[cur]={i,j};
            }else if(count[i][j]==countAndEmpty.first){
                int nearEmptySeat=getEmptySeat({i,j});
                if(nearEmptySeat>countAndEmpty.second){
                    seat[cur]={i,j};
                }
            }
        }
    }
    g[seat[cur].first][seat[cur].second]=cur;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    int idx, tmp;
    fse(0,N*N,1){
        cin>>idx;
        student.push_back(idx);
        for(int j(0);j<4;j++){
            cin>>tmp;
            like[idx].push_back(tmp);
        }
        seat[i+1]={INF,INF};
    }
    g[1][1]=student[0];
    seat[student[0]]={1,1};

    fse(1,N*N,1){
        int s=student[i];
        getEmptySeatNearLikeFriends(s);
    }
    for(int i(0);i<N;i++){
        for(int j(0);j<N;j++){
            cout<<g[i][j]<<" ";
        }cout<<endl;
    }
}