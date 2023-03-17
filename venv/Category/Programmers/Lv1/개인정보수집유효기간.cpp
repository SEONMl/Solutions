#include <string>
#include <vector>
#include<map>
#include<iostream>
using namespace std;
map<string,int> contract;
vector<int> dateToInt(string date){
    int y=stoi(date.substr(0,4));
    int m=stoi(date.substr(5,2));
    int d=stoi(date.substr(8,2));
    return {y,m,d};
}
// 날짜에서 n달-1일 이후 계산
vector<int> getExpireDate(string date, string condition){
    int howlong=contract[condition];
    int year=howlong/12;
    int month=howlong%12;
    auto target=dateToInt(date);
    target[0]+=year;
    target[1]+=month;
    target[2]--;
    if(target[1]>=13){
        target[1]-=12;
        target[0]++;
    }
    
    if(target[2]==0) {
        target[2]=28;
        target[1]--;
    }
    if(target[1]==0){
        target[1]=12;
        target[0]--;
    }
    return target;
}
// 파기여부
bool isExpired(string today, string target){
    string date=target.substr(0,10);
    string condition = target.substr(11,1);
    
    auto until=getExpireDate(date, condition); // 2019.03.28
    auto now=dateToInt(today); // 2020;01;01

    if(until[0]<now[0]) return true;
    else if(until[0]>now[0]) return false;
    else{
        if(until[1]<now[1]) return true;
        else if(until[1]>now[1]) return false;
        else{
            if(until[2]<now[2]) return true;
        }
    }
    return false;
}
vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    for(auto term:terms){
        string t=term.substr(0,1);
        int howlong=stoi(term.substr(2,term.length()-2));
        contract.insert({t,howlong});
    }
    vector<int> answer;
    int i=1;
    for(auto priv:privacies){
        if(isExpired(today, priv)){
            answer.push_back(i);
        }
        i++;
    }
    return answer;
}