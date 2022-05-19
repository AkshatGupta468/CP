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
void _dprint(T a){cerr<<bitset<32>(a) sp a<<"\n";}
const int lim=2e9;
ll qry(ll a,ll b){
    cout<<"? "<<a sp b <<endl;
    ll q;
    cin>>q;
    // ll x=4;
    // q=__gcd(a+x,b+x);
    // cout<< q nl;
    return q;
}
void solve()
{
    ll x=0;
    for(int i=0;i<30;i++){
        ll v=1<<i;
        ll q=qry(v-x,(v<<1)+v-x);
        // cerr<<"a : "<<bitset<32>(4) nl;
        // debug(v);
        // debug(q);
        if(q==(v<<1)){
            x=(x|v);
        }
        // debug(x);
    }
    cout<<"! "<< x <<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
}
