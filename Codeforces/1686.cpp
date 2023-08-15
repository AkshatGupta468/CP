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
bool solve()
{
    vector<int> a(4);
    for (auto& i : a)cin >> i;
    string s;
    cin >> s;
    ll n = a[0] + a[1] + 2 * a[2] + 2 * a[3];
    if (n == 1) {
        if (a[2] + a[3] > 0)return false;
        if (a[1] + a[0] > 1)return false;
        return (a[s[0] - 'A']);
    }
    if (count(s.begin(), s.end(), 'A') - count(s.begin(), s.end(), 'B') != a[0] - a[1])
    {
        return false;
    }
    s.push_back(s[n - 1]);


    // cerr << s nl;
    int cnt = 1;
    vector<pair<int, int>> v;
    for (int i = 1;i < s.length();i++) {
        if (s[i - 1] != s[i]) {
            cnt++;
        }
        else {
            if (cnt > 1)
                v.push_back({ cnt,s[i] - 'A' });
            cnt = 1;
        }
    }
    // for (int i = 0;i < v.size();i++)
        // cerr << v[i].first sp v[i].second nl;
    sort(v.begin(), v.end(), [](auto& l, auto& r) {
        if (l.first % 2 == r.first % 2)
            return l.second < r.second;
        return l.first % 2 < r.first % 2;
        });
    ll var = 0;
    for (int i = v.size() - 1;i >= 0;i--) {
        if (v[i].first % 2 == 0) {
            v[i].second = !v[i].second;
            continue;
        }
        var += (v[i].first / 2);
        v.pop_back();
    }
    // cerr nl;
    for (int i = 0;i < v.size();i++) {
        // cerr << v[i].first sp v[i].second nl;
        a[v[i].second + 2] -= v[i].first / 2;
    }
    cerr nl;
    for (int i = v.size() - 1;i >= 0;i--) {
        if (a[2] <= 0 && a[3] <= 0)return true;
        else if (a[2] <= 0 && a[3] <= var)return true;
        else if (a[3] <= 0 && a[2] <= var)return true;
        else if (a[2] + a[3] - var <= 0)return true;
        a[v[i].second + 2] += v[i].first / 2;
        var += v[i].first / 2 - 1;
    }
    if (a[2] <= 0 && a[3] <= 0)return true;
    else if (a[2] <= 0 && a[3] <= var)return true;
    else if (a[3] <= 0 && a[2] <= var)return true;
    else if (a[2] + a[3] - var <= 0)return true;
    return false;
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
    freopen((path + "error.txt").c_str(), "w", stderr);
#endif
    int t;
    cin >> t;
    while (t--)
        cout << (solve() ? "YES\n" : "NO\n");
}
