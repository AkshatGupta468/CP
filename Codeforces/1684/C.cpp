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
int getpos(int k, vector<vector<int>> a, int n, int m) {
    int ind = -1;
    for (int j = 1;j <= m;j++) {
        int d = 1;
        if (j == k)continue;
        else if (j == k + 1)d = 2;
        for (int i = 0;i < n;i++) {
            if (a[i][j - d] > a[i][j]) {
                ind = j;
                break;
            }
        }
    }
    cerr << k sp n sp m sp ind nl;
    if (ind != -1) {
        for (int i = 0;i < n;i++)swap(a[i][k], a[i][ind]);
        int temp = -1;
        for (int j = 1;j <= m;j++) {
            for (int i = 0;i < n;i++) {
                if (a[i][j - 1] > a[i][j]) {
                    temp = j;
                    break;
                }
            }
        }
        if (temp == -1)return ind;
        for (int i = 0;i < n;i++)swap(a[i][k], a[i][ind]);
        ind--;
        for (int i = 0;i < n;i++)swap(a[i][k], a[i][ind]);
        temp = -1;
        for (int j = 1;j <= m;j++) {
            for (int i = 0;i < n;i++) {
                if (a[i][j - 1] > a[i][j]) {
                    temp = j;
                    break;
                }
            }
        }
        if (temp == -1)return ind;
        else return -1;
    }
    for (int j = 1;j <= m;j++) {
        if (j == k)continue;
        bool flag = true;
        for (int i = 0;i < n;i++) {
            if (abs(j - k) == 1) {
                int l = min(j, k);
                int r = max(j, k);
                if (a[i][r] > a[i][l])flag = false;
                if (a[i][l - 1] > a[i][r] || a[i][l] > a[i][r + 1])flag = false;
                continue;
            }
            if (a[i][k - 1] > a[i][j] || a[i][j] > a[i][k + 1])flag = false;
            if (a[i][j - 1] > a[i][k] || a[i][k] > a[i][j + 1])flag = false;
        }
        if (flag)return j;
    }
    return -1;
}
bool solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m + 2));
    for (int i = 0;i < n;i++) { a[i][m + 1] = 2e9;a[i][0] = 0; }
    for (int i = 0;i < n;i++) {
        for (int j = 1;j <= m;j++) {
            cin >> a[i][j];
        }
    }
    int ind = -1;
    for (int j = 1;j <= m;j++) {
        for (int i = 0;i < n;i++) {
            if (a[i][j - 1] > a[i][j]) {
                ind = j;
            }
        }
    }
    if (ind == -1) {
        cout << "1 1\n";
        cerr << "---\n\n";
        return true;
    }
    debug(ind);
    int k = getpos(ind - 1, a, n, m);
    if (k != -1) {
        cout << ind - 1 sp k nl;
        cerr << "---\n\n";
        return true;
    }
    debug(ind);
    k = getpos(ind, a, n, m);
    if (k != -1) {
        cout << ind sp k nl;
        cerr << "---\n\n";
        return true;
    }
    cerr << "+++++\n\n";
    return false;
}

int main()
{
    fast_io;
#ifdef __linux__
    string path = R"(/media/gakshat468/New Volume/CP/)";
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
        cout << (solve() ? "" : "-1\n");
}
