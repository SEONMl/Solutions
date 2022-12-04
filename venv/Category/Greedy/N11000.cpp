#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int N;
vector<pair<int,int>> schedule;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    for(int i(0);i<N;i++){
        int a,b;
        cin>>a>>b;
        schedule.push_back({a,b});
    }
    sort(schedule.begin(),schedule.end());
    
    priority_queue<pair<int,int>> q;
    q.push({-schedule[0].second, -schedule[0].first});
    for(int i(1);i<N;i++){
        pair<int,int> nextClass=schedule[i];
        pair<int,int> curClass=q.top();

        if(-curClass.first<=nextClass.first){
            q.pop();
        }
        q.push({-nextClass.second, -nextClass.first});
    }
    cout<<q.size();
}