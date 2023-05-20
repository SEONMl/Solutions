#include <string>
#include <vector>
#include<set>
#include<iostream>
#include<map>
#define INF 99999999
using namespace std;

vector<int> solution(vector<string> gems) {
    set<string> gem = set(gems.begin(), gems.end());
    map<string, int> slide;
    int N=gem.size();
    
    int result=INF;
    vector<int> answer={INF,INF};
    
    int left=0, right=0;
    int prev=-1;
    while(right < gems.size()){
        if(prev!=right){
            if(slide.find(gems[right]) != slide.end()) slide[gems[right]]++;
            else slide[gems[right]]=1;
            prev=right;
        }
        if(result==N) break;

        if(slide.size()<N) right++;
        else{
            if(result > right-left+1) {
                answer = {left+1, right+1};
                result = right-left+1;
            }
            slide[gems[left]]--;
            if(slide[gems[left]]==0) slide.erase(gems[left]);
            left++;
            if(left>right) right++;
        }
    }
    return answer;
}