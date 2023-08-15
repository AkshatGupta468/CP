#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#ifdef __linux__
#include "/media/gakshat468/New Volume/CP/algo/debug.h"
#elif _WIN32
#include "D:/CP/algo/debug.h"
#endif
#else
#define debug(...) 42
#endif
#define MOD 1000000007
#define nl <<'\n'
#define display_vec(a) for(auto i:a)cout<<i<<" "; cout <<"\n";
#define sp <<" "<<
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#pragma GCC target("popcnt")

class binruplift {
public:
    int n;
    vector<vector<int>> anc;
    vector<int> decHead;
    vector<int> height;
    int sz;
    binruplift(int n, vector<int> p):decHead(p), n(n) {
        height.resize(n + 1, -1);
        anc_precomp(p);
        sz = anc[0].size() - 1;
        height[0] = 0;
        for (int i = 1;i <= n;i++) {
            if (height[i] < 0)calht(i, height, p);
        }
    }
    binruplift() {}

    int kthancestor(int k, int x) {
        int j = 0;
        while (k > 0) {
            if (k & 1) x = anc[x][j];
            k >>= 1;
            j++;
        }
        return x;
    }

    void anc_precomp(vector<int>& p) {
        anc.resize(n + 1);
        anc[0].push_back(0);
        anc[1].push_back(0);
        for (int i = 2;i <= n;i++) {
            anc[i].push_back(p[i]);
        }
        int k = 2;
        for (int j = 1;k <= n;j++, k <<= 1) {
            anc[0].push_back(0);
            for (int i = 1;i <= n;i++) {
                anc[i].push_back(anc[anc[i][j - 1]][j - 1]);
            }
        }
    }
    int calht(int x, vector<int>& height, vector<int>& p) {
        if (height[x] >= 0) return height[x];
        height[x] = calht(p[x], height, p) + 1;
        return height[x];
    }
    int findlca(int a, int b) {
        if (height[a] > height[b]) swap(a, b);
        b = kthancestor(height[b] - height[a], b);
        return findlcarec(a, b, sz);
    }
    int findlcarec(int a, int b, int r) {
        if (a == b) return a;
        if (r == 0) return anc[a][0];
        if (anc[a][r - 1] == anc[b][r - 1]) {
            return findlcarec(a, b, r - 1);
        }
        else return findlcarec(anc[a][r - 1], anc[b][r - 1], r - 1);
    }
    int getDistance(int u, int v) {
        int l = findlca(u, v);
        return height[u] + height[v] - 2 * height[l];
    }
};


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

bool solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0;i < n - 1;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    centroidDecomposition A(n, adj);
    A.update(1, upd(1));
    while (m--) {
        int type, v;
        cin >> type >> v;
        switch (type)
        {
        case 1:
            A.update(v, v);
            break;
        case 2:
            cout << A.getmin(v).val nl;
            break;
        }
    }
    return true;
}

int main()
{
    fast_io;
#ifdef __linux__
    string path = "/media/gakshat468/New Volume/CP/";
#elif _WIN32
    string path = "D:/CP/";
#endif
#ifndef ONLINE_JUDGE
    freopen((path + "input.txt").c_str(), "r", stdin);
    freopen((path + "output.txt").c_str(), "w", stdout);
    freopen((path + "error.txt").c_str(), "w", stderr);
#endif
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
        // cout << (solve() ? "YES\n" : "NO\n");
        // cout << (solve() ? "" : "-1\n");
    }
}
