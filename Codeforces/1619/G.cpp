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
vector<int> vis;
map<int, map<int, int>> xf, yf;
vector<tuple<int, int, int>> mine;
int n, k;
int dfs(int v) {
    vis[v] = true;
    // debug(v);
    auto& [x, y, time] = mine[v];
    // debug2(x, y);
    int trig = time;
    if (xf.find(x) != xf.end()) {

        auto itlow = xf[x].lower_bound(y - k);
        auto itup = xf[x].upper_bound(y + k);
        for (auto it = itlow;it != itup;it++) {
            if (vis[it->second])continue;
            trig = min(trig, dfs(it->second));
        }
    }
    if (yf.find(y) != yf.end()) {
        auto itlow = yf[y].lower_bound(x - k);
        auto itup = yf[y].upper_bound(x + k);
        for (auto it = itlow;it != itup;it++) {
            if (vis[it->second])continue;
            trig = min(trig, dfs(it->second));
        }
    }
    return trig;
}
void solve()
{
    cin >> n >> k;
    for (int i = 0;i < n;i++) {
        int x, y, time;cin >> x >> y >> time;
        xf[x][y] = i;
        yf[y][x] = i;
        mine.push_back({ x,y,time });
    }
    for (int i = 0;i < n;i++) {
        auto& [x, y, time] = mine[i];
        // debug2(i, time);
        // debug2(x, y);
    }
    vector<int> times;
    vis.assign(n, false);
    for (int i = 0;i < n;i++) {
        if (vis[i])continue;
        times.push_back(dfs(i));
    }
    sort(times.begin(), times.end(), greater<int>());
    int i;
    // debug(times);cerr nl;
    times.push_back(0);
    for (i = 0;i < times.size();i++) {
        if (times[i] < i)break;
    }
    cout << i-1 nl;
    xf.clear();yf.clear();
    mine.clear();
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
