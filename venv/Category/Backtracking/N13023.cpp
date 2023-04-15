#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 2000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N;
vector<int> friends[MAX];
bool visit[MAX];
bool answer;
void dfs(int depth, int cur){
    if(depth>=5){
        answer=true;
        return;
    }
    for(auto f:friends[cur]){
        if(visit[f]) continue;
        visit[f]=true;
        dfs(depth+1, f);
        visit[f]=false;
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int M;
    cin>>N>>M;
    fse(0,M,1){
        int a,b;
        cin>>a>>b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }
    fse(0,N,1){
        if(answer) break;
        visit[i]=true;
        dfs(1,i);
        visit[i]=false;
    }
    cout<<answer;
}