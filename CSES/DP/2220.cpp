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
    vector<pair<ll, ll>> adj[n + 1];
    for (ll i = 0;i < m;i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({ v,c });
    }
    vector<int> nodelist;
    ll inf = 1e18;
    vector<ll> dis(n + 1, inf);
    vector<int> vis(n + 1, 0);
    function<void(int)> dfs = [&](int u) {
        vis[u] = 1;
        for (auto& [v, w] : adj[u]) {
            if (vis[v] == 2)continue;
            else if (vis[v] == 0) {
                dis[v] = w + dis[u];
                dfs(v);
                dis[v] = inf;
                if (nodelist.size() > 0)break;
            }
            else if (dis[v] > dis[u] + w) {
                nodelist.push_back(v);
                break;
            }
        }
        if (nodelist.size() > 0 && vis[nodelist[0]] == 1)
            nodelist.push_back(u);
        vis[u] = 2;
    };
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            dis[j] = inf;
            vis[j] = 0;
        }
        dis[i] = 0;
        dfs(i);
        if (nodelist.size())break;
    }
    if (nodelist.size() == 0) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    reverse(nodelist.begin(), nodelist.end());
    for (auto& i : nodelist)cout << i << ' ';
    cout nl;
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
