#include <string>
#include <vector>
#include<algorithm>
#define INF 999999999
using namespace std;
int N,M;
int ans=INF;
vector<vector<int>> target;

vector<vector<int>> reverse(vector<vector<int>> v,int n, int rowcol){
    if(rowcol){ // 열 뒤집기
        for(int i(0);i<N;i++){
            v[i][n]=!v[i][n];
        }
    }else{ // 행 뒤집기
        for(int i(0);i<M;i++){
            v[n][i]=!v[n][i];
        }
    }
    return v;
}
bool check(vector<vector<int>> cur){
    for(int i(0);i<N;i++){
        for(int j(0);j<M;j++){
            if(cur[i][j]==target[i][j]) continue;
            return false;
        }
    }
    return true;
}
void dfsCol(int depth, vector<vector<int>> cur, int start){
    if(check(cur)){
        ans=min(ans, depth);
    }
    if(depth==M*N){
        return;
    }
    
    for(int i(start);i<M;i++){
        vector<vector<int>> tmp = reverse(cur,i, 1);
        dfsCol(depth+1, tmp, i+1);
    }
}
void dfs(int depth, vector<vector<int>> cur,int start){
    if(depth==N+1){
        return;
    }
    
    for(int i(start);i<N;i++){
        vector<vector<int>> tmp = reverse(cur,i,0);
        dfs(depth+1, tmp, i+1);
    }
    dfsCol(depth, cur, 0);
}
int solution(vector<vector<int>> beginning, vector<vector<int>> t) {
    N=beginning.size(); M=beginning[0].size();
    target=t;
    
    dfs(0, beginning, 0);
    
    return (ans!=INF)? ans : -1;
}