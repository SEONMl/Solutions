#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#define MAX 20'000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
set<string> a;
string arr[MAX];
bool comp(string a, string b){
    if(a.length()<b.length()){
        return true;
    }else if (a.length()==b.length()){
        if(a<b) return true;
        else return false;
    }else return false;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin>>N;
    fse(0,N,1){
        string tmp;
        cin>>tmp;
        a.insert(tmp);
    }
    int idx=0;
    for(string tmp:a){
        arr[idx]=tmp;
        idx++;
    }

    sort(arr,arr+idx,comp);
    fse(0,idx,1) cout<<arr[i]<<'\n';
}