#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using std::vector;
using std::max;
using std::min;
using std::sort;
using std::swap;
using std::reverse;

std::set<std::string> createString(std::vector<char> vec){
    if(vec.size()==1 or vec.size()==0){
        std::set<std::string> ans;
        for(auto i: vec){
            std::string s = "";
            ans.insert(s+i);
        }
        return ans;
    }else{
        std::set<std::string> ans;
        for(int i=0;i<vec.size(); i++){
            auto temp_vec = vec;
            temp_vec.erase(temp_vec.begin()+i);
            auto temp = createString(temp_vec);
            for(auto j:temp){
                ans.insert(vec[i]+j);
            }
        }
        return ans;
    }
};

// vector<std::string> wrapper(std::string s){

//     if(s==""){
//         vector<std::string> vec;
//         return vec;
//     }else if(s.length()==1){
//         vector<std::string> vec(s.begin(),s.end());
//         return vec;
//     }else{
//         vector<std::string> vec(s.begin());
//         vec.append(createString())
//     }
// }

int main(int argc, char const *argv[])
{
    // std::string s= "aaabc";
    std::string s;
    std::cin>>s;
    vector<char> vec(s.begin(),s.end());

    auto ans = createString(vec);
    std::cout<<ans.size()<<std::endl;
    for(auto i:ans){
        std::cout<<i<<std::endl;
    }
return 0;
}