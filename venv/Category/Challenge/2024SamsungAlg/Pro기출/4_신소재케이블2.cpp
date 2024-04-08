#include<unordered_map>
#define MAX 10005
using namespace std;
unordered_map<int, int> idx;
int parent[MAX],depth[MAX],distToParent[MAX];
int firstId[MAX], secondId[MAX], firstLatency[MAX], secondLatency[MAX];
int getIndex(int i){
	if(idx.find(i)==idx.end()) idx.insert({i,idx.size()+1});
	return idx[i];
}

void init(int mDevice)
{
	for(int i=0;i<MAX;i++){
		// distToParent[i]=0;
		firstId[i]=secondId[i]=0;
		firstLatency[i]=secondLatency[i]=0;
	}
	idx.clear();
}
void update(int pastId, int curId){
	int tmp=0;
	while(pastId){
		tmp+=distToParent[curId]; // p에서 c까지 한 단계씩 거리의 합

		if(firstId[pastId] == curId){ // p에서 가장 먼 노드가 c이면
			if(firstLatency[pastId] < tmp){
				firstLatency[pastId] = tmp;
			}else
				break;
		}else if(firstLatency[pastId] < tmp){
			secondLatency[pastId] = firstLatency[pastId];
			secondId[pastId] = firstId[pastId];
			firstLatency[pastId] = tmp;
			firstId[pastId] = curId;
		}else if(secondLatency[pastId] < tmp){
			secondLatency[pastId] = tmp;
			secondId[pastId] = curId;
		}else break;

		curId = pastId;
		pastId = parent[pastId];
	}
}
void connect(int mOldDevice, int mNewDevice, int mLatency)
{
	// 10000 * 10000 = 100'000'000
	int old = getIndex(mOldDevice);
	int nnew = getIndex(mNewDevice);

	parent[nnew]=old;
	depth[nnew]=depth[old]+1;
	distToParent[nnew]=mLatency;

	update(old, nnew);
}

int measure(int mDevice1, int mDevice2)
{
	// 1000 bfs??? -> 가능
	int sid=idx[mDevice1];
	int eid=idx[mDevice2];

	if(depth[sid]>depth[eid]) swap(sid, eid);

	int diff = depth[eid]-depth[sid];
	int result=0;
	while(diff--){ // 높이 맞추기
		result+=distToParent[eid];
		eid = parent[eid];
	}
	while(sid != eid){// 같은 높이에서 공통 조상 찾기
		result += distToParent[sid] + distToParent[eid];
		sid=parent[sid]; eid=parent[eid];
	}

	return result;
}

int test(int mDevice)
{
	// 1000 장비 mDevice로 전송 신호가 지나갈 때 최대 전송 시간
	int mid = idx[mDevice];
	int pid = parent[mid];
	int result = firstLatency[mid] + secondLatency[mid];

	int distSum = firstLatency[mid];
	while(pid){
		distSum+=distToParent[mid];
		if(secondLatency[pid]){
			int t;
			if(firstId[pid] == mid){
				t=secondLatency[pid];
			}else{
				t=firstLatency[pid];
			}
			result = max(result, distSum+t);
		}else{
			result = max(result, distSum);
		}
		mid = pid;
		pid = parent[pid];
	}

	return result;
}






#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define CMD_INIT			(100)
#define CMD_CONNECT			(200)
#define CMD_MEASURE			(300)
#define CMD_TEST			(400)

extern void init(int mDevice);
extern void connect(int mOldDevice, int mNewDevice, int mLatency);
extern int measure(int mDevice1, int mDevice2);
extern int test(int mDevice);

static bool run()
{
	int Q;
	int mDevice, mOldDevice, mNewDevice, mDevice1, mDevice2;
	int mLatency;
	
	int ret = -1, ans;

	scanf("%d", &Q);

	bool okay = false;

	for (int q = 0; q < Q; ++q)
	{
		int cmd;
		scanf("%d", &cmd);
		switch(cmd)
		{
		case CMD_INIT:
			scanf("%d", &mDevice);
			init(mDevice);
			okay = true;
			break;
		case CMD_CONNECT:
			scanf("%d %d %d", &mOldDevice, &mNewDevice, &mLatency);
			connect(mOldDevice, mNewDevice, mLatency);
			break;
		case CMD_MEASURE:
			scanf("%d %d", &mDevice1, &mDevice2);
			ret = measure(mDevice1, mDevice2);
			scanf("%d", &ans);
			if (ret != ans)
				okay = false;
			break;
		case CMD_TEST:
			scanf("%d", &mDevice);
			ret = test(mDevice);
			scanf("%d", &ans);
			if (ret != ans)
				okay = false;
			break;
		default:
			okay = false;
			break;
		}
	}

	return okay;
}

int main()
{
	setbuf(stdout, NULL);
    freopen("C:\\Dev\\projects\\Solutions\\venv\\Category\\.vscode\\input.txt", "r", stdin);

	int TC, MARK;

	scanf("%d %d", &TC, &MARK);
	for (int tc = 1; tc <= TC; ++tc)
	{
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}