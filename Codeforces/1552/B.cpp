#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
bool comp(pair<int,vector<int>> &x,pair<int,vector<int>> &y){
    int cnt=0;
    for(int i=0;i<5;i++){
        if(x.second[i]<y.second[i])cnt++;
    }
    return cnt>=3;
}
void solve()
{
    int n;
    cin>>n;

    vector<pair<int,vector<int>>> a(n);
    for(int i=0;i<n;i++)
    {
        a[i].first=i+1;
        a[i].second.resize(5);
        for(int j=0;j<5;j++){
            cin>>a[i].second[j];
        }
    }
    int pos=0;
    for(int i=1;i<n;i++){
        if(comp(a[i],a[pos])){
            pos=i;
        }
    }
    for(int i=0;i<n;i++){
        if(comp(a[i],a[pos])){
            cout<<"-1\n";
            return;
        }
    }
    cout<<a[pos].first<<nl;
}

int main()
{
    fast_io;

    int t;
    cin>>t;
    while(t--)
        solve();

}
