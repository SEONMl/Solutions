#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> food_times, long long k) {
    vector<int> sorted=food_times;
    sort(sorted.begin(),sorted.end());

    int target=sorted[0];
    int prev=0;
    int prevIdx=0;
    for(int i(1);i<sorted.size();i++){
        if(target!=sorted[i]){
            k-=(target-prev)*(sorted.size()-prevIdx);
            prev=target;
            prevIdx=i;
            target=sorted[i];
        }
        if(k<=0) break;
        if(i==sorted.size()-1) return -1;
    }

    int answer = 0;
    vector<long long> tmp;
    for(int i=0;i<food_times.size();i++){
        if(food_times[i]<prev) continue;
        else tmp.push_back(i+1);
    }
    if(k==0) answer=tmp[0];
    else answer=tmp[tmp.size()+k];

    return answer;
}

int main(){
    // cout<<solution({1,3,5,3,1,2,1},10);
    // cout<<solution({3,1,2},5);
    cout<<solution({100'000'002,100'000,100'000'000,100'000'000},20'000'000);
}