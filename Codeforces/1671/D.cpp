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
ll solve()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (ll i = 0;i < n;i++) {
        cin >> a[i];
    }
    ll sum = 0;
    ll minm = *min_element(a.begin(), a.end());
    ll maxm = *max_element(a.begin(), a.end());
    for (int i = 1;i < n;i++) {
        sum += abs(a[i] - a[i - 1]);
    }
    debug(sum);
    if (1 < minm) {
        vector<ll> temp = { a[0] - 1,2 * (minm - 1),a[n - 1] - 1 };
        sum += *min_element(temp.begin(), temp.end());
    }
    if (maxm < x) {
        vector<ll> temp = { x - a[0],2 * (x - maxm),x - a[n - 1] };
        sum += *min_element(temp.begin(), temp.end());
    }
    return sum;
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
        cout << (solve()) nl;
}
