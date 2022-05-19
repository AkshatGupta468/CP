#include <iostream>
#include <vector> 
#include <algorithm>
#include <set> 
#include <map>

using namespace std;
int main(){
    // int x; // - 2*10^9 till 2* 10^9
    // // long long x; // -2*10*18 till 2* 10 ^18;


    // int a[7] = {1,7,8,5,6,6,8};

    // int y = 6;

    // // // for(int i=0;i<7;i++){
    // //     if(a[i]==y){
    // //         cout << "Yes the element y is present in the array";
    // //         break;
    // //     }
    // // }
    // // Linear Search - iterating over whole array

    // // Binary Search 

    // int b[10] = {2,4,6,7,8,20,45,48,64,90};  // the array is sorted in increasing order

    // int z = 9; // element which needs to be find

    // int low = 0;
    // int high = 9;
    // bool value = false;
    // while(low<high){
    //     int mid = low + (high-low)/2;
    //     if(b[mid]==z){
    //         value = true;
    //         break;
    //     }
    //     if(b[mid]>z){
    //         high = mid-1;
    //     }
    //     else {
    //         low = mid+1;
    //     }
    // }
    // if(value) cout << "Yes\n";
    // else cout << "No\n";

    // vector<int> v1;
    // v1.push_back(5);
    // v1.push_back(4);
    // v1.push_back(9);

    // // for(int i=0;i<v1.size();i++)
    // //     cout << v1[i] << " ";
    // // cout << endl;

    // pair<int,int> p1;
    // p1.first = 5;
    // p1.second = 6;

    // // cout << p1.first << " " << p1.second << endl;

    // // vector<pair<int,int>> v2;
    // // v2.push_back({7,3});
    // // v2.push_back({5,6});
    // // v2.push_back({9,10});

    // // for(int i=0;i<v2.size();i++){
    // //     cout << v2[i].first << " " << v2[i].second << endl;
    // // }
    // // sort(v2.begin(),v2.end());

    // // for(int i=0;i<v2.size();i++){
    // //     cout << v2[i].first << " " << v2[i].second << endl;
    // // }

    // vector<int> v3{10,5,3,20,40};

    // // for(int i=0;i<v3.size();i++)
    // //     cout << v3[i] << " ";
    // // cout << endl;

    // // sort(v3.begin(),v3.end());

    // // for(int i=0;i<v3.size();i++)
    // //     cout << v3[i] << " ";
    // // cout << endl;

    // // reverse(v3.begin(),v3.end());

    // // for(int i=0;i<v3.size();i++)
    // //     cout << v3[i] << " ";
    // // cout << endl;


    // set<int> s1; // set stores unique elements in it 

    // s1.insert(5);
    // s1.insert(4);
    // s1.insert(10);
    // s1.insert(10);

    // //  4 5 10

    // cout << s1.size() << endl; // returns the number of elements present in the array

    // for(auto a: s1){
    //     cout << a << " ";  // iterates over s1
    // }


    // int cnt = s1.count(9); // returns the number of elements of value '9' in set
    // cout << cnt << endl;

    // map<int,int> m1;  //  key - value pair , key is unique and a value is assigned to it

    // m1[2] = 4;  // key - 2 , value - 4
    // m1[3] = 10; // key - 3, value - 10
    // m1[3] = 9;  // update value of key 3 to 9
    
    // for(auto it= m1.begin(); it!=m1.end();it++){
    //     cout << it->first << " " << it->second << endl;
    // }


    // cout << m1[2] << endl;


    string s = "Hello there";
    cout << s << endl;
    for(int i=0;i<s.size();i++){
        if(s[i]=='o'){
            s[i] = 'i';
        }
    }
    cout << s << endl;





}