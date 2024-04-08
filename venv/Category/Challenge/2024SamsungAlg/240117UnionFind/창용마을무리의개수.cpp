#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 101
#define fse(A,B,C) for(int i=A;i<B;i+=C) 
using namespace std;
int parent[MAX];
int find(int x){
    if(parent[x]!=x) parent[x]=find(parent[x]);
    return parent[x];
}
void unionFunc(int x, int y){
    int a=find(x);
    int b=find(y);
    if(a<b) parent[b]=a;
    else parent[a]=b;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int test_case, T;

	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N,M,a,b;
        cin>>N>>M;

        fse(1,N+1,1){
            parent[i]=i;
        }
        fse(0,M,1){
            cin>>a>>b;
            unionFunc(a,b);
        }
        
        int answer=0;
        bool visit[MAX];
        fill_n(visit, MAX,false);
        fse(1,N+1,1){
            int x=find(parent[i]);
            parent[i]=x;
            if(visit[x]) continue;
            answer++;
            visit[x]=true;
        }
        cout<<"#"<<test_case<<" "<<answer<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}