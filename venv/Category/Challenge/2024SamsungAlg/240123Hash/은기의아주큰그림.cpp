#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 10'000
#define endl '\n'
#define fse(A,B,C) for(int i=A;i<B;i+=C) 
using namespace std;
int hashing(string str, int s,int e){
    int res=0;
    int square=1;
    for(int i(e-1);i>=0;i--){
        res+= str[i]*square;
        square*=2;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int test_case, T;

	cin>>T;
    // freopen("C:\\Dev\\projects\\Solutions\\venv\\Category\\.vscode\\input.txt", "r", stdin);
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int answer;
        int H,W,N,M;
        cin>>H>>W>>N>>M;
        vector<string> dream(H), teacher(N);
        vector<int> dreamHash;
        fse(0,H,1){
            cin>>dream[i];
            dreamHash.push_back(hashing(dream[i],0,W));
            cout<<dreamHash[i]<<" ";
        }
        fse(0,N,1){
            cin>>teacher[i];
        }

        for(int i(0);i<N-H;i++){
            for(int j(0);j<M-W;j++){
                int teacherHash=hashing(teacher[i], j,j+W);
            }
        }
        


        cout<<"#"<<test_case<<" "<<answer<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}