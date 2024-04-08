#include<iostream>

#include<vector>
#include<unordered_map>
#define MAX 601
using namespace std;
typedef long long ll;
vector<pair<int,int>> g[MAX];
vector<pair<int,int>> rev[MAX];
unordered_map<int,int> index;
int getIndex(int number){
    if(index.find(number)==index.end()){
        index.insert({number, index.size()});
    }
    return index[number];
}
int init(int N, int sCity[], int eCity[], int mCost[]) {
    for(int i(0);i<MAX;i++){
        g[i].clear();
		rev[i].clear();
    }
	index.clear();

    for(int i(0);i<N;i++){
        int sIdx = getIndex(sCity[i]);
        int eIdx = getIndex(eCity[i]);
        g[sIdx].push_back({eIdx, mCost[i]});
        rev[eIdx].push_back({sIdx, mCost[i]});
    }
	return index.size();
}

void add(int sCity, int eCity, int mCost) {
    int sIdx = getIndex(sCity);
    int eIdx = getIndex(eCity);
    g[sIdx].push_back({eIdx, mCost});
    rev[eIdx].push_back({sIdx, mCost});
	return;
}

#include<queue>
int dist[MAX];
int dijkstra(int start, bool reversed){
	vector<pair<int,int>> *target = (reversed)? g : rev;

    priority_queue<pair<int,int>> pq;
    pq.push({0,start});

    fill_n(dist, MAX, 987654321);
    dist[start]=0;
    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(dist[cur]<cost) continue;
        for(auto next: target[cur]){
            int nCost = cost+next.second;
            int nNode = next.first;
            
            if(dist[nNode]>nCost){
                pq.push({-nCost, nNode});
                dist[nNode]=nCost;
            }
        }
    }

    int ret=0;
	for(pair<int,int> it:index){
        ret+=dist[it.second];
    }
	return ret;
}
int cost(int mHub) {
    int hubIdx = getIndex(mHub);
	return dijkstra(hubIdx,false) + dijkstra(hubIdx,true);
}








#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern int init(int N, int sCity[], int eCity[], int mCost[]);
extern void add(int sCity, int eCity, int mCost);
extern int cost(int mHub);

/////////////////////////////////////////////////////////////////////////

#define MAX_N 1400
#define CMD_INIT 1
#define CMD_ADD 2
#define CMD_COST 3

static bool run() {
	int q;
	scanf("%d", &q);

	int n;
	int sCityArr[MAX_N], eCityArr[MAX_N], mCostArr[MAX_N];
	int sCity, eCity, mCost, mHub;
	int cmd, ans, ret = 0;
	bool okay = false;

	for (int i = 0; i < q; ++i) {
		scanf("%d", &cmd);
		switch (cmd) {
			case CMD_INIT:
				okay = true;
				scanf("%d", &n);
				for (int j = 0; j < n; ++j) {
					scanf("%d %d %d", &sCityArr[j], &eCityArr[j], &mCostArr[j]);
				}
				scanf("%d", &ans);
				ret = init(n, sCityArr, eCityArr, mCostArr);
				if (ans != ret)
					okay = false;
				break;
			case CMD_ADD:
				scanf("%d %d %d", &sCity, &eCity, &mCost);
				add(sCity, eCity, mCost);
				break;
			case CMD_COST:
				scanf("%d %d", &mHub, &ans);
				ret = cost(mHub);
				if (ans != ret)
					okay = false;
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

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++) {
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}