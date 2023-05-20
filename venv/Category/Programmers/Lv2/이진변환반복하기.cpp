#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;
int getC(string str){
    return str.length()- count(str.begin(), str.end(), '0');
}
string to2jin(int n){
    string result="";
    while(n>0){
        result += to_string(n%2);
        n/=2;
    }
    reverse(result.begin(), result.end());
    return result;
}
vector<int> solution(string s) {
    vector<int> answer={0,0};
    while(s!="1"){
        int oneCnt=getC(s);
        answer[0]++;
        answer[1]+= s.length()-oneCnt;
        s=to2jin(getC(s));
    }
    
    return answer;
}