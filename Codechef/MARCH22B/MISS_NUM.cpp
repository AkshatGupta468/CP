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
bool check(ll a, ll b,vector<ll> v){
    if(a<1||a>1e4||b<1||b>1e4)return false;
    vector<ll> temp={a+b,a-b,a*b,a/b};
    sort(temp.begin(),temp.end());
    bool correct=true;
    for(ll k=0;k<temp.size();k++){
        if(temp[k]!=v[k])correct=false;
    }
    return correct;
}
void solve()
{
    ll n=4;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    for(ll i=0;i<2;i++){
        for(ll j=2;j<4;j++){
            if((v[j]+v[i])%2!=0||(v[j]-v[i])%2!=0)continue;
            ll a=(v[j]+v[i])/2;
            ll b=(v[j]-v[i])/2;
            if(check(a,b,v)){
                cout<< a sp b nl;
                return;
            }
        }
    }
    cout<<"-1 -1\n";
}

void solve(vector<ll> a)
{
    
    // ll x1, x2;
    // cin >> x1 >> x2;
    // a[0] = x1 - x2;
    // a[1] = x1 + x2;
    // a[2] = x1 / x2;
    // a[3] = x1 * x2;
    // cin >> a[0] >> a[1] >> a[2] >> a[3];
    sort(a.begin(),a.end());
    // for (int i = 0; i < 4; i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout nl;
    ll e[2] = {(a[0] + a[2]) / 2, (a[2] - a[0]) / 2};
    ll f[2] = {(a[1] + a[2]) / 2, (a[2] - a[1]) / 2};
    ll g[2] = {(a[0] + a[3]) / 2, (a[3] - a[0]) / 2};
    ll h[2] = {(a[1] + a[3]) / 2, (a[3] - a[1]) / 2};
    if (e[1] != 0 && (e[0] / e[1] == a[1] && e[0] * e[1] == a[3] && (a[0] + a[2]) % 2 == 0))
    {
        cout << e[0] sp e[1] nl;
    }
    else if (f[1] != 0 && (f[0] / f[1] == a[0] && f[0] * f[1] == a[3] && (a[1] + a[2]) % 2 == 0))
    {
        cout << f[0] sp f[1] nl;
    }
    else if (g[1] != 0 && (g[0] / g[1] == a[1] && g[0] * g[1] == a[2] && (a[0] + a[3]) % 2 == 0))
    {
        cout << g[0] sp g[1] nl;
    }
    else if (h[1] != 0 && (h[0] / h[1] == a[0] && h[0] * h[1] == a[2] && (a[1] + a[3]) % 2 == 0))
    {
        cout << h[0] sp h[1] nl;
    }
    else
    {
        cout << -1 sp - 1 nl;
    }
}

int main()
{
        // fast_io;
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        default_random_engine generator(seed);
        uniform_int_distribution<int> dist(-10000,10000);
     #ifdef __linux__
        string path="/mnt/3C401CB3401C75BC/CP/";
     #elif _WIN32
        string path="D:/CP/";
     #endif
     #ifndef ONLINE_JUDGE
        // freopen((path+"input.txt").c_str(), "r", stdin);
        freopen((path+"output.txt").c_str(), "w", stdout);
        freopen((path +"error.txt").c_str(),"w",stderr);
    #endif
    int T=10000;
    vector<pair<int,int>> ans;
    // cin>>t;
    int t=T;
    while(t--){
        ll a=dist(generator);
        ll b=dist(generator);
        ans.push_back({a,b});
        vector<ll> v={a+b,a-b,a*b,a/b};
        // debug2(a,b);
        // debug(v);cerr nl;
        shuffle(v.begin(),v.end(),generator);
        // debug(v);cerr nl;
        // char adfasfadf;
        // cin>>adfasfadf;
        solve(v);
    }
    t=T;
    freopen((path+"output.txt").c_str(), "r", stdin);
    vector<pair<int,int>> takenans;
    while(t--){
       int a,b;
       cin>>a>>b;
    //    debug2(a,b);
       takenans.push_back({a,b});
    }
    cerr<<"wronganswers:\n";
    for(int i=0;i<T;i++){
        auto temp=ans[i];
        if(ans[i].first<1||ans[i].second<1||ans[i].first>1e4||ans[i].second>1e4){
            ans[i]={-1,-1};
        }
        if(ans[i].first!=takenans[i].first||ans[i].second!=takenans[i].second)
        {
            debug2(temp.first,temp.second);
            debug2(takenans[i].first,takenans[i].second);
        }
    }
}