#include<iostream>
#include<vector>
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N;
vector<int> v;
bool visit[8];
void bt(int depth){
    if(depth==N){
        for(int n:v){
            cout<<n<<" ";
        }
        cout<<'\n';
        return;
    }
    fse(1,N+1,1){
        if(visit[i-1]) continue;
        v.push_back(i);
        visit[i-1]=1;
        bt(depth+1);
        visit[i-1]=0;
        v.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    bt(0);
}