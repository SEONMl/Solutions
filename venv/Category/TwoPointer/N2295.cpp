#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N;
int arr[MAX];
vector<int> sum;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    fse(0,N,1) cin>>arr[i];
    for(int i(0);i<N;i++){
        for(int j(i);j<N;j++){
            sum.push_back(arr[i]+arr[j]);
        }
    }
    sort(arr,arr+N);
    sort(sum.begin(),sum.end());
    for(int i(N-1);i>-1;i--){
        for(int j(i);j>-1;j--){
            int target=arr[i]-arr[j];
            if(binary_search(sum.begin(),sum.end(),target)){
                cout<<arr[i];
                return 0;
            }
        }
    }
}