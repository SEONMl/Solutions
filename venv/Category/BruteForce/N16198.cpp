#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 11
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N, maxEnergy=0;
vector<int> marble;
void dfs(int now, int idx, vector<int> cur_marb){
    if(idx==N-2){
        maxEnergy=max(maxEnergy, now);
        return;
    }
    fse(1,cur_marb.size()-1,1){
        vector<int> next_marb;
        for(int j(0);j<cur_marb.size();j++){
            if(i==j) continue;
            next_marb.push_back(cur_marb[j]);
        }
        dfs(now + cur_marb[i-1]*cur_marb[i+1], idx+1, next_marb);
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    fse(0,N,1) {
        int tmp;
        cin>>tmp;
        marble.push_back(tmp);
    }

    dfs(0,0,marble);
    cout<<maxEnergy;
}