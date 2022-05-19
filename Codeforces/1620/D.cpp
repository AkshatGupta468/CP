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
int calmin(vector<int> &a,int one ,int two){
    int ans=0;
    for(int i=0;i<a.size();i++){
        if(a[i]%3==0){
            int t=min(one,two);
            t=3*t+3*((one-t)/3)+6*((two-t)/3);
            ans=max((a[i]-t)/3,ans);
        }
        else if(a[i]%3==1){
            int temp=2e9;
            if(one>=1){
                temp=a[i]/3;
            }
            if(two>=2 && a[i]>=4){
                temp=(a[i]-4)/3;
            }
            ans=max(ans,temp);
        }
        else {
            int temp=2e9;
            if(one>=2){
                temp=a[i]/3;
            }
            if(two>=1)temp=a[i]/3;
            ans=max(ans,temp);
        }
    }
    return ans+one+two;
}
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=2e9;
    for(int one=0;one<=3;one++){
        for(int two=0;two<=3;two++){
            ans=min(ans,calmin(a,one,two));
        }
    }
    cout<< ans nl;
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
