#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1'000'000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int place[MAX];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N,B,C;
    cin>>N;
    fse(0,N,1) cin>>place[i];
    cin>>B>>C;
    long long answer=N;
    fse(0,N,1){
        int rest=place[i]-B;
        if(rest>0){
            answer+= rest/C + ((rest%C)?1:0);
        }
    }
    cout<<answer;
}