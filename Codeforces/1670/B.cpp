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
    int k;cin >> k;
    vector<bool> spec(26);
    for (int i = 0;i < k;i++) {
        char x;cin >> x;
        spec[x-'a']=true;
    }
    int pos=0;
    int lenm=0;
    for(int i=0;i<n;i++){
        if(spec[s[i]-'a']){
            lenm=max(lenm,i-pos);
            pos=i;
        }
    }
    cout<< lenm nl;
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
