#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1'000'000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int arr[MAX],result[MAX];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin>>N;
    fse(0,N,1) cin>>arr[i];

    vector<int> seq;
    seq.push_back(arr[0]);
    result[0]=1;

    fse(1,N,1){
        if(seq.back() < arr[i]){
            seq.push_back(arr[i]);
            result[i]=seq.size();
        }else{
            int idx= lower_bound(seq.begin(), seq.end(), arr[i]) - seq.begin();
            seq[idx]=arr[i];
            result[i]=idx+1;
        }
    }

    int k=seq.size();
    cout<<k<<'\n';
    vector<int> ans;
    for(int i(N-1); i>=0;i--){
        if(result[i]!=k) continue;
        ans.push_back(arr[i]);
        k--;
    }
    for(int i(ans.size()-1);i>=0;i--){
        cout<<ans[i]<<" ";
    }
}