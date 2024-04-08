#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#define MAX 1000001
#define fse(A,B,C) for(int i=A;i<B;i+=C) 
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int test_case, T;
	cin>>T;
    // freopen("C:\\Dev\\projects\\Solutions\\venv\\Category\\.vscode\\input.txt", "r", stdin);
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N,P;
        cin>>N>>P;
        set<int> study;
        int lastDay=0;
        fse(0,N,1){
            int tmp;
            cin>>tmp;
            study.insert(tmp);
            lastDay=tmp;
        }

        int left=42, right=0;
        int cnt=0;
        int answer=0;
        while(right<lastDay+1){
            if(study.find(right)!=study.end()){
                cnt++;
                right++;
                answer=max(answer, cnt);
            }else{
                if(P==0){
                    answer=max(answer,cnt);
                    if(study.find(left)==study.end()) P++;
                    left++;
                    cnt--;
                }else{
                    P--;
                    right++;
                    cnt++;
                }
            }
        }

        cout<<"#"<<test_case<<" "<<answer<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}