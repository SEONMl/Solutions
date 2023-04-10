#include<iostream>
#include<vector>
#include<algorithm>
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N,M,arr[8];
vector<int> num;
void dfs(int depth,int start){
    if(depth==M){
        for(int i:num) cout<<i<<" ";
        cout<<'\n';
        return;
    }
    int prev=-1;
    fse(start,N,1){
        if(prev==arr[i]) continue;
        num.push_back(arr[i]);
        prev=arr[i];
        dfs(depth+1,i);
        num.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>M;
    fse(0,N,1) cin>>arr[i];
    sort(arr,arr+N);
    dfs(0,0);
}