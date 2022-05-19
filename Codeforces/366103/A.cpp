#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
bool solve()
{
    int n;
    cin>>n;
    vector<bool> val(n);
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    
    sort(a.begin(),a.end());
    stack<int> pos;
    for(int i=0;i<n;i++){
        val[i]=abs(a[i].second-i) & 1;
        if(!pos.empty() && val[i] && a[pos.top()].first==a[i].first && (i-pos.top())%2){
            val[pos.top()]=0;
            val[i]=0;
            pos.pop();
        }
        if(val[i])pos.push(i);
    }
    for(auto i:val)if(i)return false;
    return true;
}

int main()
{
    fast_io;

    int t;
    cin>>t;
    while(t--)
        cout<<(solve()?"YES\n":"NO\n");

}
