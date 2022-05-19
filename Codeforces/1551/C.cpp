#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
struct  node
{
    int len;
    int cnt[5];
};

void solve()
{
    int n;
    cin>>n;

    vector<node> a(n);
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(auto &j:s)a[i].cnt[j-'a']++;
        a[i].len=s.length();
    }
    int ans=0;
    for(int i=0;i<5;i++){
        int tempcnt=0;
        sort(a.begin(),a.end(),[i](node &l,node &r)->bool{
            return 2*l.cnt[i]-l.len>2*r.cnt[i]-r.len;
        });
        int diff=0;
        for(int j=0;j<n;j++){
            diff+=2*a[j].cnt[i]-a[j].len;
            if(diff<=0)break;
            tempcnt++;
        }
        ans=max(ans,tempcnt);
    }
    cout<<ans<<nl;
}

int main()
{
    fast_io;

    int t;
    cin>>t;
    while(t--)
        solve();

}
