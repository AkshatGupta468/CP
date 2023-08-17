#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define display(a) for(auto i:a)cout<<i<<" ";
#define nl '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long int

string sumstringfunc(string a,string b)
{
    string ans;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());

    int carry=0,x,A,B;
    for(int i=0;;i++)
    {
        bool check=false;
        if(i<b.length())
        {
            B=(int)(b[i] - '0');
            check=true;
        }
        else
            B=0;

        if(i<a.length())
        {
            A=(int)(a[i] - '0');
            check=true;
        }
        else
            A=0;
        if(carry==0 && !check)
            break;

        x=carry + A + B;
        if(x>9)
        {
            carry=x/10;
            x%=10;
        }
        else
            carry=0;

        ans.push_back((char)(x+'0'));
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

string multiply(string upp, string down)
{
    int x = upp.size();
    int y = down.size();
    vector<string> elements;
    for (int i = down.size() - 1; i >= 0; i--)
    {
        int lowdig = down[i] - '0';
        vector<char> s1;
        int carry = 0;
        for (int j = upp.size() - 1; j >= 0; j--)
        {
            int uppdig = upp[j] - '0';
            int prod = lowdig * uppdig + carry;
            carry = prod/10;
            s1.push_back(char(prod % 10 + '0'));
        }
        if(carry!=0)
        s1.push_back(char(carry+'0'));

        string ans;
        for (int x = s1.size() - 1; x >= 0; x--)
        {
            string q(1, s1[x]);
            ans.append(q);
        }
        for (int x = 0; x < down.size() - 1 - i; x++)
            ans.append("0");

        elements.push_back(ans);
    }
    string finalans = "0";
    for (int i = 0; i < elements.size(); i++)
    {
        finalans = sumstringfunc(finalans, elements[i]);
    }
    return finalans;
}

int main()
{
    cout<<multiply("34","23");
}
