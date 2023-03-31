#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cerr<<i<<" ";
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
void _dprint(vector<T> a) { display(a) };
template<class T>
void _dprint(T a) { cerr << a << "\n"; }

enum lazytype {
    LAZY_NONE,
    LAZY_SETVALFIRST,
    LAZY_SETVALSECOND
};
struct  node
{
    ll low, high, first, second;
    node() {
        low = 0;
        high = 1e9;
    }
    node(ll _low, ll _high) {
        low = _low;
        high = _high;
    }
    void calclim() {
        low = 0;
        high = 1e9;

        if (first < second)high = (first + second) / 2;
        else if (first > second) low = (first + second + 1) / 2;
    }
};
node combine(const node& lval, const node& rval)
{
    return node(max(lval.low, rval.low), min(lval.high, rval.high));
}
struct lazyobj
{
    ll value = 0;
    lazytype cmdtype = LAZY_NONE;
    //    lazyobj(ll _value,lazytype _cmdtype){

    //    }
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
        default:
            updatethis.value = refrlazy.value;
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
        case LAZY_SETVALFIRST:
            tree[v].first = lazytree[v].value * (r - l + 1);
            break;
        case LAZY_SETVALSECOND:
            tree[v].second = lazytree[v].value * (r - l + 1);
            break;
        }
        if (l == r) {
            tree[v].calclim();
            arr[l] = tree[v];
        }
        // else{
        //     propagatecommand(lazytree[2*v],lazytree[v]);
        //     propagatecommand(lazytree[2*v+1],lazytree[v]);
        // } 
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
    // void rangeupdate(int a,int b,lazyobj update){
    //     fixindexing(a,b);
    //     if(a>b)return;
    //     recrangeupdate(0,n-1,a,b,1,update);
    // }
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
    vector<node> a(n - 1);
    cin >> a[0].first;
    for (int i = 0;i < n - 2;i++) {
        int x;cin >> x;
        a[i].second = x;
        a[i + 1].first = x;
    }
    cin >> a[n - 2].second;
    for (auto& i : a) {
        i.calclim();
    }
    segmenttree S(a, true);
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1) {
            int i, x;cin >> i >> x;
            if (i != 1)S.pointupdate(i - 1, { x,LAZY_SETVALSECOND });
            if (i != n)S.pointupdate(i, { x,LAZY_SETVALFIRST });
        }
        else {
            int l, r;cin >> l >> r;
            if (l == r) {
                cout << 0 nl;
                continue;
            }
            node qur = S.rangequery(l, r - 1);
            if (qur.low <= qur.high)cout << qur.low nl;
            else cout << -1 nl;
        }
    }
}

int main()
{
    fast_io;
#ifdef __linux__
    string path = "/mnt/3C401CB3401C75BC/CP/";
#elif _WIN32
    string path = "D:/CP/";
#endif
#ifndef ONLINE_JUDGE
    freopen((path + "input.txt").c_str(), "r", stdin);
    freopen((path + "output.txt").c_str(), "w", stdout);
    freopen((path + "error.txt").c_str(), "w", stderr);
#endif
    solve();
}
