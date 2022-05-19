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
void solve()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int ans=0;
    char c='a';
    int pos=n;
    for(int i=0;i<n;i++){
        if(s[i]-'a'>k){
            pos=i;
            break;
        }
        c=max(c,s[i]);
    }
    k-=c-'a';
    for(int i=0;i<n;i++){
        if(s[i]<=c)s[i]='a';
    }
    c=s[pos];
    if(pos<n)s[pos]-=k;
    for(int i=pos+1;i<n;i++){
        if(s[pos]<=s[i] && s[i]<=c)
        s[i]=s[pos];
    }
    cout<< s nl;
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
