#include<iostream>
#include<vector>
#include<algorithm>
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N,M;
int arr[8];
vector<int> v;
bool visit[8];
void bt(int depth){
    if(depth==M){
        for(int n:v){
            cout<<n<<" ";
        }
        cout<<'\n';
        return;
    }
    fse(0,N,1){
        if(visit[i]) continue;
        visit[i]=1;
        v.push_back(arr[i]);
        bt(depth+1);
        visit[i]=0;
        v.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>M;
    fse(0,N,1) cin>>arr[i];
    sort(arr,arr+N);
    bt(0);
}