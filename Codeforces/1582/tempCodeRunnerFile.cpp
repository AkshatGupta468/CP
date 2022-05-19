#include<iostream>
using namespace std;

int main(){
    const int n=7;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n/2;i++){
        a[n-i-1]=a[i];
        a[i]=a[n-i-1];
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}
