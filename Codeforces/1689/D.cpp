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
// vector<pair<int, int>> dir = { {0,1},{0,-1},{1,0},{-1,0} };
bool solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> col(n + 2, vector<bool>(m + 2));
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            char c;
            cin >> c;
            if (c == 'B') {
                col[i][j] = true;
            }
        }
    }
    vector<vector<vector<int>>> dis(n + 2, vector<vector<int>>(m + 2, vector<int>(4, -1e9)));
    function<void(int, int, vector<pair<int, int>>, int)> bfs = [&](int a, int b, vector<pair<int, int>> dir, int v) {
        vector<vector<bool>> vis(n + 2, vector<bool>(m + 2, false));
        queue<pair<int, int>> q;
        q.push({ a,b });
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0;i < sz;i++) {
                auto [x, y] = q.front();
                q.pop();
                if (col[x][y])dis[x][y][v] = max(dis[x][y][v], 0);

                for (auto& [dx, dy] : dir) {
                    if (x + dx<1 || x + dx>n || y + dy<1 || y + dy>m)continue;
                    dis[x + dx][y + dy][v] = max(dis[x + dx][y + dy][v], dis[x][y][v] + 1);
                    if (!vis[x + dx][y + dy])
                        q.push({ x + dx,y + dy });
                    vis[x + dx][y + dy] = true;
                }
            }
        }
    };

    bfs(1, 1, { {0,1},{1,0} }, 0);
    bfs(n, 1, { {0,1},{-1,0} }, 1);
    bfs(n, m, { {0,-1},{-1,0} }, 2);
    bfs(1, m, { {0,-1},{1,0} }, 3);
    int ans = 1e9, ansx = 0, ansy = 0;

    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            int temp = 0;
            for (int k = 0;k < 4;k++) {
                temp = max(dis[i][j][k], temp);
            }
            // cerr << temp << " ";
            if (ans > temp) {
                ansx = i;
                ansy = j;
                ans = temp;
                // debug2(ansx, ansy);
            }
        }
        // cerr nl;
    }
    // cerr << "------\n";
    cout << ansx sp ansy nl;
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
