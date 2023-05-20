#include <string>
#include <vector>
#include<map>
#include<iostream>
using namespace std;
map<char,int> garo = {{'(',10}, {')',11}, {'{',20}, {'}',21}, {'[',30}, {']',31}};
bool isCorrect(string str){
    vector<int> stk;
    for(char c: str){
        int id = garo[c];
        if(stk.empty() || stk.back()-id != -1){
            stk.push_back(id);
            continue;
        }

        stk.pop_back();
    }
    return (stk.empty())? true : false;
}
int solution(string s) {
    int answer = 0;
    for(int i(0);i<s.length();i++){
        if(isCorrect(s)) answer++;
        char c=s.at(0);
        s.push_back(c);
        s=s.substr(1,s.length()-1);
    }
    return answer;
}