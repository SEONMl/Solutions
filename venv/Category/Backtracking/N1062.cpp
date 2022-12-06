#include<iostream>
#include<vector>
#include<algorithm>
#define fse(A,B,C) for(int i=A;i<B;i+=C) 
using namespace std;
int N,K;
vector<int> word;
int answer;
void dfs(int start,int learned_bit,int depth){
    if(depth==0){
        int cnt=0;
        for(auto w:word){
            if(w==(learned_bit & w)) cnt++;
        }
        answer=max(answer,cnt);
        return;
    }else{
        for(int i=start+1;i<26;i++){ //b부터 시작
            if(learned_bit&(1<<i)) continue;
            dfs(i, learned_bit|(1<<i) ,depth-1);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>K;

    int learned_bit=0;
    char must[]={'a','n','t','i','c'};
    for(auto m:must) learned_bit|=1<<(m-'a');

    fse(0,N,1) {
        string tmp;
        cin>>tmp;
        string subbed=tmp.substr(4,tmp.size()-8);
        int bitmask=0;
        for(auto s:subbed){
            bitmask|=1<<(s-'a');
        }
        if(subbed.length()==0) bitmask=1;
        word.push_back(bitmask);
    }

    if(K>=26) answer=N;
    else if (K>=5) dfs(0,learned_bit,K-5);

    cout<<answer;
}