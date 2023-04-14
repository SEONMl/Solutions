#include <string>
#include <vector>
#include<queue>
#include<iostream>
#include<algorithm>
#define MAX 100'000
using namespace std;
int solution(vector<vector<int>> scores) {
    int N=scores.size();
    int arr[MAX+1]={0};
    for(auto score: scores){
        int a=score[0];
        int b=score[1];
        arr[a]=max(arr[a], b);
    }
    int prev=0;
    int tmp=arr[MAX];
    arr[MAX]=0;
    for(int i(MAX);i>0;i--){
        prev=max(tmp,prev);
        tmp=arr[i-1];
        arr[i-1]=prev;
    }

    priority_queue<pair<int,int>> pq;
    for(int i(0);i<N;i++){
        auto score=scores[i];
        if(arr[score[0]]<=score[1]){
            int total=score[0]+score[1];
            pq.push({total, -i});
        }
    }
    int answer=-1;
    int rank=1;
    while(!pq.empty()){
        auto top=pq.top();
        if(top.second==0){
            answer=rank;
            break;
        }
        rank++;
        pq.pop();
    }
    return answer;
}