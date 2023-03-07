#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100'001
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N,arr[MAX];
    cin>>N;
    fse(0,N,1) cin>>arr[i];
    sort(arr,arr+N,greater<>());
    long long total=0;
    fse(0,N,1){
        int k=arr[i]-i;
        if(k<=0) break;
        total+=k;
    }
    cout<<total;
}