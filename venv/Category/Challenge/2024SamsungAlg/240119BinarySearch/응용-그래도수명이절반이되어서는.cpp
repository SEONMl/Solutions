#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define MAX 200'000
#define endl '\n'
#define fse(A,B,C) for(int i=A;i<B;i+=C) 
using namespace std;
int N,K, w[MAX], s[MAX];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    int test_case, T;

	cin>>T;
    // freopen("C:\\Dev\\projects\\Solutions\\venv\\Category\\.vscode\\input.txt", "r", stdin);
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin>>N>>K;
        fse(0,N,1) cin>>w[i];
        fse(0,K,1) cin>>s[i];

        int answer=987654321;
        int left=*min_element(w,w+N), right=*max_element(w,w+N);
        while(left<right){
            int mid = (left+right)/2;

            int ok=0, j=0;
            for(int i=0;i<N;i++){
                if(w[i]<=mid){
                    ok++;
                }else{
                    ok=0;
                }

                if(s[j]==ok){
                    ok=0;
                    j++;
                    if(j==K) break;
                }
            }
            
            if(j>=K){
                right=mid;
            }else{
                left=mid+1;
            }
        }

        cout<<"#"<<test_case<<" "<<left<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}