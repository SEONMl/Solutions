#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define MAX 50'000
#define endl '\n'
#define fse(A,B,C) for(int i=A;i<B;i+=C) 
using namespace std;
vector<pair<int,int>> g[MAX];
vector<pair<int,int>> reversed[MAX];
int res[MAX];
int N;
void dijkstra(int start, bool isReversed){
    vector<pair<int,int>> *target = (isReversed)? reversed : g;

    priority_queue<pair<int,int>> pq;
    pq.push({0,start});

    vector<int> dist(N);
    fill_n(dist.begin(), N, 987654321);
    dist[start]=0;

    while(!pq.empty()){
        int cost=-pq.top().first;
        int cur=pq.top().second;
        pq.pop();

        if(dist[cur]<cost) continue;

        for(auto next: target[cur]){
            int nCost=cost+next.second;
            int nNode=next.first;

            if(dist[nNode] > nCost){
                dist[nNode]=nCost;
                pq.push({-nCost, nNode});
            }
        }
    }

    fse(0,N,1){
        res[i]+=dist[i];
    }
}
void init(){
    fse(0,MAX,1){
        g[i].clear();
        reversed[i].clear();
        res[i]=0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int test_case, T;
	cin>>T;
    // freopen("C:\\Dev\\projects\\Solutions\\venv\\Category\\.vscode\\input.txt", "r", stdin);
	for(test_case = 1; test_case <= T; ++test_case)
	{
        init();
        int M,X;
        cin>>N>>M>>X;
        X--;

        fse(0,M,1){
            int s,e,t;
            cin>>s>>e>>t;
            s--; e--;
            g[s].push_back({e, t});
            reversed[e].push_back({s,t});
        }
        
        // 2에서 출발
        dijkstra(X, false);
        // 2로 도착
        dijkstra(X,true);

        cout<<"#"<<test_case<<" "<<*max_element(res, res+N)<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
// stack 메모리 1MB 제한 -> 적당한 전역변수 사용해야 함