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
    vector<ll> a(n);
    for (ll i = 0;i < n;i++) {
        cin >> a[i];
    }
    vector<ll> backinc(n), dec(n);
    for (ll i = 0;i < n;i++) {
        for (ll j = i + 1;j < n;j++) {
            if (a[i] > a[j]) {
                backinc[j]++;
                dec[i]++;
            }
        }
    }
    ll ans = 0;
    for (ll i = 0;i < n;i++) {
        ll temp = 0;
        // cerr<<i <<"-\n";
        for (ll j = i + 1;j < n;j++) {
            if (a[i] > a[j]) {
                backinc[j]--;
            }
        }
        for (ll j = i + 1;j < n;j++) {
            temp-=backinc[j];
            if (a[i] < a[j]) {
                ans += temp;
            }
            // cerr<<j<<": " sp dec[j] sp backinc[j] nl;
            temp += dec[j];
        }
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
    ll t;
    cin >> t;
    while (t--)
        solve();
}
