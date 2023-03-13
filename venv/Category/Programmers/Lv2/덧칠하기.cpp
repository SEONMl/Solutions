#include <string>
#include <vector>
#include<queue>
using namespace std;
#include<iostream>
int solution(int n, int m, vector<int> section) {
    int answer = 0;
    priority_queue<int> pq;
    for(int i(0);i<section.size();i++){
        pq.push(-section[i]);
    }
    
    while(!pq.empty()){
        answer++;
        int start=-pq.top();
        while(!pq.empty() && start+m-1>=-pq.top()){
            pq.pop();
        }
    }
    return answer;
}