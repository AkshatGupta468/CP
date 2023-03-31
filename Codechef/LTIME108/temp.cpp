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
int fun(vector<int>& pos, vector<int>& zeropos) {
    int cnt = 0;
    int p = 0, q = 0;
    bool flag = 0;
    int last = -1;
    while (1)
    {
        if (!flag) {
            while (p < pos.size() && pos[p] <= last)
            {
                p++;
            }
            if (p == pos.size())break;
            last = pos[p];
            flag = true;
            cnt++;
        }
        else {
            while (q < zeropos.size() && zeropos[q] <= last)
            {
                q++;
            }
            if (q == zeropos.size())break;
            last = zeropos[p];
            flag = false;
            cnt++;
        }
    }
    return cnt;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int t = 0;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
        t ^= a[i];
    }
    int x = 0;
    map<int, vector<int>> pos;
    vector<int> zeropos;
    for (int i = 0;i < n;i++) {
        x ^= a[i];
        if (x == 0) {
            zeropos.push_back(i);
        }
        else
            pos[x].push_back(i);
    }
    if(t!=0){
        cout<<n-fun(pos[t],zeropos) nl;
        return;
    }
    else {
        int ans=0;`
        for(auto &e:pos){
            ans=max(ans,fun(e.second,zeropos));
        }
        cout<< n-ans nl;
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
    int t;
    cin >> t;
    while (t--)
        solve();
}
