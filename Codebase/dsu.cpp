class dsu {
public:
    vector<int> head;
    vector<int> childs;
    int n;
    dsu(int n) {
        head.resize(n + 1);
        childs.resize(n + 1);
        this->n = n;
        for (int i = 1;i <= n;i++) {
            head[i] = i;
            childs[i] = 1;
        }
    }
    int find(int x) {
        while (head[x] != head[head[x]]) {
            head[x] = head[head[x]];
        }
        return head[x];
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)return;
        if (childs[x] > childs[y])swap(x, y);
        head[x] = y;
        childs[y] += childs[x];
    }
};

class dsuWithRollback {
public:
    vector<int> head;
    vector<int> childs;
    int n;
    dsuWithRollback(int n) {
        head.resize(n + 1);
        childs.resize(n + 1);
        this->n = n;
        for (int i = 1;i <= n;i++) {
            head[i] = i;
            childs[i] = 1;
        }
    }
    vector<tuple<int, int, int>> lastmove;
    vector<int> persist;
    int find(int x) {
        while (head[x] != x) {
            x = head[x];
        }
        return head[x];
    }
    int noofConnectedComponents() {
        return n - lastmove.size();
    }
    void rollback() {
        while (lastmove.size() > persist.back()) {
            auto [x, y, headx] = lastmove.back();
            lastmove.pop_back();
            head[x] = headx;
            childs[y] -= childs[x];
        }
        persist.pop_back();
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)return;
        if (childs[x] > childs[y])swap(x, y);
        lastmove.push_back({ x,y,head[x] });
        head[x] = y;
        childs[y] += childs[x];
    }
};
