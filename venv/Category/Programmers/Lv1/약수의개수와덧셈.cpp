#include <string>
#include <vector>
#include<math.h>
#include<algorithm>
using namespace std;
int getYaksooCount(int n){
    vector<int> v;
    for(int i(1);i<=sqrt(n);i++){
        if(n%i==0) {
            v.push_back(i);
            if(count(v.begin(),v.end(),n/i)==0) v.push_back(n/i);
        }
    }
    return v.size();
}
int solution(int left, int right) {
    int answer = 0;
    for(int i(left);i<=right;i++){
        int tmp=getYaksooCount(i);
        if(tmp%2) answer-=i;
        else answer+=i;
    }
    return answer;
}