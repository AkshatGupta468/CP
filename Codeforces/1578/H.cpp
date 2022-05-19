#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
class solve
{
    string s;
    vector<int> v;
    stack<int> st;
    public:
    solve(){
        cin>>s;
        v.resize(s.length());
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')st.push(i);
            else if(s[i]==')'){
                v[st.top()]=i;
                st.pop();
            }
        }
        cout<<cal(0,s.length()-1)<<nl;
    }
    int cal(int l,int r){
        if(l>=r)return 0;
        int t1=cal(l+1,v[l]-1);
        l=v[l]+3;
        if(l>r)return t1;
        int t2=cal(l,r);
        return max(t1+1,t2);
    }
};

int main()
{
    fast_io;
        solve();
}
