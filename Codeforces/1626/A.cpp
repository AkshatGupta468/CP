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
    string s;
    cin>>s;
    int n=26;
    vector<int> a(n,0);
    for(int i=0;i<s.size();i++)
    {
        a[s[i]-'a']++;
    }
    for(int i=0;i<n;i++){
        if(a[i]==2)cout<<char('a'+i);
    }
    for(int i=0;i<n;i++){
        if(a[i]==1)cout<<char('a'+i);
    }
    for(int i=0;i<n;i++){
        if(a[i]==2)cout<<char('a'+i);
    }
    cout<<nl;
}

int main()
{
    fast_io;

    int t;
    cin>>t;
    while(t--)
        solve();

}
