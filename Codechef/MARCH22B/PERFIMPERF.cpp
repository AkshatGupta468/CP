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
    int sz=1e1+1;
    vector<vector<int>> fac(sz);
    unordered_map<int,vector<int>> m;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        for(int j=2;j*j<=x;j++){
            while (x%(j*j)==0)
            {
                x/=j*j;
            }
            if(x%j==0){
                // cerr<<i sp j nl;
                fac[j].push_back(i);
                x/=j;
            }
        }
        if(x>1){
            // cerr<<i sp x nl;
            if(x<sz)
            fac[x].push_back(i);
            else m[x].push_back(i);
        }
    }
    int ans=0;
    for(auto &v:m){
        vector<int> temp;
        for(auto &j:v.second){
            temp.push_back(j);
        }
        fac.push_back(temp);
    }
    sort(fac.begin(),fac.end());
    for(int i=1;i<fac.size();i++){
        // debug(i);
        // debug(fac[i]);cerr nl;
        if(fac[i]!=fac[i-1])ans++;
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
