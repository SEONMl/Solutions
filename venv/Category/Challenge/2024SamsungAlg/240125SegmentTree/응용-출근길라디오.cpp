#define MAX_NODE 100'000
#define MAX_ROAD 1'000
#include<vector>
#include<cmath>
#include<unordered_map>
using namespace std;
int N,M;
vector<int> realTime(MAX_NODE); // 실시간 교통 시간 0-1 사이0, 1-2 사이1 ...
unordered_map<int, vector<int>> roadMap;
int tree[MAX_NODE*4];
void buildTree(int cur, int start,int end){
    if(start==end){
        tree[cur]=realTime[start];
        return;
    }

    int mid=(start+end)/2;
    buildTree(cur*2, start, mid);
    buildTree(cur*2+1, mid+1, end);

    tree[cur]=tree[cur*2]+tree[cur*2+1];
}
void updateTree(int cur, int start, int end, int target){
    if(target<start || end<target){return ;}
    if(start==end){
        tree[cur]=realTime[start]; // 변경
        return;
    }

    int mid = (start+end)/2;
    updateTree(cur*2, start, mid, target);
    updateTree(cur*2+1, mid+1, end, target);
    
    tree[cur]=tree[cur*2]+tree[cur*2+1];
}
int searchTree(int cur, int start,int end, int left, int right){
    if(right<start || end<left) return 0;
    if(left<=start && end<=right) return tree[cur];

    int mid=(start+end)/2;
    auto leftChild = searchTree(cur*2, start,mid, left,right);
    auto rightChild = searchTree(cur*2+1, mid+1,end, left,right);

    return leftChild+rightChild;
}

void init(int n, int m, int mType[], int mTime[])
{
    roadMap.clear();
    for(int i=0;i<MAX_NODE*4;i++) {
        tree[i]=0;
        if(i<MAX_ROAD){
            roadMap.insert({i, {}});
        }
    }

    N=n; M=m;
    for(int i=0;i<N-1;i++){
        realTime[i]=mTime[i];
        roadMap[mType[i]].push_back(i);
    }

    buildTree(1,0,N-2);
}

void update(int mID, int mNewTime)
{
    realTime[mID]=mNewTime;
    updateTree(1,0,N-2,mID);
}

int calculateRatio(int origin, int mRatio256){
    double result = origin * mRatio256 / 256;
    return (int)(round(result));
}
int updateByType(int mTypeID, int mRatio256)
{
    int ret=0;
    for(int target: roadMap[mTypeID]){
        int tmp = calculateRatio(realTime[target], mRatio256);
        ret+=tmp;
        realTime[target]=tmp;
        updateTree(1,0,N-2,target);
    }
	return ret;
}

int calculate(int mA, int mB)
{
    if(mA>mB){
        int tmp=mA;
        mA=mB;
        mB=tmp;
    }
    if(mA==mB-1) return realTime[mA];
    return searchTree(1,0,N-2, mA,mB-1);
}
void destroy(){} // 빈 함수





#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define CMD_INIT 100
#define CMD_DESTROY 200
#define CMD_UPDATE 300
#define CMD_UPDATE_TYPE 400
#define CMD_CALC 500

void init(int N, int M, int mType[], int mTime[]);
void destroy();
void update(int mID, int mNewTime);
int updateByType(int mTypeID, int mRatio256);
int calculate(int mA, int mB);

#define MAX_N 100000

static int mType[MAX_N];
static int mTime[MAX_N];

static int run()
{
	int C;
	int isOK = 0;
	int cmd, ret, chk;

	int N, M;
	int mID, mTypeID, mNewTime, mRatio;
	int mA, mB;

	scanf("%d", &C);

	for (int c = 0; c < C; ++c)
	{
		scanf("%d", &cmd);
		switch (cmd)
		{
		case CMD_INIT:
			scanf("%d %d ", &N, &M);
			for (int i = 0; i < N - 1; i++) scanf("%d", &mType[i]);				
			for (int i = 0; i < N - 1; i++) scanf("%d", &mTime[i]);
			init(N, M, mType, mTime);
			isOK = 1;
			break;

		case CMD_UPDATE:
			scanf("%d %d", &mID, &mNewTime);
			update(mID, mNewTime);			
			break;

		case CMD_UPDATE_TYPE:
			scanf("%d %d", &mTypeID, &mRatio);
			ret = updateByType(mTypeID, mRatio);
			scanf("%d", &chk);
			if (ret != chk)
				isOK = 0;
			break;

		case CMD_CALC:
			scanf("%d %d", &mA, &mB);
			ret = calculate(mA, mB);
			scanf("%d", &chk);
			if (ret != chk)
				isOK = 0;
			break;

		default:
			isOK = 0;
			break;
		}
	}
	destroy();
	return isOK;
}

int main()
{
	setbuf(stdout, NULL);
	//freopen("sample_input.txt", "r", stdin);
    freopen("C:\\Dev\\projects\\Solutions\\venv\\Category\\.vscode\\input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++)
	{
		if (run()) printf("#%d %d\n", tc, MARK);
		else printf("#%d %d\n", tc, 0);
	}
	return 0;
}