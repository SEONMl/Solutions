#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#define MAX 50
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N,M,g[MAX][MAX];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int pos[MAX][MAX];
int answer;

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

    pair<int,int> prev={1,v[0]};
    vector<int> res, tmp;
    for(int i(1); i<v.size() ;i++){
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

    if(res.size()>=N*N) {
        for(int i(0);i<N*N-1;i++){
            tmp.push_back(res[i]);
        }
        res=tmp;
    }
    return res;
}
pair<vector<int>,bool> pop(vector<int> v){
    vector<int> tar=transform(v);
    vector<int> res;

    bool hasMoreThanFour = false;
    for(int i(0);i<tar.size();i+=2){
        if(tar[i]>=4) {
            answer+=tar[i]*tar[i+1];
            hasMoreThanFour=true;
            continue;
        }
        for(int j(0); j<tar[i] ;j++){
            res.push_back(tar[i+1]);
        }
    }

    return {res, hasMoreThanFour};
}
vector<int> moveAndPop(vector<int> current){
    pair<vector<int>,bool> tmp;
    do{
        vector<int> res;
        for(int i(0);i<current.size();i++){ // 0인 원소 제거
            if(current[i]) res.push_back(current[i]);
        }
        tmp = pop(res); // 4개 이상 폭발
        current = tmp.first;
    }while(tmp.second);

    return tmp.first;
}
vector<int> attack(int dir, int dis, vector<int> current){
    for(int i(1);i<=dis;i++){
        int nx=N/2+dx[dir-1]*i;
        int ny=N/2+dy[dir-1]*i;
        int idx = pos[nx][ny];
        current[idx]=0;
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
        v=attack(dir,dis,v);
        print(v);
    }
    cout<<answer;
}