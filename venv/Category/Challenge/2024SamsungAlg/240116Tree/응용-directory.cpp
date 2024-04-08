#define NAME_MAXLEN 6
#define PATH_MAXLEN 1999

// The below commented functions are for your reference. If you want 
// to use it, uncomment these functions.
/*
int mstrcmp(const char *a, const char *b)
{
	int i;
	for (i = 0; a[i] != '\0'; i++)
	{
		if (a[i] != b[i])
			return a[i] - b[i];
	}
	return a[i] - b[i];
}

int mstrncmp(const char *a, const char *b, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (a[i] != b[i])
			return a[i] - b[i];
	}
	return 0;
}

int mstrlen(const char *a)
{
	int len = 0;

	while (a[len] != '\0')
		len++;

	return len;
}

void mstrcpy(char *dest, const char *src)
{
	int i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
}

void mstrncpy(char *dest, const char *src, int len)
{
	for (int i = 0; i<len; i++)
	{
		dest[i] = src[i];
	}
	dest[len] = '\0';
}
*/
#include<iostream>
#include<vector>
#include<map>
using namespace std;
vector<string> split(char path[]){
    vector<string> res;
    string tmp="";
    for(int i=0; i<sizeof(path); i++){
        char c=path[i];
        if(c=='/'){
            res.push_back(tmp);
            tmp="";
        }
        tmp+=c;
    }
    return res;
}
struct Node{
    string value;
    vector<Node*> child;

    void addDirectory(string name){
        Node newNode;
        newNode.value=name;
        child.push_back(&newNode);
    }
    void addDirectory(Node* node){
        child.push_back(node);
    }
    void removeDirectory(){
        child.clear();
    }
};
Node root;
map<string, Node*> cache;

Node* findNode(vector<string> path){
    Node* head = &root;
    for(int i=0;i<path.size();i++){
        for(auto next: head->child){
            if(next->value==path[i]){
                head = next;
                continue;
            }
        }
    }
    return head;
}

void init(int n) {
    root.value="";
    root.child.clear();
// 각 testcase 시작 시, 초기화를 위해 1번 호출되고 루트 디렉터리를 생성한다.

// Parameters
// n: 이번 testcase에서 루트 디렉터리를 포함하여 생성되는 최대 디렉터리의 개수 (5 ≤ n ≤ 50,000)
}

void cmd_mkdir(char path[PATH_MAXLEN + 1], char name[NAME_MAXLEN + 1]) {
    auto pathStr=split(path);
    string newDir(name);

    Node* target = findNode(pathStr);
    target->addDirectory(newDir);
    // cache.insert(pathStr, target);
}

void cmd_rm(char path[PATH_MAXLEN + 1]) {
    auto pathStr=split(path);
    Node *target = findNode(pathStr);
    target->removeDirectory();
}

void cmd_cp(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {
    auto src=split(srcPath);
    auto dst=split(dstPath);
    Node *srcTarget = findNode(src);
    Node *dstTarget = findNode(dst);

    dstTarget->addDirectory(srcTarget);
}

void cmd_mv(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]) {
    auto src=split(srcPath);
    auto dst=split(dstPath);
    Node *srcTarget = findNode(src);
    Node *dstTarget = findNode(dst);
}
int count(Node *tree){
    int res=1;
    for(auto child: tree->child){
        res += count(child);
    }
    return res;
}
int cmd_find(char path[PATH_MAXLEN + 1]) {
    auto pathStr=split(path);
    auto target = findNode(pathStr);
	return count(target);
    // return 0;
}











#ifndef _CRT_SECURE_NO_WARNINGS 
#define _CRT_SECURE_NO_WARNINGS 
#endif

#include<stdio.h>

#define CMD_MKDIR 1
#define CMD_RM 2
#define CMD_CP 3
#define CMD_MV 4
#define CMD_FIND 5

#define NAME_MAXLEN 6
#define PATH_MAXLEN 1999

extern void init(int n);
extern void cmd_mkdir(char path[PATH_MAXLEN + 1], char name[NAME_MAXLEN + 1]);
extern void cmd_rm(char path[PATH_MAXLEN + 1]);
extern void cmd_cp(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]);
extern void cmd_mv(char srcPath[PATH_MAXLEN + 1], char dstPath[PATH_MAXLEN + 1]);
extern int cmd_find(char path[PATH_MAXLEN + 1]);

static bool run(int m) {

	bool isAccepted = true;
	int cmd;
	char name[NAME_MAXLEN + 1];
	char path1[PATH_MAXLEN + 1], path2[PATH_MAXLEN + 1];

	while (m--) {

		scanf("%d", &cmd);

		if (cmd == CMD_MKDIR) {
			scanf("%s%s", path1, name);
			cmd_mkdir(path1, name);
		}
		else if (cmd == CMD_RM) {
			scanf("%s", path1);
			cmd_rm(path1);
		}
		else if (cmd == CMD_CP) {
			scanf("%s%s", path1, path2);
			cmd_cp(path1, path2);
		}
		else if (cmd == CMD_MV) {
			scanf("%s%s", path1, path2);
			cmd_mv(path1, path2);
		}
		else {
			int ret;
			int answer;

			scanf("%s", path1);
			ret = cmd_find(path1);
			scanf("%d", &answer);

			isAccepted &= (ret == answer);
		}
	}

	return isAccepted;
}

int main(void) {

	int test, T;
	int n, m;

	// freopen("sample_input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d", &T);

	for (test = 1; test <= T; ++test) {

		scanf("%d%d", &n, &m);

		init(n);

		if (run(m)) {
			printf("#%d 100\n", test);
		}
		else {
			printf("#%d 0\n", test);
		}
	}

	return 0;
}