using namespace std;
#define MAX_N 350
#define INF 987654321
#include<memory.h>
#include<algorithm>
#include<vector>
#include<queue>

int N, RANGE;
int(*road)[MAX_N];
int board[MAX_N][MAX_N];
vector<pair<int, int>> graph[201];
pair<int, int> pos[201];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void init(int n, int mRange, int mMap[MAX_N][MAX_N])
{
	N = n; RANGE = mRange;
	road = mMap;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board[i][j] = -1;
		}
	}
	for (int i = 0; i < 201; i++) {
		graph[i].clear();
	}

	return;
}

pair<int, int> q[MAX_N * MAX_N];
void add(int mID, int mRow, int mCol) // 200
{
	int s = 0, e = 0;
	q[e++] = { mRow, mCol };

	bool visit[MAX_N][MAX_N];
	memset(visit, false, sizeof visit);
	visit[mRow][mCol] = true;

	for (int dist = 0; e - s > 0 && dist <= RANGE; dist++) {
		int si = e - s;
		while (si--) { // !q.empty()
			auto front = q[s++]; int x = front.first, y = front.second;

			if (board[x][y] != -1) {
				int tar = board[x][y];
				graph[tar].push_back({ mID, dist });
				graph[mID].push_back({ tar, dist });
			}

			if (dist < RANGE) {
				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i], ny = y + dy[i];
					if (0 <= nx && nx < N && 0 <= ny && ny < N && road[nx][ny] == 0 && !visit[nx][ny]) {
						q[e++] = { nx, ny };
						visit[nx][ny] = true;
					}
				}
			}

		}
	}

	board[mRow][mCol] = mID;
	pos[mID] = { mRow, mCol };

	return;
}

int dist[201];
int getDistance(int id1, int id2) {
	auto a = pos[id1], b = pos[id2];
	return abs(a.first - b.first) + abs(a.second - b.second);
}
int distance(int from, int to) // 800
{
	priority_queue<pair<int, int>> pq;
	//memset(dist, 0x3F, sizeof dist); // ...? INF로 초기화하면 틀림..
	for (int i = 0; i < 201; i++) {
		dist[i] = INF;
	}
	dist[from] = 0;
	pq.push({ -getDistance(from, to), from });

	while (!pq.empty()) {
		auto top = pq.top(); pq.pop();
		int d = -top.first, cur = top.second;
		d -= getDistance(cur, to);

		if (dist[cur] != d) continue;
		if (cur == to) return d;
		for (auto tar : graph[cur]) {
			int nxt = tar.first, weight = tar.second;
			if (dist[nxt] > d + weight) {
				dist[nxt] = d + weight;
				pq.push({ -(dist[nxt] + getDistance(nxt, to)), nxt });
			}
		}
	}

	return -1;
}








#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define MAX_N 350

void init(int N, int mRange, int mMap[MAX_N][MAX_N]);
void add(int mID, int mRow, int mCol);
int distance(int mFrom, int mTo);

/////////////////////////////////////////////////////////////////////////

#define INIT		0
#define ADD			1
#define DISTANCE	2

static bool run()
{
	int cmd, ans, ret;
	int N, range, id, id2, r, c;
	int Q = 0;
	bool okay = false;
	int region[MAX_N][MAX_N];

	scanf("%d", &Q);

	for (int q = 0; q < Q; ++q)
	{
		scanf("%d", &cmd);

		switch (cmd)
		{
		case INIT:
			scanf("%d %d", &N, &range);

			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					scanf("%d", &region[i][j]);

			init(N, range, region);
			okay = true;
			break;

		case ADD:
			scanf("%d %d %d", &id, &r, &c);
			add(id, r, c);
			break;

		case DISTANCE:
			scanf("%d %d", &id, &id2);
			ret = distance(id, id2);
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
	// freopen("sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++)
	{
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}