#include<iostream>
#include<vector>
#define fse(A,B,C) for(int i=A;i<B;i+=C) 
using namespace std;
int K;
int seq[13];
vector<int> tmp;
void bt(int start, int depth){
    if(K-start+depth<6) return;
    if(depth==6){
        for(int n:tmp){
            cout<<n<<" ";
        }
        cout<<'\n';
    }
    fse(start,K,1){
        tmp.push_back(seq[i]);
        bt(i+1,depth+1);
        tmp.pop_back();
    }   
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(1){
        cin>>K;
        fse(0,K,1) cin>>seq[i];
        if(K==0) break;
        bt(0,0);
        cout<<'\n';
    }
}