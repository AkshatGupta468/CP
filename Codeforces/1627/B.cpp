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
    vector<pair<int,int>> v={{1,1},{n,1},{1,m},{n,m}};
    vector<int> ans;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int temp=-1;
            for(auto &e:v){
                temp=max(temp,abs(e.first-i)+abs(e.second-j));
            }
            ans.push_back(temp);
        }
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<n*m;i++){
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
