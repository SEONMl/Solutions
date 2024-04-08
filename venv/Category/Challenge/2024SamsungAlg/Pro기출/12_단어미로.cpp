using namespace std;
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string.h>
#include<queue>
#define SQR_FIVE 32
#define SQR_TEN 1024
#define SQR_FIFTEEN 32768
typedef long long ll;

// #include<bits/stdc++.h>
struct Room{
	int id, *dir;
	char *word;
	Room(int id, int *dir, char *ch) : id(id), dir(dir), word(ch) {}
};
unordered_map<ll, Room*> chToRoom;
unordered_map<int, priority_queue<Room*>> combi[5];
Room *cur;
void init()
{
	cur=NULL;
	chToRoom.clear();
	for(int i=0;i<5;i++){
		for(int j=0;j<(1<<20);j++){
			combi[i].clear();
		}
	}
}
int hf4(char *ch){
	return ch[0]+ch[1]*SQR_FIVE + ch[2]*SQR_TEN + ch[3]*SQR_FIFTEEN;
}
int hf2(char *ch){
	return ch[0]+ch[1]*SQR_FIVE;
}
int hb4(char *ch){
	return ch[7]+ch[8]*SQR_FIVE + ch[9]*SQR_TEN + ch[10]*SQR_FIFTEEN;
}
int hb2(char *ch){
	return ch[7]+ch[8]*SQR_FIVE;
}
int hc3(char *ch){
	return ch[4]+ch[5]*SQR_FIVE + ch[6]*SQR_TEN;
}

ll getHash(char *ch){
	ll ret = 0;
	for(int i=0;i<11;i++){
		ret<<=5;
		ret += ch[i];
	}
	return ret;
}

void addRoom(int mID, char mWord[], int mDirLen[]) // 30000
{
	for(int i=0;i<11;i++) mWord[i] -= 'a';

	Room *room = new Room(mID, mDirLen, mWord);
	chToRoom[getHash(mWord)] = room;

	combi[0][hf2(mWord)].push(room);
	combi[1][hf4(mWord)].push(room);
	combi[2][hc3(mWord)].push(room);
	combi[3][hb2(mWord)].push(room);
	combi[4][hb4(mWord)].push(room);
}

void setCurrent(char mWord[]) //500
{
	for(int i=0;i<11;i++) mWord[i] -= 'a';
	cur = chToRoom[getHash(mWord)];
}

int moveDir(int mDir) //50000
{
	int tmp=0;
	if(mDir==1) tmp=4;
	else if(mDir==2) tmp=7;

	int hash = getHash(cur->word);


	return 0;
}

void changeWord(char mWord[], char mChgWord[], int mChgLen[])
{ // 3000
	for(int i=0;i<11;i++) {
		mWord[i] -= 'a';
		mChgWord[i] -= 'a';
	}
	auto tar = chToRoom[getHash(mWord)];
	tar->word = mChgWord;
	tar->dir = mChgLen;

	combi[0][hf2(mWord)].erase;
	combi[1][hf4(mWord)].push(tar);
	combi[2][hc3(mWord)].push(tar);
	combi[3][hb2(mWord)].push(tar);
	combi[4][hb4(mWord)].push(tar);
}






#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string.h>

extern void init();
extern void addRoom(int mID, char mWord[], int mDirLen[]);
extern void setCurrent(char mWord[]);
extern int moveDir(int mDir);
extern void changeWord(char mWord[], char mChgWord[], int mChgLen[]);

/////////////////////////////////////////////////////////////////////////

#define INIT	0
#define ADD		1
#define SET		2
#define MOVE	3
#define CHANGE	4

#define MAX_LENGTH	(11 + 1)

static bool run()
{
	int cmd, ans, ret, mid;
	int dir[3];
	char mWord[MAX_LENGTH];
	char mRetWord[MAX_LENGTH];

	int Q = 0;
	bool okay = false;

	scanf("%d", &Q);
	for (int q = 0; q < Q; ++q)
	{
		scanf("%d", &cmd);
		switch (cmd)
		{
		case INIT:
			init();
			okay = true;
			break;

		case ADD:
			scanf("%d %s %d %d %d", &mid, mWord, &dir[0], &dir[1], &dir[2]);
			addRoom(mid, mWord, dir);
			break;

		case SET:
			scanf("%s", mWord);
			setCurrent(mWord);
			break;

		case MOVE:
			scanf("%d %d", &dir[0], &ans);
			ret = moveDir(dir[0]);
			if (ret != ans) {
				okay = false;
			}
			break;

		case CHANGE:
			scanf("%s %s %d %d %d", mWord, mRetWord, &dir[0], &dir[1], &dir[2]);
			changeWord(mWord, mRetWord, dir);
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