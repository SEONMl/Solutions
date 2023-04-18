#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
#define MAX 1000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N,W,L;
    cin>>N>>L>>W;//개수 길이 하중
    int truck[MAX];
    fse(0,N,1) cin>>truck[i];
    deque<pair<int,int>> bridge; // 입장시간?
    int totalWeight=0;
    int idx=0;
    int t;
    for(t=1;t<=N*1000;t++){
        if(!bridge.empty() && bridge.front().second+L==t){
            totalWeight-=bridge.front().first;
            bridge.pop_front();
        }
        if(bridge.size()<L){
            if(idx<N && totalWeight+truck[idx]<=W){
                totalWeight+=truck[idx];
                bridge.push_back({truck[idx], t});
                idx++;
            }
        }
        if(bridge.empty()) break;
    }
    cout<<t;
}