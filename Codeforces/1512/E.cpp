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
    int n,l,r,s;
    cin>>n>>l>>r>>s;
    int len=r-l+1;

    if(s<len*(len+1)/2||n*len-len*(len-1)/2<s){
        cout<<"-1\n";
        return;
    }
    s-=len*(len+1)/2;
    int start=1;
    vector<bool> vis(n+1,false);
    for(int i=len;i>=1;i--){
        if(s==0){
            vis[i]=true;
        }
        else if(s>=n-len){
            s-=(n-len);
            vis[i+n-len]=true;
        }
        else{
            vis[i+s]=true;
            s=0;
        }
    }
    int index=1;
    for(int i=1;i<l;index++){
        if(vis[index])continue;
        else{
            cout<<index<<" ";
            i++;
        }
    }
    for(int i=1;i<=n;i++){
        if(vis[i]){
            cout<<i<<" ";
        }
    }
    for(;index<=n;index++){
        if(vis[index])continue;
            cout<<index<<" ";
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
