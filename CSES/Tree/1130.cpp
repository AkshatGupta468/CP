#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cerr<<i<<" ";
#define nl <<'\n'
#define sp <<" "<<
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
// #define debug2(n1,n2) cerr << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
#ifndef ONLINE_JUDGE
#define debug(n) cerr << #n << " : "; _dprint(n); 
#else 
#define debug(n)
#endif
template<class T>
void _dprint(vector<T> a) { display(a) };
template<class T>
void _dprint(T a) { cerr << a << "\n"; }
vector<pair<int, int>> dp;
void dfs(int v, int p, vector<int> adj[]) {
    // cerr<<"startof :"<<v nl;
    for (auto& e : adj[v]) {
        if (e == p)continue;
        // cerr<<"calling "<< e <<" from "<< v nl;
        dfs(e, v, adj);
        // debug2(v,e);
        // debug(max(dp[e].first,dp[e].second));
        dp[v].second+=max(dp[e].first,dp[e].second);
    }
    for (auto& e : adj[v]) {
        if (e == p)continue;
        int maxm=max(dp[e].first,dp[e].second);
        dp[v].first=max(dp[v].first,dp[v].second-maxm+dp[e].second+1);
    }
    // cerr<<"endof :"<<v nl;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> adj[n + 1];
    // cerr<<"iput\n";
    for (int i = 0;i < n-1;i++) {
        int u, v;
        cin >> u >> v; 
        // cerr<< u sp v nl;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // cerr<<"dusol\n";
    for(int i=1;i<=n;i++){
        // cerr<<i <<": ";
        for(auto &e:adj[i]){
            // cerr<< e <<" ";
        }
        // cerr nl;
    }
    dp.clear();
    dp.resize(n + 1);
    dfs(1, 0, adj);
    // for(int i=1;i<=n;i++){
    //     cout<<i <<": "<<dp[i].first sp dp[i].second nl;
    // }
    cout << max(dp[1].first, dp[1].second) nl;
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
