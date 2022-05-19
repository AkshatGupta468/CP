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
    string s;cin >> s;
    vector<int> len{ 1 };
    for (int i = 1;i < n;i++) {
        if (s[i] == s[i - 1]) {
            (*len.rbegin())++;
        }
        else len.push_back(1);
    }
    bool flag = false;
    int ans = 0;
    for (int i = 0;i < len.size();i++) {
        if (flag) {
            if (len[i] % 2)flag = false;
            else  ans++;
        }
        else if (len[i] % 2) {
            flag = true;
            ans++;
        }
    }
    

    int sec = len.size();
    for (int i = 0;i < len.size();i++) {
        if (flag) {
            if (len[i] == 2) {
                if(i<len.size()-1)len[i+1]+=len[i];
                if(i>0)len[i-1]+=len[i];
                sec -= 2;
            }
            if (len[i] % 2)flag = false;
        }
        else if (len[i] % 2) {
            // if(len[i]==1){
            //     if(i<n-1){
            //         len[i+1]++;
            //         if(i>0)len[i+1]+=len[i-1];
            //     }
            // }
            flag = true;
        }
    }
    for(int i=0;i<n;i++){
        if(len[i]==1){
            sec-=1+(i>0 && i<len.size()-1);
        }
    }
    cout << ans sp sec nl;
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
