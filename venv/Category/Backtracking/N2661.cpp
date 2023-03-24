#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
bool over;
bool isSequence(string s){
    int n=s.length();
    for(int i(1);i<=n/2;i++){
        string a=s.substr(n-i, i);
        string b=s.substr(n-2*i, i);
        if(a==b) return true;
    }
    return false;
}
void dfs(string cur, int N){
    if(isSequence(cur)||over){
        return;
    }
    if(cur.length()==N){
        cout<<cur;
        over=true;
        return ;
    }
    for(char i='1';i<='3';i++){
        if(cur.back()==i) continue;
        string tmp=cur;
        tmp.push_back(i);
        dfs(tmp, N);
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin>>N;
    fse(1,4,1){
        dfs(to_string(i),N);
    }
}