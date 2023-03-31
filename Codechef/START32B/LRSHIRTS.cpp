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
long long binaryMultiply(long long ,long long ,long long);

int binaryExp(int a,int b,int M)
{
    // base a
    //power b
    //modular M
    //(a^b)%M

    int ans=1;
    while(b>0)
    {
        if(b&1)
        {
            ans=(ans*1ll*a)%M;
        }
        a=(a*1ll*a)%M;
        b>>=1;
    }
    return ans;
}

void solve()
{
    int n;
    cin>>n;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second=i;
    }
    a.push_back({n+1,-1});
    sort(a.begin(),a.end());
    int l=0,r=1;
    ll ans=1;
    while (r<=n)    
    {
        while (a[r-1].second<a[r].second)r++;
        
        ans=((ans+binaryExp(2,r-l,MOD))%MOD -1)%MOD;

        l=r;
        r++;
    }
    
    cout<< ans nl;
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
