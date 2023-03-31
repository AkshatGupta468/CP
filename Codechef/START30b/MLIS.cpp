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
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<pair<int,int>> len(n+1,{0,0});
    vector<int> dpinc(n+1,INT_MAX);
    dpinc[0]=0;
    int index=0;
    for(int i=0;i<n;i++){
        if(a[i]>dpinc[index]){
            index++;
            dpinc[index]=a[i];
        }
        else{
            int pos=lower_bound(dpinc.begin(),dpinc.begin()+index,a[i])-dpinc.begin();
            dpinc[pos]=a[i];
        }
        len[i].first=index;
    }
    vector<int> dpdec(n+1,0);
    dpdec[0]=INT_MAX;
    index=0;
    for(int i=n-1;i>=0;i--){
        if(a[i]<dpdec[index]){
            index++;
            dpdec[index]=a[i];
        }
        else{
            int pos=lower_bound(dpdec.begin(),dpdec.begin()+index,a[i],greater<int>())-dpdec.begin();
            dpdec[pos]=a[i];
        }
        len[i].second=index;
    }
    int ans=len[0].second;
    for(int i=0;i<n;i++){
        ans=max(ans,len[i].first+len[i+1].second);
    }
    cout << ans nl;
}

int main()
{
        fast_io;
    #ifndef ONLINE_JUDGE
    // string path="/mnt/3C401CB3401C75BC/CP/";
    string path="D:/CP/";
        freopen((path+"input.txt").c_str(), "r", stdin);
        freopen((path+"output.txt").c_str(), "w", stdout);
        freopen((path +"error.txt").c_str(),"w",stderr);
    #endif
    int t;
    cin>>t;
    while(t--)
        solve();
}
