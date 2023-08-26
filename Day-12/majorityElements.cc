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
            nums[idx]+=marker;
      }        
      int target = std::ceil(count/double(2));
      for(int i=0; i<count; i++){
            if((nums[i]/marker)>=target){
                  return nums[i]%marker;
            }
      }
      return nums[0];
    }
};

int main(int argc, char const *argv[])
{
      Solution s;
      // vector<int> vec = {12,12,12,5,5,12,12,12};
      // vector<int> vec = {3,2,3};
      vector<int> vec = {1,1,2,2,1,1};
      auto ans = s.majorityElement(vec);
      std::cout<<ans<<std::endl;
return 0;
}