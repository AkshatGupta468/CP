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
ll binr(ll l,ll r,ll x){
    if(l+1==r)return l;
    ll n=(l+r)/2ll;
    if(6*n*n<=x)return binr(n,r,x);
    else return binr(l,n,x);
}
void solve()
{
    ll n;
    cin>>n;
    ll r=1e5+1;
    ll v=binr(0,r,n);
    if(6*v*v==n){
        cout<<3*v nl;
        return;
    }
    else if(4*v+6*v*v>=n){
        cout<<3*v +1 nl;
        return;
    }
    else if(8*v+2+6*v*v>=n){
        cout<<3*v+2 nl;
        return;
    }
    else{
        cout<<3*v+3 nl;
        return;
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
