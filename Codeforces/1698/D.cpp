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
bool query(int l, int r) {
    cout << "? " << l sp r nl;
    vector<int> a(r - l + 1);
    int ext = 0;
    for (int i = 0;i < a.size();i++) {
        int x;cin >> x;
        ext += (x<l || x>r);
    }
    return (r - l + 1 - ext) % 2;
}
int bs(int l, int r) {
    if (l == r)return l;
    int x = (l + r) / 2;
    if (query(l, x)) return bs(l, x);
    else return bs(x + 1, r);
}
bool solve()
{
    int n;
    cin >> n;
    int ans = bs(1, n);
    cout << "! " << ans nl;
    return true;
}

int main()
{

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        // cout << (solve() ? "YES\n" : "NO\n");
        // cout << (solve() ? "" : "-1\n");
    }
}
