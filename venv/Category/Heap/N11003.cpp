#include<iostream>
#include<queue>
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int L,N,tmp;
    priority_queue<pair<int,int>> pq;
    cin>>N>>L;
    fse(0,N,1){
        cin>>tmp;
        pq.push({-tmp, i});
        while (pq.top().second < i-L+1) {
            pq.pop();
        }
        cout<<-pq.top().first<<" ";
    }
}