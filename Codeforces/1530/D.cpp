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
    vector<int> inv(n+1,-1);
    vector<int> ans(n+1,-1);
    vector<int> a(n+1);
    queue<int> q;
    int cnt=n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(inv[a[i]]<0){
            inv[a[i]]=i;
            ans[i]=a[i];
            cnt--;
        }
        else q.push(i);
    }
    int sz=q.size();
    cout<<n-sz<<nl;
    while(sz--){
        int x=q.front();
        if(inv[x]==-1 && ans[x]==-1){
            inv[x]=inv[a[x]];
            inv[a[x]]=x;
            ans[x]=a[x];
            ans[inv[x]]=x;
            q.pop();
        }
        else {
            q.push(q.front());
            q.pop();
        }
    }

    for(int i=1;i<=n;i++){
        if(inv[i]==-1){
            inv[i]=q.front();
            ans[q.front()]=i;
            q.pop();
        }
    }
    
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
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
