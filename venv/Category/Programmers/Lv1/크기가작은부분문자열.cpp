#include <string>
#include <vector>

using namespace std;

int solution(string target, string p) {
    int answer = 0;
    long long intP=stol(p);
    
    int window=p.length();
    long long idx=0;
    while(idx<=target.length()-window){
        string slide=target.substr(idx, window);
        if(stol(slide)<=intP) answer++;
        idx++;
    }
    return answer;
}