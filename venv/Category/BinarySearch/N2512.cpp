#include<iostream>
#include<algorithm>
#define MAX 10000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N,M,ans;
int req[MAX];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    int maxV=0;
    fse(0,N,1) {
        cin>>req[i];
        maxV=max(maxV,req[i]);
    }
    cin>>M;

    int s=0;
    int e=M;
    while(s+1<e){
        int target=(s+e)/2;
        int tmp=0;
        fse(0,N,1){
            tmp+=min(req[i],target);
        }

        if(tmp<=M){
            ans=max(ans,target);
            s=target;
        }else{
            e=target;
       }
    }
    ans=(maxV>=ans)?ans:maxV;
    cout<<ans;
}