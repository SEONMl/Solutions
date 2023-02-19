#include<iostream>
#include<vector>
#include<queue>
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N, pay,day;
    cin>>N;
    priority_queue<pair<int,int>> pq;
    fse(0,N,1){
        cin>>pay>>day;
        pq.push({-day,pay});
    }

    int money=0;
    int now=1;
    while(!pq.empty()){
        auto tmp=pq.top();
        pq.pop();
        if(-tmp.first>=now) {
            money+=tmp.second;
            now++;
        }
        cout<<tmp.first<<" "<<tmp.second<<" "<<money<<endl;
    }
    cout<<money;
}

/*
20
85 8
56 11
58 12
28 20
36 12
45 9
55 4
1 3
71 6
72 15
38 9
76 20
67 5
78 2
48 18
100 3
16 2
7 10
95 5
42 14

1050
*/