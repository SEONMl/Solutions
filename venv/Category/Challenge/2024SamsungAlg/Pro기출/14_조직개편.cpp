using namespace std;
#include<vector>
#include<unordered_map>
struct Node {
	int num, accumNum; Node* parent;
	vector<Node*> children={};
	bool removed;

	Node(int n, Node* p) : num(n), accumNum(n), parent(p), removed(false) {}
};
unordered_map<int, Node*> tree;
void init(int mId, int mNum) {
	tree.clear();

	Node* root = new Node(mNum, NULL);
	tree[mId] = root;

	return;
}

int add(int mId, int mNum, int mParent) { // 8000
	Node* parent = tree[mParent];
	if (parent->children.size() >= 2) {
		return -1;
		// 입력 오류 ㅡㅡ 틀릴리가 없지
	}

	Node* node = new Node(mNum, parent);
	tree[mId] = node;

	parent->children.push_back(node);

	Node* nxt = parent;
	while (nxt != NULL) {
		nxt->accumNum += mNum;
		nxt = nxt->parent;
	}

	return parent->accumNum;
}

void removeChildren(Node* node) {
	for (auto nxt : node->children) {
		removeChildren(nxt);
	}
	node->removed = true;
}

int remove(int mId) { // 1000
	if (tree.find(mId) == tree.end()) return -1;

	Node* nxt = tree[mId]->parent;
	while (nxt != 0) {
		if (nxt->removed) return -1;
		nxt = nxt->parent;
	}

	removeChildren(tree[mId]);

	return tree[mId]->accumNum;
}

int reorganize(int M, int K) { //1000	bs

	return 0;
}





#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern void init(int mId, int mNum);
extern int add(int mId, int mNum, int mParent);
extern int remove(int mId);
extern int reorganize(int M, int K);

/////////////////////////////////////////////////////////////////////////

#define CMD_INIT 1
#define CMD_ADD 2
#define CMD_REMOVE 3
#define CMD_REORGANIZE 4

static bool run() {
	int q;
	scanf("%d", &q);

	int mid, mnum, mparent, m, k;
	int cmd, ans, ret = 0;
	bool okay = false;

	for (int i = 0; i < q; ++i) {
		scanf("%d", &cmd);
		switch (cmd) {
		case CMD_INIT:
			scanf("%d %d", &mid, &mnum);
			init(mid, mnum);
			okay = true;
			break;
		case CMD_ADD:
			scanf("%d %d %d %d", &mid, &mnum, &mparent, &ans);
			ret = add(mid, mnum, mparent);
			if (ans != ret)
				okay = false;
			break;
		case CMD_REMOVE:
			scanf("%d %d", &mid, &ans);
			ret = remove(mid);
			if (ans != ret)
				okay = false;
			break;
		case CMD_REORGANIZE:
			scanf("%d %d %d", &m, &k, &ans);
			ret = reorganize(m, k);
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
	freopen("C:\\Dev\\projects\\Solutions\\venv\\Category\\.vscode\\input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++) {
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}