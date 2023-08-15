#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cerr<<i<<" ";
#define nl <<'\n'
#define sp <<" "<<
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug2(n1,n2) cerr << #n1 << " : " << _dprint(n1) << "  " << #n2 << " : " << n2 << '\n';
#ifndef ONLINE_JUDGE
#define debug(n) cerr << #n << " : "; _dprint(n); 
#else 
#define debug(n)
#endif
template<class T>
void _dprint(vector<T> a) { display(a) };
template<class T>
void _dprint(T a) { cerr << a << "\n"; }
int getcentroid(int v, vector<vector<int>> &adj, vector<bool> &vis) {
    vis[v] = true;
    // cerr << v nl;
    bool centroid=true;
    int childs=-1;
    int n=vis.size()-1;
    for (auto& e : adj[v]) {
        if(vis[e])continue;
        int temp=getcentroid(e,adj,vis);
        // debug2(e,temp);
        if(temp>0)return temp;
        if(abs(temp)>(n/2))centroid=false;
        childs+=temp;
    }
    if(n+childs>n/2)centroid=false;
    if(centroid) return v;
    return childs;
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    for (int i = 0;i < n - 1;i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> vis(n + 1);
    cout << getcentroid(1, adj, vis) nl;
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
    // int t;
    // cin >> t;
    // while (t--)
        solve();
}
