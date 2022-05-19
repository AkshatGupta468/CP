#include<bits/stdc++.h>
using namespace std;
#define MOD 998244353 
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
long long binaryMultiply(long long, long long, long long);

ll binaryExp(int a, int b, int M)
{
    int ans = 1;
    while (b > 0) {
        if (b & 1)
        {
            ans = (ans * 1ll * a) % M;
        }
        a = (a * 1ll * a) % M;
        b >>= 1;
    }
    return ans;
}

vector<int> spf;
class num {
public:
    unordered_map<int, int> fac;
    num() {
    }
    num(int x) {
        while (x > 1) {
            fac[spf[x]]++;
            x /= spf[x];
        }
    }
    void displa() {
        for (auto& i : fac) {
            cerr << i.first sp i.second nl;
        }
        cerr nl;
    }
    ll calnum() {
        ll sum = 1;
        for (auto& i : fac) {
            sum = (sum * binaryExp(i.first, i.second, MOD)) % MOD;
        }
        return sum;
    }
    friend num& operator/ (num&, num&);
    friend num& operator* (num&, num&);
    friend num& lcm(num&, num&);
};
const int sz = 2e5 + 1;
vector<num> getnumof;
vector<int> childs;
vector<num> ans;
set<pair<int, int>> vis;
vector<int> sieve(int size)
{
    vector<int> fac(size);
    int n = fac.size();
    for (int i = 0;i < n;i++) fac[i] = i;
    for (int i = 2;i * i <= n;i++) {
        for (int j = i * i;fac[i] == i && j < n;j += i)
            fac[j] = min(i, fac[j]);
    }
    return fac;
}
num& operator/ (num& a, num& b) {
    unordered_set<int> keys;
    for (auto& i : a.fac)keys.insert(i.first);
    for (auto& i : b.fac)keys.insert(i.first);
    num ans;
    for (auto i : keys) {
        ans.fac[i] = a.fac[i] - b.fac[i];
    }
    return ans;
}
num& operator* (num& a, num& b) {
    unordered_set<int> keys;
    for (auto& i : a.fac)keys.insert(i.first);
    for (auto& i : b.fac)keys.insert(i.first);
    num ans;
    for (auto i : keys) {
        ans.fac[i] = a.fac[i] + b.fac[i];
    }
    return ans;
}
num& lcm(num& a, num& b) {
    unordered_set<int> keys;
    for (auto& i : a.fac)keys.insert(i.first);
    for (auto& i : b.fac)keys.insert(i.first);
    num ans;
    for (auto i : keys) {
        ans.fac[i] = max(a.fac[i], b.fac[i]);
    }
    return ans;
}
int calchilds(int v, vector<tuple<int, int, int>> adj[]) {
    childs[v] = 1;
    for (auto& [e, x, y] : adj[v]) {
        if (childs[e] > 0)continue;
        childs[v] += calchilds(e, adj);
    }
    return childs[v];
}

int getcentroid(int v, int n, vector<tuple<int, int, int>>  adj[], num& retrace) {
    for (auto& [e, x, y] : adj[v]) {
        if (vis.count({ v,e }))continue;
        if (childs[e] > n / 2) {
            int temp = childs[v] - childs[e];
            childs[e] = childs[v];
            childs[v] = temp;
            retrace = retrace * getnumof[x];
            retrace = retrace / getnumof[y];
            return getcentroid(e, n, adj, retrace);
        }
    }
    return v;
}
void updatesubtree(int v, int p, vector<tuple<int, int, int>> adj[]) {
    // cerr<< v nl;
    for (auto& [e, x, y] : adj[v]) {
        if (e == p)continue;
        if (vis.count({ v,e }))continue;
        ans[e] = ans[v] * (getnumof[y]);
        ans[e] = ans[e] / (getnumof[x]);
        updatesubtree(e, v, adj);
    }
}
void solve(int u, int n, vector<tuple<int, int, int>> adj[]) {
    num retrace;
    int v = getcentroid(u, n, adj, retrace);
    // debug2(v, u);
    childs[v] = 0;
    vector<pair<int, int>> tempstore;
    for (auto& [e, x, y] : adj[v]) {
        // cerr << "sdfsf\n";
        // debug2(v, e);
        if (vis.count({ v,e }))continue;
        tempstore.push_back({ e,v });
        vis.insert({ e,v });
        solve(e, childs[e], adj);
        // debug2(v, e);
        // cerr << "donesolve\n";
        // adj[e].insert({ v,y,x });
        // debug2(v, e);
        // cerr << "pfpf:\n";
        // ans[e].displa();
    }
    for (auto& [e, x, y] : adj[v]) {
        // cerr<<"from in"<<x nl;
        // getnumof[x].displa();
        if (vis.count({ v,e }))continue;
        ans[v] = lcm(ans[v], getnumof[x]);
    }
    // debug2(v, u);
    num mul;
    for (auto& [e, x, y] : adj[v]) {
        if (vis.count({ v,e }))continue;

        num val = (ans[v] * getnumof[y]);
        val = val / getnumof[x];
        num temp = lcm(ans[e], val);
        temp = temp / val;
        mul = lcm(mul, temp);
    }
    // cerr << "lcm:\n";
    // ans[v].displa();
    // cerr << "mul:\n";
    // mul.displa();
    ans[v] = ans[v] * mul;
    // cerr << "after-v:\n";
    // ans[v].displa();
    // updatesubtree(v, 0, adj);
    ans[u] = ans[v] * retrace;
    // cerr << "after-u:\n";
    // ans[u].displa();
    for (auto& i : tempstore) {
        // auto& [e, x, y] = i.second;
        // cerr << e sp x sp y nl;
        vis.erase(i);
    }
    // cerr<<"close";
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
    spf = sieve(2e5 + 10);
    getnumof.push_back(num(1));
    for (int i = 1;i < sz;i++) {
        getnumof.push_back(num(i));
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        // debug(n);
        vector<tuple<int, int, int>>  adj[n + 1];
        childs.assign(n + 1, 0);
        ans.assign(n + 1, num());
        for (int i = 0;i < n - 1;i++) {
            int j, k, x, y;cin >> j >> k >> x >> y;
            int g = __gcd(x, y);
            x /= g;
            y /= g;
            adj[j].push_back({ k,x,y });
            adj[k].push_back({ j,y,x });
        }
        calchilds(1, adj);
        solve(1, n, adj);
        // cerr << "sdfsd";
        // ans[1].displa();
        updatesubtree(1, 0, adj);

        ll fans = 0;
        for (int i = 1;i <= n;i++) {
            // cerr<<ans[i].calnum() <<" ";
            fans = (fans + ans[i].calnum()) % MOD;
        }
        // cerr nl;
        cout << fans nl;
    }
}
