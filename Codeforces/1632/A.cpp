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
    string s;cin>>s;
    if(s.size()==1){
        cout<<"YES\n";
    }
    else if(s.size()==2 && s[0]!=s[1]){
        cout<<"YES\n";
    }
    else cout<<"NO\n";
}

int main()
{
    fast_io;

    int t;
    cin>>t;
    while(t--)
        solve();

}
