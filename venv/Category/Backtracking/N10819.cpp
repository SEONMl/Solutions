#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 9
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N,answer;
vector<int> v;
bool visit[MAX];
void bt(vector<int> arr,int depth,int num){
    if(depth==N){
        int tmp=0;
        fse(0,N-1,1){
            tmp+=abs(arr[i]-arr[i+1]);
        }
        answer=max(answer,tmp);
        return;
    }
    for(int i=0;i<N;i++){
        if(visit[i]) continue;
        visit[i]=true;
        arr.push_back(v[i]);
        bt(arr,depth+1, num);
        visit[i]=false;
        arr.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    fse(0,N,1) {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    vector<int> arr;
    bt(arr,0,0);
    cout<<answer;
}
/*
조합 사용 next_permutation(arr,arr+N)

int func() {
	int sum = 0;
	for (int i = 0; i < n-1; i++)
	{
		sum += abs(arr[i+1] - arr[i]);
	}
	return sum;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	while (next_permutation(arr, arr + n))
	{
		mx = max(mx, func());
	}
	cout << mx;
	return 0;
}
*/