#include<iostream>
#include<vector>
#include<algorithm>
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
vector<int> arr;
bool isGoodNumber(int i){
    int target=arr[i];
    int s=0;int e=arr.size()-1;
    while(s<e){
        if(s==i) s++;
        if(e==i) e--;
        if(s==e) return false;
        int mid=arr[s]+arr[e];
        if(mid<target) s++;
        else if(mid>target) e--;
        else return true;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin>>N;
    int tmp;
    fse(0,N,1){
        cin>>tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(),arr.end());
    int cnt=0;
    fse(0,N,1){
        if(isGoodNumber(i)) cnt++;
    }
    cout<<cnt;
}