#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using std::vector;
using std::map;
using std::max;
using std::min;
using std::sort;
using std::swap;
using std::reverse;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        auto size = nums.size();
        vector<int> temp;

        for(int i=0; i<size;i++){
            if(m[target-nums[i]]){
                temp={i,m[target-nums[i]]-1};
                return temp;
            }else{
                m[nums[i]]=i+1;
            }

        }
        return temp;
    }
};

int main(int argc, char const *argv[])
{
      vector<int> vec ={2,7,11,15};
      Solution s;
      auto ans = s.twoSum(vec,9);
      for(auto i:ans){
            std::cout<<i<<std::endl;
      };
return 0;
}