#include<iostream>
#include<vector>
#include<algorithm>
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N,M, arr[8];
bool visit[8];
vector<int> num;
void dfs(int depth){
    if(depth==M){
        for(int n:num){cout<<n<<" ";}
        cout<<'\n';
        return;
    }
    int prev=-1;
    fse(0,N,1){
        // 직전에 고른 수가 아니고, 이미 고른 수가 아님
        if(!visit[i] && prev!=arr[i]){
            prev=arr[i];
            visit[i]=true;
            num.push_back(arr[i]);
            dfs(depth+1);
            visit[i]=false;
            num.pop_back();
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>M;
    fse(0,N,1) cin>>arr[i];
    sort(arr,arr+N);
    dfs(0);
}