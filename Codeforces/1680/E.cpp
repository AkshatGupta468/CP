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
    int n;
    cin >> n;
    vector<string> a(2);
    cin >> a[0] >> a[1];
    vector<vector<ll>> dpl(n + 1, vector<ll>(2)), dpr(n + 1, vector<ll>(2));
    vector<bool> flagl(n + 1), flagr(n + 1);
    for (int i = 0;i < n;i++) {
        dpl[i + 1][0] = dpl[i][0] + flagl[i] + (a[1][i] == '*');
        if (flagl[i])
            dpl[i + 1][0] = min(dpl[i][1] + 2 * flagl[i], dpl[i + 1][0]);
        dpl[i + 1][1] = dpl[i][1] + flagl[i] + (a[0][i] == '*');
        if (flagl[i])
            dpl[i + 1][1] = min(dpl[i + 1][1], dpl[i][0] + 2 * flagl[i]);
        flagl[i + 1] = (flagl[i] || a[0][i] == '*' || a[1][i] == '*');
    }

    for (int i = n;i > 0;i--) {
        dpr[i - 1][0] = dpr[i][0] + flagr[i] + (a[1][i - 1] == '*');
        if(flagr[i]) dpr[i - 1][0]=min(dpr[i - 1][0],dpr[i][1] + 2 * flagr[i]);
        dpr[i - 1][1] = dpr[i][1] + flagr[i] + (a[0][i - 1] == '*');
        if(flagr[i]) dpr[i - 1][1]=min(dpr[i - 1][1],dpr[i][0] + 2 * flagr[i]);
        flagr[i - 1] = (flagr[i] || a[0][i - 1] == '*' || a[1][i - 1] == '*');
    }
    ll ans = 1e9;
    for (int i = 0;i < n;i++) {
        ans = min(dpl[i][0] + flagl[i] + dpr[i + 1][0] + flagr[i + 1] + (a[1][i] == '*'), ans);
        ans = min(dpl[i][1] + flagl[i] + dpr[i + 1][1] + flagr[i + 1] + (a[0][i] == '*'), ans);
        if (flagl[i] && flagr[i + 1]) {
            ans = min(dpl[i][0] + 2 + dpr[i + 1][1] + 1, ans);
            ans = min(dpl[i][1] + 2 + dpr[i + 1][0] + 1, ans);
        }
    }
    // for(int i=0;i<=n;i++){
    //     cerr<<dpl[i][0] sp dpl[i][1] nl;
    // }
    // cerr nl;
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
