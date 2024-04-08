#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#define fse(A,B,C) for(int i=A;i<B;i+=C) 
using namespace std;
int K;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int test_case, T;

	cin>>T;
    // freopen("C:\\Dev\\projects\\Solutions\\venv\\Category\\.vscode\\input.txt", "r", stdin);
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin>>K;
        string s;
        cin>>s;

        int N=s.length();

        set<string> arr;
        for(int i(0);i<N;i++){
            for(int j(1);j<=N;j++){
                string tmp=s.substr(i,j);
                arr.insert(tmp);
            }
        }

        int cnt=0;
        string answer="none";
        for(string tmp:arr){
            // cout<<tmp<<" ";
            if(++cnt==K) answer = tmp;
        }

        cout<<"#"<<test_case<<" "<<answer<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}