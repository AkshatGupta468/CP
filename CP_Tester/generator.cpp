#include<bits/stdc++.h>
#include "/media/gakshat468/New Volume/CP/testlib/testlib.h"
using namespace std;
#define ll long long int
#define nl <<'\n';

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = 10;
    println(n);
    for (int i = 1;i <= n;i++) {
        vector<int> v(n);
        for (int j = 1;j <= n;j++)v[j - 1] = j;
        shuffle(v.begin(), v.end());
        println(v);
    }
}
