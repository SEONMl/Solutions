#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
#define MAX 10'001
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N,M;
vector<int> trust[MAX];
bool visit[MAX];
int hack[MAX];
void dfs(int n,int start){
    hack[n]++;
    visit[start]=true;
    for(int next:trust[start]){
        if(visit[next]) continue;
        dfs(n,next);
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>M;
    fse(0,M,1){
        int a,b;
        cin>>a>>b; // 3이 1을 신뢰
        trust[b].push_back(a);
    }
    fse(1,N+1,1){
        memset(visit, false, sizeof(visit));
        dfs(i,i);
    }

    int maxValue=*max_element(hack,hack+N);
    fse(1,N+1,1){
        if(hack[i]==maxValue){
            cout<<i<<" ";
        }
    }
}