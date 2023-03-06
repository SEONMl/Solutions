#include<iostream>
#include<vector>
#include<queue>
#define MAX 1500
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin>>N;
    priority_queue<int> pq;
    fse(0,N*N,1){
        int tmp;
        cin>>tmp;
        pq.push(-tmp);
        if(pq.size()>N) pq.pop();
    }

    cout<<-pq.top();
}