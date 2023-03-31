struct node {
    int val;
    node(int val = 1e9):val(val) {}
};

struct upd {
    int pos;
    upd(int pos = 0):pos(pos) {};
};

node combine(const node& l, const node& r) {
    return min(l.val, r.val);
}

class centroidDecomposition {
public:
    int n;
    vector<vector<int>> adj;
    vector<int> sz;
    vector<int> decHead;
    vector<int> parent;
    vector<bool> removed;
    binruplift B;

    vector<node> tree;
    void resolve(int u, upd q) {
        tree[u].val = min(tree[u].val, B.getDistance(u, q.pos));
    }
    centroidDecomposition(int n, vector<vector<int>> adj):n(n), adj(adj) {
        sz.resize(n + 1, 1);
        decHead.resize(n + 1);
        removed.resize(n + 1, false);
        parent.resize(n + 1);
        tree.resize(n + 1);
        getsz(1, 0);
        build(1, 0);
        B = binruplift(n, parent);
    }

    void getsz(int u, int p) {
        parent[u] = p;
        for (auto& v : adj[u])
            if (v != p) {
                getsz(v, u);
                sz[u] += sz[v];
            }
    };

    int getcentroid(int u, int n) {
        for (auto& v : adj[u]) {
            if (sz[v] > n / 2) {
                sz[u] -= sz[v];
                sz[v] += sz[u];
                return getcentroid(v, n);
            }
        }
        return u;
    };

    void build(int u, int p) {
        u = getcentroid(u, sz[u]);
        decHead[u] = p;
        removed[u] = true;
        sz[u] = 0;
        for (auto& v : adj[u]) {
            if (!removed[v])
                build(v, u);
        }
    };

    node getmin(int q) {
        node res;
        for (int u = q;u != 0;u = decHead[u]) {
            res = combine(res, tree[u].val + B.getDistance(q, u));
        }
        return res;
    }

    void update(int u, upd q) {
        for (;u != 0;u = decHead[u]) {
            resolve(u, q);
        }
    }
};
