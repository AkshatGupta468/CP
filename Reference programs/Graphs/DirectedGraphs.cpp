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
bool cycledetectionDirected(vector<ll> adj[], ll n) {
    vector<ll> indeg(n + 1);
    queue<ll> q;
    for (ll i = 1;i <= n;i++) {
        for (auto& e : adj[i])
            indeg[e]++;
    }
    for (ll i = 1;i <= n;i++) {
        if (indeg[i] == 0)q.push(i);
    }
    while (!q.empty())
    {
        ll x = q.front();
        q.pop();
        for (auto& e : adj[x]) {
            indeg[e]--;
            if (indeg[e] == 0)q.push(e);
        }
    }
    for (ll i = 1;i <= n;i++) {
        if (indeg[i]) {
            return true;
        }
    }
    return false;
}
void Kosaraju() {
    //Implement Kosaraju algorithm
}

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> adj[n + 1];
    for (ll i = 0;i < m;i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    cout << cycledetectionDirected(adj, n);
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
