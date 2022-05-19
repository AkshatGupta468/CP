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
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if(sum%2){
        cout<<"0\n";
        return;
    }
    vector<bool> dp(n*2000+1,false);
    dp[0]=true;
    for(int i=0;i<n;i++){
        for(int j=dp.size()-a[i]-1;j>=0;j--){
            dp[j+a[i]]=(dp[j+a[i]]||dp[j]);
        }
    }
    if(!dp[sum/2]){
        cout<<"0\n";
        return;
    }
    int pos=0;
    for(int i=1;i<n;i++){
        if((a[i] & -a[i]) <(a[pos] & -a[pos])){
            pos=i;
        }
    }
    cout<<1<<nl;
    cout<<pos+1<<nl;
}

int main()
{
    fast_io;
        solve();

}
