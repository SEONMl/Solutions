#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 10000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N,M;
int arr[MAX];
void bt(vector<int> v, int d){
    if(M==d){
        for(int k:v){
            cout<<k<<" ";
        }
        cout<<'\n';
        return;
    }
    fse(0,N,1){
        if(v.size()>0 && v.back()>arr[i]) continue;
        v.push_back(arr[i]);
        bt(v,d+1);
        v.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>M;
    fse(0,N,1) cin>>arr[i];
    sort(arr,arr+N);
    bt({},0);
}