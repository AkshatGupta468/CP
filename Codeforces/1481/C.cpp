#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
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
bool solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(n),c(m);
    vector<vector<int>> col(n+1);
    vector<int> avail(n+1,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        avail[b[i]]=i+1;
        if(b[i]!=a[i])col[b[i]].push_back(i+1);
    }
    for(int i=0;i<m;i++){
        cin>>c[i];
    }
    vector<int> ans(m);
    for(int i=m-1;i>=0;i--){
        if(!avail[c[i]]){
            if(i==m-1)return false;
            avail[c[i]]=ans[i+1];
        }
        ans[i]=avail[c[i]];
        if(col[c[i]].size()>0){
            ans[i]=*(col[c[i]].rbegin());
            debug(i);
            debug(ans[i]);
            col[c[i]].pop_back();
        }
    }
    for(int i=1;i<=n;i++)if(col[i].size()>0)return false;
    cout<<"YES\n";
    for(int i=0;i<m;i++)cout<<ans[i]<<" ";
    cout nl;
    return true;
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
        cout<<(solve()?"":"NO\n");
}
