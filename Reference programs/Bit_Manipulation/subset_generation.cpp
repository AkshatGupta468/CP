//Subset Generation using Bitmasks
//Print all the subsets of a given array of n elements n<=20
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

/*
    Each element of set can be either chosen or not chosen so for each element we have 2 choices(to take or not take)
    hence for a set of n unique elements there are 2^n subsets that can be formed.

    Each subset can be represented by a binary representation where 1 represents element is taken and 0 represents element is not taken
    so by each integer's binary representation represents a unique subset of the original set.
    when the integer is from [0,2^n-1]
*/
//Time-Compleity => O(n*(2^n))  //n is the size of original set
vector<vector<int>> subsets_generate(vector<int>& arr)
{
    //here n is arr.size()
    long long sz = 1 << arr.size(); //sz=2^n

    vector<vector<int>> subsets(sz);
    for (long long i = 0;i < sz;i++)    //iterating from 0 to 2^n-1
    {
        long long temp = 1;
        //This loop check which bits are set in binary representation of i.
        for (int j = 0;j < arr.size();j++, temp <<= 1)
        {
            if (i & temp)
                subsets[i].push_back(arr[j]); //for every set bit the element is pushed in the subset
        }
    }
    return subsets;
}
// Given a fixed array A of 2^N integers, we need to calculate ∀ x function F(x) = Sum of all A[i] such that x&i = i, i.e., i is a subset of x.
void fun() {
    // Bruteforce:Timecomplexity : O(2^N)
        // for (int mask = 0;mask < (1 << N); ++mask) {
        //     for (int i = 0;i < (1 << N); ++i) {
        //         if ((mask & i) == i) {
        //             F[mask] += A[i];
        //         }
        //     }
        // }
    // Suboptimal Solution :Time Complexity O(3^N)
    //no. of iterations= sumover(0<=k<=N){(n C k)*2^k}= 3^N
        // iterate over all the masks
        // for (int mask = 0; mask < (1 << n); mask++) {
        //     F[mask] = A[0];
        //     // iterate over all the subsets of the mask
        //     for (int i = mask; i > 0; i = (i - 1) & mask) {
        //         F[mask] += A[i];
        //     }
        // }
    //SOS Dynamic Programming Solution ;TimeComplexity O(N * 2^N)
        //iterative version
        // for (int mask = 0; mask < (1 << N); ++mask) {
        //     dp[mask][-1] = A[mask];	//handle base case separately (leaf states)
        //     for (int i = 0;i < N; ++i) {
        //         if (mask & (1 << i))
        //             dp[mask][i] = dp[mask][i - 1] + dp[mask ^ (1 << i)][i - 1];
        //         else
        //             dp[mask][i] = dp[mask][i - 1];
        //     }
        //     F[mask] = dp[mask][N - 1];
        // }
        // //memory optimized, super easy to code.
        // for (int i = 0; i < (1 << N); ++i)
        //     F[i] = A[i];
        // for (int i = 0;i < N; ++i) for (int mask = 0; mask < (1 << N); ++mask) {
        //     if (mask & (1 << i))
        //         F[mask] += F[mask ^ (1 << i)];
        // }
}
int main()
{
    vector<int> arr = { 3,4,7 }; //Sample input array
    vector<vector<int>> subsets = subsets_generate(arr);
    //Printing each subset in each line
    for (auto& i : subsets)
    {
        cout << "{";
        for (auto& j : i)
        {
            cout << j << " ";
        }
        cout << "}\n";
    }
}
