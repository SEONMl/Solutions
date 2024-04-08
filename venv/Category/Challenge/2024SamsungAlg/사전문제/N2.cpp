#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 51
#define fse(A,B,C) for(int i=A;i<B;i+=C) 
using namespace std;
int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int test_case;
	int T;

	cin>>T;
    
    int arr[MAX][3];
    int dp[MAX][20];
	for(test_case = 1; test_case <= T; ++test_case)
	{

        int N,a,b,c, answer=-1, total=0;
        cin>>N;
        
        fse(0,N,1){
            cin>>a>>b>>c;
            total+=a+b+c;
            arr[i][0]=a; arr[i][1]=b; arr[i][2]=c;
        }
        
        fse(0,N,1){
            for(int j=0;j<8;j++){
                dp[i][j]=0;
            }
        }

        if(N>=3){
            dp[0][1]=arr[0][0]; dp[0][2]=arr[0][1]; dp[0][4]=arr[0][2];

            for(int i=1;i<N;i++){
                for(int k=0;k<3;k++){
                    for(int j=1;j<8;j++){
                        if(dp[i-1][j]==0) continue;
                        
                        int n = j|(1<<k);
                        dp[i][n] = max(dp[i][n], dp[i-1][j]+arr[i][k]);
                    }
                }
            }
            answer = total - dp[N-1][7];
        }
        
        cout<<"#"<<test_case<<" "<<answer<<'\n';
	}
	return 0;
}