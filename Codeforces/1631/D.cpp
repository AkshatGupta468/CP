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

    vector<int> a(n+1);
    vector<int> v(n+1);
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        v[i]=x;
        a[x]++;
    }
    for(int i=1;i<=n;i++){
        a[i]+=a[i-1];
    }
    int l=0,r=n+1;
    for(int i=0;i<n;i++){
        int x=lower_bound(a.begin(),a.end(),a[i]+(n+k+1)/2)-a.begin();
        if(x==n+1)continue;
        if(x-i<r-l){
            r=x;
            l=i;
        }
    }
    cout<<l+1<<" "<<r<<nl;
    for(int i=1;i<=n;i++){
        v[i]=-1+2*(l<v[i] && v[i]<=r)+v[i-1];
        // cout<<v[i]<<" ";
    }
    // cout<<nl;
    int e=0,val=1;
    for(int i=1;i<=n && val<k;i++){
        if(val==v[i]){
            cout<<e+1<<" "<<i<<nl;
            e=i;
            val++;
        }
    }
    cout<<e+1<<" "<<n<<nl;
}

int main()
{
    fast_io;

    int t;
    cin>>t;
    while(t--)
        solve();

}
