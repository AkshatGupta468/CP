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
void _dprint(vector<T> a){display(a)};
template<class T>
void _dprint(T a){cerr<<a<<"\n";}
class fenwick{
    vector<ll> tree;
    fenwick(int n){
        tree.resize(n+1,LONG_LONG_MIN);
        // for(int i=0;i<a.size();i++){
        //     update(i+1,a[i]);
        // }
    }
    void update(int x,ll val){
        while (x<tree.size()){
            tree[x]=max(val,tree[x]);
            x+=(x & -x);
        }
    }
    ll query(int x){
        ll q=LONG_LONG_MIN;
        while (x>0){
            sum+=tree[x];
            x-=(x & -x);
        }
        return sum;
    }
};

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n),dp(n);
    vector<pair<ll,ll>> prefix(n);
    for(auto &i:a)cin>>i;
    prefix[0]=a[0];
    dp[0]=(a[0].first>0);
    dp[0]=-(a[0].first<0);
    for(int i=1;i<n;i++){
        prefix[i].first+=prefix[i-1].first+a[i];
        dp[i]=(a[i].first>0);
        dp[i]=-(a[i].first<0);
    }
    sort(prefix.begin(),prefix.end());
    vector<int> m(n);
    for(int i=0;i<=n;i++){
        m[-prefix[i].second]=i;
    }
    fenwick f(n);
    for(int i=1;i<=n;i++){
        dp[i]=f.query(m[i]-1)+i;
        f.update(i,dp[i]-i);
    }
}

int main()
{
        fast_io;
     #ifdef __linux__
        string path="/mnt/3C401CB3401C75BC/CP/";
     #elif _WIN32
        string path="D:/CP/";
     #endif
     #ifndef ONLINE_JUDGE
        freopen((path+"input.txt").c_str(), "r", stdin);
        freopen((path+"output.txt").c_str(), "w", stdout);
        freopen((path +"error.txt").c_str(),"w",stderr);
    #endif
    int t;
    cin>>t;
    while(t--)
        solve();
}
