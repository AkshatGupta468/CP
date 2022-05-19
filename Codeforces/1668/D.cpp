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
class fenwick {
public:
    vector<ll> tree;
    fenwick(int n) {
        tree.resize(n + 1, -1e7);
    }
    void update(int x, ll val) {
        while (x < tree.size())
        {
            tree[x] = max(tree[x], val);
            x += (x & -x);
        }
    }
    ll query(int x) {
        ll q = -1e17;
        while (x > 0)
        {
            q = max(tree[x], q);
            x -= (x & -x);
        }
        return q;
    }
};
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n+1), dp(n+1);
    vector<ll> prefix(n+1);
    vector<pair<ll,ll>> tp(n);
    for (ll i = 1;i <= n;i++) {
        cin >> a[i];
        prefix[i] += prefix[i - 1] + a[i];
        tp[i-1]={prefix[i],-i};
    }
    sort(tp.begin(), tp.end());
    vector<int> m(n+1);
    for (int i = 0;i < n;i++) {
        m[-tp[i].second] = i + 1;
    }
    fenwick f(n);
    
    for (int i = 1;i <= n;i++) {
        dp[i] = (a[i] > 0);
        dp[i] = -int(a[i] < 0);
        dp[i] += dp[i - 1];
        dp[i] = max(dp[i],f.query(m[i]) + i);
        if(prefix[i]>0)dp[i]=i;
        f.update(m[i], dp[i] - i);
    }
    cout << dp[n] nl;
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
    int t;
    cin >> t;
    while (t--)
        solve();
}
