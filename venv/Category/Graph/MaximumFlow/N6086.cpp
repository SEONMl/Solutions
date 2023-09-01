#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<memory.h>
#define MAX 52
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int g[MAX][MAX], rev[MAX][MAX];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin>>N; 
    fse(0,N,1){ // src: A(0), sink: Z(25) 
        char a,b; int c;
        cin>>a>>b>>c;
        int a1=a-'A';
        int b1=b-'A';
        g[a1][b1]+=c;
        g[b1][a1]+=c;
    }

    int answer=0;
    int route[MAX];
    int end='Z'-'A';
    while(1){
        memset(route, -1, MAX*sizeof(int));
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int front=q.front();
            q.pop();
            if(front==end) break;

            for(int i(0);i<MAX;i++){
                if(route[i]==-1&&g[front][i]-rev[front][i]>0) {
                    q.push(i);
                    route[i]=front;
                }
            }
        }
        if(route[end]==-1) break;

        int minflow=99999999;
        for(int target(end); target!=0 ;target=route[target]){
            int prv=route[target];
            minflow=min(minflow, g[prv][target]-rev[prv][target]);
        }

        for(int target(end); target!=0 ;target=route[target]){
            int prv=route[target];
            rev[prv][target] += minflow;
            rev[target][prv] -= minflow;
        }
        answer+=minflow;
    }

    cout<<answer;
}