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
    string s;
    cin>>s;
    ll x=1,y=1;
    bool dpresent=false,rpresent=false;
    for(int i=0;i<s.length();i++){
        if(s[i]=='R'){
            x++;
            rpresent=true;
        }
        else {
            y++;
            dpresent=true;
        }
    }
    debug2(x,y);
    ll ans=s.length();
    if(!dpresent||!rpresent){
        cout<< n nl;
        return;
    }
    dpresent=false;rpresent=false;
    for(int i=0;i<s.length();i++){
        if(s[i]=='R' && dpresent)ans+=(n-y);
        else if(s[i]=='D' && rpresent)ans+=(n-x);
        if(s[i]=='R'){rpresent=true;}
        else {dpresent=true;}
    }
    ans+=(n-x+1)*(n-y+1);
    cout << ans nl;
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
