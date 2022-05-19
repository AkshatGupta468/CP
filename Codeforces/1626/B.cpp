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
    for(int i=s.size()-1;i>0;i--){
        if(s[i]-'0'+s[i-1]-'0'>=10){
            for(int j=0;j<i-1;j++)
            cout<<s[j];
            cout<<s[i]-'0'+s[i-1]-'0';
            for(int j=i+1;j<s.size();j++)cout<<s[j];
            cout<<nl;
            return;
        }
    }
    
    cout<<s[0]-'0'+s[1]-'0'<<s.substr(2)<<nl;
}

int main()
{
    fast_io;

    int t;
    cin>>t;
    while(t--)
        solve();

}
