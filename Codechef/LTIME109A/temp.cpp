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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> adj[n + 1];
    for (int i = 0;i < m;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> vis(n + 1);
    vector<bool> isInnocent(n + 1, false);
    vector<int> indeg(n + 1);
    priority_queue<pair<int, int>> q;
    for (int i = 1;i <= n;i++) {
        for (auto& e : adj[i])
            indeg[e]++;
    }
    for (int i = 1;i <= n;i++)
        if (indeg[i] == 0)
            q.push({ 1,i });

    for (int i = 1;i <= n;i++) {
        q.push({ 1,i });
        while (!q.empty()) {
            auto x = q.top();
            q.pop();
            if (x.first > k) {
                isInnocent[x.second] = true;
                continue;
            }
            if (vis[x.second])continue;
            vis[x.second] = true;
            for (auto& e : adj[x.second]) {
                q.push({ x.first + 1, e });
            }
        }
    }
    function<void(int)> dfs = [&](int x) {
        isInnocent[x] = true;
        for (auto& v : adj[x]) {
            if (!isInnocent[v])
                dfs(v);
        }
    };
    int ans = 0;
    for (int i = 1;i <= n;i++) {
        if (isInnocent[i])
            dfs(i);
    }
    for (int i = 0;i <= n;i++)
        ans += isInnocent[i];

    cout << ans nl;
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
    int t;
    int t_ = 0;
    cin >> t;
    while (t_++ < t)
    {
        cout << "Case #" << t_ << ": ";
        solve();
    }
}
