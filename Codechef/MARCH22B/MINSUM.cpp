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
    string a;
    cin>>a;
    string s=a,t;
    sort(s.begin(),s.end());
    int x=count(s.begin(),s.end(),'1');
    char c[2]={'0','1'};
    if(x>n-x){
        swap(c[0],c[1]);
        x=n-x;    
    }
    int q=(n-x)/(x+1); 
    int r=(n-x)%(x+1);
    for(int i=0;i<x;i++){
        t+=string((r>0),c[0])+string(q,c[0])+c[1];
        r--;
    }
    t+=string(q,c[0]);
    cerr<<string(q,c[0]) nl;
    reverse(t.begin(),t.end());
    if(c[0]=='1')reverse(s.begin(),s.end());
    cout<<s nl;
    cout<<t nl;
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
