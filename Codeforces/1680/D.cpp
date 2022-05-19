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
void solve()
{
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n+1),prefcnt(n+1),prefsum(n+1);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        prefsum[i]+=prefsum[i-1]+a[i];
        prefcnt[i]+=prefcnt[i-1]+(a[i]==0);
    }
    ll ans=0;
    for(ll i=0;i<n;i++){
        for(ll j=i;j<n;j++){
            if(prefcnt[i]>prefcnt[j]-prefcnt[i])continue;
            ll t
            ans=max(ans,
                (prefsum[i]+prefcnt[i]*k) - (prefsum[j]-(prefcnt[j]-2*prefcnt[i])*k));
           ans=max(ans,0(prefsum[j]+(prefcnt[j]-2*prefcnt[i])*k) - (prefsum[i]-prefcnt[i]*k));
        }
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
