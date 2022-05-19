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
vector<int> sieve(int size)
{
    vector<int> fac(size);
    int n=fac.size();
    for(int i=0;i<n;i++) fac[i]=i;
    for(int i=2;i*i<=n;i++)
    {
        for(int j=i*i;fac[i]==i && j<n;j+=i)
            fac[j]=min(i,fac[j]);
    }
    return fac;
}
bool solve()
{
    ll x,d;
    cin>>x>>d;
    ll splitcnt=0;
    while (x%d==0)
    {
        splitcnt++;
        x/=d;
    }
    if(splitcnt==1)return false;
    bool lisprime=true,disprime=true;
    for(ll i=2;i*i<=x;i++){
        if(x%i==0)return true;
    }
    if(splitcnt==2)return false;
    for(ll i=2;i*i<=d;i++){
        if(d%i==0){
            disprime=false;
        }
    }
    if(disprime)return false;
    if(splitcnt>3)return true;
    for(ll i=1;i*i<=x*d;i++){
        if((x*d)%i==0 && i%d!=0 && (x*d/i)%d!=0)return true;
    }
    return false;
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
        cout<<(solve()?"YES\n":"NO\n");
}
