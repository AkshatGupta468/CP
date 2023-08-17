#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cerr<<i<<" ";
#define nl <<'\n'
#define sp <<" "<<
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug2(n1,n2) cerr << #n1 << " : "; _dprint(n1);cerr << "  " << #n2 << " : "; _dprint(n2) ;cerr<< '\n';
#ifndef ONLINE_JUDGE
#define debug(n) cerr << #n << " : "; _dprint(n);cerr <<'\n'; 
#else 
#define debug(n)
#endif
template<class T>
void _dprint(vector<T> a) { display(a) };
template<class T>
void _dprint(T a) { cerr << a; }
//https://cses.fi/problemset/task/1732
// CSES - String Algorithms - Finding Borders
vector<int> getzarray(string a) {
    int n = a.size();
    vector<int> z(n);
    int l = 1, r = 1;
    for (int i = 1;i < n;i++) {
        if (r - i >= 0)z[i] = min(z[i - l], r - i);
        while (i + z[i] < n && a[i + z[i]] == a[z[i]])z[i]++;
        if (i + z[i] > r)l = i, r = i + z[i];
    }
    return z;
}
bool solve()
{
    string s;
    cin >> s;
    int n = s.length();
    vector<int> z = getzarray(s);
    for (int i = n - 1;i > 0;i--) {
        if (z[i] == n - i)cout << z[i] << ' ';
    }
    cout nl;
    return true;
}

int main()
{
    fast_io;
#ifdef __linux__
    string path = "/media/gakshat468/New Volume/CP/";
#elif _WIN32
    string path = "D:/CP/";
#endif
#ifndef ONLINE_JUDGE
    freopen((path + "input.txt").c_str(), "r", stdin);
    freopen((path + "output.txt").c_str(), "w", stdout);
    freopen((path + "error.txt").c_str(), "w", stderr);
#endif
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
        // cout << (solve() ? "YES\n" : "NO\n");
        // cout << (solve() ? "" : "-1\n");
    }
}
