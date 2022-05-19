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
    int n;
    cin>>n;

    vector<int> a(n),b(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
    }
    if(n%2){
        cout<<1<<nl;return;
    }
    sort(a.begin(),a.end());sort(b.begin(),b.end());
    cout<<(a[n/2]-a[n/2-1]+1)*1ll*(b[n/2]-b[n/2-1]+1)<<nl;
}

int main()
{
    fast_io;

    int t;
    cin>>t;
    while(t--)
        solve();

}
