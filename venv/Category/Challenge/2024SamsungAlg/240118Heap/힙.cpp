#include<iostream>
#include<vector>
#include<queue>
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
        cout<<"#"<<test_case<<" ";
        int N;
        cin>>N;
        priority_queue<int> pq;
        int cmd, x;
        fse(0,N,1){
            cin>>cmd;
            if(cmd==1){
                cin>>x;
                pq.push(x);
            }else{
                if(!pq.empty()){
                    cout<<pq.top()<<" ";
                    pq.pop();
                    continue;
                }
                cout<<-1<<" ";
            }
        }
        cout<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}