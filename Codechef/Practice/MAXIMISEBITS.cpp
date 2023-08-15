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
    int n, m, k;
    cin >> n >> m >> k;
    string a, b;
    cin >> a >> b;
    vector<vector<int>> cnt(26, vector<int>(2));
    for (auto& i : a) {
        cnt[i - 'a'][0]++;
    }
    for (auto& i : a) {
        cnt[i - 'a'][1]++;
    }
    int pos[2] = { 0,0 };
    string c;
    int x[2] = { 0,0 };
    while (cnt[pos[0]][0] == 0)pos[0]++;
    while (cnt[pos[1]][1] == 0)pos[1]++;
    while (pos[0] != 26 && pos[1] != 26) {
        if (x[0] == k) {
            x[0] = 0;
            x[1] = 1;
            c.push_back('a' + pos[1]);
            cnt[pos[1]][1]--;
        }
        else if (x[1] == k) {
            x[1] = 0;
            x[0] = 1;
            c.push_back('a' + pos[0]);
            cnt[pos[0]][0]--;
        }
        else if (pos[0] < pos[1]) {
            c.push_back('a' + pos[0]);
            cnt[pos[0]][0]--;
        }
        else if (pos[0] < pos[1]) {
            c.push_back('a' + pos[0]);
            cnt[pos[0]][0]--;
        }
        while (pos[0] < 26 && cnt[pos[0]][0] == 0)pos[0]++;
        while (pos[1] < 26 && cnt[pos[1]][1] == 0)pos[1]++;
    }
    cout << c nl;
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





