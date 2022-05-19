#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
class Soultion 
{
    public:
    vector<pair<int,int>> a;
    int n;
    bool check(int x){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(cnt<=a[i].second && x-cnt-1<=a[i].first){
                cnt++;
                if(cnt>=x)return true;
            }
        }
        return false;
    }
    int binrsrch(int l ,int r){
        if(l+1==r) return l;
        int x=(l+r)/2;
        if(check(x))  return binrsrch(x,r);
        else return binrsrch(l,x);
    }
    Soultion(){
        solve();
    }
    void solve()
    {
        cin>>n;
        a.resize(n+1);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].first>>a[i].second;
        }
        cout<<binrsrch(1,n+1)<<nl;
    }
};

int main()
{
    fast_io;

    int t;
    cin>>t;
    while(t--){
        Soultion s;
    }
        

}
