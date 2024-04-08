#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 400
#define endl '\n'
#define fse(A,B,C) for(int i=A;i<B;i+=C) 
using namespace std;
vector<string> v;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int test_case, T;

	cin>>T;
    // freopen("C:\\Dev\\projects\\Solutions\\venv\\Category\\.vscode\\input.txt", "r", stdin);
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N;
        cin>>N;
        string s;
        cin>>s;

        v.clear();
        
        fse(0,s.length(),1){
            v.push_back(s.substr(i, s.length()-i));
        }

        sort(v.begin(), v.end());
        string answer=(N>=v.size())? "none":v[N-1];

        for(string d:v) cout<<d<<" ";
        cout<<endl;
        cout<<"#"<<test_case<<" "<<answer<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}