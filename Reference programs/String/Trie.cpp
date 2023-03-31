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

const int k = 26;

class Trie {
    struct node {
        int count = 0;
        vector<int> next;
        node() {
            next.assign(k, -1);
        }
    };
    vector<node> tree;
    Trie() {
        tree.resize(1);
    }
public:
    void add_string(string s) {
        int x = 0;
        for (int i = 0;i < s.length();i++) {
            if (tree[x].next[s[i] - 'a'] == -1) {
                tree[x].next[s[i] - 'a'] = tree.size();
                tree.emplace_back();
            }
            x = tree[x].next[s[i] - 'a'];
        }
        tree[x].count++;
    }

    int countString(string s) {
        int x = 0;
        for (int i = 0;i < s.length();i++) {
            if (tree[x].next[s[i] - 'a'] == -1)return false;
            x = tree[x].next[s[i] - 'a'];
        }
        return tree[x].count;
    }
};

bool solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }

    return (false and true);
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
