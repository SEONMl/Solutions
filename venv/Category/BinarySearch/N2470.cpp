#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#define MAX 100000
using namespace std;
int N;
int liquid[MAX];
tuple<int,int,int> ans;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    for(int i(0);i<N;i++)cin>>liquid[i];
    sort(liquid,liquid+N);

    int left=0,right=N-1;
    ans={2'000'000'001,0,0};

    while(left<right){
        long tmp=liquid[left]+liquid[right];
        if(abs(tmp) < get<0>(ans)){
            ans={abs(tmp),liquid[left],liquid[right]};
        }

        if(tmp==0){
            break;
        }else if(tmp>0){
            right--;
        }else{
            left++;
        }
    }

    cout<<get<1>(ans)<<" "<<get<2>(ans);
}