#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 51
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N, water[MAX][MAX];
vector<pair<int,int>> cloud;
int dx[]={0,-1,-1,-1,0,1,1,1};
int dy[]={-1,-1,0,1,1,1,0,-1};
bool prevCloud[MAX][MAX];
int countWater();
void moveAndRain(int d,int s){
    s%=N;
    for(int i(0);i<cloud.size();i++){
        auto c=cloud[i];
        int nx=c.first+dx[d]*s;
        int ny=c.second+dy[d]*s;
        
        if(nx>=N) nx=nx-N;
        if(ny>=N) ny=ny-N;
        if(nx<0) nx=N+nx;
        if(ny<0) ny=N+ny;
        cloud[i]={nx,ny};
        prevCloud[nx][ny]=true;
        water[nx][ny]++;
        
    }
}
void waterCopyMagic(){
    for(int i(0);i<cloud.size();i++){
        auto c=cloud[i];
        int cnt=0;
        for(int j(1);j<8;j+=2){
            int nx=c.first+dx[j];
            int ny=c.second+dy[j];
            if(0<=nx&&nx<N&&0<=ny&&ny<N && water[nx][ny]>0){
                cnt++;
            }
        }
        water[c.first][c.second]+=cnt;
    }
    cloud.clear();
}
void makeCloud(){
    for(int i(0);i<N;i++){
        for(int j(0);j<N;j++){
            if(prevCloud[i][j]){
                prevCloud[i][j]=false;
                continue;
            }
            if(water[i][j]>=2){
                water[i][j]-=2;
                cloud.push_back({i,j});
            }
        }
    }
}
int countWater(){
    int answer=0;
    for(int i(0);i<N;i++){
        for(int j(0);j<N;j++){
            answer+=water[i][j];
        }
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int M;
    cin>>N>>M;
    for(int i(0);i<N;i++){
        for(int j(0);j<N;j++){
            cin>>water[i][j];
        }
    }
    cloud.push_back({N-1,0});
    cloud.push_back({N-1,1});
    cloud.push_back({N-2,0});
    cloud.push_back({N-2,1});
    fse(0,M,1){
        int d,s;
        cin>>d>>s;
        moveAndRain(d-1,s);
        waterCopyMagic();
        makeCloud();
        countWater();
    }
    
    cout<<countWater();
}