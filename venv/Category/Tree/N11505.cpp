#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1'000'000
#define INF 1000000007
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
typedef long long ll;
int arr[MAX];
ll tree[(1<<22)];
void init(int node, int start,int end){
    if(start==end) {
        tree[node]=arr[start];
        return;
    }
    init(node*2, start, (start+end)/2);
    init(node*2+1, (start+end)/2+1, end);
    tree[node]=tree[node*2]*tree[node*2+1]%INF;
}
ll query(int node,int start, int end, int left,int right){
    if(end<left || right<start){
        return 1;
    }
    if(left<=start&&end<=right){
        return tree[node];
    }
    ll lv=query(node*2, start, (start+end)/2, left,right);
    ll rv=query(node*2+1, (start+end)/2+1, end, left, right);
    return lv*rv % INF;
}
void update(int node, int start,int end,int target,int value){
    if(start>target|| end<target) return;
    if(start==end){
        arr[target]=value;
        tree[node]=value;
        return;
    }
    update(node*2, start,(start+end)/2, target, value);
    update(node*2+1, (start+end)/2+1, end, target, value);
    tree[node]=tree[node*2]*tree[node*2+1] % INF;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N,M,K;
    cin>>N>>M>>K;
    fse(0,N,1){
        cin>>arr[i];
    }
    init(1,0,N-1);
    fse(0,M+K,1){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1){ // b번째 수 c로
            update(1, 0,N-1,b-1, c);
        }else{ // [b,c] 곱
            cout<<query(1,0,N-1,b-1,c-1)<<'\n';
        }
    }
}