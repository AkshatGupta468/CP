#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cerr<<i<<" ";
#define nl <<'\n'
#define sp <<" "<<
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug2(n1,n2) cerr << #n1 << " : "; _dprint(n1);cerr << "  " << #n2 << " : "; _dprint(n2) ;cerr<< '\n';
#ifndef ONLINE_JUDGE
#define debug(n) cerr << #n << " : "; _dprint(n);cerr <<'\n'; 
#else 
#define debug(n)
#endif
template<class T>
void _dprint(vector<T> a) { display(a) };
template<class T>
void _dprint(T a) { cerr << a; }

struct node {
    ll val;
    node() {
        val = 1e18;
    }
    node(int val) :val(val) {};
};

node combine(const node& l, const node& r) {
    return node(min(l.val, r.val));
}

class Segmentree {
    vector<int> a;
    vector<node> tree;
    int n;
    bool isInputOnebased = true;
public:
    Segmentree(int n, bool isInputOnebased) :n(n), isInputOnebased(isInputOnebased) {
        tree.resize(4 * n + 1);
        a.resize(n);
    }
    Segmentree(vector<node> a, bool isInputOnebased) :n(a.size()), a(a), isInputOnebased(isInputOnebased) {
        buildtree(0, n - 1, 1);
    }

    void fixIndexing(int& k) {
        if (isInputOnebased)k--;
    }

    node buildtree(int l, int r, int v) {
        if (l == r) {
            tree[v] = a[l];
            return tree[v];
        }
        int mid = (l + r) / 2;
        buildtree(l, mid, 2 * v);
        buildtree(mid + 1, r, 2 * v + 1);
        tree[v] = combine(tree[2 * v], tree[2 * v + 1]);
        return tree[v];
    }

    void pointupdate(int pos, node updateval) {
        fixIndexing(pos);
        recPointUpdate(0, n - 1, pos, 1, updateval);
    }

    void recPointUpdate(int l, int r, int pos, int v, const node& updateval) {
        if (pos < l || r < pos)return;
        if (l == r && l == pos) {
            tree[v] = updateval;
           , return;
        }
        int mid = (l + r) / 2;
        recPointUpdate(l, mid, pos, 2 * v, updateval);
        recPointUpdate(mid + 1, r, pos, 2 * v + 1, updateval);
        tree[v] = combine(tree[2 * v + 1], tree[2 * v]);
    }

    node rangeQuery(int ql, int qr) {
        fixIndexing(ql);
        fixIndexing(qr);
        return recRangeQuery(0, n - 1, ql, qr, 1);
    }

    node recRangeQuery(int l, int r, int ql, int qr, int v) {
        if (qr < l || r < ql)return node();
        if()
        int mid = (l + r) / 2;
        return combine(recRangeQuery(l, mid, ql, qr, 2 * v), recRangeQuery(mid + 1, r, ql, qr, 2 * v + 1));
    }

};
void solve()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<node> a(n);
    for (int i = 0;i < n;i++) {
        cin >> a[i].val;
    }
    Segmentree S(a, true);
    for (int i = 0;i < m;i++) {
        int type;
        cin >> type;
        int x, y;
        cin >> x >> y;
        if (type == 2)
            cout << S.rangeQuery(x, y).val nl;
        else
            S.pointupdate(x, y);
    }

}

int main()
{
    // fast_io;
    solve();
}
