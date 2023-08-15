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
vector<ll> treesize;
vector<bool> vis;
ll n, k1, k2;
ll ans;
void calsize(ll v, set<ll> adj[]) {
    vis[v] = true;
    treesize[v] = 1;
    for (auto& e : adj[v]) {
        if (vis[e])continue;
        calsize(e, adj);
        treesize[v] += treesize[e];
    }
}
ll getcentroid(ll v, ll p, set<ll> adj[]) {
    for (auto& e : adj[v]) {
        if (e == p)continue;
        if (treesize[e] > treesize[v] / 2) {
            treesize[v] -= treesize[e];
            treesize[e] += treesize[v];
            return getcentroid(e, v, adj);
        }
    }
    return v;
}
void calkcount(ll u, set<ll> adj[]) {
    ll v = getcentroid(u, u, adj);
    // debug2(u, v);
    vector<vector<ll>> dist;
    ll maxsz = 0;
    for (auto& e : adj[v]) {
        vector<ll> tdist = { 0 ,1 };
        queue<pair<ll, ll>> q;
        q.push({ e,v });
        while (!q.empty()) {
            ll cnt = 0;
            ll sz = q.size();
            for (ll i = 0;i < sz;i++) {
                auto x = q.front();
                q.pop();
                for (auto& p : adj[x.first]) {
                    if (p == x.second)continue;
                    cnt++;
                    q.push({ p,x.first });
                }
            }
            tdist.push_back(cnt);
        }
        // debug(e);
        // debug(tdist);
        maxsz = max(maxsz, (ll)(tdist.size()));
        dist.push_back(tdist);
    }
    vector<ll> distsum(maxsz);
    ll count;
    for (ll i = 1;i < maxsz;i++) {
        for (auto& vec : dist) {
            if (i >= vec.size())continue;
            distsum[i] += vec[i];
            vec[i] += vec[i - 1];
        }
        distsum[i] += distsum[i - 1];
    }
    if (k2 < distsum.size())
        ans += distsum[k2] - distsum[k1 - 1];
    for (auto& vec : dist) {
        for (ll i = 1;i < vec.size();i++) {
            distsum[i]-=vec
        }
        for (ll i = 1;i < vec.size();i++) {
            if (k2 - i < distsum.size() && k1 - i - 1 >= 1)
                ans += (distsum[k2 - i] - distsum[k1 - i - 1] - ()) * vec[i];
        }
    }
    // debug2(v, ans);
    for (auto& e : adj[v]) {
        adj[e].erase(v);
        calkcount(e, adj);
    }
}
void solve()
{
    cin >> n >> k1 >> k2;
    ans = 0;
    set<ll> adj[n + 1];
    treesize.assign(n + 1, 0);
    for (ll i = 0;i < n - 1;i++) {
        ll a, b;cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    vis.assign(n + 1, false);
    treesize.assign(n + 1, 0);
    calsize(1, adj);
    calkcount(1, adj);
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
