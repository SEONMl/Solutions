#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define MAX 200'001
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
vector<int> g[MAX];
int indegree[MAX];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N,M;
    cin>>N>>M;
    fse(0,M,1){
        int k,x[MAX],r;
        cin>>k;
        for(int j(0);j<k;j++){
            cin>>x[j];
        }
        cin>>r;
        indegree[r]=k;
        for(int j(0);j<k;j++){
            g[x[j]].push_back(r);
        }
    }

    bool visit[N+1]={0};
    // 현재 가지고 있는 포션
    int L;
    cin>>L;
    queue<int> q;
    fse(0,L,1){
        int k;
        cin>>k;
        q.push(k);
        indegree[k]=0;
    }
    vector<int> answer;
    while(!q.empty()){
        int portion=q.front();
        q.pop();
        answer.push_back(portion);
        visit[portion]=true;
        for(int next:g[portion]){
            if(visit[next]) continue;
            indegree[next]--;// 이렇게 하면 안됨
            if(indegree[next]==0){
                q.push(next);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    cout<<answer.size()<<"\n";
    for(int a:answer){
        cout<<a<<" ";
    }
}