#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
#define MAX 10001
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
priority_queue<pair<int,int>> pq;
int profit[MAX];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N, pay,day;
    cin>>N;
    int lastday=0;
    fse(0,N,1){
        cin>>pay>>day;
        pq.push({pay,-day});
        lastday=max(lastday,day);
    }
    while(!pq.empty()){
        auto biggest=pq.top();
        int pay=biggest.first;
        int day=-biggest.second;
        pq.pop();
        while(day>0&&profit[day]!=0){
            day--;
        }
        profit[day]=max(profit[day],pay);
    }
    int total=0;
    fse(1,lastday+1,1){
        total+=profit[i];
    }
    cout<<total;
}