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
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0;i < m;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> topoorder;
    vector<int> indeg(n + 1);
    queue<int> q;
    for (int i = 1;i <= n;i++) {
        for (auto& e : adj[i])
            indeg[e]++;
    }
    for (int i = 1;i <= n;i++)
        if (indeg[i] == 0)
            q.push(i);
    while (!q.empty()) {
        topoorder.push_back(q.front());
        q.pop();
        for (auto& e : adj[topoorder.back()]) {
            indeg[e]--;
            if (indeg[e] == 0)q.push(e);
        }
    }

    for (int i = 1;i <= n;i++) {
        if (indeg[i] > 0)return false;
    }
    for (auto& i : topoorder)cout << i << " ";
    cout nl;
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
    int t = 1;
    // cin >> t;
    while (t--) {
        // solve();
        // cout << (solve() ? "YES\n" : "NO\n");
        cout << (solve() ? "" : "IMPOSSIBLE\n");
    }
}
