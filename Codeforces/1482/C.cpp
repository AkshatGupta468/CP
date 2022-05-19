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
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> cnt(n+1,0);
    vector<vector<int>> a(m);
    for(int i=0;i<m;i++){
        int k;cin>>k;
        a[i].resize(k);
        for(int j=0;j<k;j++)
            cin>>a[i][j];
        if(k==1)cnt[a[i][0]]++;
    }
    for(auto &i:cnt)
        if(i>(m+1)/2){
            cout<<"NO\n";
            return;
        }
    cout<<"YES\n";
    for(int i=0;i<m;i++){
        if(a[i].size()==1){
            cout<<a[i][0] <<" ";
            continue;
        }
        if(cnt[a[i][0]]==(m+1)/2){
            cnt[a[i][1]]++;
            cout<<a[i][1] <<" ";
        }
        else{
            cnt[a[i][0]]++;
            cout<<a[i][0] <<" ";
        }
    }
    cout nl;
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
