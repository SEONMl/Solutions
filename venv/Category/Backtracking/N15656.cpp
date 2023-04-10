#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 7
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N,M,arr[MAX];
vector<int> check;
void dfs(int depth,int start){
    if(depth==M){
        for(int c:check){
            cout<<c<<" ";
        }cout<<'\n';
        return;
    }
    for(int i(start);i<N;i++){
        check.push_back(arr[i]);
        dfs(depth+1, start);
        check.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>M;
    fse(0,N,1)cin>>arr[i];
    sort(arr,arr+N);
    dfs(0,0);
}