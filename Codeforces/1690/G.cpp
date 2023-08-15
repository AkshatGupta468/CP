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
bool solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    a[0] = 2e9;
    int  minval = 2e9;
    set<int> s = { 0 };
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        if (minval > a[i]) {
            s.insert(i);
            minval = a[i];
        }
    }
    for (int i = 0;i < m;i++) {
        int k, d;
        cin >> k >> d;
        a[k] -= d;
        s.insert(k);
        set<int>::iterator it = s.find(k);
        it--;
        if (a[*it] <= a[k]) {
            s.erase(k);
        }
        else {
            it = s.find(k);it++;
            while (it != s.end() && a[k] <= a[*it]) {
                auto temp = it;
                it++;
                s.erase(temp);
            }
        }
        cout << s.size() - 1 << " ";
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
    cin >> t;
    while (t--) {
        solve();
        // cout << (solve() ? "YES\n" : "NO\n");
        // cout << (solve() ? "" : "-1\n");
    }
}
