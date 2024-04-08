#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<sstream>
#define MAX 10'000
#define fse(A,B,C) for(int i=A;i<B;i+=C) 
using namespace std;
void insert(list<int>& password){
    int x,y;
    cin>>x>>y;
    list<int> tmp;
    for(int j=0;j<y;j++){
        int s;
        cin>>s;
        auto iter = next(password.begin(), x+j);
        password.insert(iter, s);
    }
}
void deleteN(list<int>& password){
    int x,y;
    cin>>x>>y;
    auto iter=next(password.begin(), x);
    password.erase(iter,next(iter, y));
}
void add(list<int>& password){
    int y;
    cin>>y;
    list<int> tmp;
    for(int j=0;j<y;j++){
        int s;
        cin>>s;
        password.push_back(s);
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int test_case, T=10;
    // T=1;
    freopen("C:\\Dev\\projects\\Solutions\\venv\\Category\\.vscode\\input.txt", "r", stdin);

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int answer;
        int N,M;
        list<int> password;

        cin>>N;
        fse(0,N,1){
            int tmp;
            cin>>tmp;
            password.push_back(tmp); //원본 암호문
        }

        cin>>M;
        string cmd;
        fse(0,M,1){
            cin>>cmd;
            if(cmd=="I"){
                insert(password);
            }else if(cmd=="D"){
                deleteN(password);
            }else if(cmd=="A"){
                add(password);
            }
        }

        cout<<"#"<<test_case<<" ";
        int count=0;
        for (const int& value : password) {
            cout << value << " ";
            if (++count >= 10) {
                break; // 처음 10개 원소만 출력
            }
        }
        cout<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}