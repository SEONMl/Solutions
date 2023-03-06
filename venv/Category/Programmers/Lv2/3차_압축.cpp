#include <string>
#include <vector>
#include<map>
#define MAX 1001

using namespace std;
map<string,int> dict;
string nextString(string msg, int start){
    string prev;
    for(int i(1);i<=msg.length()-start;i++){
        string sub=msg.substr(start,i);
        if(dict.find(sub)!=dict.end()){
            prev=sub;
        }else break;
    }
    return prev;
}
vector<int> solution(string msg) {
    for(char i('A');i<='Z';i++){
        dict.insert({string(1,i), i-'A'+1});
    }
    
    vector<int> answer;
    int s=0;
    while(s<msg.length()){
        string str=nextString(msg,s);
        answer.push_back(dict[str]);
        
        string next=msg.substr(s,str.length()+1);
        dict.insert({next, dict.size()+1});
        s+=str.length();
    }
    
    return answer;
}
