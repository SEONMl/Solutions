#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<queue>
#define MAX 100'000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
vector<tuple<int,int,int,int>> planet;
int parent[MAX];
int find(int x){
    if(parent[x]!=x) return find(parent[x]);
    return parent[x];
}
void makeunion(int a,int b){
    int x=find(a);
    int y=find(b);
    if(x<y) parent[x]=y;
    else parent[y]=x;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin>>N;
    fse(0,N,1){
        int x,y,z;
        cin>>x>>y>>z;
        planet.push_back({x,y,z,i});
    }
    sort(planet.begin(), planet.end(), [](tuple<int,int,int,int> a,tuple<int,int,int,int> b)-> bool {return get<0>(a) < get<0>(b);});
    priority_queue<tuple<int,int,int>> q;
    for(int i(1);i<N;i++) q.push({-abs(get<0>(planet[i-1])-get<0>(planet[i])), get<3>(planet[i-1]), get<3>(planet[i])});

    sort(planet.begin(), planet.end(), [](tuple<int,int,int,int> a,tuple<int,int,int,int> b)-> bool {return get<1>(a) < get<1>(b);});
    for(int i(1);i<N;i++) q.push({-abs(get<1>(planet[i-1])-get<1>(planet[i])), get<3>(planet[i-1]), get<3>(planet[i])});

    sort(planet.begin(), planet.end(), [](tuple<int,int,int,int> a,tuple<int,int,int,int> b)-> bool {return get<2>(a) < get<2>(b);});
    for(int i(1);i<N;i++) q.push({-abs(get<2>(planet[i-1])-get<2>(planet[i])), get<3>(planet[i-1]), get<3>(planet[i])});

    int answer=0;
    int K=N-1;
    for(int i(0);i<N;i++) parent[i]=i;
    while(K){
        auto top=q.top();
        q.pop();
        int x=get<1>(top), y=get<2>(top);
        if(find(x)==find(y)) continue;
        
        makeunion(x,y);
        answer+=-get<0>(top);
        K--;
    }
    cout<<answer;
}