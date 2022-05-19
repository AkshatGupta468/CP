#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cerr<<i<<" ";
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
const int sz=17;
void solve()
{
    int l,r;
    cin>>l>>r;
    vector<int> a(r-l+1);
    vector<int> cnt(sz,0),pre(sz,0);
    for(int i=l;i<=r;i++){
        int x;
        cin>>x;
        a[i-l]=x;
        for(int j=0;x>0;j++){
            cnt[j]+=(x & 1);
            x>>=1;
        }
        x=i;
        for(int j=0;x>0;j++){
            pre[j]+=(x & 1);
            x>>=1;
        }
    }
    int ans=0,mark=0;
    for(int i=sz-1;i>=0;i--){
        ans<<=1;mark<=1;
        if(2*pre[i]==(r-l+1)){
            mark++;
        }
        if(cnt[i]!=pre[i]){
            ans++;
        }
    }
    for(int i=l;i<=r;i++){
        a[i-l]=(a[i-l]^ans);
    }
    for
    cout<< ans nl;
}

int main()
{
        fast_io;
     #ifdef __linux__
        string path="/mnt/3C401CB3401C75BC/CP/";
     #elif _WIN32
        string path="D:/CP/";
     #endif
     #ifndef ONLINE_JUDGE
        freopen((path+"input.txt").c_str(), "r", stdin);
        freopen((path+"output.txt").c_str(), "w", stdout);
        freopen((path +"error.txt").c_str(),"w",stderr);
    #endif

    int t;
    cin>>t;
    while(t--)
        solve();
}
