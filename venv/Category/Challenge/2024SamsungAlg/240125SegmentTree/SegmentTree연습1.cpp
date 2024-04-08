#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100'002
#define INF 2'000'000'000
#define endl '\n'
#define fse(A,B,C) for(int i=A;i<B;i+=C) 
using namespace std;
vector<int> arr(MAX);
int N;
pair<int,int> tree[MAX*4]; // 최소, 최대
void init(int cur, int start,int end){
    if(start==end){
        tree[cur]={arr[start],arr[start]};
        return;
    }

    int mid=(start+end)/2;
    init(cur*2, start, mid);
    init(cur*2+1, mid+1, end);

    tree[cur].first=min(tree[cur*2].first, tree[cur*2+1].first);
    tree[cur].second=max(tree[cur*2].second, tree[cur*2+1].second);
}
void update(int cur, int start, int end, int target){
    if(target<start || end<target){return ;}
    if(start==end){
        tree[cur]={arr[start], arr[start]};
        return;
    }

    int mid = (start+end)/2;
    update(cur*2, start, mid, target);
    update(cur*2+1, mid+1, end, target);

    tree[cur].first=min(tree[cur*2].first, tree[cur*2+1].first);
    tree[cur].second=max(tree[cur*2].second, tree[cur*2+1].second);
}
pair<int,int> search(int cur, int start,int end, int left, int right){
    if(right<start || end<left) return {INF, -INF};
    if(left<=start && end<=right) return tree[cur];

    int mid=(start+end)/2;
    auto leftChild = search(cur*2, start,mid, left,right);
    auto rightChild = search(cur*2+1, mid+1,end, left,right);

    return {min(leftChild.first, rightChild.first), max(leftChild.second, rightChild.second)};
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int test_case, T;

	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{

        int Q;
        cin>>N>>Q;

        for(int i=0;i<MAX*4;i++){
            tree[i]={INF, -INF};
        }

        fse(0,N,1) {
            cin>>arr[i];
        }
        init(1,0,N-1);

        cout<<"#"<<test_case<<" ";
        
        int cmd, a,b;
        fse(0,Q,1){
            cin>>cmd;
            if(cmd==0){ // arr[a]를 b로 바꿈
                cin>>a>>b;
                arr[a]=b;
                update(1,0,N-1,a);
            }else{  // 구간의 max-min 출력
                cin>>a>>b;
                auto ret = search(1,0,N-1,a,b-1);
                cout<<ret.second-ret.first<<" ";        
            }
        }

        cout<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}