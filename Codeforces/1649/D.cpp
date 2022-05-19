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
bool solve()
{
    int n,c;
    cin>>n>>c;
    c*=2;
    vector<int> a(n);
    vector<int> vis(c+1,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        vis[a[i]]=1;
    }
    for(int i=1;i<=c;i++){
        vis[i]+=vis[i-1];
    }
    for(int i=1;i<=c;i++){
        if(vis[i]>vis[i-1]){
            for(int j=1;(j+1)*i-1<=c;j++){
                if(vis[(j+1)*i-1]-vis[j*i-1]>0 && vis[j]-vis[j-1]==0)return false;
            }
        }
    }
    return true;
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
       cout<<(solve()?"Yes\n":"No\n");
}
