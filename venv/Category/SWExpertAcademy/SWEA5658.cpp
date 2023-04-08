/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<set>
#include<queue>
#include<algorithm>
#include<vector>
#include<cmath>
#define MAX 28
#define fse(A,B,C) for(int i(A);i<B;i+=C)
using namespace std;
int charToNumber(char alphabet){
    switch (alphabet)
    {
    case 'A': return 10;
    case 'B': return 11;
    case 'C': return 12;
    case 'D': return 13;
    case 'E': return 14;
    case 'F': return 15;
    default: return alphabet-'0';
    }
}
int trans(vector<char> code){ // 2 1 0 순
    int result=0;
    int n=code.size();
    fse(0,n,1){
        result+= charToNumber(code[n-1-i])*pow(16,i);
    }
    return result;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	// freopen("sample_input.txt", "r", stdin);
	cin>>T;


	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N,K;
        cin>>N>>K;
        deque<int> dq;
        fse(0,N,1){
            char tmp;
            cin>>tmp;
            dq.push_back(tmp);
        }
        int start=N-N/4;
        set<int> numSet;
        for(int i(0);i<N/4;i++){ // N/4회전
            for(int j(0);j<N;j+=N/4){
                vector<char> c;
                for(int k(j);k<j+N/4;k++){
                    c.push_back(dq[k]);
                }
                numSet.insert(trans(c));
            }
            char last = dq.back();
            dq.pop_back();
            dq.push_front(last);
        }

        priority_queue<int> pq;
        for(int s:numSet){
            pq.push(s);
        }
        while(K>1){
            pq.pop();
            K--;
        }
        cout<<"#"<<test_case<<" "<<pq.top()<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}