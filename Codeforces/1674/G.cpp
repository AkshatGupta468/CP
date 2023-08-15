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
vector<ll> indeg;
vector<ll> dp;
vector<vector<ll>> adj;
void dfs(ll v) {
    if (dp[v] != -1)return;
    dp[v] = 1;
    if (adj[v].size() < 2)return;
    for (auto& e : adj[v]) {
        dfs(e);
        if (indeg[e] > 1)
            dp[v] = max(dp[v], 1 + dp[e]);
    }
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    dp.assign(n + 1, -1);
    indeg.assign(n + 1, 0);
    adj.assign(n + 1, {});
    for (ll i = 0;i < m;i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (ll i = 1;i <= n;i++) {
        for (auto& e : adj[i])
            indeg[e]++;
    }
    ll ans = 0;
    for (int i = 1;i <= n;i++) {
        dfs(i);
        ans = max(ans, dp[i]);
    }
    cout << ans nl;
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
