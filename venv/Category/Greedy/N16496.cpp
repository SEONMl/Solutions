#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define MAX 1000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
bool comp(string a,string b){
    return a+b > b+a;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin>>N;
    string arr[MAX];
    fse(0,N,1) cin>>arr[i];
    sort(arr, arr+N, comp);
    if(arr[0]=="0"){
        cout<<0;
    }else{
        for(int i(0);i<N;i++){
            cout<<arr[i];
        }
    }
}