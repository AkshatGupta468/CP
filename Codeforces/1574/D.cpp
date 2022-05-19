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
    vector<int> a[n];
    for(int i=0;i<n;i++){
        int c;cin>>c;
        a[i].resize(c);
        for(auto &j:a[i])cin>>j;
    }
    int m;cin>>m;
    pair<ll,vector<int>> banned[m];
    vector<int> dict[m];
    for(int i=0;i<m;i++){
        banned[i].first=0;
        banned[i].second.resize(n);
        for(int j=0;j<n;j++){
            cin>>banned[i].second[j];
            banned[i].second[j]--;
            banned[i].first+=a[j][banned[i].second[j]];
        }
        dict[i]=banned[i].second;
    }
    sort(dict,dict+m);
    pair<ll,vector<int>> ans({0,vector<int>(n)});
    sort(banned,banned+m);
    vector<int> temp;
    for(int i=0;i<n;i++){
        temp.push_back(a[i].size()-1);
    }
    if(!binary_search(dict,dict+m,temp)){
        ans.second=temp;
    }
    else{
        for(int i=m-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(banned[i].second[j]==0)continue;
                if(banned[i].first+a[j][banned[i].second[j]-1]-a[j][banned[i].second[j]]>ans.first){
                    vector<int> tempbuild=banned[i].second;
                    tempbuild[j]--;
                    if(!binary_search(dict,dict+m,tempbuild)){
                        ans.first=banned[i].first+a[j][banned[i].second[j]-1]-a[j][banned[i].second[j]];
                        ans.second=tempbuild;
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans.second[i]+1 <<" ";
    }
    cout nl;
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
        solve();
}
