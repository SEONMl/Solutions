#include <string>
#include <vector>
#include<algorithm>
#define MAX 8
using namespace std;
int N;
bool visit[MAX];
int ans;
void dfs(int cnt,int cur_piro, int depth,vector<vector<int>> dun){
    if(depth==N){
        ans=max(ans,cnt);
        return;
    }
    
    for(int i(0);i<N;i++){
        if(visit[i]) continue;
        if(dun[i][0]<=cur_piro){
            visit[i]=true;
            dfs(cnt+1, cur_piro-dun[i][1], depth+1, dun);
            visit[i]=false;
        }else{
            visit[i]=true;
            dfs(cnt,cur_piro, depth+1, dun);
            visit[i]=false;
        }
    }
}

int solution(int k, vector<vector<int>> dun) {
    N=dun.size();
    dfs(0,k,0,dun);
    return ans;
}