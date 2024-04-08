#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#define MAX 10
#define fse(A,B,C) for(int i=A;i<B;i+=C) 
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int test_case, T;

	cin>>T;
    // freopen("C:\\Dev\\projects\\Solutions\\venv\\Category\\.vscode\\input.txt", "r", stdin);
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int answer=0, N,K,arr[MAX], X=0,D=1;
        cin>>N;
        fse(0,N,1){
            cin>>arr[i];
        }
        cin>>K;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,K});

        while(pq.top().second>0){
            auto cur = pq.top();
            pq.pop();

            pq.push({cur.first+cur.second, 0});
            fse(0,N,1){
                pq.push({cur.first+cur.second%arr[i], cur.second/arr[i]});
            }
        }
        
        answer=pq.top().first;
        cout<<"#"<<test_case<<" "<<answer<<'\n';
	}
	return 0;
}