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

    vector<int> a(n);
    vector<int> p(2,-1);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]%2)p[i%2]=i;
    }
    if(p[0]==-1 && p[1]==-1){
        cout<<"-1\n";
        return;
    }
    int ans=0,temp=0;
    for(int i=0;p[0] !=-1 && i<n;i++){
        if(i%2)
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
