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
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> adj[n + 1], radj[n + 1];
    for (ll i = 0;i < m;i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({ v,c });
        radj[v].push_back({ u,c });
    }

    pair<ll, ll> inf = { 1e18,0 };
    vector<pair<ll, ll>> dis(n + 1, inf);
    dis[1] = { 0,0 };
    for (int k = 0;k < n;k++) {
        for (int u = 1;u <= n;u++) {
            for (auto& [v, c] : adj[u]) {
                if (dis[v].first > dis[u].first + c) {
                    dis[v].first = dis[u].first + c;
                    dis[v].second = u;
                }
            }
        }
    }
    ll pos = -1;
    for (int u = 1;u <= n;u++) {
        for (auto& [v, c] : adj[u]) {
            if (dis[v].first > dis[u].first + c) {
                pos = v;
                break;
            }
        }
    }
    if (pos == -1) {
        cout << "NO\n";
        return;
    }
    vector<bool> vis(n + 1, false);
    vector<ll> nodelist = { dis[pos].second };
    while (!vis[pos]) {
        vis[pos] = true;
        nodelist.push_back(dis[pos].second);
        pos = dis[pos].second;
    }
    nodelist.push_back(dis[pos].second);

    reverse(nodelist.begin(), nodelist.end());

    cout << "YES\n";
    cout << nodelist[0] << " ";
    for (int i = 1;i < nodelist.size();i++) {
        cout << nodelist[i] << " ";
        if (nodelist[i] == nodelist[0])break;
    }
    cout nl;
}

int main()
{
    fast_io;
#ifdef __linux__
    string path = R"(/media/gakshat468/New Volume/CP/)";
#elif _WIN32
    string path = "D:/CP/";
#endif
#ifndef ONLINE_JUDGE
    freopen((path + "input.txt").c_str(), "r", stdin);
    // freopen((path + "output.txt").c_str(), "w", stdout);
    freopen((path + "error.txt").c_str(), "w", stderr);
#endif
    solve();
}
