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
    int x=0;
    for(int i=0;i<n;i++){
        cout<<(x^i)<<nl;
        int q;
        cin>>q;
        if(q==-1||q==1)return;
        x^=x^i;
    }
}

int main()
{
    cout.flush();

    int t;
    cin>>t;
    while(t--)
        solve();

}
