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
    int n;
    cin >> n;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0;i < n - 1;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v,w });
        adj[v].push_back({ u,w });
    }
    vector<stack<int>> st(n + 1);
    vector<int> anc(n + 1);
    vector<int> cnt(2 * n + 1);
    for (int i = 1;i <= n;i++) {
        cnt[i + n] = n;
        st[i].push(n + i);
    }
    vector<int> siz(n + 1);
    function<void(int)> dfs = [&](int v) {
        siz[v] = 1;
        for (auto& [u, w] : adj[v]) {
            if (siz[u])continue;
            st[w].push(u);
            dfs(u);
            st[w].pop();
            siz[v] += siz[u];
            anc[u] = st[w].top();
            cnt[anc[u]] -= siz[u];
        }
        cnt[v] += siz[v];
    };
    dfs(1);
    ll ans = 0;
    for (int i = 1;i <= n;i++) {
        ans += cnt[i] * 1ll * cnt[anc[i]];
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
