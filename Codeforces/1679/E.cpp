#include<bits/stdc++.h>
using namespace std;
#define MOD 998244353 
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
    string s;
    cin >> s;
    int charmax = 3;
    int sz = (1 << charmax);
    vector<ll> ans(sz);
    for (int i = 0;i < n;i++) {
        ll mask = 0;
        ans[0]++;
        ll currans = 0;
        for (int l = 1;i - l >= 0 && i + l < n ;l++) {
            if (s[i - l] != '?' && s[i + l] != '?' && (s[i - l] != s[i + l])) {
                    if (s[i - l] != s[i + l - 1]) 
                    break;
            }
            else if (s[i - l] == '?' && s[i + l - 1] == '?') {
            }
            else if (s[i - l] == '?') {
                mask = (mask | (1 << int(s[i + l] - 'a')));
            }
            else if (s[i + l] == '?') {
                mask = (mask | (1 << int(s[i - l] - 'a')));
            }
            cerr << mask sp i sp l nl;
            ans[mask] ++;
        }
    }
    cerr<<"--\n";
    for (int i = 0;i < n;i++) {
        ll mask = 0;
        ll currans = 0;
        for (int l = 1;i - l >= 0 && i + l - 1 < n;l++) {
            if (s[i - l] != '?' && s[i + l - 1] != '?') {
                if (s[i - l] != s[i + l - 1]) 
                    break;
            }
            else if (s[i - l] == '?' && s[i + l - 1] == '?') {
            }
            else if (s[i - l] == '?') {
                mask = (mask | (1 << int(s[i + l - 1] - 'a')));
            }
            else if (s[i + l - 1] == '?') {
                mask = (mask | (1 << int(s[i - l] - 'a')));
            }
            cerr << mask sp i sp l nl;
            ans[mask] ++;
        }
    }
    for (int i = 0;i < sz;i++) {
        for (int j = 0;j < charmax;j++) {
            int v = (1 << j);
            if (i & v)
                ans[i] = (ans[i] + ans[(i ^ v)])%MOD;
        }
        cerr << ans[i] << " ";
    }
    cerr nl;
    int q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        int mask = 0;
        for (int i = 0;i < s.length();i++) {
            mask = (mask | (1 << int(s[i] - 'a')));
        }
        cout << ans[mask] nl;
    }
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
