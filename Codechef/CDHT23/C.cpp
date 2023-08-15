#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#ifdef __linux__
#include "/media/gakshat468/New Volume/CP/algo/debug.h"
#elif _WIN32
#include "D:/CP/algo/debug.h"
#endif
#else
#define debug(...) 42
#endif
#define MOD 1000000007
#define nl <<'\n'
#define display_vec(a) for(auto i:a)cout<<i<<" "; cout <<"\n";
#define sp <<" "<<
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long
#pragma GCC target("popcnt")

const int inf = 1e18;
bool solve()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> a(r + 2, vector<int>(c + 2));
    vector<vector<int>> s(r + 2, vector<int>(c + 2));

    for (int i = 1;i <= r;i++) {
        for (int j = 1;j <= c;j++) {
            cin >> a[i][j];
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }
    function<int(int, int, int, int)> getwindowsum = [&](int x1, int x2, int y1, int y2) ->int {
        return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
    };

    vector<vector<array<int, 2>>> dp(r + 2, vector<array<int, 2>>(c + 2, { -inf,-inf }));

    dp[r][c] = { 0,0 };
    for (int i = r;i >= 1;i--) {
        for (int j = c;j >= 1;j--) {
            if (i == r && j == c)continue;
            int x = (i + j) % 2;
            array<int, 2> down = { dp[i + 1][j][0] + getwindowsum(i, i, j + 1, c)  , dp[i + 1][j][1] };
            array<int, 2> right = { dp[i][j + 1][0]  , dp[i][j + 1][1] + getwindowsum(i + 1, r, j, j) };

            if (down[(i + j) % 2] != right[(i + j) % 2])
                dp[i][j] = (down[(i + j) % 2] > right[(i + j) % 2]) ? down : right;
            else
                dp[i][j] = (down[!((i + j) % 2)] < right[!((i + j) % 2)]) ? down : right;
        }
    }

    cout << dp[1][1][0] sp dp[1][1][1] nl;
    return true;
}

signed main()
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
