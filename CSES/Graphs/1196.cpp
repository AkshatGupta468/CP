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
void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<pair<ll, ll>> adj[n + 1];
    for (ll i = 0;i < m;i++) {
        ll u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({ v,c });
    }

    vector<ll> vis(n + 1);
    vector<ll> ans;
    priority_queue<pair<ll, ll>> p;
    p.push({ 0,1 });
    while (!p.empty())
    {
        auto [w, u] = p.top();
        p.pop();
        if (vis[u] == k)continue;
        vis[u]++;
        if (u == n)
            ans.push_back(-w);
        for (auto& [v, c] : adj[u]) {
            p.push({ w - c,v });
        }
    }
    for (int i = 0;i < k;i++) {
        cout << ans[i] << " ";
    }
    cout nl;
}

int main()
{
    // fast_io;
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

    solve();
}
