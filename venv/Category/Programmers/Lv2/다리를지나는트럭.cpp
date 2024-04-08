#include <string>
#include <vector>
#include<queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<pair<int,int>> q; int tot=0;
    int N=truck_weights.size();
    
    int time=0; int i=0;
    while(time==0 || !q.empty()){

        int tar=truck_weights[i];
        if(!q.empty() && q.front().first+bridge_length<=time){
            auto top = q.front();
            q.pop();
            tot -= top.second;
        }
        
        if(i<N && tot+tar <= weight){
            q.push({time, tar});
            tot+=tar;
            i++;
        }
        time++;

    }
    
    return time;
}