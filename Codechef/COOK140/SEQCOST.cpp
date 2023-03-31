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
ll n, c;
struct range
{
    ll p, len, i;
};

ll costcal(vector<ll> a, ll k) {
    deque<range> dq;
    // cerr << k nl;
    dq.push_back({ 1,k, 0 });
    ll pos = 1;
    ll totcost = 0;
    for (ll i = 1;i < n;i++) {
        // cerr << "    " << i nl;
        if (a[i] >= k) {
            while (!dq.empty())
            {
                auto f = dq.front();
                totcost += f.len * (i - f.i) * (i - f.i);
                dq.pop_front();
            }
            dq.push_back({ 1,k,i });
            pos = 1;
            continue;
        }
        // cerr << "    " << i nl;
        if (pos + a[i] - 1 >= k) {
            ll tai = k - pos + 1;
            // cerr << "    " << i nl;
            while (dq.front().p>=pos && dq.front().p + dq.front().len - 1 <= pos + tai - 1)
            {
                auto f = dq.front();
                totcost += f.len * (i - f.i) * (i - f.i);
                dq.pop_front();
            }
            dq.push_back({ pos,tai,i });
            pos = 1;
            a[i] -= tai;
        }
        if (a[i] == 0)continue;
        while (dq.front().p + dq.front().len - 1 <= pos + a[i] - 1)
        {
            auto f = dq.front();
            totcost += f.len * (i - f.i) * (i - f.i);
            dq.pop_front();
        }
        auto f = dq.front();
        if (f.p <= pos + a[i] - 1) {
            dq.pop_front();
            totcost += (pos + a[i] - f.p) * (i - f.i) * (i - f.i);
            dq.push_front({ pos + a[i],f.len - (pos + a[i] - f.p),f.i });
        }
        dq.push_back({ pos,a[i],i });
        pos = (pos + a[i]);
    }
    // cerr << k nl;
    return totcost;
}
bool check(ll x, vector<ll>& a) {
    return (c * x - costcal(a, x) <= c * (x + 1) - costcal(a, x + 1));
}
ll getx(ll l, ll r, vector<ll>& a) {
    if (l + 1 == r)return l;
    ll mid = (l + r) / 2;
    if (check(mid, a)) return getx(mid, r, a);
    else return getx(l, mid, a);
}
void solve()
{
    cin >> n >> c;
    vector<ll> a(n);
    for (ll i = 0;i < n;i++) {
        cin >> a[i];
    }
    // for (int i = 1;i <= min(a[0], a[n - 1]);i++) {
    //     cerr << i sp costcal(a, i) nl;
    // }
    // cerr nl;
    if (c <= n - 1) {
        cout << 0 nl;
        return;
    }
    ll x = getx(0, min(a[0], a[n - 1]), a);
    x++;
    // debug(x);
    ll k = costcal(a, x);
    cout << c * x - k nl;
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
