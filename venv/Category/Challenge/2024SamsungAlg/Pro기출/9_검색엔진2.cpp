#include<unordered_map>
#include<vector>
#define MAX 15005
using namespace std;
#include<iostream>
typedef long long ll;
int relation[MAX];
int find(int x){
	if(relation[x]==x) return relation[x];
	return relation[x]=find(relation[x]);
}
void unionBoth(int x,int y){
	int a=find(x), b=find(y);
	if(a<b) relation[a]=b;
	else relation[b]=a;
}
ll compress[MAX];
ll hashing(char *ch){
	ll hash=0; int cur=0;
	while(ch[cur]!='\0'){
		hash<<=5;
		hash += ch[cur++]-'a';
	}
	return hash;	
}
int ID=0;
struct Trie{
	int id;
	char value;
	Trie *children[26];
	Trie(char v){
		value = v;
		for(int i=0;i<26;i++) children[i]=NULL;
	}
	
	void insert(char ch[]){
		Trie *head = this;
		for(int i=0;ch[i];i++){
			char c = ch[i];
			if(head->children[c-'a']==NULL) head->children[c-'a'] = new Trie(c);
			head = head->children[c-'a'];
		}
		head->id = ID++;
	}
};
Trie *root;
struct Result
{
	int mOrder;
	int mRank;
};

void init()
{
	ID = 0;
	root = new Trie(' ');
	for(int i=0;i<MAX;i++){
		relation[i]=i;
		compress[i]=-1;
	}
	return;
}

void search(char mStr[], int mCount)// 15000
{

	return;
}

Result recommend(char mStr[])//500
{

	Result ret = { 0, 0 };
	return ret;
}

int relate(char mStr1[], char mStr2[]) //50
{
	return 0;
}

void rank1(char mPrefix[], int mRank, char mReturnStr[]) // 	8000
{
	return;
}






#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string.h>

extern void init();
extern void search(char mStr[], int count);
extern Result recommend(char mStr[]);
extern int relate(char mStr1[], char mStr2[]);
extern void rank1(char mPrefix[], int mRank, char mReturnStr[]);

#define MAX_LENGTH      (7 + 1)
#define CMD_INIT		(100)
#define CMD_SEARCH		(200)
#define CMD_RECOMMEND	(300)
#define CMD_RELATE		(400)
#define CMD_RANK		(500)

static bool run()
{
	int query_num;
	bool okay = false;

	scanf("%d", &query_num);

	for (int q = 0; q < query_num; ++q) {
		int cmd, ret, ans, ans2, mCount, mRank;
		char mStr[MAX_LENGTH], mStr2[MAX_LENGTH], mReturnStr[MAX_LENGTH];
		Result res;

		scanf("%d", &cmd);

		switch (cmd) {
		case CMD_INIT:
			init();
			okay = true;
			break;
		case CMD_SEARCH:
			scanf("%s %d", mStr, &mCount);
			search(mStr, mCount);
			break;
		case CMD_RECOMMEND:
			scanf("%s", mStr);
			res = recommend(mStr);
			scanf("%d %d", &ans, &ans2);
			if (res.mOrder != ans || res.mRank != ans2)
				okay = false;
			break;
		case CMD_RELATE:
			scanf("%s %s", mStr, mStr2);
			ret = relate(mStr, mStr2);
			scanf("%d", &ans);
			if (ret != ans)
				okay = false;
			break;
		case CMD_RANK:
			scanf("%s %d", mStr, &mRank);
			rank1(mStr, mRank, mReturnStr);
			scanf("%s", mStr2);
			if (strncmp(mStr2, mReturnStr, MAX_LENGTH) != 0)
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

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++) {
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}