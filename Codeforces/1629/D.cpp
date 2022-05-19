#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
bool solve()
{
    int n;
    cin>>n;

    vector<string> a;
    bool flag=false;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        a.push_back(s);
        if(s.length()==1)flag=true;
        else if(s.length()==2 && s[0]==s[1])flag=true;
        else if(s.length()==3 && s[0]==s[2])flag=true;
    }
    if(flag) return true;
    set<string> s;
    for(int i=0;i<n;i++){
        if(a[i].length()==2){
            string temp=a[i];
            reverse(temp.begin(),temp.end());
            if(s.count(temp))return true;
            for(char j='a';j<='z';j++){
                temp.push_back(j);
                if(s.count(temp))return true;
                temp.pop_back();
            }
        }
        else {
            string temp=a[i];           
            reverse(temp.begin(),temp.end());
            if(s.count(temp))return true;
            temp=a[i].substr(1,2);
            reverse(temp.begin(),temp.end());
            if(s.count(temp))return true;
        }
        s.insert(a[i]);
    }
    return false;
}

int main()
{
    fast_io;

    int t;
    cin>>t;
    while(t--)
        cout<<(solve()?"YES\n":"NO\n");

}
