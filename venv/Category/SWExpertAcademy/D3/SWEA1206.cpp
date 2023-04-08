
#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1000
#define fse(A,B,C) for(int i(A);i<B;i+=C)
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	// freopen("input.txt", "r", stdin);
	
	for(test_case = 1; test_case <= 10; ++test_case)
	{
        int N,arr[MAX], result[MAX];
        cin>>N;
        fse(0,N,1){
            cin>>arr[i];
        }
        fse(2,N-2,1){
            int cur=arr[i];
            int left = min(cur-arr[i-1], cur-arr[i-2]);
            int right = min(cur-arr[i+1], cur-arr[i+2]);
            result[i]=min(left,right);
        }
        int answer=0;
        fse(2,N-2,1){
            if(result[i]>0) answer+=result[i];
        }
        cout<<"#"<<test_case<<" "<<answer<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
/*
1
10
3 4 2 4 9 0 6 4 0 6
*/