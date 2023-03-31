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
class frac{
    ll x;
    vector<ll> pf;
    vector<ll> cnt;
    vector<ll> xcnt;
    map<vector<ll>,ll> m;
    public:
    ll ans=0;
    frac(ll _x,vector<ll> &a){
        x=_x;
        for(ll i=2;i*i<=_x;i++){
            if(_x%i==0){
                pf.push_back(i);
                ll tempcnt=0;
                while(_x%i==0){
                    _x/=i;
                    tempcnt++;
                }
                xcnt.push_back(tempcnt);
                cnt.push_back(0);
            }
        }
        if(_x>1){
            pf.push_back(_x);
            xcnt.push_back(1);
            cnt.push_back(0);
        }
        m[cnt]=1;
        fun(a);
    }
    void fun(vector<ll> &a){
        for(ll i=0;i<a.size();i++){
            vector<ll> tempcnt(pf.size(),0);
            for(ll j=0;j<pf.size();j++){
                while(a[i]%pf[j]==0){
                    tempcnt[j]++;
                    a[i]/=pf[j];
                }
            }
            if(a[i]==1){
                for(ll j=0;j<pf.size();j++){
                    cnt[j]+=tempcnt[j]-xcnt[j];
                }
                m[cnt]++;
            }
            if(a[i]>1||i==a.size()-1){
                for(auto &roots:m){
                    ans+=roots.second*(roots.second-1)/2;
                }
                fill(cnt.begin(),cnt.end(),0);
                m.clear();
                m[cnt]=1;
            }
        }
    }
};
void solve()
{
    ll n,x;
    cin>>n>>x;
    vector<ll> a(n);
    for(ll i=0;i<n;i++)cin>>a[i];
    frac f(x,a);
    cout<<f.ans nl;
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
