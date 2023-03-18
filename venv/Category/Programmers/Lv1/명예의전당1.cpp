#include <string>
#include <vector>
#include<queue>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    priority_queue<int> q;
    vector<int> answer;
    for(int s: score){
        q.push(-s);
        if(q.size()>k) q.pop();
        answer.push_back(-q.top());
    }
    return answer;
}