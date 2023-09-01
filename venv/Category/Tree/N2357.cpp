#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100'000
#define INF 2000000000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int arr[MAX], min_tree[MAX*3], max_tree[MAX*3];
void init(int node, int start,int end){
    if(start==end) {
        min_tree[node]=arr[start];
        max_tree[node]=arr[start];
        return;
    }
    init(node*2, start, (start+end)/2);
    init(node*2+1, (start+end)/2+1, end);
    min_tree[node]=min(min_tree[node*2], min_tree[node*2+1]);
    max_tree[node]=max(max_tree[node*2], max_tree[node*2+1]);
}
vector<int> query(int node,int start, int end, int left,int right){
    if(end<left || right<start){
        return {INF,0};
    }
    if(left<=start&&end<=right){
        return {min_tree[node], max_tree[node]};
    }
    auto lv=query(node*2, start, (start+end)/2, left,right);
    auto rv=query(node*2+1, (start+end)/2+1, end, left, right);
    return {min(lv[0],rv[0]), max(lv[1],rv[1])};
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N,M;
    cin>>N>>M;
    fse(0,N,1){
        cin>>arr[i];
    }
    init(1,0,N-1);
    fse(0,M,1){
        int a,b;
        cin>>a>>b;
        auto res=query(1,0,N-1,a-1,b-1);
        cout<<res[0]<<" "<<res[1]<<'\n';
    }
}