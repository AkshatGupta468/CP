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
ll n, k;
ll getans(vector<ll> a) {
    ll s = 0, cnt = 0;
    for (ll j = n;j > 0;j--) {
        cnt += (a[j] == 0);
        s += a[j];
    }
    ll fsum = 0, ans = -1;
    for (ll j = 1;j <= n;j++) {
        if (s - k * cnt > 0 || s + k * cnt < 0)break;
        if (a[j] == 0) {
            cnt--;
            ll x = min(k, k * cnt - s);
            s += x;
            fsum += x;
        }
        else fsum += a[j];
        ans = max(ans, fsum + 1);
    }
    return ans;
}
void solve()
{
    cin >> n >> k;
    vector<ll> a(2 * n + 1);
    for (ll i = 1;i <= n;i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    ll ans = -1;
    for (ll i = 0;i < n;i++) {
        vector<ll> b(n + 1);
        for (ll j = i + 1;j <= i + n;j++) {
            b[j - i] = a[j];
        }
        ans = max(ans, getans(b));
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
