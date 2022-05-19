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
    int n,C;
    cin>>n>>C;
    vector<ll> cost_pow(C+1,0);
    vector<tuple<ll,ll,ll>> units(n);
    for(auto &[c,d,h]:units){
        cin>>c>>d>>h;
        cost_pow[c]=max(cost_pow[c],d*h);
    }
    vector<ll> best(C+1);
    for(int c=1;c<=C;c++){
        for(int q=1;q*c<=C;q++){
            best[c*q]=max(best[c*q],q*cost_pow[c]);
        }
    }
    for(int c=1;c<=C;c++)
    best[c]=max(best[c],best[c-1]);

    int m;cin>>m;
    vector<tuple<ll,ll>> monsters(m);
    for(auto &[D,H]:monsters){
        cin>>D>>H;
        int pos=upper_bound(best.begin(),best.end(),D*H)-best.begin();
        if(pos==C+1)cout<<"-1 ";
        else cout<<pos<<" ";
    }
    cout nl;
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
        solve();
}
