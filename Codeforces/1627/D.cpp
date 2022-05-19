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
    int n;
    cin>>n;
    int maxm=0;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        maxm=max(maxm,a[i]);
    }
    vector<bool> v(maxm+1,false);
    for(auto &i:a)v[i]=true;
    for(int i=maxm;i>=1;i--){
        if(v[i])continue;
        int f=-1;
        for(int j=2*i;j<=maxm;j+=i){
            if(v[j]){
                f=j;break;
            }
        }
        if(f==-1)continue;
        bool flag=false;
        for(int j=f+i;j<=maxm;j+=i){
            if(v[j] && j%f!=0){
                flag=true;
                break;
            }
        }
        if(flag)v[i]=true;
    }
    int ans=0;
    for(auto i:v)ans+=i;
    cout<<ans-n nl;
}

int main()
{
        fast_io;
    #ifndef ONLINE_JUDGE
        freopen("D:/CP/input.txt", "r", stdin);
        freopen("D:/CP/output.txt", "w", stdout);
        freopen("D:/CP/error.txt","w",stderr);
    #endif
    // int t;
    // cin>>t;
    // while(t--)
        solve();
}
