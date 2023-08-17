#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl <<'\n'
#define sp <<" "<<
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug2(n1,n2) cerr << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
#ifndef ONLINE_JUDGE
#define debug(n) cerr << #n << " : "; _dprint(n); 
#else 
#define debug(n)
#endif
template<class T>
void _dprint(vector<T> a) { for (auto& i : a)cerr << i << " ";cerr nl; };
template<class T>
void _dprint(T a) { cerr << a << "\n"; }

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
    return min(lval.val, rval.val);
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
            tree[v].val += lazytree[v].value;
            break;
        case LAZY_SETVAL:
            tree[v].val = lazytree[v].value;
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

    segmenttree(vector<node>& tarr, bool _inputisonebased)
    {
        n = tarr.size();
        inputisonebased = _inputisonebased;
        tree.resize(4 * n + 1);
        lazytree.resize(4 * n + 1);
        arr = tarr;
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


void solve()
{
    int n, q;
    cin >> n >> q;
    vector<node> arr(n);
    for (int i = 0;i < n;i++) {
        cin >> arr[i].val;
    }
    segmenttree S(arr, true);
    while (q--)
    {
        int type;cin >> type;
        lazyobj x;
        int a, b;
        switch (type)
        {
        case 1:
            cin >> a >> b >> x.value;
            x.cmdtype = LAZY_INCREASE;
            S.rangeupdate(a, b, x);
            break;
        case 2:
            cin >> a >> b >> x.value;
            x.cmdtype = LAZY_SETVAL;
            S.rangeupdate(a, b, x);
            break;
        case 3:
            cin >> a >> b;
            cout << S.rangequery(a, b).val nl;
            break;
        }
    }
}

int main()
{
    fast_io;
#ifndef ONLINE_JUDGE
    string path = "../../";
    freopen((path + "input.txt").c_str(), "r", stdin);
    freopen((path + "output.txt").c_str(), "w", stdout);
    freopen((path + "error.txt").c_str(), "w", stderr);
#endif
    solve();
}

