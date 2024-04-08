#include<vector>
#include<algorithm>
#include<queue>
#define MAX 10000
#define INF 987654321
using namespace std;

int population[MAX], road[MAX], base; // i,i+1 도로개수
int timeTree[MAX * 4];
int N;
priority_queue<pair<int, int>> pq;
void update(int node, int left, int right);

void init(int n, int mPopulation[])
{
	N = n; base=1;
	pq = priority_queue<pair<int,int>>();
	while( base < N-1) base *= 2;
	
	for (int i = 0; i < N; i++) {
		population[i] = mPopulation[i];
		road[i] = 1;

		if (i == N - 1) continue;
		int weight = (mPopulation[i] + mPopulation[i + 1]);
		timeTree[base + i] = weight;
		pq.push({ weight, -i});
	}
	for(int i=base-1 ; i>0 ;i--){
		timeTree[i] = timeTree[i*2] + timeTree[i*2+1];
	}
	return;
}
void update(int index, int value) {
	index += base;
	timeTree[index] = value;
	while(index>>=1) timeTree[index] =timeTree[index*2] + timeTree[index*2+1];
}
int search(int node, int start, int end, int left, int right) {
	int ret = 0;
	for(start += base, end += base; start<=end ; start>>=1, end >>=1){
		if(start % 2 == 1) ret += timeTree[start++];
		if(end % 2 == 0) ret += timeTree[end--];
	}
	return ret;
}

int expand(int M) // 3 * 5000 
{
	//양 도시의 합의 최고값 세그트리
	int ret=0;
	while (M--) {
		auto top = pq.top(); pq.pop();
		int target = -top.second;
		road[target]++;
		ret = (population[target] + population[target + 1]) / road[target];

		pq.push({ ret, -target });
		update(target, ret);
	}

	// 이동시간이 가장 긴 도로를 찾아 차선을 하나 확장
	//이웃한 도시 간의 이동 시간이 가장 긴 도로를 한 차선 확장하기를 M번 반복한다.
	// 마지막으로 확장한 도로의 확장 후 이동시간
	return ret;
}

int calculate(int mFrom, int mTo) // 2500
{
	// mFrom인 도시에서 고유번호가 mTo인 도시까지 이동하는 데 걸리는 시간을 반환
	// 사건 = 두 도시의 인구의합 / 도로의 차선 수
	if (mFrom > mTo) {
		swap(mFrom, mTo);
	}

	return search(1, mFrom, mTo - 1, 0, N - 2);
}

int divide(int mFrom, int mTo, int K)
{
	// from to를 k개의 선거구로 나누는데 최대인구가 최소가 되게
	int left = 1, right = INF;
	while (left < right) {
		int mid = (left + right) / 2;
		int p = 0;
		for (int i = mFrom; i <= mTo && p <= K; p++) {// 선거구는 연속해야 함
			int tmp = 0, j = i;
			while (j <= mTo && tmp + population[j] <= mid) {
				// mid가 최소라고 가정 후 K개로 나눠질 수 있는지
				tmp += population[j++];
			}
			i = j;
		}

		if (p <= K) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}

	return right;
}

/*
100 70 155 30 80
1+2, 2+3 -> 410
170, 225, 185, 110 -> 170 112 185 110 / 170 112 92 110
92+112 = 204

*/








#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern void init(int N, int mPopulation[]);
extern int expand(int M);
extern int calculate(int mFrom, int mTo);
extern int divide(int mFrom, int mTo, int K);

/////////////////////////////////////////////////////////////////////////

#define MAX_N				10000

#define CMD_INIT			100
#define CMD_EXPAND			200
#define CMD_CALCULATE		300
#define CMD_DIVIDE			400

static bool run()
{
	int population[MAX_N];
	int cmd, ans, ret;
	int Q = 0;
	int N, from, to, num;
	bool okay = false;

	scanf("%d", &Q);

	for (int q = 0; q < Q; ++q)
	{
		scanf("%d", &cmd);

		switch (cmd)
		{
		case CMD_INIT:
			scanf("%d", &N);

			for (int i = 0; i < N; i++)
				scanf("%d", &population[i]);

			init(N, population);
			okay = true;
			break;

		case CMD_EXPAND:
			scanf("%d", &num);
			ret = expand(num);
			scanf("%d", &ans);
			if (ret != ans)
				okay = false;
			break;

		case CMD_CALCULATE:
			scanf("%d %d", &from, &to);
			ret = calculate(from, to);
			scanf("%d", &ans);
			if (ret != ans)
				okay = false;
			break;

		case CMD_DIVIDE:
			scanf("%d %d %d", &from, &to, &num);
			ret = divide(from, to, num);
			scanf("%d", &ans);
			if (ret != ans)
				okay = false;
			break;

		default:
			okay = false;
		}
	}

	return okay;
}

int main()
{
	setbuf(stdout, NULL);
	freopen("C:\\Dev\\projects\\Solutions\\venv\\Category\\.vscode\\input.txt", "r", stdin);


	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++)
	{
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}
