#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#define MAX 10'000
#define fse(A,B,C) for(int i=A;i<B;i+=C) 
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int test_case, T;

	cin>>T;
    // freopen("C:\\Dev\\projects\\Solutions\\venv\\Category\\.vscode\\input.txt", "r", stdin);
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int answer=-1;
        int N,M,L;
        cin>>N>>M>>L;

        list<int> seq;

        fse(0,N,1){
            int tmp;
            cin>>tmp;
            seq.push_back(tmp);
        }
        fse(0,M,1){
            char cmd;
            cin>>cmd;
            if(cmd=='I'){
                int target, value;
                cin>>target>>value;
                auto it = next(seq.begin(),target);
                seq.insert(it, value);
            }else if(cmd=='D'){
                int target;
                cin>>target;
                auto it=next(seq.begin(), target);
                seq.erase(it);
            }else{ // C
                int target, value;
                cin>>target>>value;
                auto it=next(seq.begin(), target);
                *it=value;
            }
        }
        if(seq.size()>=L){
            answer=*next(seq.begin(), L);
        }
        cout<<"#"<<test_case<<" "<<answer<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}