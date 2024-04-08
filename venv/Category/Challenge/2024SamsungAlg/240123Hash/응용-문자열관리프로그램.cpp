#include<vector>
#include<queue>
#define MAX 150'000
using namespace std;

deque<char> dq;
bool reversed;
int hashCnt[1<<20];

void hashing_back(int offset){
	int hash=0;
	for(int i=dq.size()-1, j=0; i>=0 && j<4;i--, j++){
		hash <<= 5;
		hash += dq[i]-'a'+1;
		hashCnt[hash] += offset;
	}
}
void hashing_front(int offset){
	int hash=0, power32 = 1;
	for(int i=0;i<4 && i<dq.size();i++){
		hash += power32*(dq[i]-'a'+1);
		power32 <<= 5;
		hashCnt[hash]+=offset;
	}
}

void init(char mStr[])
{
	dq.clear();
	reversed=false;
	fill_n(hashCnt, 1<<20, 0);

	int N=0;
	char c;
	while((c=mStr[N++])!='\0'){
		dq.push_back(c);
		hashing_back(1);
	}
}
void appendWord(char mWord[])
{
	int cur=0;
	char c;
	while((c=mWord[cur++])!='\0'){
		if(reversed) {
			dq.push_front(c);
			hashing_front(1);
		}
		else {
			dq.push_back(c);
			hashing_back(1);
		}
	}
}

void cut(int k)
{
	if(reversed){
		for(int i(0);i<k;i++) {
			hashing_front(-1);
			dq.pop_front();
		}
	}else{
		for(int i(0);i<k;i++) {
			hashing_back(-1);
			dq.pop_back();
		}
	}
}

void reverse()
{
	reversed = !reversed;
}
int countOccurrence(char mWord[])
{
	int hash=0;
	if(reversed){
		for(int i=0;mWord[i];i++){
			hash <<= 5;
			hash+=(mWord[i]-'a'+1);
		}
	}else{
		int power32=1; //?
		for(int i=0;mWord[i];i++){
			hash += power32*(mWord[i]-'a'+1);
			power32 <<= 5;
		}
	}
	return hashCnt[hash];
}






#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define CMD_INIT    1
#define CMD_APPEND  2
#define CMD_CUT     3
#define CMD_REVERSE 4
#define CMD_COUNT   5

extern void init(char mStr[]);
extern void appendWord(char mWord[]);
extern void cut(int k);
extern void reverse();
extern int countOccurrence(char mWord[]);

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

static bool run()
{
	bool correct = false;
	int queryCnt;
	scanf("%d", &queryCnt);
	static char mStr[30001], mWord[5];

	while (queryCnt--)
	{
		int cmd;
		scanf("%d", &cmd);

		if (cmd == CMD_INIT)
		{
			scanf("%s", mStr);
			init(mStr);
			correct = true;
		}
		else if (cmd == CMD_APPEND)
		{
			scanf("%s", mWord);
			
			if (correct)
			{
				appendWord(mWord);
			}
		}
		else if (cmd == CMD_CUT)
		{
			int k;
			scanf("%d", &k);
			
			if (correct)
			{
				cut(k);
			}
		}
		else if (cmd == CMD_REVERSE)
		{
			if (correct)
			{
				reverse();
			}
		}
		else if (cmd == CMD_COUNT)
		{
			scanf("%s", mWord);

			int ret = -1;
			if (correct)
			{
				ret = countOccurrence(mWord);
			}

			int ans;

			scanf("%d", &ans);
			if(ret != ans)
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