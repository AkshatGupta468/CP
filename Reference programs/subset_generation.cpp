#include<bits/stdc++.h>
using namespace std;

#define ll long long int
vector<vector<int>> subset_generate(vector<int> arr)
{
    ll n = 1 << arr.size();
    vector<vector<int>> subsets(n);
    for (ll i = 0;i < n;i++)
    {
        ll temp = 1;
        for (int j = 0;j < arr.size();j++, temp <<= 1)
        {
            if (i & temp)
                subsets[i].push_back(arr[j]);
        }
    }
    return subsets;
}
// https://codeforces.com/blog/entry/45223
//Given a fixed array A of 2^N integers, we need to calculate ∀ x function F(x) = Sum of all A[i] 
// such that x&i = i, i.e., i is a subset of x.
void fun() {
    //BruteForce: TimeComplexity O(4^N)
    // for (int mask = 0;mask < (1 << N); ++mask) {
    //     for (int i = 0;i < (1 << N); ++i) {
    //         if ((mask & i) == i) {
    //             F[mask] += A[i];
    //         }
    //     }
    // }

    //Suboptimal solution: Time Complexity O(3^N)
    // no.of iterations => sumover(0<=k<=N)((N C k)*2^k)= 3^N
    // for (int mask = 0; mask < (1 << n); mask++) {
    //     F[mask] = A[0];
    //     // iterate over all the subsets of the mask
    //      //This for loop only iterates over the subsets of the mask 
    //     for (int i = mask; i > 0; i = (i - 1) & mask) {
    //         F[mask] += A[i];
    //     }
    // }

    //
}
int main()
{
    vector<int> arr = { 3,4,7 };
    vector<vector<int>> subsets = subset_generate(arr);
    for (auto& i : subsets)
    {
        for (auto& j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}
