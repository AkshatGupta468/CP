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
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    vector<int> cnt(n+1),mexrt(n);
    int pos=0;
    for(int i=n-1;i>=0;i--){
        cnt[a[i]]++;
        while(cnt[pos]>0)pos++;
        mexrt[i]=pos;
    }
    // display(mexrt);cout<<nl;
    vector<int> ans;
    cnt.clear();
    cnt.resize(n+1,0);
    pos=0;
    int l=0;
    for(int i=0;i<n;i++){
        cnt[a[i]]++;
        while (cnt[pos]>0)pos++;
        if(pos==mexrt[l]){
            // debug2(i,pos);
            ans.push_back(mexrt[l]);
            while(l<=i){
                cnt[a[l]]--;
                l++;
            }
            pos=0;
        }
    }
    cout<<ans.size()<<nl;
    display(ans);cout<<nl;
}

int main()
{
    fast_io;

    int t;
    cin>>t;
    while(t--)
        solve();

}
