#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
// a^b= 다른 숫자 1
bool compare(string a){
    int cnt=0;
    for(char c:a){
        if(c) cnt++;
    }
    if(cnt==1||cnt==2) return true;
    return false;
}
string toBit(long long n){
    string res="";
    while(n>0){
        res.push_back(n%2);
        n/=2;
    }
    reverse(res.begin(),res.end());
    return res;
}
vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(long long num:numbers){
        long long tmp=num+1;
        while(1){
            if(compare(toBit(num^tmp))){
                answer.push_back(tmp);
                break;
            }
            tmp++;
        }
    }
    return answer;
}