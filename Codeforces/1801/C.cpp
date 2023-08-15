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

enum lazytype {
    LAZY_NONE,
    LAZY_INCREASE,
    LAZY_SETVAL
};

struct  node
{
    ll val;
    node(ll tval) {
        val = tval;
    }
    node() {
        val = 0;
    }
};

node combine(const node& lval, const node& rval)
{
    return (lval.val + rval.val);
}
struct lazyobj {
    ll value = 0;
    lazytype cmdtype = LAZY_NONE;
};

class segmenttree
{
public:
    node nullval;
    bool inputisonebased;
    void propagatecommand(lazyobj& updatethis, const lazyobj& refrlazy) {
        switch (refrlazy.cmdtype)
        {
        case LAZY_NONE:
            break;
        case LAZY_SETVAL:
            updatethis.value = refrlazy.value;
            updatethis.cmdtype = LAZY_SETVAL;
            break;
        case LAZY_INCREASE:
            updatethis.value += refrlazy.value;
            if (updatethis.cmdtype == LAZY_NONE)
                updatethis.cmdtype = refrlazy.cmdtype;
            break;
        }
    }
    void fixindexing(int& a, int& b) {
        a -= inputisonebased;
        b -= inputisonebased;
    }
    void fixindexing(int& k) {
        k -= inputisonebased;
    }
    int n;
    vector<node> tree;
    vector<node> arr;
    vector<lazyobj> lazytree;
    void resolve(int v, int l, int r) {
        switch (lazytree[v].cmdtype) {
        case LAZY_NONE:
            break;
        case LAZY_INCREASE:
            tree[v].val += lazytree[v].value * (r - l + 1);
            break;
        case LAZY_SETVAL:
            tree[v].val = lazytree[v].value * (r - l + 1);
            break;
        }
        if (l == r) {
            arr[l].val = tree[v].val;
        }
        else {
            propagatecommand(lazytree[2 * v], lazytree[v]);
            propagatecommand(lazytree[2 * v + 1], lazytree[v]);
        }
        lazytree[v].value = 0;
        lazytree[v].cmdtype = LAZY_NONE;
    }

    segmenttree(vector<node>& arr, bool inputisonebased):arr(arr), inputisonebased(inputisonebased), n(arr.size())
    {
        tree.resize(4 * n + 1);
        lazytree.resize(4 * n + 1);
        build(1, 0, n - 1);
    }

    segmenttree(int n, bool inputisonebased):n(n), inputisonebased(inputisonebased)
    {
        tree.resize(4 * n + 1);
        lazytree.resize(4 * n + 1);
        arr.resize(n);
        build(1, 0, n - 1);
    }

    void build(int v, int l, int r)
    {
        if (l == r)
        {
            tree[v] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
        tree[v] = combine(tree[2 * v], tree[2 * v + 1]);
    }
    void pointupdate(int k, lazyobj update) {
        fixindexing(k);
        recrangeupdate(0, n - 1, k, k, 1, update);
    }
    void rangeupdate(int a, int b, lazyobj update) {
        fixindexing(a, b);
        if (a > b)return;
        recrangeupdate(0, n - 1, a, b, 1, update);
    }
    void recrangeupdate(int l, int r, int a, int b, int v, lazyobj update) {
        resolve(v, l, r);
        if (r<a || l>b) return;
        if (a <= l && r <= b) {
            propagatecommand(lazytree[v], update);
            resolve(v, l, r);
            return;
        }
        int mid = (l + r) / 2;
        recrangeupdate(l, mid, a, b, 2 * v, update);
        recrangeupdate(mid + 1, r, a, b, 2 * v + 1, update);
        tree[v] = combine(tree[2 * v], tree[2 * v + 1]);
    }

    node rangequery(int a, int b)
    {
        fixindexing(a, b);
        if (a > b) return nullval;
        return recrangequery(0, n - 1, a, b, 1);
    }
    node pointquery(int k) {
        fixindexing(k);
        return recrangequery(0, n - 1, k, k, 1);
    }
    node recrangequery(int l, int r, int a, int b, int v)
    {
        resolve(v, l, r);
        if (r<a || l>b)
            return nullval;
        if (a <= l && r <= b)
            return tree[v];
        int mid = (l + r) / 2;
        return combine(recrangequery(l, mid, a, b, 2 * v), recrangequery(mid + 1, r, a, b, 2 * v + 1));
    }
};

bool solve()
{
    int n;
    cin >> n;

    vector<vector<int>> a(n);
    for (int i = 0;i < n;i++) {
        int k;
        cin >> k;
        for (int j = 0;j < k;j++) {
            int x;
            cin >> x;
            if (a[i].empty() || x > a[i].back())
                a[i].push_back(x);
        }
    }

    vector<int> val(1, 0);
    vector<int> dp(1, 0);

    sort(a.begin(), a.end(), [](auto& l, auto& r) {
        return l.back() < r.back();
        });

    for (int i = 0;i < n;i++) {
        int currbest = 0;
        for (int j = 0;j < a[i].size();j++) {
            int pos = lower_bound(val.begin(), val.end(), a[i][j]) - val.begin() - 1;
            currbest = 1 + max(currbest, dp[pos]);
        }
        if (val.back() == a[i].back())
            dp.back() = max(dp.back(), currbest);
        else {
            val.push_back(a[i].back());
            dp.push_back(currbest);
        }
    }

    cout << dp.back() nl;
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
    cin >> t;
    while (t--) {
        solve();
        // cout << (solve() ? "YES\n" : "NO\n");
        // cout << (solve() ? "" : "-1\n");
    }
}
