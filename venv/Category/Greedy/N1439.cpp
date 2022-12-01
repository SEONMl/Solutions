#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100000
using namespace std;
int check(string str, char c){
    int cnt=(str.at(0)==c) ? 0 : 1;
    char prev=str.at(0);
    for(auto s:str){
        if(s==c) {
            prev=s;
            continue;
        }
        if(prev==s) continue;
        cnt++;
        prev=s;
    }
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    int ans=9e8;
    ans=min(ans,check(s,'0'));
    ans=min(ans,check(s,'1'));
    cout<<ans;
}