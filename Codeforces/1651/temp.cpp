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
    map<ll,map<ll,ll>> c;
    map<pair<ll,ll>,bool> m;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        c[x][y]=1;
    }
    vector<vector<int>> v;
    for(auto &i:c){
        vector<int> temp;
        for(auto &j:i.second){
            temp.push_back(j.first);
        }
        v.push_back(temp);
    }
    for(int i=0,j=v.size()-1;i<=j;i++,j--){
        for(int l=0,r=v[i].size();l<=r;l++,r--){
            
        }
    }
}

int main()
{
        fast_io;
    #ifndef ONLINE_JUDGE
    string path="/mnt/3C401CB3401C75BC/CP/";
    // string path="D:/CP/";
        freopen((path+"input.txt").c_str(), "r", stdin);
        freopen((path+"output.txt").c_str(), "w", stdout);
        freopen((path +"error.txt").c_str(),"w",stderr);
    #endif
    int t;
    cin>>t;
    while(t--)
        solve();
}
