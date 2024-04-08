#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<limits.h>
#define MAX 200'000
#define INF 987654321
#define endl '\n'
#define fse(A,B,C) for(int i=A;i<B;i+=C) 
using namespace std;
typedef long long ll;
vector<pair<int,int>> g[MAX];
int val[MAX], N;
ll dist[MAX], answer;
void dijkstra(){
    priority_queue<pair<ll,int>> pq;
    pq.push({0,0});

    dist[0]=0;
    val[0]=0;
    while(!pq.empty()){
        ll cost = -pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(dist[node]<cost) continue;

        for(auto next: g[node]){
            ll nCost = cost+next.first;
            int nNode = next.second;

            if(nCost < dist[nNode]){
                dist[nNode]=nCost;
                val[nNode]=next.first;
                pq.push({-nCost, nNode});
            } else if(nCost==dist[nNode]){
                val[nNode]=min(val[nNode], next.first);
            }
        }
    }

    fse(0,N,1){
            answer+=val[i];
    }
}
void init(){
    fse(0,MAX,1) g[i].clear();
    fill_n(dist, MAX, LLONG_MAX);
    fill_n(val, MAX, INF);
    answer=0;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int test_case, T;

	cin>>T;
    // freopen("C:\\Dev\\projects\\Solutions\\venv\\Category\\.vscode\\input.txt", "r", stdin);
	for(test_case = 1; test_case <= T; ++test_case)
	{
        init();
        int M;
        cin>>N>>M;

        fse(0,M,1){
            int a,b,c;
            cin>>a>>b>>c;
            g[a-1].push_back({c,b-1});
            g[b-1].push_back({c,a-1});
        }

        dijkstra();
        
        cout<<"#"<<test_case<<" "<<answer<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}