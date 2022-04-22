#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    int n;
    cin >> n;
    int* array = new int[n];

    for(int j=0; j<n; j++)
    {
        cin>>array[j];
    }

    for(int i=n-1; i>=0 ;i--)
    {
        cout<<array[i]<<" ";
    }
    return 0;
}
