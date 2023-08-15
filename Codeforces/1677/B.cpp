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
    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<vector<int>> rcnt(n + 1, vector<int>(m + 1));
    auto ccnt = rcnt;
    queue<int> q;
    for (int j = 1;j <= m;j++) {
        q.push(0);
    }
    int colgood = 0, ind = 0;
    ll last = -m;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++, ind++) {
            int x = s[ind] - '0';
            if (x)last = ind;
            if (x && !q.front())colgood++;
            x = (x | q.front());
            q.pop();
            q.push(x);
            ccnt[i][j] = colgood;
            rcnt[i][j] = rcnt[i - 1][j] + (ind - last < m);
        }
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            cout << ccnt[i][j] + rcnt[i][j] << " ";
        }
    }
    cout nl;
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
