#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a)   \
    for (auto i : a) \
        cout << i << " ";
#define nl '\n'
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define int long long
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1, n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';

vector<vector<int>> adj;
vector<bool> vis;
vector<vector<int>> v;
vector<int> dfs(int x)
{
    vis[x] = true;
    vector<int> ans(2, 0);
    for (auto e : adj[x])
    {
        if (vis[e])
            continue;
        vector<int> child = dfs(e);
        for (int i = 0; i < 2; i++)
        {
            ans[i] += max(abs(v[x][i] - v[e][0]) + child[0], abs(v[x][i] - v[e][1]) + child[1]);
        }
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    v.clear();
    v.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        v[i].resize(2);
        cin >> v[i][0] >> v[i][1];
    }
    adj.clear();
    vis.clear();
    vis.resize(n + 1, false);
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int l, r;
        cin >> l >> r;
        adj[l].push_back(r);
        adj[r].push_back(l);
    }
    vis[1] = true;
    vector<int> ans = dfs(1);
    cout << max(ans[0], ans[1]) << nl;
}

int32_t main()
{
    fast_io;

    int t;
    cin >> t;
    while (t--)
        solve();
}
