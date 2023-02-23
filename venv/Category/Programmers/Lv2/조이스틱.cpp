#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define MAX 100'000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N;
vector<int> countLeftUntilNotA(string name, int curidx){
    int cntLeft=0;
    while(cntLeft<N){
        if(name.at(curidx)!='A') {
            return {cntLeft, curidx};
        }
        cntLeft++;
        curidx--;
        if(curidx<0) curidx=N-1;
    }
    return {-1};
}
vector<int> countRightUntilNotA(string name, int curidx){
    int cntRight=0;
    while(cntRight<N){
        if(name.at(curidx)!='A') {
            return {cntRight,curidx};
        }
        cntRight++;
        curidx=(curidx+1)%N;
    }
    return {-1};
}
int change(string* name, int idx){
    // B~M N O~Z
    char c=name->at(idx);
    int move= min(c-'A', 'Z'-c+1);
    
    name->at(idx)='A';
    return move;
}
int solution(string name) {
    N=name.length();
    int ans=0;
    int cur=0;
    while(1){
        auto left=countLeftUntilNotA(name,cur);
        auto right=countRightUntilNotA(name,cur);
        if(left[0]==-1) break;

        if(left[0]<right[0]){
            cur=left[1];
            ans+=left[0];
        }else {
            cur=right[1];
            ans+=right[0];
        }

        ans+=change(&name, cur);
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cout<<solution("JEROEN"); // 56
    cout<<endl<<solution("JAN");
}