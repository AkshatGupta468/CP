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
struct desktop
{
    int fx, fy;
    vector<vector<int>> vis;
    int n, m;
    int outcnt;
    ll cancnt() {
        return (fy - 1) * n + fx;
    }
    bool inside(int x, int y) {
        if (y == fy)return x <= fx;
        else return y < fy;
    }
    void flipicon(int x, int y) {
        if (vis[x][y]) {
            outcnt -= !inside(x, y);
            vis[x][y] = 0;
            dec();
        }
        else {
            inc();
            outcnt += !inside(x, y);
            vis[x][y] = 1;
        }
    }
    desktop() {
        cin >> n >> m;
        fy = 1;fx = 0;
        outcnt = 0;
        vis.assign(n + 1, vector<int>(m + 1));
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= n;j++) {
                char c;cin >> c;
                if (c == '*')flipicon(i, j);
            }
        }
    }
    void dec() {
        fx--;
        if (fx == 0 && fy > 0) {
            fx = n;fy--;
        }
    }
    void inc() {
        fx++;
        if (fx == n + 1) {
            fy++;
            fx = 1;
        }
    }
};
void solve()
{
    desktop D;
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        D.flipicon(x, y);
        cout << D.outcnt nl;
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
    int t;
    cin >> t;
    while (t--)
        solve();
}
