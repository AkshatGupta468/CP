#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

int main() {
    pbds A; // declaration

    A.insert(3);
    A.insert(4);
    A.insert(5);
    A.insert(5);
    A.insert(6);
    A.insert(6);
    A.insert(7);
    A.insert(8);
    A.insert(9);

    // finding kth element - 4th query
    // cout << "0th element: " << *A.find_by_order(1) << endl;
    // A.erase();
    // A.erase(A.upper_bound(4));
    // cout << "0th element: " << *A.find_by_order(1) << endl;
    cout << "No. of elems smaller than 6: " << A.order_of_key(6) << endl; // 2
    // // lower bound -> Lower Bound of X = first element >= X in the set
    // cout << "Lower Bound of 6: " << *A.lower_bound(6) << endl;
    // // Upper bound -> Upper Bound of X = first element > X in the set
    // cout << "Upper Bound of 6: " << *A.upper_bound(6) << endl;
    // // // Remove elements - 2nd query
    // A.erase(1);
    // A.erase(11); // element that is not present is not affected


    // A contains
}