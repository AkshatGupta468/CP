#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define display(a)   \
    for (auto i : a) \
        cerr << i << " ";
#define nl << '\n'
#define sp << " " <<
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long int
#define debug2(n1, n2) cerr << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
#ifndef ONLINE_JUDGE
#define debug(n)         \
    cerr << #n << " : "; \
    _dprint(n);
#else
#define debug(n)
#endif
template <class T>
void _dprint(vector<T> a){display(a)};
template <class T>
void _dprint(T a) { cerr << a << "\n"; }
vector<vector<ll>> c(5001, vector<ll>(5001, 0));
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int l = 0, r = 0, cnt = 0;
    if (k == 0)
    {
        cout << "1\n";
        return;
    }
    ll ans = 1, last = 0;
    do
    {
        last = 0;
        while (r < n && cnt + (s[r] == '1') <= k)
        {
            if (s[r] == '1')
                cnt++;
            r++;
            last++;
        }
        if (cnt < k)
            break;
        // cerr<< l sp r nl;
        ans = ((ans + c[r - l][k]) - c[r - l - last][k - 1] + MOD) % MOD;
        // debug(ans);debug(c[r-l][k]);debug(c[r-l-last][k-1]);
        while (cnt == k)
        {
            if (s[l] == '1')
                cnt--;
            l++;
        }
    } while (r < n);
    cout << ans nl;
}

int main()
{
    // fast_io;
#ifdef __linux__
    string path = "/mnt/3C401CB3401C75BC/CP/";
#elif _WIN32
    string path = "D:/CP/";
#endif
#ifndef ONLINE_JUDGE
    freopen((path + "input.txt").c_str(), "r", stdin);
    freopen((path + "output.txt").c_str(), "w", stdout);
    // freopen((path +"error.txt").c_str(),"w",stderr);
#endif
    c[0][0] = 1;
    for (int i = 1; i <= 5000; i++)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }
    c[0].assign(5001, 1);
    // for(int i=0;i<=7;i++){
    //     for(int j=0;j<=i;j++){
    //         cerr<<c[i][j]<<" ";
    //     }
    //     cerr nl;
    // }
    // int t;
    // cin>>t;
    // while(t--)
    solve();
}
