#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 500'000
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
        vector<int> horse, cow;
        int c1,c2,z;
        cin>>c1>>c2;
        fse(0,N,1){
            cin>>z;
            horse.push_back(z);
        }
        fse(0,M,1){
            cin>>z;
            cow.push_back(z);
        }

        sort(cow.begin(),cow.end());

        int answer = 987654321;
        int cnt = 0;
        fse(0,N,1){
            int left=0, right=M-1;
            while(left<=right){
                int mid = (left+right)/2;
                int curDis=abs(horse[i]-cow[mid]);
                if(curDis==answer){
                    cnt++;
                }else if(curDis<answer){
                    cnt=1;
                    answer=curDis;
                }

                if(horse[i]<cow[mid]){
                    right=mid-1;
                }else if(horse[i]>cow[mid]){
                    left=mid+1;
                }else{
                    break;
                }
            }
        }


        cout<<"#"<<test_case<<" "<<answer+abs(c1-c2)<<" "<<cnt<<'\n'; // 거리, 쌍 수
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}