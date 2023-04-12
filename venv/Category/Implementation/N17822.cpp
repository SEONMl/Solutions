#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 51
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N,M;
deque<int> dq[MAX];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool CLOCK=false, REVERSE_CLOCK=true;
int addAllOnCircle(){
    int result=0;
    for(int i(1);i<=N;i++){
        for(int j(0);j<M;j++){
            result+=dq[i][j];
        }
    }
    return result;
}

void rotateCircle(int idx, int k, bool reverse_clock){
    while(k--){
        if(!reverse_clock){
            int tmp=dq[idx].back();
            dq[idx].pop_back();
            dq[idx].push_front(tmp);
        }else{
            int tmp=dq[idx].front();
            dq[idx].pop_front();
            dq[idx].push_back(tmp);
        }
    }
}
bool findAdjustAndMakeZero(int a,int b, bool visit[][MAX]){
    queue<pair<int,int>> q;
    q.push({a,b});
    visit[a][b]=true;
    vector<pair<int,int>> res;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        res.push_back({x,y});
        q.pop();

        for(int i(0);i<4;i++){
            int nx=x+dx[i], ny=y+dy[i];

            if(ny<0) ny=M-1;
            if(ny>=M) ny=0;
            if(1>nx||nx>N|| visit[nx][ny]) continue;

            if(dq[x][y]==dq[nx][ny]){
                visit[nx][ny]=true;
                q.push({nx,ny});
            }
        }
    }
    if(res.size()==1){
        return false;
    }
    for(auto pos:res){
        int x=pos.first, y=pos.second;
        dq[x][y]=0;
    }
    return true;
}
void calculateAverage(){
    int sum=0;
    int cnt=0;
    for(int i(1);i<=N;i++){
        for(int j(0);j<M;j++){
            if(dq[i][j]==0) continue;
            sum+=dq[i][j];
            cnt++;
        }
    }
    if(cnt==0) return; // DivisionByZero Error

    int avgCeil= sum/cnt + ((sum%cnt)?1:0);
    bool ddakco=(sum%cnt==0);
    for(int i(1);i<=N;i++){
        for(int j(0);j<M;j++){
            if(dq[i][j]==0) continue;
            
            if(dq[i][j]>avgCeil) dq[i][j]--;
            else if(dq[i][j]<avgCeil) dq[i][j]++;
            else if(dq[i][j]==avgCeil && !ddakco) dq[i][j]--;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T,tmp,x,d,k;
    cin>>N>>M>>T;
    fse(1,N+1,1){
        for(int j(0);j<M;j++){
            cin>>tmp;
            dq[i].push_back(tmp);
        }
    }
    while(T--){
        cin>>x>>d>>k; // x배수 d방향 k번 회전, d=0 시계, d=1 반시계
        // 원판 회전
        int heading=(d==1)? REVERSE_CLOCK : CLOCK;
        for(int i(x);i<=N;i+=x){
            rotateCircle(i, k, heading);
        }
        bool visit[MAX][MAX]={0};

        bool existAdjust=false;
        // 인접 숫자 0으로
        for(int i(1);i<=N;i++){
            for(int j(0);j<M;j++){
                if(!visit[i][j] && dq[i][j]!=0){
                    existAdjust|=findAdjustAndMakeZero(i,j,visit);
                }
            }
        }
        // 없으면 평균 +-1
        if(!existAdjust){
            calculateAverage();
        }
    }
    // 원판 수 합
    int answer= addAllOnCircle();
    cout<<answer;
}