#include<iostream>
#include<vector>
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector<int> prefixsum;
    int N,M,tmp,cnt=0;
    cin>>N>>M;
    cin>>tmp;
    prefixsum.push_back(tmp);
    fse(1,N,1){
        cin>>tmp;
        prefixsum.push_back(prefixsum.back()+tmp);
    }

    for(int i(0);i<N;i++){
        for(int j(i);j<N;j++){
            int sum=prefixsum[j];
            if(i>0){
                sum-=prefixsum[i-1];
            }
            if(sum==M) cnt++;
        }
    }
    cout<<cnt;
}