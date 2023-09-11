#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::max;
using std::min;
using std::sort;
using std::swap;
using std::reverse;

std::vector<std::string> generateGray(vector<std::string> v,int n){
    vector<std::string> vec;
    for(int i=0; i<v.size(); i++){
        vec.push_back("0"+v[i]);
    }
    for(int i=v.size()-1  ; i>=0; i--){
        vec.push_back("1"+v[i]);
    }
    return vec;
} 

int main(int argc, char const *argv[])
{

    int n=0;
    std::cin>>n;
    vector<std::string> ans= {"0","1"};
    for(int i=1; i<n;i++){
        ans = generateGray(ans,i);
    }
    for(auto i:ans){
        std::cout<<i<<std::endl;
    };

return 0;
}