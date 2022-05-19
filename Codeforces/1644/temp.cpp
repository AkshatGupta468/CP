#include<bits/stdc++.h>
using namespace std;
#define MOD 998244353 
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl <<'\n'
#define sp <<" "<<
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug2(n1,n2) cerr << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
#ifndef ONLINE_JUDGE
#define debug(n) cerr << #n << " : "; _dprint(n); 
#else 
#define debug(n)
#endif
template<class T>
void _dprint(vector<T> a){display(a)};
template<class T>
void _dprint(T a){cerr<<a<<"\n";}
long long binaryMultiply(long long ,long long ,long long);

int binaryExp(int a,int b,int M)
{
    // base a
    //power b
    //modular M
    //(a^b)%M

    int ans=1;
    while(b>0)
    {
        if(b&1)
        {
            ans=(ans*1ll*a)%M;
        }
        a=(a*1ll*a)%M;
        b>>=1;
    }
    return ans;
}
void solve()
{
    int n,m,k,q;
    cin>>n>>m>>k>>q;
    vector<pair<int,int>> qry(q);
    for(int i=0;i<q;i++){
        cin>>qry[i].first>>qry[i].second;
    }
    if(n==1 || m==1){
        cout<<k  nl;
        return;
    }
    int count=0;
    map<int,bool> vis[2];
    int row=0,col=0;
    for(int i=q-1;i>=0;i--){
        if(row==n||col==m)break;
        bool flag=false;
        if(vis[0].count(qry[i].first)==0){
            flag=true;
            row++;
            vis[0][qry[i].first]=1;
        }
        if(vis[1].count(qry[i].second)==0){
            flag=true;
            col++;
            vis[1][qry[i].second]=1;
        }
        count+=flag;
    }
    int ans=binaryExp(k,count,MOD);
    cout<<ans nl;
}

int main()
{
        fast_io;
    #ifndef ONLINE_JUDGE
        freopen("D:/CP/input.txt", "r", stdin);
        freopen("D:/CP/output.txt", "w", stdout);
        freopen("D:/CP/error.txt","w",stderr);
    #endif
    int t;
    cin>>t;
    while(t--)
        solve();
}
