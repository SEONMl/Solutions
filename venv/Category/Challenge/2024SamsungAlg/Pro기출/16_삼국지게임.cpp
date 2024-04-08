using namespace std;
// #include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
struct Ground{
	int id;
	int soldier;
	int x, y;
	Ground(int id,int so, int x,int y) : id(id), soldier(so), x(x), y(y) {}
};
unordered_map<char*, int> idx;
vector<Ground*> grounds;
int N;
int dx[9] = {-1,-1,-1, 0,0, 1,1,1};
int dy[9] = {-1,0,1, -1,1, -1,0,1};
Ground *g[25][25];
int posRelation[10000];
unordered_set<int> negRelation[8630];
int find(int x){
	if(posRelation[x] != x) return posRelation[x]=find(posRelation[x]);
	return posRelation[x];
}
void unionBoth(int a,int b){
	int x=find(a), y=find(b);
	if(x<y) posRelation[y]=x;
	else posRelation[x]=y;
}
int getIndex(char *c){
	if(idx.find(c)!=idx.end()) return idx[c];
	idx[c] = idx.size();
	return idx[c];
}
bool isEnemy(int a,int b){
	for(int k: negRelation[a]){
		if(k==b) return true;
	}
	return false;
}

void init(int n, int mSoldier[25][25], char mMonarch[25][25][11])
{
	N=n;
	idx.clear();

	for(int i=0;i<n;i++){
		posRelation[i]=i;
		for(int j=0;j<n;j++){
			int id = idx[mMonarch[i][j]];
			auto tmp = new Ground(id, mSoldier[i][j], i,j);
			grounds.push_back(tmp);
			g[i][j]=tmp;
		}
	}
	for(int i=0;i<8630;i++){
		negRelation[i].clear();
	}

}



int ally(char mMonarchA[11], char mMonarchB[11])
{	//8000 
	// 이미 동맹 -1 , 적대 -2
	int a=getIndex(mMonarchA), b=getIndex(mMonarchB);
	if(a==b) return -1;
	
	if(isEnemy(a,b)) return -2;


	// 성공 1
	unionBoth(a,b);
	for(int k: negRelation[a]){
		negRelation[b].insert(k);
	}
	for(int k: negRelation[b]){
		negRelation[a].insert(k);
	}
	return 1;
}

int attack(char monarchA[11], char monarchB[11], char mGeneral[11])
{ // 8000
	// 동맹관계 확인 동맹이다 -1
	int a=getIndex(monarchA), b=getIndex(monarchB);
	if(a==b) return -1;

	// 인접 확인, 인접하지 않다 -2
	// 8방향 파인드-같다 -> 솔져 더해서 전투, 적대관계 유니온
	Ground *target = grounds[b];
	int x=target->x, y=target->y;
	bool fight=false; int soliderA=0, soliderB=target->soldier/2;
	target->soldier /= 2;

	for(int i=0;i<8;i++){
		int nx = x+dx[i], ny = y+dy[i];
		if(0>nx||nx>=N || 0>ny||ny>=N) continue;

		Ground *tmp = g[nx][ny];
		int tmpId = find(tmp->id);
		if(tmpId==a){
			fight=true;
			soliderA += (tmp->soldier /= 2);
		}
	}

	if(!fight) return -2;

	// 다르다

	// 공격 성공 1, 방어성공 또는 0명 0
	return -3;
}

int recruit(char mMonarch[11], int mNum, int mOption)
{// 13000
	// 10000 * 13000 = 130'000'000
	if(mOption==0){

	}else{

	}
	return -1;
}




void destroy(){}



#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define CMD_INIT 100
#define CMD_DESTROY 200
#define CMD_ALLY 300
#define CMD_ATTACK 400
#define CMD_RECRUIT 500

/////////////////////////////////////////////////////////////////////////
extern void init(int N, int mSoldier[25][25], char mGeneral[25][25][11]);
extern void destroy();
extern int ally(char mMonarchA[11], char mMonarchB[11]);
extern int attack(char mMonarchA[11], char mMonarchB[11], char mGeneral[11]);
extern int recruit(char mMonarch[11], int mNum, int mOption);
/////////////////////////////////////////////////////////////////////////

#define MAX_N 25
#define MAX_L 10

static int Sol[MAX_N][MAX_N];
static char General[MAX_N][MAX_N][MAX_L + 1];

static int run()
{
	int isOK = 0;

	int N;
	int cmd;
	int result;
	int check;

	int mN;
	char mMonarchA[11];
	char mMonarchB[11];
	char mGeneral[11];
	int mOption;
	int num;

	scanf("%d", &N);

	for (int c = 0; c < N; ++c)
	{
		scanf("%d", &cmd);
		switch (cmd)
		{
		case CMD_INIT:
			scanf("%d", &mN);
			for (int j = 0; j < mN; j++)
				for (int i = 0; i < mN; i++)
					scanf("%d", &Sol[j][i]);

			for (int j = 0; j < mN; j++)
				for (int i = 0; i < mN; i++)
					scanf("%s", General[j][i]);

			init(mN, Sol, General);
			isOK = 1;
			break;

		case CMD_ALLY:
			scanf("%s %s", mMonarchA, mMonarchB);
			result = ally(mMonarchA, mMonarchB);
			scanf("%d", &check);
			if (result != check)
				isOK = 0;
			break;

		case CMD_ATTACK:
			scanf("%s %s %s", mMonarchA, mMonarchB, mGeneral);
			result = attack(mMonarchA, mMonarchB, mGeneral);
			scanf("%d", &check);
			if (result != check)
				isOK = 0;
			break;

		case CMD_RECRUIT:
			scanf("%s %d %d", mMonarchA, &num, &mOption);
			result = recruit(mMonarchA, num, mOption);
			scanf("%d", &check);
			if (result != check)
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

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++)
	{
		if (run()) printf("#%d %d\n", tc, MARK);
		else printf("#%d %d\n", tc, 0);
	}
	return 0;
}