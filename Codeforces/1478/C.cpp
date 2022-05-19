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
bool solve()
{
    ll n;
    cin>>n;
    vector<ll> d(n*2);
    for(int i=0;i<2*n;i++){
        cin>>d[i];
    }
    sort(d.begin(),d.end(),greater<ll>());
    ll sum=0;
    map<ll,bool> m;
    for(int i=0;i<2*n;i+=2){
        debug(i);
        if(d[i]!=d[i+1])return false;
        debug(i);
        if((d[i]-sum)%(2*n-i)!=0)return false;
        debug(i);
        ll r=(d[i]-sum)/(2*n-i);
        if(r<=0||m[r])return false;
        m[r]=true;
        sum+=2*r;
    }
    return true;
}

int main()
{
        fast_io;
    #ifndef ONLINE_JUDGE
        freopen("D:/CP/input.txt", "r", stdin);
        freopen("D:/CP/output.txt", "w", stdout);
        freopen("D:/CP/error.txt","w",stderr);
    #endif
    int t;
    cin>>t;
    while(t--)
       cout<<(solve()?"YES\n":"NO\n");
}
