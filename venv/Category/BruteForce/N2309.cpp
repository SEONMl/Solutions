#include<iostream>
#include<vector>
#include<algorithm>
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
vector<int> v;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int total=0;
    fse(0,9,1) {
        int tmp;
        cin>>tmp;
        total+=tmp;
        v.push_back(tmp);
    }

    sort(v.begin(),v.end());
    for(int i=0;i<8;i++){
        for(int j=1;j<9;j++){
            if(total-v[i]-v[j]==100){
                for(int k=0;k<9;k++){
                    if(k==i||k==j) continue;
                    cout<<v[k]<<'\n';
                }
                return 0;
            }
        }
    }
}