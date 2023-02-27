#include <string>
#include <vector>
#include<algorithm>
#include <iostream>
#include<queue>
#define fse(A,B,C) for(int i=A;i<B;i+=C)
#define MAX 10'000

using namespace std;
int N;
bool visit[MAX];
vector<string> ans;
void dfs(string prevEnd, vector<vector<string>> t,int d, vector<string> tmp){
    if(d==N){
        tmp.push_back(prevEnd);
        if(ans.size()==0) ans=tmp;
        else ans=min(ans,tmp);
        return;
    }
    fse(0,N,1){
        if(visit[i]) continue;
        if(t[i][0]==prevEnd){
            visit[i]=true;
            tmp.push_back(t[i][0]);
            dfs(t[i][1], t, d+1, tmp);
            tmp.pop_back();
            visit[i]=false;
        }
    }
}
vector<string> solution(vector<vector<string>> t) {
    N=t.size();
    sort(t.begin(), t.end());
    fse(0,N,1) {
        if(t[i][0]=="ICN"){
            visit[i]=true;
            dfs(t[i][1], t, 1, {"ICN"});
            visit[i]=false;
        }
    }
    return ans;
}