#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
    int user = stages.size();
    sort(stages.begin(),stages.end());
    vector<int> answer;
    priority_queue<pair<double,int>> heap;

    int current=0;
    for(int i=1;i<=N;i++){
        if(user<=0){
            heap.push({0,-i});
            continue;
        }
        int cnt=0;
        for(int j=current;j<stages.size();j++){
            if(stages[j]==i)cnt++;
            else break;
        }
        current+=cnt;
        double fault_rate=(double)cnt/(double)user;
        heap.push({fault_rate,-i});
        user-=cnt;
    }

    int heap_size=heap.size();
    for(int i=0;i<heap_size;i++){
        auto tmp=heap.top();
        answer.push_back(-tmp.second);
        heap.pop();
    }
    return answer;
}

int main(){
    solution(5, {2, 1, 2, 6, 2, 4, 3, 3});
    solution(4, {4,4,4,4,5,1,2,5,5,5,5,2,3});
    solution(8, {4,4,4,4,1,1,2});
}