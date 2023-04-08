#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 51
#define INF 99999999
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N,M,g[MAX][MAX];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int pos[MAX][MAX];
vector<int> popped={0,0,0,0};

void print(vector<int> v){
    for(int k:v) cout<<k<<" ";
    cout<<endl;
}
vector<int> snailAlgorithm(){
    vector<int> v;
    int size=N*N-2, sign=1;
    int x=0,y=0;
    for(int i(0);i<N;i++){
        pos[0][i]=size--;
        if(g[0][i]) v.push_back(g[0][i]);
        y=i;
    }
    for(int i(N-1) ; i>0 ; i--){
        for(int j(0) ; j<i ; j++){
            x += sign;
            pos[x][y] = size--;
            if(g[x][y]) v.push_back(g[x][y]);
        }
        sign *= -1;
        for(int j(0) ; j<i ; j++){
            y += sign;
            pos[x][y] = size--;
            if(g[x][y]) v.push_back(g[x][y]);
        }
    }
    reverse(v.begin(), v.end());
    return v;
}

vector<int> transform(vector<int> v){ // 변화단계 및 중복 원소 체크용
    if(v.size()==0) return {};

    pair<int,int> prev={1, v[0]};
    vector<int> res;
    for(int i(1); i<v.size() && res.size()<N*N;i++){
        if(prev.second!=v[i]){
            res.push_back(prev.first); // 개수
            res.push_back(prev.second); // 번호
            prev={1,v[i]};
        }else{
            prev.first++;
        }
    }
    res.push_back(prev.first);
    res.push_back(prev.second);

    while(res.size()>=N*N){
        res.pop_back();
    }
    return res;
}

vector<int> moveAndPop(vector<int> current){
    bool checkAgain=true;
    while(checkAgain){
        checkAgain=false;
        pair<int,int> prev={INF,0}; // 숫자, 개수
        vector<int> res;
        for(int i(0);i<current.size();i++){ // 0인 원소 제거
            if(current[i]) {
                if(prev.first==current[i]) prev.second++;
                else{
                    if(prev.second>=4){
                        for(int j(0);j<prev.second;j++){
                            popped[prev.first]++;
                            res.pop_back();
                        }
                        checkAgain=true;
                    }
                    prev={current[i], 1};
                }
                res.push_back(current[i]);
            }
        }

        if(prev.second>=4){
            for(int j(0);j<prev.second;j++){
                popped[prev.first]++;
                res.pop_back();
            }
            checkAgain=true;
        }
        current=res;
    }
    return current;
}
vector<int> attack(int dir, int dis, vector<int> current){
    for(int i(1);i<=dis;i++){
        int nx=N/2+dx[dir]*i;
        int ny=N/2+dy[dir]*i;
        int idx = pos[nx][ny];
        if(idx<current.size()) current[idx]=0;
    }
    current=moveAndPop(current);
    current=transform(current);
    return current;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>M;
    for(int i(0);i<N;i++){
        for(int j(0);j<N;j++){
            cin>>g[i][j];
        }
    }
    vector<int> v=snailAlgorithm();
    fse(0,M,1){
        int dir,dis;
        cin>>dir>>dis;
        v=attack(dir-1,dis,v);
    }
    int ans=popped[1]+popped[2]*2+popped[3]*3;
    cout<<ans;
}