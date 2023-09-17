#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#define mod (int)(1e+9)+7
using std::vector;
using std::map;
using std::max;
using std::min;
using std::sort;
using std::swap;
using std::reverse;

long countSubsequences(vector<int> arr, int n) {
    // Write your code here. 
    map<int,int> m;

    for(int i=0; i<n; i++){
        m[arr[i]]++;
    }

    long long int ans=0;

    for(auto i:m){
        std::cout<<pow(2,i.second)-1<<std::endl;
        ans+=((long long int)(pow(2,i.second)-1)%(mod));
    }

    return ans%(mod);
}
/*
4
1 1 1 2
*/

int main(int argc, char const *argv[])
{
    int n= 1e+5;
    vector<int> v;
    for(int i=0; i<n; i++){
        v.push_back(1e+9);
    }
    std::cout<<countSubsequences(v,n)<<std::endl;
return 0;
}