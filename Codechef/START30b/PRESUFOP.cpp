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
    ll n;
    cin>>n;
    vector<ll> a(n),b(n);
    for(ll i=0;i<n;i++)cin>>a[i];
    for(ll i=0;i<n;i++)cin>>b[i];
    for(ll i=0;i<n;i++)a[i]=b[i]-a[i];
    ll pref=0,suff=0;
    for(ll i=1;i<n;i++){
        if(a[i]>a[i-1])suff+=a[i]-a[i-1];
        else pref+=a[i-1]-a[i];
    }
    if(*min_element(a.begin(),a.end())<0||pref>a[0]||suff>a[n-1]){
        cout<<"-1\n";
        return;
    }
    cout<< a[0]+suff nl;
}

int main()
{
        fast_io;
    #ifndef ONLINE_JUDGE
    string path="/mnt/3C401CB3401C75BC/CP/";
    // string path="D:/CP/";
        freopen((path+"input.txt").c_str(), "r", stdin);
        freopen((path+"output.txt").c_str(), "w", stdout);
        freopen((path +"error.txt").c_str(),"w",stderr);
    #endif
    int t;
    cin>>t;
    while(t--)
        solve();
}
