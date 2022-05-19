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
class dsu {
public:
    vector<int> head;
    vector<int> childs;
    int n;
    dsu(int n) {
        head.resize(n + 1);
        childs.resize(n + 1);
        this->n = n;
        for (int i = 1;i <= n;i++) {
            head[i] = i;
            childs[i] = 1;
        }
    }
    int find(int x) {
        while (head[x] != head[head[x]]) {
            head[x] = head[head[x]];
        }
        return head[x];
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)return;
        if (childs[x] > childs[y])swap(x, y);
        head[x] = y;
        childs[y] += childs[x];
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0;i < m;i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({ b,w });
        adj[b].push_back({ a,w });
    }
    vector<dsu> bitcom(30, dsu(n)), fbitfix(30, dsu(n));
    vector<vector<int>> ans(30, vector<int>(n + 1, 2));
    for (int i = 0;i < 30;i++) {
        stack<int> s;
        vector<bool> vis(n + 1, false);
        s.push(1);
        vis[1]=true;
        int v = (1 << i);
        while (!s.empty())
        {
            auto x = s.top();
            s.pop();
            for (auto& e : adj[x]) {
                if (v & e.second)bitcom[i].unite(x, e.first);
                if (i != 0 && (v & e.second) && (1 & e.second))fbitfix[i].unite(x, e.first);
                if (!(1 & e.second)) { ans[i][x] = 1;ans[i][e.first] = 1; }
                if (vis[e.first])continue;
                vis[e.first] = true;
                s.push(e.first);
            }
        }
        for (int j = 1;j <=n;j++) {
            ans[i][fbitfix[i].find(j)] = min(ans[i][fbitfix[i].find(j)], ans[i][j]);
        }
        for (int j = 1;j <=n;j++) {
            ans[i][j] = min(ans[i][fbitfix[i].find(j)], ans[i][j]);
        }
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j < 30;j++)
            ans[0][i] = min(ans[0][i], ans[j][i]);
    }
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        int fans = 2;
        fans = ans[0][u];
        for (int i = 0;i < 30;i++) {
            if (bitcom[i].find(u) == bitcom[i].find(v))
                fans = 0;
        }
        cout << fans nl;
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
