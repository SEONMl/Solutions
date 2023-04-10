#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 8
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N, M;
int arr[MAX];
bool visit[MAX];
void dfs(int dep, int start) {
	if (dep == M) {
		fse(0,N,1){
			if(visit[i]) cout << arr[i] << " ";
		}cout << '\n';
		return;
	}
	for (int i(start); i < N; i++) {
		if (visit[i])continue;
		visit[i] = true;
		dfs(dep+1, i + 1);
		visit[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	fse(0, N, 1) cin >> arr[i];
	sort(arr, arr + N);
	bool visit[MAX] = { 0 };
	dfs(0,0);
}