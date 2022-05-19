#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
void solve()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=k-3;i++){
        cout<<"1 ";
        n--;
    }
    int lb=n/4,r=n%4;
    switch(r){
        case 0:{
            cout<<lb<<" "<<lb<<" "<<2*lb<<nl;
            break;
        }
        case 2:{
            cout<<2<<" "<<2*lb<<" "<<2*lb<<nl;
            break;
        }
        case 1:
        case 3:{
            cout<<1<<" "<<n/2<<" "<<n/2<<nl;
        }
    }
}

int main()
{
    fast_io;

    int t;
    cin>>t;
    while(t--)
        solve();

}
