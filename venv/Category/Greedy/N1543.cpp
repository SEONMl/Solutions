#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100'000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string a,b; // 개행문자 자동 제거
    getline(cin, a);
    getline(cin, b);
    int alen=a.length();
    int blen=b.length();
    int idx=0;
    int answer=0;
    while(idx <= alen-blen){
        string sub=a.substr(idx, blen);
        if(sub==b){
            answer++;
            idx+=blen;
        }else{
            idx++;
        }
    }
    cout<<answer;
}