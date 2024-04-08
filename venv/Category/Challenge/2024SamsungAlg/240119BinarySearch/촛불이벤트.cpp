#include<iostream>
#include<cmath>
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
        int answer=-1;

        ll N;
        cin>>N;

        N*=2;
        ll left=1, right=sqrt(N);
        while(left<=right){
            ll m = (left+right)/2;
            ll mid = m*(m+1);

            if(mid< N){
                left=m+1;
            }else if(mid> N){
                right=m-1;
            }else{
                answer=m;
                break;
            }
        }

        cout<<"#"<<test_case<<" "<<answer<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}