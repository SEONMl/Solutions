#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1'000'000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N;
vector<int> seq;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;

    seq.push_back(MAX);
    fse(0,N,1){
        int arr;
        cin>>arr;
        if(seq.back() < arr){
            seq.push_back(arr);
        }else{
            int idx=lower_bound(seq.begin(),seq.end(),arr)-seq.begin();
            seq[idx]=arr;
        }
    }

    cout<<seq.size()<<'\n';
    fse(0,seq.size(),1) cout<<seq[i]<<" ";
}