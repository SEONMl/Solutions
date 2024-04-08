#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<queue>
#include<cmath>
#define MAX 1000
#define fse(A,B,C) for(int i=A;i<B;i+=C) 
using namespace std;
typedef long long ll;
int parent[MAX];
int find(int x){
    if(parent[x]!=x) return parent[x]=find(parent[x]);
    return parent[x];
}
void unionAll(int a,int b){
    int x=find(a);
    int y=find(b);
    if(x<y) parent[y]=x;
    else parent[x]=y;
}
ll distance(pair<ll,ll> &x, pair<ll,ll> &y){
    return (x.first-y.first)*(x.first-y.first) + (x.second-y.second)*(x.second-y.second);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int test_case, T;

	cin>>T;
    // freopen("C:\\Dev\\projects\\Solutions\\venv\\Category\\.vscode\\input.txt", "r", stdin);
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N;
        double E;
        cin>>N;
        vector<pair<ll,ll>> island;
        fse(0,N,1){
            int x;
            cin>>x;
            island.push_back({x,0});
            parent[i]=i;
        }
        fse(0,N,1){
            int y;
            cin>>y;
            island[i].second=y;
        }
        cin>>E;

        vector<tuple<ll,int,int>> edge;
        for(int i(0);i<N;i++){
            for(int j(0);j<i;j++){
                ll L2 = distance(island[i], island[j]);
                edge.push_back({L2, i,j});
            }
        }

        double answer=0;
        sort(edge.begin(), edge.end());
        for(int i(0);i<edge.size();i++){
            auto cur = edge[i];
            ll dis = get<0>(cur);
            int s = get<1>(cur);
            int e = get<2>(cur);

            if(find(s)==find(e)) continue;
            answer += dis;
            unionAll(s,e);
        }

        ll result=static_cast<ll>(round(answer*E));
        cout<<"#"<<test_case<<" "<<result<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
