#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n%2){
        cout<<"NO\n";
        return;
    }
    pair<int,char> a[26]{};
    for(int i=0;i<26;i++){
        a[i].second=i+'a';
    }
    for(auto &i:s)a[i-'a'].first++;
    for(int i=0;i<26;i++){
        if(a[i]>n/2){
            cout<<"NO\n";
            return;
        }
    }
    int pos=0;
    cout<<"YES\n";
    for(int i=0;i<26;){
        if(a[i]==0){
            i++;
            continue;
        }
        a[i]--;
        s[pos%2*(n/2)+pos/2]=i+'a';
        pos++;
    }
    cout<<s<<nl;
}

int main()
{
    fast_io;

    int t;
    cin>>t;
    while(t--)
        solve();

}
