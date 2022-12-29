#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int pressString(int k,string str){
    string prev=str.substr(0,k);
    // substr(시작점, 시작점부터 개수)
    int i=k;
    int len=str.length()%k;
    int overlap=1;
    while(i+k<=str.length()){
        string tmp=str.substr(i,k);
        if(prev.compare(tmp)==0){
            overlap++;
        }else{
            if(overlap>1){
                len+=to_string(overlap).length();
                overlap=1;
            }
            len+=k;
        }
        prev=tmp;
        i+=k;
    }
    if(overlap>1) {
        len+=to_string(overlap).length();
    }
    len+=k;
    cout<<len<<" ";
    return len;
}
int solution(string s) {
    int N=s.length();
    int answer = N;
    for(int i(1);i<=N/2;i++){
        answer=min(answer, pressString(i,s));
    }
    cout<<answer<<endl;
    return answer;
}
int main(){
    solution("aabbaccc");// 7
    solution("ababcdcdababcdcd"); //9
    solution("abcabcdede"); //8
    solution("abcabcabcabcdededededede"); //14
    solution("xababcdcdababcdcd"); //17
    solution("a");
}