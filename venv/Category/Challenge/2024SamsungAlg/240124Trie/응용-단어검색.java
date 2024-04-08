class Trie {
    int count;
    Trie[] children;

    Trie() {
        count = 0;
        children = new Trie[26];
    }

    boolean hasChild(int idx) {
        return children[idx] != null;
    }
}

class UserSolution {
    int cnt = 0;
    boolean isRemove = false;
    Trie root = new Trie();

    void updateCount(Trie head, char[] str, int cur) {
        char c = str[cur];
        if (head != null) {
            if (c == '?') {
                for (int i = 0; i < 26; i++) {
                    if (!head.hasChild(i)) continue;
                    updateCount(head.children[i], str, cur + 1);
                }
            } else if (c == '\0') {
                cnt += head.count;
                if (isRemove) head.count = 0;
            } else {
                updateCount(head.children[c - 'a'], str, cur + 1);
            }
        }
    }

    void updateCount(char[] str) {
        cnt = 0;
        char c = str[0];
        if (c == '?') {
            for (int i = 0; i < 26; i++) {
                if (!root.hasChild(i)) continue;
                updateCount(root.children[i], str, 0);
            }
        } else {
            updateCount(root.children[c - 'a'], str, 0);
        }
    }

    void init() {
        Trie a = root;
        root = new Trie();
    }

    int add(char[] str) {
        Trie head = root;
        int i = 0;
        char c;
        while ((c = str[i]) != '\0') {
            int idx = c - 'a';
            if (head.children[idx] == null) {
                head.children[idx] = new Trie();
            }
            head = head.children[idx];
            i++;
        }

        head.count++;
        return head.count;
    }

    int remove(char[] str) {
        isRemove = true;
        updateCount(str);
        return cnt;
    }

    int search(char[] str) {
        isRemove = false;
        updateCount(str);
        return cnt;
    }

}
