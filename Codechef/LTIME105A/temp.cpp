#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
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
    ll permsum=n*(n+1)/2;
    vector<ll> a(n+1);
    ll sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }   
    cout<<a.size() nl;
    int cnt=0;
    vector<int> vis(n+1,0);
    for(ll x=n+1;x<=2*1e7;x++){
        if(sum%x==permsum%x){
            cnt++;
            for(int i=1;i<=n;i++){
                if(a[i]%x<=n)
                vis[a[i]%x]=x;
            }
            bool flag=true;
            for(int i=1;i<=n;i++){
                if(vis[i]!=x){
                    flag=false;
                    break;
                }
            }
            if(flag){
                cout<<"YES "<<x nl;
                return; 
            }
        }
    }

    cout<<"NO\n";
    cerr<<cnt nl;
}

int main()
{
        // fast_io;
    #ifndef ONLINE_JUDGE
        freopen("D:/CP/input.txt", "r", stdin);
        // freopen("D:/CP/output.txt", "w", stdout);
        freopen("D:/CP/error.txt","w",stderr);
    #endif
    int t;
    cin>>t;
    while(t--)
        solve();
}
