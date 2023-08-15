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
    ll n;
    cin >> n;
    vector<int> adj(n);
    vector<vector<int>> a(2, vector<int>(n));
    for (ll k = 0;k < 2;k++) {
        for (ll i = 0;i < n;i++) {
            cin >> a[k][i];
            a[k][i]--;
        }
    }
    for (ll i = 0;i < n;i++) {
        adj[a[0][i]] = i;
    }
    vector<ll> len;
    vector<bool> vis(n, false);
    for (ll i = 0;i < n;i++) {
        if (vis[i])continue;
        ll x = i;
        ll cnt = 0;
        do
        {
            cnt++;
            vis[x] = true;
            x = adj[a[1][x]];
        } while (!vis[x]);
        len.push_back(cnt);
    }
    debug(len);
    ll ans = 0;
    for (auto& l : len) {
        ll parity = (l & 1);
        l = (l ^ parity);
        ans += l * l / 2 + (n - l) * l;
        n -= l;
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
    int t;
    cin >> t;
    while (t--)
        solve();
}
