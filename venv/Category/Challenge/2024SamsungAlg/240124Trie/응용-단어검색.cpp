#include <iostream>
#include <vector>

using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
    int count;
    TrieNode* children[ALPHABET_SIZE];

    TrieNode() : count(0) {
        fill(children, children + ALPHABET_SIZE, nullptr);
    }
};

class Trie {
public:
    Trie() : root(new TrieNode), cnt(0), isRemove(false) {}

    ~Trie() {
        // Trie를 사용한 후에는 메모리를 해제해야 합니다.
        deleteTrie(root);
    }

    void updateCount(const char* str) {
        cnt = 0;
        char c = *str;
        if (c == '?') {
            for (int i = 0; i < ALPHABET_SIZE; i++) {
                if (root->children[i] != nullptr) {
                    updateCount(root->children[i], str + 1);
                }
            }
        } else {
            updateCount(root->children[c - 'a'], str + 1);
        }
    }

    void init() {
        // 기존 Trie를 삭제하고 새로운 Trie를 생성합니다.
        deleteTrie(root);
        root = new TrieNode;
    }

    int add(const char* str) {
        TrieNode* head = root;
        int idx;
        while (*str != '\0') {
            idx = *str - 'a';
            if (head->children[idx] == nullptr) {
                head->children[idx] = new TrieNode;
            }
            head = head->children[idx];
            str++;
        }

        head->count++;
        return head->count;
    }

    int remove(const char* str) {
        isRemove = true;
        updateCount(str);
        return cnt;
    }

    int search(const char* str) {
        isRemove = false;
        updateCount(str);
        return cnt;
    }

private:
    TrieNode* root;
    int cnt;
    bool isRemove;

    void updateCount(TrieNode* head, const char* str) {
        char c = *str;
        if (head != nullptr) {
            if (c == '?') {
                for (int i = 0; i < ALPHABET_SIZE; i++) {
                    if (head->children[i] != nullptr) {
                        updateCount(head->children[i], str + 1);
                    }
                }
            } else if (c == '\0') {
                cnt += head->count;
                if (isRemove) head->count = 0;
            } else {
                updateCount(head->children[c - 'a'], str + 1);
            }
        }
    }

    void deleteTrie(TrieNode* node) {
        if (node != nullptr) {
            for (int i = 0; i < ALPHABET_SIZE; i++) {
                deleteTrie(node->children[i]);
            }
            delete node;
        }
    }
};









#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern void init();
extern int add(char str[]);
extern int remove(char str[]);
extern int search(char str[]);

/////////////////////////////////////////////////////////////////////////

#define MAX_LEN 30
#define CMD_INIT 1
#define CMD_ADD 2
#define CMD_REMOVE 3
#define CMD_SEARCH 4

static bool run() {
	int q;
	scanf("%d", &q);

	char str[MAX_LEN + 1];
	int cmd, ans, ret = 0;
	bool okay = false;

	for (int i = 0; i < q; ++i) {
		scanf("%d", &cmd);
		switch (cmd) {
			case CMD_INIT:
				init();
				okay = true;
				break;
			case CMD_ADD:
				scanf("%s %d", str, &ans);
				ret = add(str);
				if (ans != ret)
					okay = false;
				break;
			case CMD_REMOVE:
				scanf("%s %d", str, &ans);
				ret = remove(str);
				if (ans != ret)
					okay = false;
				break;
			case CMD_SEARCH:
				scanf("%s %d", str, &ans);
				ret = search(str);
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
    freopen("C:\\Dev\\projects\\Solutions\\venv\\Category\\.vscode\\input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++) {
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}