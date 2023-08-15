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
char query1(int i) {
    cout << "? 1 " << i << endl;
    char c;
    cin >> c;
    if (c == '0')exit(0);
    return c;
}
int query2(int l, int r) {
    cout << "? 2 " << l sp r << endl;
    int c;
    cin >> c;
    if (c == 0)exit(0);
    return c;
}
bool solve()
{
    int n;
    cin >> n;
    vector<pair<int, char>> posn;
    string s;
    char c = query1(1);
    posn.push_back({ 1,c });
    s.push_back(c);
    int lastdiff = 1;
    function<int(int, int, int, int)> bs = [&](int l, int r, int i, int sz) {
        if (l + 1 == r)return l;
        int mid = (l + r) / 2;
        int q = query2(posn[mid].first, i);
        if (q == sz - mid)
            return bs(mid, r, i, sz);
        else
            return bs(l, mid, i, sz);
    };
    for (int i = 2;i <= n;i++) {
        int currdiff = query2(posn[0].first, i);
        if (currdiff > lastdiff) {
            c = query1(i);
            posn.push_back({ i,c });
            s.push_back(c);
            lastdiff++;
        }
        else {
            int v = bs(0, posn.size(), i, posn.size());
            s.push_back(posn[v].second);
            posn[v].first = i;
        }
        sort(posn.begin(), posn.end());
    }
    cout << "! " << s << endl;
    return true;
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
        // cout << (solve() ? "YES\n" : "NO\n");
        // cout << (solve() ? "" : "-1\n");
    }
}
