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
void printit(vector<pair<int,int>> &v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].first;j++){
            cout<<v[i].second <<" ";
        }
    }
    cout nl;
}
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        if(v.empty()||(v.rbegin()->second)!=a[i]){
            v.push_back({1,a[i]});
        }
        else (v.rbegin()->first)++;
    }
    sort(v.begin(),v.end(),greater<pair<int,int>>());
    if(v.size()<=2||v[0].first>n/2){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    printit(v);
    rotate(v.begin(),v.begin()+1,v.end());
    printit(v);
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
