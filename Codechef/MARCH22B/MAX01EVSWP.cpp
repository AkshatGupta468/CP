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
    int n;
    cin>>n;
    string s;
    cin>>s;
    int a[2][2]{};
    for(int i=0;i<n;i++){
        a[i%2][s[i]-'0']++;
    }
    int x=min(a[0][0],a[1][1]);
    a[0][0]-=x;
    a[1][1]-=x;
    int pos[2]={0,0};
    for(int i=2*x;i<n;i++){
        if(a[i%2][pos[i%2]]==0)pos[i%2]++;
        a[i%2][pos[i%2]]--;
        s[i]=char('0'+pos[i%2]);
    }

    int ans=x;
    for(int i=2*x+1;i<n;i++){
        if(s[i-1]=='0' && s[i]=='1')ans++;
    }
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
