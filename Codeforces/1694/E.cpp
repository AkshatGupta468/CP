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
bool solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> adj[n + 1];
    vector<ll> radj[n + 1];
    vector<ll> outdeg(n + 1);
    for (ll i = 0;i < m;i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    for (int i = 1;i <= n;i++) {
        outdeg[i] = adj[i].size();
    }
    priority_queue<pair<ll, ll>> p;
    vector<ll> ans(n + 1, 1e18);
    ans[n] = 0;
    vector<bool> vis(n + 1, false);
    p.push({ 0,n });
    while (!p.empty()) {
        int v = p.top().second;
        p.pop();
        if (vis[v])continue;
        vis[v] = true;
        for (auto& u : radj[v]) {
            if (ans[u] > ans[v] + outdeg[u]) {
                ans[u] = ans[v] + outdeg[u];
                p.push({ -ans[u],u });
            }
            outdeg[u]--;
        }
    }
    cout << ans[1] nl;
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
    }
    // cout << (solve() ? "YES\n" : "NO\n");
    // cout << (solve() ? "" : "-1\n");

}
