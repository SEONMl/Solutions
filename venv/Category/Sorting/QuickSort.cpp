#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 500'000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N;
int arr[MAX];
void quickSort(int start, int end){
    if(start>=end) return;

    int left=start+1, right=end;
    int pivot=start;
    
    bool left_stop=false, right_stop=false;
    while(left<=right){
        cout<<arr[left]<<" "<<arr[right]<<endl;
        while(left<=end && arr[left]<=arr[pivot]) left++;
        while(right>start && arr[right]>=arr[pivot]) right--;

        if(left>right){
            int tmp=arr[right];
            arr[right]=arr[pivot];
            arr[pivot]=tmp;   
        }
        else{
            int tmp=arr[left];
            arr[left]=arr[right];
            arr[right]=tmp;
        }
    }
    quickSort(start, left-1);
    quickSort(left+1, end);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    fse(0,N,1){
        cin>>arr[i];
    }
    quickSort(0,N-1);
}