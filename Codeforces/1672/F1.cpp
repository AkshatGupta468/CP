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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }
    vector<pair<int, vector<int> >> pos(n + 1);
    for (int i = 0;i <= n;i++) {
        pos[i].first = i;
    }
    for (int i = 0;i < n;i++) {
        pos[a[i]].second.push_back(i);
    }
    sort(pos.begin(), pos.end(), [](auto& l, auto& r) {
        return l.second.size() > r.second.size();
        });
    vector<int> ans(n);
    while (1) {
        while (!pos.empty() && pos.back().second.empty())pos.pop_back();
        if (pos.empty())break;
        for (int j = 0;j < pos.size() - 1;j++) {
            ans[pos[j + 1].second.back()] = pos[j].first;
            pos[j + 1].second.pop_back();
        }
        ans[pos[0].second.back()] = pos.back().first;
        pos[0].second.pop_back();
    }
    for (int i = 0;i < n;i++) {
        cout << ans[i] << ' ';
    }
    cout nl;
}

int main()
{
    // fast_io;
#ifdef __linux__
    string path = "/media/gakshat468/New Volume/CP/";
#elif _WIN32
    string path = "D:/CP/";
#endif
#ifndef ONLINE_JUDGE
    freopen((path + "input.txt").c_str(), "r", stdin);
    freopen((path + "output.txt").c_str(), "w", stdout);
    // freopen((path + "error.txt").c_str(), "w", stderr);
#endif
    int t;
    cin >> t;
    while (t--)
        solve();
}

