#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100'000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int Sa,Sb;
string S,T;
int countChar(string s, char c){
    return count(s.begin(), s.end(),c);
}
bool dfs(string s, int a, int b){
    if(a < Sa) return 0;
    if(b < Sb) return 0;
    if(s.length()==S.length()){
        if(s==S) return 1;
        return 0;
    }

    bool possible=false;
    string tmp=s;
    if(tmp.back()=='A') {
        tmp.pop_back();
        possible|=dfs(tmp, a-1, b);
    }

    tmp=s;
    if(tmp.front() =='B') {
        reverse(tmp.begin(), tmp.end());
        tmp.pop_back();
        possible|=dfs(tmp, a, b-1);
    }

    return possible;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>S>>T;
    int Ta=countChar(T, 'A');
    int Tb=countChar(T, 'B');
    Sa=countChar(S,'A');
    Sb=countChar(S,'B');
    cout<<dfs(T,Ta,Tb);
}