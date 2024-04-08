using namespace std;
#define MAX 100001
#include<vector>
#include<algorithm>
int N;
int ground[MAX];
vector<pair<int,int>> minStk, maxStk;
int mx;

void insertMin(int tar, int idx){
	while(!minStk.empty() && minStk.back().first>tar){
		minStk.pop_back();
	}
	minStk.push_back({tar, idx});
}
void insertMax(int tar, int idx){
	while(!maxStk.empty() && maxStk.back().first<tar){
		maxStk.pop_back();
	}
	maxStk.push_back({tar, idx});
}
void makeStack(){
	minStk.clear(); maxStk.clear();
	for(int i=1;i<N+1;i++){
		insertMin(ground[i], i);
		insertMax(ground[i], i);
	}
}
int calculate(){
	int ret=0;
	mx=maxStk.back().first;
	pair<int,int> prev;
	while(maxStk.size()>1){
		prev=maxStk.back();
		maxStk.pop_back();

		ret += prev.first * ( prev.second - maxStk.back().second);
	}
	ret += prev.first * prev.second;

	while(minStk.size()>1 && minStk.back().first < mx){
		prev=minStk.back();
		minStk.pop_back();

		ret += prev.first * ( prev.second - minStk.back().second);
	}

	return ret;
}

void init(int n)
{
	N=n;
	for(int i=0;i<MAX;i++){
		ground[i]=0;
	}
	return;
}


int stock(int mLoc, int mBox) // 최대 2천만 높이
{
	ground[mLoc] += mBox;
	makeStack();
	return calculate();
}

int ship(int mLoc, int mBox)
{
	ground[mLoc] -= mBox;
	makeStack();
	return calculate();
}

int getHeight(int mLoc)
{
	return ground[mLoc];
}







#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define CMD_INIT			(100)
#define CMD_STOCK			(200)
#define CMD_SHIP			(300)
#define CMD_GET_HEIGHT		(400)

extern void init(int N);
extern int stock(int mLoc, int mBox);
extern int ship(int mLoc, int mBox);
extern int getHeight(int mLoc);

static bool run()
{
	int Q;
	int N, mLoc, mBox;
	
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
			scanf("%d", &N);
			init(N);
			okay = true;
			break;
		case CMD_STOCK:
			scanf("%d %d", &mLoc, &mBox);
			ret = stock(mLoc, mBox);
			scanf("%d", &ans);
			if (ret != ans)
				okay = false;
			break;
		case CMD_SHIP:
			scanf("%d %d", &mLoc, &mBox);
			ret = ship(mLoc, mBox);
			scanf("%d", &ans);
			if (ret != ans)
				okay = false;
			break;
		case CMD_GET_HEIGHT:
			scanf("%d", &mLoc);
			ret = getHeight(mLoc);
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