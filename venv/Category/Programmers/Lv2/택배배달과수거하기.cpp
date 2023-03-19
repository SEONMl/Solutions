#include <string>
#include <vector>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    priority_queue<pair<int,int>> dlv;
    priority_queue<pair<int,int>> pku;
    for(int i(0);i<n;i++){
        if(deliveries[i]!=0) dlv.push({i, deliveries[i]});
        if(pickups[i]!=0) pku.push({i, pickups[i]});
    }

    while(!dlv.empty() || !pku.empty()){
        int tmp=cap;
        int dis=0;
        while(!dlv.empty()&& tmp>0){
            auto box=dlv.top();
            dlv.pop();
            dis=max(dis, box.first);

            if(box.second>tmp){
                dlv.push({box.first, box.second-tmp});
                tmp=0;
            }else{
                tmp-=box.second;
            }
        }
        tmp=cap;
        while(!pku.empty() && tmp>0){
            auto box=pku.top();
            pku.pop();
            dis=max(dis, box.first);

            if(box.second>tmp){
                pku.push({box.first, box.second-tmp});
                tmp=0;
            }else{
                tmp-=box.second;
            }
        }
        answer+=(dis+1)*2;
    }
    
    cout<<answer;
    return answer;
}

int main(){
    solution(4,6,{0,0,0,0,0,0},{0,3,0,4,0,2});
    solution(2,7,{1,0,2,0,1,0,2},{0,2,0,1,0,2,0});
}