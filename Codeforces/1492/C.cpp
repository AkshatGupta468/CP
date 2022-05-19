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
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    vector<int> pos(m+1,0);
    int j=n-1;
    for(int i=m-1;i>=0;i--){
        for(;j>=0;j--){
            if(s[j]==t[i]){
                pos[i]=j;
                j--;
                break;
            }
        }
    }
    j=0;
    int ans=0;
    for(int i=0;i<m-1;i++){
        for(;j<n;j++){
            if(s[j]==t[i]){
                pos[i]=j;
                ans=max(ans,pos[i+1]-pos[i]);
                j++;
                break;
            }
        }
    }
    cout<<ans<<nl;
}

int main()
{
    fast_io;
        solve();

}
