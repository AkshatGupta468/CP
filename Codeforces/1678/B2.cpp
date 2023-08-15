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
int getans(string s, int n, int start) {
    int cnt[2]{};
    cnt[start] = 1e6;
    cnt[!start] = 1;
    for (int i = 0;i < n;i += 2) {
        if (s[i] == s[i + 1]) {
            int v = s[i] - '0';
            cnt[v] = min(cnt[v], 1 + cnt[!v]);
            cnt[!v] = 1e6;
        }
        else {
            int tcnt[2]{};
            tcnt[0] = min(cnt[0], 1 + cnt[1]);
            tcnt[1] = min(1 + cnt[0], cnt[1]);
            cnt[0] = tcnt[0];
            cnt[1] = tcnt[1];
        }
    }
    return min(cnt[0], cnt[1]);
}
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0;i < n;i += 2) {
        ans += (s[i] != s[i + 1]);
    }
    cout << ans sp min(getans(s, n, 0), getans(s, n, 1)) nl;
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
