#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 500'000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
long long inversion; // N^N 번
int arr[MAX],sorted[MAX];
void merge(int start,int end){
    long long mid=(start+end)/2;

    long long l_idx=start;
    long long r_idx=mid+1;
    int k=start;
    while(l_idx<=mid && r_idx<=end){
        if(arr[l_idx]>arr[r_idx]){
            sorted[k++]=arr[r_idx++];
            inversion += mid - l_idx + 1; //이 부분
            continue;
        }
        sorted[k++]=arr[l_idx++];
    }
    if(l_idx>mid){
        for(int i(r_idx);i<=end;i++){
            sorted[k++]=arr[i];
        }
    }else{
        for(int i(l_idx);i<=mid;i++){
            sorted[k++]=arr[i];
        }
    }
    for(int i(start);i<=end;i++){
        arr[i]=sorted[i];
    }
}
void mergeSort(int start,int end){
    if(start==end) return;
    
    int mid=(start+end)/2;
    mergeSort(start, mid);
    mergeSort(mid+1, end);
    merge(start,end);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin>>N;
    fse(0,N,1){
        cin>>arr[i];
    }
    mergeSort(0,N-1);
    cout<<inversion;
}