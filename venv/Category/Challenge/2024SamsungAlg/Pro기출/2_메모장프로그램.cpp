#include<stdio.h>

#define MAX 305
#include<deque>
using namespace std;
int H,W, curH, curW;
deque<char> memo[MAX];
int counting[MAX][26]; // 행의 알파벳의 개수를 저장
int length;
void init(int h, int w, char mStr[]) // 90000+30000
{
	H=h; W=w;
	curH=curW=length=0;
	int i;
	for(int i=0;i<MAX;i++){
		memo[i].clear();
		fill_n(counting[i], 26, 0);
	}
	for(i=0;mStr[i];i++){
		length++;
		memo[i/W].push_back(mStr[i]);
		counting[i/W][mStr[i]-'a']++;
	}
}

void insert(char mChar)
{
	memo[curH].insert(memo[curH].begin()+curW, mChar); // deque 중간에 삽입 가능;
	counting[curH][mChar-'a']++;

	int tmpH=curH;
	curW++;
	if(curW==W){
		curH++; curW=0;
	}
	while((int)memo[tmpH].size() > W){
		char tmp=memo[tmpH].back();
		memo[tmpH].pop_back();
		counting[tmpH][tmp-'a']--;

		memo[tmpH+1].push_front(tmp);
		counting[tmpH+1][tmp-'a']++;
		tmpH++;
	}
	length++;
}

char moveCursor(int mRow, int mCol)
{
	mRow--; mCol--;
	if(mRow*W + mCol >= length){
		curH = length/W;
		curW = length%W;
		return '$';
	}
	curH=mRow; curW=mCol;
	return memo[mRow][mCol];
}

int countCharacter(char mChar)
{
	int row=curH, col=curW;
	int ret =0;
	if(col){
		for(int i=col; i < (int) memo[row].size();i++){
			ret += (memo[row][i]==mChar);
		}
		++row;
	}
	for(int i=row;i<H;i++){
		ret+= counting[i][mChar-'a'];
	}
	return ret;
}











#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define CMD_INIT       100
#define CMD_INSERT     200
#define CMD_MOVECURSOR 300
#define CMD_COUNT      400

extern void init(int H, int W, char mStr[]);
extern void insert(char mChar);
extern char moveCursor(int mRow, int mCol);
extern int countCharacter(char mChar);

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

static bool run()
{
	bool correct = false;
	int queryCnt;
	scanf("%d", &queryCnt);
	int H, W;
	char mChar;
	static char mStr[90001];

	while (queryCnt--)
	{
		int cmd;
		scanf("%d", &cmd);

		if (cmd == CMD_INIT)
		{
			scanf("%d %d %s", &H, &W, mStr);
			init(H, W, mStr);
			correct = true;
		}
		else if (cmd == CMD_INSERT)
		{
			scanf(" %c", &mChar);
			insert(mChar);
		}
		else if (cmd == CMD_MOVECURSOR)
		{
			int mRow, mCol;
			scanf("%d %d", &mRow, &mCol);

			char ret = moveCursor(mRow, mCol);

			char ans;
			scanf(" %c", &ans);
			if (ret != ans)
			{
				correct = false;
			}
		}
		else if (cmd == CMD_COUNT)
		{
			scanf(" %c", &mChar);

			int ret = countCharacter(mChar);

			int ans;
			scanf("%d", &ans);
			if (ret != ans)
			{
				correct = false;
			}
		}
	}
	return correct;
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