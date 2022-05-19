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
#define int long long
template<class T>
void _dprint(vector<T> a){display(a)};
template<class T>
void _dprint(T a){cerr<<a<<"\n";}
int solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n<=2)return 0;
    int c=-1;
    for(int i=0;i<n-1;i++){
        if(a[i+1]>=a[i]){
            if(c==-1)
            c=a[i+1]-a[i];
            else if(a[i+1]-a[i]!=c)return -1;
        }
    }
    int m=-1;
    for(int i=0;i<n-1;i++){
        if(a[i+1]<=a[i]){
            if(m==-1){
                m=c+a[i]-a[i+1];
            }
            else if(m!=c+a[i]-a[i+1]){
                return -1;
            }
        }
    }
    if(c<=0) return 0;
    if(m<0)return 0;
    for(auto &i:a)if(i>=m)return -1;
    cout<<m<<" ";
    return c;
}

int32_t main()
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
        cout<<solve() nl;
}
