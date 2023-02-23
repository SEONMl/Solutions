#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define MAX 100'000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N;
int ans=9e8;
bool isAllA(string str){
    for(char c:str){
        if(c!='A') return false;
    }
    return true;
}
void dfs(string cur_name,int idx, int cnt, int depth){
    if(depth>N) return;
    if(isAllA(cur_name)){
        ans=min(ans, --cnt);
    }
    if(idx<0) idx=N-1;
    if(idx>=N) idx=0;
    char c=cur_name.at(idx);
    cur_name.at(idx)='A';
    int changeCount=min(c-'A', 'Z'-c+1);
    
    dfs(cur_name, idx-1, cnt+changeCount+1, depth+1);
    dfs(cur_name, idx+1, cnt+changeCount+1, depth+1);
}
int solution(string name) {
    N=name.length();
    if(isAllA(name)) return 0;
    ans=9e8;
    dfs(name, 0, 0, 0);
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cout<<solution("JAN");
    cout<<endl<<solution("AAAA");
}