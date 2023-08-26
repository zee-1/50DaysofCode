#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
using std::vector;
using std::max;
using std::min;
using std::sort;
using std::swap;
using std::reverse;

int hash(int item,int marker,int n){
      return ((item+n/2)%marker);
}

class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int marker = 6*1e4;
      int count = nums.size();
      for(int i=0; i<count; i++){
            auto idx = hash(nums[i]%marker,count,count);
            nums[idx] =marker +(nums[idx]);
            // nums[idx] =marker +abs(nums[idx]);
      }        
      int target = std::ceil(count/double(2));
      for(int i=0; i<count; i++){
            auto idx = hash(nums[i]%marker,count,count);
            if((nums[idx]/marker)>=target){
                  return (nums[i]%marker);
            }
      }
      return nums[0];
    }
};

int main(int argc, char const *argv[])
{
      // std::cout<<__INT32_MAX__<<std::endl;
      std::cout<<59999%60000<<std::endl;
      // std::cout<< (-1000000000+2)%int(5)<<std::endl;
      // std::cout<< (1000000000+2)%int(5)<<std::endl;
      // Solution s;
      // vector<int> vec = {12,12,12,5,5,12,12,12};
      // vector<int> vec = {1000000000,1000000000,-1000000000,-1000000000,-1000000000};
      // vector<int> vec = {-1,100,2,100,100,4,100};
      // vector<int> vec = {3,2,3};
      // vector<int> vec = {1,1,2,2,1,1};
      // auto ans = s.majorityElement(vec);
      // std::cout<<ans<<std::endl;
return 0;
}