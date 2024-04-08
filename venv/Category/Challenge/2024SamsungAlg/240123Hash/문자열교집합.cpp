#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#define MAX 10'000
#define endl '\n'
#define fse(A,B,C) for(int i=A;i<B;i+=C) 
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int test_case, T;

	cin>>T;
    // freopen("C:\\Dev\\projects\\Solutions\\venv\\Category\\.vscode\\input.txt", "r", stdin);
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N,M;
        cin>>N>>M;
        vector<string> a,b, res;
        fse(0,N,1){
            string t;
            cin>>t;
            a.push_back(t);
        }
        fse(0,M,1){
            string t;
            cin>>t;
            b.push_back(t);
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        auto it = set_intersection(a.begin(),a.end(),b.begin(),b.end(), back_inserter(res));
        // res.resize(it-res.begin());
        cout<<"#"<<test_case<<" "<<res.size()<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}