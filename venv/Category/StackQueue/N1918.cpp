#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100'000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
bool isOperation(char c){
    return (c=='+'||c=='-'|| c=='*'||c=='/');
}
bool isStartGaro(char c){
    return c=='(';
}
bool isEndGaro(char c) {
    return c==')';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    vector<char> stk;
    string result="";

    for(char c: s){
        if(isStartGaro(c)){
            stk.push_back(c);
            continue;
        }
        if(isEndGaro(c)){
            char top=stk.back();
            while(!isStartGaro(top)){
                result.push_back(top);
                stk.pop_back();
                top=stk.back();
            }
            stk.pop_back(); // ( 제거
            continue;
        }
        if(isOperation(c)){
            // 우선순위 계산
            if(stk.empty() || stk.back()=='('){
                stk.push_back(c);
                continue;
            }

            char top=stk.back();
            if((c=='*'||c=='/')&&(top=='+'||top=='-')){ // 현재 > 스택 탑
                stk.push_back(c);
                continue;
            }
            while(!stk.empty() && stk.back()!='('){
                stk.pop_back();
                result.push_back(top);
                top=stk.back();
            }
            stk.push_back(c);
            continue;
        }
        result.push_back(c);
    }
    while(!stk.empty()){
        result.push_back(stk.back());
        stk.pop_back();
    }
    cout<<result;
}