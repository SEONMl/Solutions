#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100'000
#define INF 2000000000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
typedef long long ll;
int arr[MAX], tree[MAX*3];
void init(int node, int start,int end){
    if(start==end) {
        tree[node]=arr[start];
        return;
    }
    init(node*2, start, (start+end)/2);
    init(node*2+1, (start+end)/2+1, end);
    tree[node]=min(tree[node*2], tree[node*2+1]);
}
ll query(int node,int start, int end, int left,int right){
    if(end<left || right<start){
        return INF;
    }
    if(left<=start&&end<=right){
        return tree[node];
    }
    ll lv=query(node*2, start, (start+end)/2, left,right);
    ll rv=query(node*2+1, (start+end)/2+1, end, left, right);
    return min(lv,rv);
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
        cout<<query(1,0,N-1,a-1,b-1)<<'\n';
    }
}