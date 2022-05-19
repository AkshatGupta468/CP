#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define nl << "\n"
#define ft first
#define sd second
#define all(x) (x).begin(), (x).end()
#define display(a)   \
    for (auto i : a) \
        cout << i << " ";
#define debug(n) cerr << #n << " : " << n << '\n';
#define debug2(n1, n2) cerr << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
#define sp << " " <<
#define mod 998244353

// 2022-05-05 21:13:35
using namespace std;

int cntTotal = 0;

void dfs(int s, vector<vector<int>> &adj, vector<bool> &visited, vector<vector<int>> &ans)
{
    if (visited[s])
    {
        return;
    }
    visited[s] = true;
    ans[cntTotal].pb(s);
    // process node 
    if(adj[s].size()==0)
    cntTotal++;
    for (auto u : adj[s])
    {
        dfs(u, adj,visited,ans);
    }
}

// Created By EOWL
void solve()
{
    int n;
    cin >> n;
    vector<bool> visited(n, 0);
    vector<vector<int>> ans(n);
    vector<vector<int>> adj(n+1);
    vector<int>in(n+1,0);
    in[0]=INT_MAX;
    cntTotal=0;
    vector<int>start;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
    if(x!=i)
        adj[x].pb(i);
        if(i==x)
        start.pb(i);
    }
    for(int i=0;i<start.size();i++)
    dfs(start[i], adj,visited,ans);
    cout<<cntTotal nl;
    for(int i=0;i<ans.size();i++)
    {
        if(ans[i].size()!=0)
        {
            cout<<ans[i].size() nl;
            for(int j=0;j<ans[i].size();j++)
            {
                cout<<ans[i][j]<<" ";
            }
            cout nl;
        }
    }
    cout nl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     #ifdef __linux__
        string path="/mnt/3C401CB3401C75BC/CP/";
     #elif _WIN32
        string path="D:/CP/";
     #endif
     #ifndef ONLINE_JUDGE
        freopen((path+"input.txt").c_str(), "r", stdin);
        freopen((path+"output.txt").c_str(), "w", stdout);
        freopen((path +"error.txt").c_str(),"w",stderr);
    #endif
    int test;
    cin >> test;
    while (test--)
        solve();
}