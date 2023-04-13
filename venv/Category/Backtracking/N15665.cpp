#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100'000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N,M, arr[8];
vector<int> n;
void dfs(int depth){
    if(depth==M){
        for(int k:n) cout<<k<<" ";
        cout<<'\n';
        return;
    }
    int prev=-1;
    fse(0,N,1){
        if(prev==arr[i]) continue;
        n.push_back(arr[i]);
        prev=arr[i];
        dfs(depth+1);
        n.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>M;
    fse(0,N,1) cin>>arr[i];
    sort(arr,arr+N);
    dfs(0);
}