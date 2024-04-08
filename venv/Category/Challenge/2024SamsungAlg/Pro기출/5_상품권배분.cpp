#include<vector>
#include<algorithm>
#include<unordered_map>
#define MAX 18005
#define MAX_DEPARTMENT 1005
#define INF 987654321
using namespace std;
unordered_map<int, int> idx;
int N, id, total;
int info[MAX], accum[MAX], parent[MAX];
int indegree[MAX];
bool isRemoved[MAX];

void init(int n, int mId[], int mNum[]) {
	N = n; id = 0; total=0;
	idx.clear();
	for(int i=0;i<MAX;i++){
		parent[i]=i;
		indegree[i]=0;
		isRemoved[i]=false;
		accum[i]=0;
		info[i]=0;
	}

	for (int i = 0; i < N; i++) {
		idx[mId[i]] = id;
		info[id] = mNum[i];
		accum[id] = mNum[i];
		total+=mNum[i];
		parent[id]=-1;
		id++;
	}
}
int add(int mId, int mNum, int mParent) { // 17000
	int pid = idx[mParent];
	if (indegree[pid] >= 3) return -1;

	int cid = id++;
	idx[mId] = cid;

	info[cid] = mNum;
	total+=mNum;
	parent[cid]=pid;
	indegree[pid]++;

	int i=cid;
	while(i!=-1){
		accum[i] += mNum;
		i=parent[i];
	}
	// mparent 포함 서브트리 인원수 합 반환

	return accum[pid];
}
int remove(int mId) { //2000 mid 서브트리의 합
	//	부서 존재X -1
	if (idx.find(mId) == idx.end()) return -1;

	int cid=idx[mId];

	// 이미 삭제된 노드의 자식 노드 일 수도
	for(int node=cid; node !=-1; node=parent[node]){
		if(isRemoved[node]){
			isRemoved[cid]=true;
			return -1;
		}
	}

	indegree[parent[cid]]--;
	isRemoved[cid]=true;

	int tmp=accum[cid];
	total-=accum[cid];
	while(cid!=-1){
		accum[cid] -= tmp;
		cid=parent[cid];
	}
	
	return tmp;
}

int distribute(int K) { // 1000 binary search
	if(K>=total) return *max_element(accum, accum+N);
	vector<int> si(accum, accum+N);
	sort(si.begin(), si.end());

	// ????????????????????????
	// 제일 큰 데부터 빼서,
	int t=total;
	for(int i=N-1;i>=0;i--){
		t -= si[i];
		int L = (K-t)/(N-i);
		if((i>0? si[i-1]:0) <= L){
			return L;
		}
	}

	return 0;
}







#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern void init(int N, int mId[], int mNum[]);
extern int add(int mId, int mNum, int mParent);
extern int remove(int mId);
extern int distribute(int K);

/////////////////////////////////////////////////////////////////////////

#define CMD_INIT 1
#define CMD_ADD 2
#define CMD_REMOVE 3
#define CMD_DISTRIBUTE 4

static bool run() {
	int q;
	scanf("%d", &q);

	static int midArr[1000], mnumArr[1000];
	int mid, mnum, mparent, n, k;
	int cmd, ans, ret = 0;
	bool okay = false;

	for (int i = 0; i < q; ++i) {
		scanf("%d", &cmd);
		switch (cmd) {
		case CMD_INIT:
			scanf("%d", &n);
			for (int j = 0; j < n; ++j) {
				scanf("%d %d", &midArr[j], &mnumArr[j]);
			}
			init(n, midArr, mnumArr);
			okay = true;
			break;
		case CMD_ADD:
			scanf("%d %d %d %d", &mid, &mnum, &mparent, &ans);
			ret = add(mid, mnum, mparent);
			if (ans != ret)
				okay = false;
			// printf("add --------------- %d %d \n", ret, ans);
			break;
		case CMD_REMOVE:
			scanf("%d %d", &mid, &ans);
			ret = remove(mid);
			if (ans != ret)
				okay = false;
			// printf("remove --------------- %d %d\n", ret, ans);
			break;
		case CMD_DISTRIBUTE:
			scanf("%d %d", &k, &ans);
			ret = distribute(k);
			if (ans != ret)
				okay = false;
			printf("dist -------?-------- %d %d \n", ret, ans);
			break;
		default:
			okay = false;
			break;
		}
	}
	return okay;
}

int main() {
	setbuf(stdout, NULL);
	freopen("C:\\Dev\\projects\\Solutions\\venv\\Category\\.vscode\\input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++) {
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}