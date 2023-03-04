#include <string>
#include <vector>
#include<map>
#include<algorithm>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char,int> keypad;
    for(string key:keymap){
        for(int i(1);i<=key.length();i++){
            char c=key.at(i-1);
            if(keypad.find(c)!=keypad.end()){
                keypad[c]=min(keypad[c],i);
            }else keypad[c]=i;
        }
    }
    
    for(string target:targets){
        int k=0;
        for(char t:target){
            if(keypad.find(t)==keypad.end()){
                k=-1;
                break;
            }
            k+=keypad[t];
        }
        answer.push_back(k);
    }
    return answer;
}