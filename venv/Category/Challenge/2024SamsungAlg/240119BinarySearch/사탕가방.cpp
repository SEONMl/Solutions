#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1000000000000000000
#define fse(A,B,C) for(int i=A;i<B;i+=C) 
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int test_case, T;

	cin>>T;
    // freopen("C:\\Dev\\projects\\Solutions\\venv\\Category\\.vscode\\input.txt", "r", stdin);
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N; ll M;
        cin>>N>>M;
        
        ll arr[100];
        fse(0,N,1){
            cin>>arr[i];
        }

        ll s=1, e=MAX;
        ll answer=0;
        while(s<=e){
            ll mid=s+(e-s)/2;

            ll cnt=0;
            fse(0,N,1){
                cnt += arr[i]/mid;
            }

            if(cnt<M) e=mid-1;
            else{
                answer=mid;
                s=mid+1;
            }
        }
        cout<<"#"<<test_case<<" "<<answer<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}