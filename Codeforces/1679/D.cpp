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

vector<ll> a;
ll n, m, k;

void getlen(ll v, vector<ll> adj[], vector<ll>& len, ll lim) {
    len[v] = 1;
    for (auto& e : adj[v]) {
        if (a[e] > lim)continue;
        if (len[e] == 0) getlen(e, adj, len, lim);
        len[v] = max(len[v], 1 + len[e]);
    }
}
bool cycledetectionDirected(vector<ll> adj[], ll lim) {
    vector<ll> indeg(n + 1);
    queue<ll> q;
    for (ll i = 1;i <= n;i++) {
        if (a[i] > lim)continue;
        for (auto& e : adj[i]) {
            if (a[e] > lim)continue;
            indeg[e]++;
        }
    }
    for (ll i = 1;i <= n;i++) {
        if (a[i] > lim)continue;
        if (indeg[i] == 0)q.push(i);
    }
    while (!q.empty())
    {
        ll x = q.front();
        q.pop();
        for (auto& e : adj[x]) {
            if (a[e] > lim)continue;
            indeg[e]--;
            if (indeg[e] == 0)q.push(e);
        }
    }
    for (ll i = 1;i <= n;i++) {
        if (a[i] > lim)continue;
        if (indeg[i]) {
            return true;
        }
    }
    return false;
}

bool check(vector<ll> adj[], ll lim) {
    if (cycledetectionDirected(adj, lim)) return true;
    vector<ll> len(n + 1);
    for (ll i = 1;i <= n;i++) {
        if (a[i] > lim)continue;
        if (len[i] == 0) getlen(i, adj, len, lim);
        if (len[i] >= k)return true;
    }
    return false;
}
ll binrsrch(ll l, ll r, vector<ll> adj[]) {
    if (l + 1 == r)return r;
    ll x = (l + r) / 2;
    if (check(adj, x)) return binrsrch(l, x, adj);
    else return binrsrch(x, r, adj);
}
void solve()
{
    cin >> n >> m >> k;
    a.assign(n + 1, 0);
    for (ll i = 1;i <= n;i++) {
        cin >> a[i];
    }
    vector<ll> adj[n + 1];
    for (ll i = 0;i < m;i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    if (!check(adj, 1e9)) {
        cout << "-1\n";
        return;
    }
    cout << binrsrch(0, 1e9, adj) nl;
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
