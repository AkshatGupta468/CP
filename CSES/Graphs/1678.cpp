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
bool cycledetectionDirected(vector<ll> adj[], ll n) {
    bool flag = false;
    vector<int> vis(n + 1);
    vector<int> ans;
    function<bool(int)> dfs = [&](int x) {
        if (vis[x] == 2)return false;
        ans.push_back(x);
        // cerr << x nl;
        if (vis[x] == 1)return true;
        // cerr << x nl;
        vis[x] = 1;
        for (auto& v : adj[x]) {
            // cerr << "--" << v  nl;
            if (dfs(v))return true;
            // cerr << "--" << v  nl;
        }
        ans.pop_back();
        vis[x] = 2;
        return false;
    };

    for (ll i = 1;i <= n;i++) {
        dfs(i);
        if (ans.size())break;
    }
    if (!ans.size())return false;
    int pos = 0;
    for (int i = 0;i < ans.size();i++) {
        if (ans[i] == ans.back()) {
            pos = i;
            break;
        }
    }
    cout << ans.size() - pos  nl;
    for (int i = pos;i < ans.size();i++) {
        cout << ans[i] << " ";
    }
    cout nl;
    return true;
}

bool solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> adj[n + 1];
    for (ll i = 0;i < m;i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    if (!cycledetectionDirected(adj, n))cout << "IMPOSSIBLE\n";
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
    {
        solve();
        // cout << (solve() ? "YES\n" : "NO\n");
        // cout << (solve() ? "" : "-1\n");
    }
}
