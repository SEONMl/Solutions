#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define MAX 10
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
deque<int> trees[MAX][MAX]; // 나무
int g[MAX][MAX]; // 양분
int A[MAX][MAX]; // 추가 양분
int N;
void springSummer() {
    for(int i(0);i<N;i++){
        for(int j(0);j<N;j++){
            int k=0;
            while(trees[i][j].size()>k &&g[i][j]>=trees[i][j][k]){
                g[i][j]-=trees[i][j][k];
                trees[i][j][k]++;
                k++;
            }
            int l=trees[i][j].size()-1;
            while(l>=k){
                g[i][j]+=(trees[i][j][l]/2);
                trees[i][j].pop_back();
                l--;
            }
        }
    }
}
void installTree(const int x,const int y){
    int dx[]={-1,-1,-1,0,0,1,1,1};
    int dy[]={-1,0,1,-1,1,-1,0,1};
    fse(0,8,1){
        int nx=x+dx[i], ny=y+dy[i];
        if(0<=nx&&nx<N&&0<=ny&&ny<N){
            trees[nx][ny].push_front(1);
        }
    }
}
void autumnWinter(){
    for(int i(0);i<N;i++){
        for(int j(0);j<N;j++){
            for(auto tree: trees[i][j]){
                if(tree%5==0) installTree(i,j);
            }
            g[i][j]+=A[i][j];
        }
    }
}
int countAllTrees(){
    int answer=0;
    for(int i(0);i<N;i++){
        for(int j(0);j<N;j++){
            for(auto tree:trees[i][j]){
                answer++;
            }
        }
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int M,K,x,y,z;
    cin>>N>>M>>K;
    for(int i(0);i<N;i++){
        for(int j(0);j<N;j++){
            g[i][j]=5;
            cin>>A[i][j];
        }
    }
    for(int i(0);i<M;i++){
        cin>>x>>y>>z;
        trees[x-1][y-1].push_back(z);
    }
    while(K--){
        springSummer();
        autumnWinter();
    }

    cout<<countAllTrees();
}