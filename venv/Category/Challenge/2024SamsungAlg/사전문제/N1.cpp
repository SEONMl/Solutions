#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#define MAX 20000
#define HEIGHT 150
#define fse(A,B,C) for(int i=A;i<B;i+=C) 
using namespace std;
int main(int argc, char** argv)
{    
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int test_case;
	int T;

	cin>>T;

    pair<int,int> pos[MAX];

    int i=0;
    for(int x(0);x<HEIGHT;x++){
        for(int y(0);y<=x;y++){
            pos[i++]={x,y};
        }
    }
    
    
	for(test_case = 1; test_case <= T; ++test_case)
	{

		int a,b,tmp, answer;
        cin>>a>>b;
        
        if(b<a){
            tmp=a;
            a=b;
            b=tmp;
        }

        auto s=pos[a-1], e=pos[b-1];
        int x1=s.first, y1=s.second, x2=e.first, y2=e.second, h=x2-x1;
        answer=h;
        if(!(y2-h<=y1 && y1<=y2)){
            answer += min(abs(y2-h-y1), abs(y2-y1));
        }

        cout<<"#"<<test_case<<" "<<answer<<'\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}