const int k = 26;

class Trie {
    struct node {
        int count = 0;
        vector<int> next;
        node() {
            next.assign(k, -1);
        }
    };
    vector<node> tree;
    Trie() {
        tree.resize(1);
    }
public:
    void add_string(string s) {
        int x = 0;
        for (int i = 0;i < s.length();i++) {
            if (tree[x].next[s[i] - 'a'] == -1) {
                tree[x].next[s[i] - 'a'] = tree.size();
                tree.emplace_back();
            }
            x = tree[x].next[s[i] - 'a'];
        }
        tree[x].count++;
    }

    int countString(string s) {
        int x = 0;
        for (int i = 0;i < s.length();i++) {
            if (tree[x].next[s[i] - 'a'] == -1)return false;
            x = tree[x].next[s[i] - 'a'];
        }
        return tree[x].count;
    }
};