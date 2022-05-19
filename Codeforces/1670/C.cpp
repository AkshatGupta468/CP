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
const ll sz = 5e5 + 1;
ll twopow[sz];
void dfs(ll x, vector<ll> adj[], vector<bool>& vis) {
    vis[x] = true;
    for (auto& e : adj[x]) {
        if (vis[e])continue;
        dfs(e, adj, vis);
    }
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> adj[n + 1];
    vector<pair<ll, ll>> p(n);
    for (ll i = 0;i < n;i++) {
        cin >> p[i].first;
    }
    for (ll i = 0;i < n;i++) {
        cin >> p[i].second;
    }
    vector<bool> vis(n + 1, false);
    for (ll i = 0;i < n;i++) {
        auto& [u, v] = p[i];
        if(u==v){
            vis[u]=true;
            continue;
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> d(n);
    for (ll i = 0;i < n;i++) {
        cin >> d[i];
        if (vis[d[i]])continue;
        dfs(d[i], adj, vis);
    }
    debug(vis);
    int cnt = 0;
    for (ll i = 1;i <= n;i++) {
        if (vis[i])continue;
        dfs(i, adj, vis);
        cnt++;
    }
    cout << twopow[cnt] nl;
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
    twopow[0] = 1;
    for (int i = 1;i < sz;i++) {
        twopow[i] = (twopow[i - 1] * 2ll) % MOD;
    }
    int t;
    cin >> t;
    while (t--)
        solve();
}
